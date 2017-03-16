#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<cstring>
using namespace std;

#define FOR(I,A,B) for (int I=int(A);I<int(B);++I)
#define MEM(A,B) memset(A,B,sizeof(A));
#define CPY(A,B) memcpy(A,B,sizeof(B));
typedef __int64 LL;
const char a[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i',
                    'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 
                    'f', 'm', 'a', 'q'};
int ca, t;
int c[26];
string str;
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("A.out", "w", stdout);
    for (cin >> ca, getline(cin, str); ca; --ca) {
	    getline(cin, str);
		FOR(i, 0, str.size())
		   if ('a' <= str[i] && str[i] <= 'z') str[i] = a[str[i] - 'a'];
		cout << "Case #" << ++t << ": " << str << endl;
	}
}
