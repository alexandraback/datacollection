#include "fractiles.h"

#include <sstream>
#include <string>
#include <iostream>

#include <algorithm>
#include <functional>

#include "parse.h"

FractilesProblem::FractilesProblem()
	: m_answers( 0 )
	, m_T( 100 )
	, m_cases( 100 )
{
}

FractilesProblem::~FractilesProblem()
{
	for( unsigned int i = 0; i < m_cases.size(); ++i )
	{
		delete m_cases[i];
	}
}

void FractilesProblem::Init( std::vector< std::string > const& in )
{
	Parse( in );
}

void FractilesProblem::Solve()
{
	for( unsigned int i = 0; i < m_T; ++i )
	{
		std::ostringstream os;
		m_cases[i]->Solve();
		std::vector< std::string > const& answers = m_cases[i]->GetAnswers();
		unsigned int count = answers.size();
		if( count == 0 )
		{
			os << "IMPOSSIBLE";
		}
		else
		{
			os << answers[0].c_str();
			for( unsigned int a = 1; a < count; ++a )
			{
				os << " " << answers[a].c_str();
			}
		}
		m_answers.push_back( os.str() );
	}
}

std::vector< std::string > const& FractilesProblem::GetAnswer() const
{
	return m_answers;
}

void FractilesProblem::DumpState() const
{
	std::cout << "T = " << m_T << std::endl;
	for( unsigned int i = 0; i < m_T; ++i )
	{
		std::cout << "K[" << i << "] = " << m_cases[i]->m_K << ", ";
		std::cout << "C[" << i << "] = " << m_cases[i]->m_C << ", ";
		std::cout << "S[" << i << "] = " << m_cases[i]->m_S << std::endl;
	}
}

void FractilesProblem::DumpAnswer() const
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

void FractilesProblem::OutputStateAndAnswer( std::ostream& os ) const
{
	for( unsigned int i = 0; i < m_answers.size(); ++i )
	{
		os << "K[" << i << "] = " << m_cases[i]->m_K << ", ";
		os << "C[" << i << "] = " << m_cases[i]->m_C << ", ";
		os << "S[" << i << "] = " << m_cases[i]->m_S << std::endl;
		os << "Case #" << i << ": " << m_answers[i] << std::endl;
	}

	if( m_answers.size() != m_T )
	{
		os << "Alert! answers num(" << m_answers.size() << ") does not match test num(" << m_T << ")." << std::endl;
	}
}

void FractilesProblem::Parse( std::vector< std::string > const& in )
{
	m_T = atoi( in[0].c_str() );
	unsigned int lineNum = 1;
	unsigned int caseNum = 0;
	while( lineNum < in.size() )
	{
		std::vector< std::string > tokens = ParseUtil::Tokenize( in[lineNum] );
		unsigned int K = atoi( tokens[0].c_str() );
		unsigned int C = atoi( tokens[1].c_str() );
		unsigned int S = atoi( tokens[2].c_str() );
		Case* cs = new Case( K, C, S );
		m_cases[caseNum] = cs;
		++caseNum;
		++lineNum;
	}
}

FractilesProblem::Case::Case( unsigned int k, unsigned int c, unsigned int s )
	: m_answers( 0 )
	, m_K( k )
	, m_C( c )
	, m_S( s )
{
}

FractilesProblem::Case::~Case()
{
}

std::vector< std::string > const& FractilesProblem::Case::GetAnswers() const
{
	return m_answers;
}

void FractilesProblem::Case::Solve()
{
	Analysis analysis( m_K, m_C, m_S, true );
	analysis.Exec();
	
	for( unsigned int i = 0; i < analysis.m_answers.size(); ++i )
	{
		std::ostringstream os;
		os << analysis.m_answers[i];
		m_answers.push_back( os.str() );
	}
}

FractilesProblem::Case::Analysis::Analysis( unsigned int k, unsigned int c, unsigned int s, bool isFast )
	: m_sequences( nullptr )
	, m_answers()
	, m_k( k )
	, m_c( c )
	, m_s( s )
	, m_isFast( isFast )
{
	if( !m_isFast )
	{
		m_originals = new Sequence[m_k];
		m_sequences = new Sequence[m_k];
		memset( m_originals, 0x0000, sizeof(Sequence) * m_k );
		memset( m_sequences, 0x0000, sizeof(Sequence) * m_k );
	}
}

FractilesProblem::Case::Analysis::~Analysis()
{
	if( !m_isFast )
	{
		delete[m_k] m_sequences;
		delete[m_k] m_originals;
	}
}

void FractilesProblem::Case::Analysis::Exec()
{
	if( m_c == 0 ) return;
	
	unsigned __int64 kc = m_k;
	unsigned __int64 kh = 0;
	if( !m_isFast )
	{
		for( unsigned int k = 0; k < m_k; ++k )
		{
			m_originals[k].Set( k );
		}
		memcpy( m_sequences, m_originals, sizeof(Sequence) * m_k );
	}

	for( unsigned int c = 0; c < m_c - 1; ++c )
	{
		kh += ( c < m_k ) ? c: m_k - 1;
		kh *= m_k;
		kc *= m_k;
		if( !m_isFast )
		{
			if( c < m_k )
			{
				m_sequences[c].Fill( m_k );
			}
		}
	}
	if( m_s * m_c < m_k )
	{
		return;
	}
	
	unsigned int t = 0;
	for( unsigned int s = 0, t = 0; s < m_s && t < m_k; ++s )
	{
		unsigned __int64 k = t;
		++t;
		if( t + m_c > m_k + 1 )
		{
			unsigned int c = 1;
			for( ; t < m_k; ++c, ++t )
			{
				k *= m_k;
				k += t;
			}
			for( ; c < m_c && c < m_k; ++c )
			{
				k *= m_k;
			}
			m_answers.push_back( k + 1 );
			break;
		}
		for( unsigned int c = 1; c < m_c && c < m_k; ++c, ++t )
		{
			k *= m_k;
			k += t;
		}
		m_answers.push_back( k + 1 );
	}
}

