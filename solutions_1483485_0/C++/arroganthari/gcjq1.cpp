#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<deque>
#include<vector>
#include<cctype>
#include<iomanip>
#include<cmath>
#include<fstream>

# define F(i, n) 	for( int i = 0; i < (n); i++)
# define Fi(i, m, n) 	for( int i = (m); i < (n); i++)
# define Fr(i, n) 	for( int i = (n); i > 0; i-- )
# define Fri(i, m, n)	for( int i = (m); i > n; i-- )
# define P 		printf
# define Pd(x) 		printf("%d" , x )
# define PN 		printf("\n")
# define S 		scanf
# define Sd(x) 		scanf("%d",&x)
# define PB 		push_back
# define SZ(x) 		((int)((x).size()))
# define VI		vector<int>
# define SI		set<int>

typedef long long ll;

ll mod = (ll)1000000007;

using namespace std;


int main()
{
	char revr[] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
	int test;
	ifstream in("in.txt");
	ofstream out("out.txt");
	
	in >> test;
	Fi(i,1,test+1)
	{
		string s;
		do{
		getline(in, s);
		}while(s[0] != ' ' && (s[0] < 'a' || s[0] > 'z'));
		string s1 = "";
		int ssize = SZ(s);
		F(j,ssize)
		{
			if( s[j] == ' ')
			s1 += s[j];
			else
			s1 += revr[s[j]-'a'];
		}
		out << "Case #" << i << ": " << s1 << endl;
	}
	in.close();
	out.close();
	return 0;
}
