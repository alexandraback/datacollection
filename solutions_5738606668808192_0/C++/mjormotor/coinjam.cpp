#include "coinjam.h"

#include <sstream>
#include <string>
#include <iostream>
#include <fstream>

#include <algorithm>
#include <functional>
#include <math.h>

#include "parse.h"

#define PRIME_COUNT			400000000
#define PRIME_SIEVE_COUNT	400000000
//#define PRIME_PATH			"prime.txt"
#define PRIME_PATH			""

BitArray::BitArray( unsigned __int64 size )
	: m_data( nullptr )
	, m_size( size )
{
	if( m_size > 0 )
	{
		unsigned __int64 count = GetDataCount();
		m_data = new BaseType[count];
		memset( m_data, 0x00, sizeof( BaseType ) * count );
	}
}

BitArray::~BitArray()
{
	if( m_size > 0 )
	{
		unsigned __int64 count = GetDataCount();
		delete[count] m_data;
	}
}

bool BitArray::operator[]( unsigned __int64 index ) const
{
	unsigned __int64 dataIndex = GetDataIndex( index );
	unsigned __int64 baseIndex = index - sizeof( BaseType ) * 8 * dataIndex;
	return !!( m_data[dataIndex] & ( 0x00000001 << baseIndex ) );
}

unsigned __int64 BitArray::GetSize() const
{
	return m_size;
}

unsigned __int64 BitArray::GetDataCount() const
{
	return m_size / ( sizeof( BaseType ) * 8 );
}

unsigned __int64 BitArray::GetDataIndex( unsigned __int64 index ) const
{
	return index / ( sizeof( BaseType ) * 8 );
}

unsigned __int64 BitArray::FindNextIndex( unsigned __int64 index, unsigned __int64 indexLast ) const
{
	unsigned __int64 size = GetSize();
	if( indexLast >= size )
	{
		indexLast = size - 1;
	}
	unsigned __int64 dataIndex = GetDataIndex( index );
	unsigned __int64 baseIndex = index - sizeof( BaseType ) * 8 * dataIndex;
	BaseType data = m_data[dataIndex] >> baseIndex;
	if( data > 0 )
	{
		while( !( data & 0x00000001 ) )
		{
			data >>= 1;
			++index;
		}
		return index;
	}
	unsigned __int64 dataIndexLast = GetDataIndex( indexLast );
	unsigned __int64 dataCount = GetDataCount();
	while( dataIndex + 1 < dataIndexLast )
	{
		++dataIndex;
		data = m_data[dataIndex];
		if( data > 0 )
		{
			index = sizeof( BaseType ) * 8 * dataIndex;
			while( !( data & 0x00000001 ) )
			{
				data >>= 1;
				++index;
			}
			return index;
		}
	}
	if( dataIndex == dataIndexLast )
	{
		return size;
	}
	dataIndex = dataIndexLast;
	data = m_data[dataIndex];
	baseIndex = indexLast - sizeof( BaseType ) * 8 * dataIndex;
	data &= ( 0x00000001 << baseIndex ) - 1;
	if( data > 0 )
	{
		index = sizeof( BaseType ) * 8 * dataIndex;
		while( !( data & 0x00000001 ) )
		{
			data >>= 1;
			++index;
		}
		return index;
	}
	return size;
}

BitArray& BitArray::Set( unsigned __int64 index )
{
	unsigned __int64 dataIndex = GetDataIndex( index );
	unsigned __int64 baseIndex = index - sizeof( BaseType ) * 8 * dataIndex;
	m_data[dataIndex] |= 0x00000001 << baseIndex;
	return *this;
}

BitArray& BitArray::Unset( unsigned __int64 index )
{
	unsigned __int64 dataIndex = GetDataIndex( index );
	unsigned __int64 baseIndex = index - sizeof( BaseType ) * 8 * dataIndex;
	m_data[dataIndex] &= ~( 0x00000001 << baseIndex );
	return *this;
}

BitArray& BitArray::Toggle( unsigned __int64 index )
{
	unsigned __int64 dataIndex = GetDataIndex( index );
	unsigned __int64 baseIndex = index - sizeof( BaseType ) * 8 * dataIndex;
	BaseType flags = 0x00000001 << baseIndex;
	if( !!( m_data[dataIndex] & flags ) )
	{
		m_data[dataIndex] &= ~flags;
	}
	else
	{
		m_data[dataIndex] |= flags;
	}
	return *this;
}

Primes* Primes::s_instance = nullptr;

Primes::Primes( std::string const& path )
	: m_path( path )
	, m_primes( PRIME_COUNT )
	, m_bound( 0 )
{
	s_instance = this;

	std::ifstream ifs( m_path );
	std::string buf;
	while( ifs && getline( ifs, buf ) )
	{
		m_bound = atoi( buf.c_str() );
		m_primes.Set( atoi( buf.c_str() ) );
	}
	if( m_bound == 0 )
	{
		Sieve();
	}
}

