#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <climits>
#include <stdio.h>
#include <strstream>
using namespace std;

typedef long long LL;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<int> > vii;
typedef vector<vector<string> > vss;
typedef pair<int, int> pii;
#define x first
#define y second
#define INF 0x7fffffff
//#define INFLL 0x7fffffffffffffff
#define INFLL LLONG_MAX
#define SIZE(v) int((v).size())
#define ALL(v) (v).begin(), (v).end()
#define FOR(i,x) for(int i=0;i<x;i++)
#define FORic(i,y,x) for(int i=y;i<=x;i++)
#define FORdc(i,y,x) for(int i=y;i>=x;i--)
#define FILL(a,v) memset(a, v, sizeof(a))
#define PI 3.14159265358979323846

int main()
{
	char buf[256];
	int n;
	gets(buf);
	string sb = buf;
	istrstream istr(sb.data());
	istr >> n;
	FOR(i,n){
		gets(buf);
		int j = 0;
		while(buf[j] != '\0'){
			if(buf[j] >= 'a' && buf[j] <= 'z'){
				//buf[j] -= 'a';
				//buf[j] += 24;
				//buf[j] %= 26;
				//buf[j] += 'a';
				switch(buf[j]){
				case 'a':
					buf[j] = 'y';
					break;
				case 'b':
					buf[j] = 'h';
					break;
				case 'c':
					buf[j] = 'e';
					break;
				case 'd':
					buf[j] = 's';
					break;
				case 'e':
					buf[j] = 'o';
					break;
				case 'f':
					buf[j] = 'c';
					break;
				case 'g':
					buf[j] = 'v';
					break;
				case 'h':
					buf[j] = 'x';
					break;
				case 'i':
					buf[j] = 'd';
					break;
				case 'j':
					buf[j] = 'u';
					break;
				case 'k':
					buf[j] = 'i';
					break;
				case 'l':
					buf[j] = 'g';
					break;
				case 'm':
					buf[j] = 'l';
					break;
				case 'n':
					buf[j] = 'b';
					break;
				case 'o':
					buf[j] = 'k';
					break;
				case 'p':
					buf[j] = 'r';
					break;
				case 'q':
					buf[j] = 'z';
					break;
				case 'r':
					buf[j] = 't';
					break;
				case 's':
					buf[j] = 'n';
					break;
				case 't':
					buf[j] = 'w';
					break;
				case 'u':
					buf[j] = 'j';
					break;
				case 'v':
					buf[j] = 'p';
					break;
				case 'w':
					buf[j] = 'f';
					break;
				case 'x':
					buf[j] = 'm';
					break;
				case 'y':
					buf[j] = 'a';
					break;
				case 'z':
					buf[j] = 'q';
					break;
				}
			}
			j++;
		}
		printf("Case #%d: %s\n", i+1, buf);
	}
}
