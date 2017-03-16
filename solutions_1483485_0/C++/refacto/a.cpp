#include <fstream>
#include <vector>
#include <map>
#include <iostream>
#include <iterator>
#include <sstream>
#include <algorithm>
#include <string>
#include <list>
#include <set>
#include <memory>
#include <assert.h>



#ifdef _DEBUG

	inline void assert_false_plus(const std::string & message)
	{message;
 		assert(false);
	}

	inline void assert_false()				{ assert_false_plus(""); }

	#define assert_plus(expr, message)		{ if (!(expr)) assert_false_plus(message); }
	#define assert_(expr)					{ assert_plus(expr, ""); }

#else

	#define assert_false_plus(message)
	#define assert_false()
	#define assert_plus(expr, message)
	#define assert_(expr)

#endif





using namespace std;


ifstream fin("in.txt");
ofstream fout("out.txt");


typedef char gChar;
typedef char eChar;


map<gChar, eChar>	map_g_e;


void initMap(gChar g, eChar e)
{
	assert_((map_g_e[g] == '\0') || (map_g_e[g] == e));
	map_g_e[g] = e;
}


void initMap(string gStr, string eStr)
{
	assert_(gStr.length() == eStr.length());

	for (int i = 0 ; i < (int)gStr.length() ; ++i)
		initMap(gStr[i], eStr[i]);
}


void initMap()
{
	initMap('y', 'a');
	initMap('e', 'o');
	initMap('q', 'z');
	initMap("ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand");
	initMap("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities");
	initMap("de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up");

	assert_(map_g_e.size() == 26 || map_g_e.size() == 27);
	if (map_g_e.size() == 26)
	{
		set<gChar> gCharMissing;
		set<eChar> eCharMissing;
		for (char c = 'a' ; c <= 'z' ; ++c)
		{
			gCharMissing.insert(c);
			eCharMissing.insert(c);
		}

		for (auto iMap = map_g_e.cbegin() ; iMap != map_g_e.cend() ; ++iMap)
		{
			gCharMissing.erase(iMap->first);
			eCharMissing.erase(iMap->second);
		}

		assert_(gCharMissing.size() == 1);
		assert_(eCharMissing.size() == 1);

		map_g_e[*gCharMissing.begin()] = *eCharMissing.begin();
	}
}


string solveTest(int t)
{
	string res;

	string gLine;
	getline(fin, gLine);
	
	for (auto g = gLine.cbegin() ; g != gLine.cend() ; ++g)
		res += map_g_e[*g];

	return res;
}




int main()
{
	initMap();

	assert_plus(fin, "could not open input file");
	assert_plus(fout, "could not create output file");

	string s;
	int T;
	fin >> T;
	getline(fin, s);
	for (int t = 1 ; t <= T ; ++t)
		fout << "Case #" << t << ": " << solveTest(t) << endl;

	return 0;
}