Primes::~Primes()
{
	s_instance = nullptr;
}

unsigned __int64 Primes::GetDivisor( unsigned __int64 decimal )
{
	return s_instance->FindDivisor( decimal );
}

unsigned __int64 Primes::FindNextPrime( unsigned __int64 decimal )
{
	while( decimal >= m_bound )
	{
		Sieve();
	}
	unsigned __int64 prime = m_primes.FindNextIndex( decimal + 1, m_bound );
	while( prime >= m_primes.GetSize() )
	{
		Sieve();
		prime = m_primes.FindNextIndex( decimal + 1, m_bound );
	}
	return prime;
}

unsigned __int64 Primes::FindDivisor( unsigned __int64 decimal )
{
	for( unsigned __int64 divisor = 2; divisor * divisor < decimal; divisor = FindNextPrime( divisor ) )
	{
		if( decimal % divisor == 0 )
		{
			return divisor;
		}
	}
	return decimal;
}

void Primes::Sieve()
{
	SieveOfAtkin( PRIME_SIEVE_COUNT );

	std::ofstream ofs( m_path );
	if( ofs )
	{
		std::cout << m_path << " saving.." << std::endl;
		for( unsigned int i = 0; i < m_bound; ++i )
		{
			if( m_primes[i] )
			{
				ofs << i << std::endl;
			}
		}
		std::cout << m_path << " saved.." << std::endl;
	}
}

void Primes::SieveOfAtkin( unsigned __int64 count )
{
    unsigned __int64 upperBound = m_bound + count;
	unsigned __int64 upperBoundSqrt = static_cast< unsigned __int64 >( sqrt( static_cast< long double >( upperBound ) ) );

	if( m_bound < 3 )
	{
		m_primes.Set( 2 );
		m_primes.Set( 3 );
	}
	
	for( unsigned __int64 x = 1; x <= upperBoundSqrt; x++ )
	{
		for( unsigned __int64 y = 1; y <= upperBoundSqrt; y++ )
		{
			unsigned __int64 n = ( 4 * x * x ) + ( y * y );
			if( n <= upperBound && ( n % 12 == 1 || n % 12 == 5 ) )
			{
				m_primes.Toggle( n );
			}
			n = ( 3 * x * x ) + ( y * y );
			if( n <= upperBound && ( n % 12 == 7 ) )
			{
				m_primes.Toggle( n );
			}
			n = ( 3 * x * x ) - ( y * y );
			if( x > y && n <= upperBound && ( n % 12 == 11 ) )
			{
				m_primes.Toggle( n );
			}
		}
	}

	for( unsigned __int64 n = ( 5 > m_bound ) ? 5 : m_bound + 1; n <= upperBoundSqrt; n++ )
	{
		if( m_primes[n] )
		{
			unsigned __int64 x = n * n;
			for( unsigned __int64 i = x; i <= upperBound; i += x )
			{
				m_primes.Unset( i );
			}
		}
	}

	m_bound = upperBound;
}

CoinJamProblem::CoinJamProblem()
	: m_answers( 0 )
	, m_T( 100 )
	, m_cases( 100 )
	, m_primes( PRIME_PATH )
{
}

CoinJamProblem::~CoinJamProblem()
{
	for( unsigned int i = 0; i < m_cases.size(); ++i )
	{
		delete m_cases[i];
	}
}

void CoinJamProblem::Init( std::vector< std::string > const& in )
{
	Parse( in );
}

void CoinJamProblem::Solve()
{
	for( unsigned int i = 0; i < m_T; ++i )
	{
		std::ostringstream os;
		m_cases[i]->Solve();
		std::vector< std::string > const& answers = m_cases[i]->GetAnswers();
		for( unsigned int j = 0; j < m_cases[i]->m_J; ++j )
		{
			m_answers.push_back( answers[j] );
		}
	}
}

std::vector< std::string > const& CoinJamProblem::GetAnswer() const
{
	return m_answers;
}

void CoinJamProblem::DumpState() const
{
	std::cout << "T = " << m_T << std::endl;
	for( unsigned int i = 0; i < m_T; ++i )
	{
		std::cout << "N[" << i << "] = " << m_cases[i]->m_N << ", ";
		std::cout << "J[" << i << "] = " << m_cases[i]->m_J << std::endl;
	}
}

void CoinJamProblem::DumpAnswer() const
{
	for( unsigned int i = 0; i < m_answers.size(); ++i )
	{
		std::cout << "Case #" << i << ": " << m_answers[i] << std::endl;
	}

	if( m_answers.size() != m_T )
	{
		std::cout << "Alert! answers num(" << m_answers.size() << ") does not match test num(" << m_T << ")." << std::endl;
	}
}

