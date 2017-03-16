#include "revengeofthepancakes.h"

#include <sstream>
#include <string>
#include <iostream>

#include <algorithm>
#include <functional>

#include "parse.h"

RevengeOfThePancakesProblem::RevengeOfThePancakesProblem()
	: m_answers( 0 )
	, m_T( 100 )
	, m_cases( 100 )
{
}

RevengeOfThePancakesProblem::~RevengeOfThePancakesProblem()
{
	for( unsigned int i = 0; i < m_cases.size(); ++i )
	{
		delete m_cases[i];
	}
}

void RevengeOfThePancakesProblem::Init( std::vector< std::string > const& in )
{
	Parse( in );
}

void RevengeOfThePancakesProblem::Solve()
{
	for( unsigned int i = 0; i < m_T; ++i )
	{
		std::ostringstream os;
		m_cases[i]->Solve();
		os << m_cases[i]->GetAnswer();
		m_answers.push_back( os.str() );
	}
}

std::vector< std::string > const& RevengeOfThePancakesProblem::GetAnswer() const
{
	return m_answers;
}

void RevengeOfThePancakesProblem::DumpState() const
{
	std::cout << "T = " << m_T << std::endl;
	for( unsigned int i = 0; i < m_T; ++i )
	{
		std::cout << "S[" << i << "] = " << m_cases[i]->m_S.c_str() << std::endl;
	}
}

void RevengeOfThePancakesProblem::DumpAnswer() const
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

void RevengeOfThePancakesProblem::OutputStateAndAnswer( std::ostream& os ) const
{
	for( unsigned int i = 0; i < m_answers.size(); ++i )
	{
		os << "S[" << i << "] = " << m_cases[i]->m_S.c_str() << std::endl;

		os << "Case #" << i << ": " << m_answers[i] << std::endl;
	}

	if( m_answers.size() != m_T )
	{
		os << "Alert! answers num(" << m_answers.size() << ") does not match test num(" << m_T << ")." << std::endl;
	}
}

void RevengeOfThePancakesProblem::Parse( std::vector< std::string > const& in )
{
	m_T = atoi( in[0].c_str() );
	unsigned int lineNum = 1;
	unsigned int caseNum = 0;
	while( lineNum < in.size() )
	{
		std::vector< std::string > tokens = ParseUtil::Tokenize( in[lineNum] );
		std::string const& S = tokens[0];
		Case* cs = new Case( S );
		m_cases[caseNum] = cs;
		++caseNum;
		++lineNum;
	}
}

RevengeOfThePancakesProblem::Case::Case( std::string const& s )
	: m_answer( UINT_MAX )
	, m_S( s )
	, m_states( 0 )
{
}

RevengeOfThePancakesProblem::Case::~Case()
{
}

unsigned int RevengeOfThePancakesProblem::Case::GetAnswer() const
{
	return m_answer;
}

void RevengeOfThePancakesProblem::Case::Solve()
{
	m_answer = 0;
	unsigned int n = m_S.length();
	if( n == 0 ) return;
	char sign = m_S[0];
	for( unsigned int i = 1; i < n; ++i )
	{
		if( sign != m_S[i] )
		{
			++m_answer;
			sign = m_S[i];
		}
	}
	if( sign == '-' )
	{
		++m_answer;
	}
}
