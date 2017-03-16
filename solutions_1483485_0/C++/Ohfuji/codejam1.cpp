#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>
#include <string.h>

using namespace std;

string translate(string g)
{
	char schar[] = "abcdefghijklmnopqrstuvwxyz";
	char gchar[] = "ynficwlbkuomxsevzpdrjgthaq";
	string s;
	for ( int i = 0; i < g.size(); i++ ) {
		char *p = strchr( gchar, g[i]);
		if ( p ) {
			s.push_back( schar[p-gchar]);
		} else {
			s.push_back(g[i]);
		}
	}
	return s;
}

int main(int argc, char* argv[])
{
	char	buf[512];
	int	casenum;

	fgets(buf, sizeof(buf)-1,stdin);
	sscanf( buf, "%d", &casenum);
	string g;
	for ( int i = 1; i <= casenum; i++ ) {
		fgets(buf, sizeof(buf)-1,stdin);
		g = buf;
		cout << "Case #" << i << ": " << translate(g);
	}

	return 0;
}