FractilesProblem::Case::Analysis::Sequence::Sequence()
	: m_l( 0x0000000000000000ULL )
	, m_h( 0x0000000000000000ULL )
{
}

bool FractilesProblem::Case::Analysis::Sequence::operator[]( unsigned int index ) const
{
	if( index < 64 )
	{
		return ( m_l >> index ) & 0x0000000000000001ULL;
	}
	index -= 64;
	return ( m_h >> index ) & 0x0000000000000001ULL;
}

FractilesProblem::Case::Analysis::Sequence FractilesProblem::Case::Analysis::Sequence::operator>>( unsigned int index ) const
{
	Sequence ret = *this;
	ret >>= index;
	return ret;
}

FractilesProblem::Case::Analysis::Sequence FractilesProblem::Case::Analysis::Sequence::operator<<( unsigned int index ) const
{
	Sequence ret = *this;
	ret <<= index;
	return ret;
}

FractilesProblem::Case::Analysis::Sequence& FractilesProblem::Case::Analysis::Sequence::operator>>=( unsigned int index )
{
	if( index < 64 )
	{
		m_l >>= index;
		m_l |= m_h << ( 63 - index );
		m_h >>= index;
	}
	else
	{
		index -= 64;
		m_l = m_h >> index;
		m_h = 0x0000000000000000ULL;
	}
	return *this;
}

FractilesProblem::Case::Analysis::Sequence& FractilesProblem::Case::Analysis::Sequence::operator<<=( unsigned int index )
{
	if( index < 64 )
	{
		m_h <<= index;
		m_h |= m_l >> ( 63 - index );
		m_l <<= index;
	}
	else
	{
		index -= 64;
		m_h = m_l << index;
		m_l = 0x0000000000000000ULL;
	}
	return *this;
}

unsigned int FractilesProblem::Case::Analysis::Sequence::GetOrder() const
{
	unsigned int order = 0;
	if( m_h == 0x0000000000000000ULL )
	{
		unsigned __int64 factor = m_l;
		while( factor != 0x0000000000000000ULL )
		{
			++order;
			factor >>= 1;
		}
		return order;
	}
	order += 64;
	unsigned __int64 factor = m_h;
	while( factor != 0x0000000000000000ULL )
	{
		++order;
		factor >>= 1;
	}
	return order;
}

FractilesProblem::Case::Analysis::Sequence& FractilesProblem::Case::Analysis::Sequence::Set( unsigned int index )
{
	if( index < 64 )
	{
		m_l |= 0x0000000000000001ULL << index;
	}
	else
	{
		index -= 64;
		m_h |= 0x0000000000000001ULL << index;
	}
	return *this;
}

FractilesProblem::Case::Analysis::Sequence& FractilesProblem::Case::Analysis::Sequence::Set( Sequence const& sequence )
{
	m_l |= sequence.m_l;
	m_h |= sequence.m_h;
	return *this;
}

FractilesProblem::Case::Analysis::Sequence& FractilesProblem::Case::Analysis::Sequence::Fill( unsigned int count )
{
	return Fill( 0, count );
}

FractilesProblem::Case::Analysis::Sequence& FractilesProblem::Case::Analysis::Sequence::Fill( unsigned int index, unsigned int count )
{
	unsigned int head = index;
	unsigned int tail = index + count;
	unsigned __int64 headMask = 0xffffffffffffffffULL;
	unsigned __int64 tailMask = 0xffffffffffffffffULL;
	unsigned __int64 mask = 0x0000000000000000ULL;
	if( head < 64 )
	{
		headMask = 0x0000000000000001ULL << head;
		--headMask;
	}
	if( tail < 64 )
	{
		tailMask = 0x0000000000000001ULL << tail;
		--tailMask;
		mask = tailMask & ~headMask;
		m_l |= mask;
	}
	else
	{
		headMask = 0xffffffffffffffffULL;
		if( head >= 64 )
		{
			head -= 64;
			headMask = 0x0000000000000001ULL << head;
			--headMask;
		}
		tail -= 64;
		tailMask = 0x0000000000000001ULL << tail;
		--tailMask;
		mask = tailMask & ~headMask;
		m_h |= mask;
	}
	return *this;
}

FractilesProblem::Case::Analysis::Sequence& FractilesProblem::Case::Analysis::Sequence::Clear()
{
	m_l = 0x0000000000000000ULL;
	m_h = 0x0000000000000000ULL;
	return *this;
}

FractilesProblem::Case::Analysis::Sequence& FractilesProblem::Case::Analysis::Sequence::Clear( unsigned int index )
{
	if( index < 64 )
	{
		unsigned __int64 mask = 0x0000000000000001ULL << index;
		--mask;
		m_l &= mask;
		m_h = 0x0000000000000000ULL;
	}
	else
	{
		index -= 64;
		unsigned int mask = 0x0000000000000001ULL << index;
		--mask;
		m_l |= m_h & mask;
		m_h = 0x0000000000000000ULL;
	}
	return *this;
}
