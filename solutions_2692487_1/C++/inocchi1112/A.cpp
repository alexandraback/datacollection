#include <stdint.h>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

//#define TEST

namespace {


#if defined(TEST)
	const char INPUT_FILENAME[32]	= "A-test.in";
	const char OUTPUT_FILENAME[32]	= "A-result.txt";
#else
#	if 0
	const char INPUT_FILENAME[32]	= "A-small-attempt0.in";
	const char OUTPUT_FILENAME[32]	= "A-small_result.txt";
#	else
	const char INPUT_FILENAME[32]	= "A-large.in";
	const char OUTPUT_FILENAME[32]	= "A-large_result.txt";
#	endif
#endif
	
	//------------------------------
	// split
	void split( vector<string>& list, string& str, const string& delim )
	{
		int cutAt;
		while( (cutAt = str.find_first_of(delim)) != str.npos )
		{
			if(cutAt > 0)
			{
				list.push_back(str.substr(0, cutAt));
			}
			str = str.substr(cutAt + 1);
		}
		if(str.length() > 0)
		{
			list.push_back(str);
		}
	}

	//------------------------------
	struct SInput
	{
		int a;
		vector<int> n;
	};
}	// anonymous namespace


class CWork
{
public:	
	//------------------------------
	void exec()
	{
		m_testNum = 0;
		load();
		ofstream stream( OUTPUT_FILENAME );
		for( int i=0; i<m_testNum; ++i )
		{
#if defined(TEST)
			execImpl(i, cout);
#else
			execImpl(i, stream);
#endif
		}
	}
	
private:
	//------------------------------
	void load()
	{
		ifstream s( INPUT_FILENAME );
		string str;
		getline( s, str );
		sscanf_s( str.c_str(), "%d", &m_testNum );

		for( int loop=0; loop<m_testNum; ++loop )
		{
			getline( s, str );
			SInput input;
			int N;
			sscanf_s( str.c_str(), "%d %d", &input.a, &N );
			getline( s, str );
			vector<string> ls;
			split( ls, str, " ");
			for( int i=0; i<N; ++i ) {
				input.n.push_back( atoi(ls[i].c_str()) );
			}
			sort( input.n.begin(), input.n.end() );
			m_input.push_back( input );
		}
	}

	void func( int a, int is, int ie, int count )
	{
		if ( count >= m_result ) {
			return;
		}

		// ãzé˚Ç≈Ç´ÇÈÇ∆Ç±ÇÎÇ‹Ç≈ãzé˚
		while(1) {
			if ( is > ie ) {
				break;
			}
			if ( a > m_i.n[is] ) {
				a += m_i.n[is];
				is++;
			}
			else {
				break;
			}
		}
		if( is > ie ) {
			if ( m_result > count ) {
				m_result = count;
			}
			return;
		}

		// í«â¡
		if( a > 1 ) {
			func( a+(a-1), is, ie, count+1 );
		}
		// çÌèú
		func( a, is, ie-1, count+1 );
	}

	//------------------------------
	void execImpl(int index, ostream& stream)
	{
		const SInput& input = m_input[index];
		m_i = input;
		m_result = INT_MAX;
		func( input.a, 0, input.n.size()-1, 0 );
		stream << "Case #" << (index+1) << ": ";
		stream << m_result;
		stream << endl;
	}

	//------------------------------
	int m_testNum;
	int m_result;
	vector<SInput> m_input;
	SInput m_i;
};

int main(int argc, char *argv[])
{
	clock_t start,end;
	start = clock();

	CWork work;
	work.exec();
	
	end = clock();
	printf( "time=%fsec\n", (double)(end-start)/CLOCKS_PER_SEC);
	getchar();
}
