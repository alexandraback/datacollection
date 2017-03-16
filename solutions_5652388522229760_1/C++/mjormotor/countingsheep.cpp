#include "countingsheep.h"

#include <sstream>
#include <string>
#include <iostream>

#include <algorithm>
#include <functional>

#include "parse.h"

CountingSheepProblem::CountingSheepProblem()
	: m_answers( 0 )
	, m_T( 100 )
	, m_cases( 100 )
{
}

CountingSheepProblem::~CountingSheepProblem()
{
	for( unsigned int i = 0; i < m_cases.size(); ++i )
	{
		delete m_cases[i];
	}
}

void CountingSheepProblem::Init( std::vector< std::string > const& in )
{
	Parse( in );
}

void CountingSheepProblem::Solve()
{
	for( unsigned int i = 0; i < m_T; ++i )
	{
		std::ostringstream os;
		m_cases[i]->Solve();
		unsigned int answer = m_cases[i]->GetAnswer();
		if( answer == 0 )
		{
			os << "INSOMNIA";
		}
		else
		{
			os << answer;
		}
		m_answers.push_back( os.str() );
	}
}

std::vector< std::string > const& CountingSheepProblem::GetAnswer() const
{
	return m_answers;
}

void CountingSheepProblem::DumpState() const
{
	std::cout << "T = " << m_T << std::endl;
	for( unsigned int i = 0; i < m_T; ++i )
	{
		std::cout << "N[" << i << "] = " << m_cases[i]->m_N << std::endl;
	}
}

void CountingSheepProblem::DumpAnswer() const
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

void CountingSheepProblem::OutputStateAndAnswer( std::ostream& os ) const
{
	for( unsigned int i = 0; i < m_answers.size(); ++i )
	{
		os << "N[" << i << "] = " << m_cases[i]->m_N << std::endl;

		os << "Case #" << i << ": " << m_answers[i] << std::endl;
	}

	if( m_answers.size() != m_T )
	{
		os << "Alert! answers num(" << m_answers.size() << ") does not match test num(" << m_T << ")." << std::endl;
	}
}

void CountingSheepProblem::Parse( std::vector< std::string > const& in )
{
	m_T = atoi( in[0].c_str() );
	unsigned int lineNum = 1;
	unsigned int caseNum = 0;
	while( lineNum < in.size() )
	{
		std::vector< std::string > tokens = ParseUtil::Tokenize( in[lineNum] );
		unsigned int N = atoi( tokens[0].c_str() );
		Case* cs = new Case( N );
		m_cases[caseNum] = cs;
		++caseNum;
		++lineNum;
	}
}

CountingSheepProblem::Case::Case( unsigned int N )
	: m_answer( UINT_MAX )
	, m_N( N )
	, m_states( 0 )
{
}

CountingSheepProblem::Case::~Case()
{
}

unsigned int CountingSheepProblem::Case::GetAnswer() const
{
	return m_answer;
}

void CountingSheepProblem::Case::Solve()
{
	m_answer = 0;
	if( m_N == 0 ) return;

	do
	{
		m_answer += m_N;
		unsigned int n = m_answer;
		while( n > 0 )
		{
			unsigned int digit = n % 10;
			m_states |= 0x01 << digit;
			n /= 10;
		}
	} while( m_states != 0x3FF );
}
