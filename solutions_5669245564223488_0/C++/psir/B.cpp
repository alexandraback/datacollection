#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <cstdlib>
#include <string>
#include <sstream>
#include <gmpxx.h>

using namespace std;

#define VS vector<string>
#define VI vector<int>
#define VVI vector< VI >
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORC(it,kont) for(__typeof((kont).begin()) it = (kont).begin(); it!=(kont).end(); ++it)
#define MOD 1000000007

char buff[20000];

VS a;
VI cnt;
vector<char> in;
vector<char> out;
long long fact[110];
long long pow2[110];

int main()
    {
    fact[0] = 1;
    pow2[0] = 1;
    FOR(i,1,110)
	{
	fact[i] = (fact[i-1]*i)%MOD;
	pow2[i] = (pow2[i-1]*2)%MOD;
	}

    int T;
    gets(buff);
    sscanf(buff,"%d",&T);

    FOR( t, 0, T )
        {
	VI lpf(26,0);
	VI lp(26,0);
	VI ch(26,0);
	int N;
	cin >> N;
	a.resize(N);
	FOR(i,0,N) cin >> a[i];
        long long sol = 0;     

	bool ok = 1;

	int edge[26][26]={0};

	FOR(i,0,N)
		FOR(j,0,a[i].size())
			ch[a[i][j]-'a'] ++;
	int brch = 0;
	FOR(j,0,26) brch += (ch[j] > 0 );

	FOR(i,0,N) 
		{
		int L = a[i].size();
		FOR(j,1,L-1)
			if(a[i][j]!=a[i][0] && a[i][j]!=a[i][L-1] )
				lpf[a[i][j]-'a'] = 1;
		bool dodao = 0;
		FOR(j,0,L-1)
			if(a[i][j]!=a[i][j+1])
				{
				++edge[a[i][j]-'a'][a[i][j+1]-'a'];
				dodao = 1;
				}
		if ( dodao == 0 )
			lp[a[i][0]-'a']++;
		}
	int cntedge = 0;	

	FOR(i,0,26)
		{
		int tmpsum = 0;
		FOR(j,0,26) tmpsum += edge[i][j];
		if( tmpsum > 1 ) ok = 0;
		int tmpsum2 = 0;
		FOR(j,0,26) tmpsum2 += edge[j][i];
		if( tmpsum2 > 1 ) ok = 0;

		cntedge += tmpsum;
		}		

	FOR(i,0,26) if( lpf[i] == 1 && lp[i] > 0 ) ok = 0;
	sol=1;
	FOR(i,0,26) {
		sol = (sol * fact[lp[i]])%MOD;
		//cout << sol << endl;
		}
	//cout << brch << " " << cntedge << endl;
	//cout << brch << endl;
	//cout << cntedge << endl;
	//FOR(i,0,26) cout << lp[i] << " ";
	//cout << endl;
	if( cntedge >= brch ) ok = 0;
 	sol = (sol*fact[brch - cntedge] ) %MOD;
	if( ok )
        	printf("Case #%d: %lld\n",t+1,sol);
	else 
		printf("Case #%d: 0\n",t+1);
        }
    return 0;
    }