void CoinJamProblem::OutputStateAndAnswer( std::ostream& os ) const
{
	for( unsigned int i = 0; i < m_answers.size(); ++i )
	{
		os << "N[" << i << "] = " << m_cases[i]->m_N << ", ";
		os << "J[" << i << "] = " << m_cases[i]->m_J << std::endl;
		os << "Case #" << i << ": " << m_answers[i] << std::endl;
	}

	if( m_answers.size() != m_T )
	{
		os << "Alert! answers num(" << m_answers.size() << ") does not match test num(" << m_T << ")." << std::endl;
	}
}

void CoinJamProblem::Parse( std::vector< std::string > const& in )
{
	m_T = atoi( in[0].c_str() );
	unsigned int lineNum = 1;
	unsigned int caseNum = 0;
	while( lineNum < in.size() )
	{
		std::vector< std::string > tokens = ParseUtil::Tokenize( in[lineNum] );
		unsigned int N = atoi( tokens[0].c_str() );
		unsigned int J = atoi( tokens[1].c_str() );
		Case* cs = new Case( N, J );
		m_cases[caseNum] = cs;
		++caseNum;
		++lineNum;
	}
}

CoinJamProblem::JamCoin::JamCoin( unsigned __int64 binary )
{
	memset( m_radices, 0x00, sizeof( m_radices ) );
	memset( m_divisors, 0x00, sizeof( m_divisors ) );
	m_radices[2] = binary;
	while( binary > 0 )
	{
		++m_radices[1];
		binary >>= 1;
	}
	m_divisors[2] = Primes::GetDivisor( m_radices[2] );
	if( m_divisors[2] < m_radices[2] )
	{
		m_radices[0] = 2;
		unsigned int base = GetLastCheckedBase();
		do
		{
			++base;
			GenerateRadix( base );
			m_divisors[base] = Primes::GetDivisor( m_radices[base] );
			if( m_divisors[base] == m_radices[base] )
			{
				break;
			}
			m_radices[0] = base;
		} while( base < 10 );
	}
}

bool CoinJamProblem::JamCoin::IsValid() const
{
	return GetLastCheckedBase() == 10;
}

unsigned int CoinJamProblem::JamCoin::GetLastCheckedBase() const
{
	return static_cast< unsigned int >( m_radices[0] );
}

unsigned int CoinJamProblem::JamCoin::GetBinaryLength() const
{
	return static_cast< unsigned int >( m_radices[1] );
}

unsigned __int64 CoinJamProblem::JamCoin::GetDivisor( unsigned int base ) const
{
	return m_divisors[base];
}

std::string CoinJamProblem::JamCoin::GetBinaryStr() const
{
	std::ostringstream os;
	unsigned int n = GetBinaryLength();
	unsigned __int64 binary = m_radices[2];
	unsigned __int64 mask = 0x0000000000000001ull << ( n - 1 );
	for( unsigned int i = 0; i < n; ++i )
	{
		if( binary & mask )
		{
			os << "1";
		}
		else
		{
			os << "0";
		}
		mask >>= 1;
	}
	return os.str();
}


void CoinJamProblem::JamCoin::GenerateRadix( unsigned int base )
{
	unsigned __int64 radix = 0;
	unsigned int n = GetBinaryLength();
	unsigned __int64 binary = m_radices[2];
	unsigned __int64 mask = 0x0000000000000001ull << ( n - 1 );
	for( unsigned int i = 0; i < n; ++i )
	{
		radix *= base;
		if( binary & mask )
		{
			++radix;
		}
		mask >>= 1;
	}
	m_radices[base] = radix;
}

CoinJamProblem::Case::Case( unsigned int n, unsigned int j )
	: m_answers( 0 )
	, m_N( n )
	, m_J( j )
{
}

CoinJamProblem::Case::~Case()
{
}

std::vector< std::string > const& CoinJamProblem::Case::GetAnswers() const
{
	return m_answers;
}

void CoinJamProblem::Case::Solve()
{
	unsigned __int64 binary = 0x0000000000000001ull << ( m_N - 1 );
	unsigned __int64 binaryLast = 0x0000000000000001ull << m_N;
	if( m_N > 0 )
	{
		++binary;
	}
	for( unsigned int j = 0; j < m_J; ++j )
	{
		while( binary < binaryLast )
		{
			JamCoin jamcoin( binary );
			binary += 0x0000000000000002ull;
			if( jamcoin.IsValid() )
			{
				std::ostringstream os;
				os << jamcoin.GetBinaryStr();
				for( unsigned int base = 2; base <= 10; ++base )
				{
					os << " " << jamcoin.GetDivisor( base );
				}
				m_answers.push_back( os.str() );
				break;
			}
		}
	}
}
