//============================================================================
// Author      : Prateek Agarwal
// Institution : NITJ
//============================================================================

#include <bits/stdc++.h>

#define ll long long

#define TEST int t;scan(t);while(t--)
#define scan(n) scanf("%d",&n)
#define set(x,y) memset(x,y,sizeof(x))
#define loop(i,l,r,x) for (int i=l;i<=r;i+=x)
#define printl(n) printf("%d\n",n)
#define print(n) printf("%d ",n)
#define pb push_back

#define INF 1000000000
#define M 1000000007
#define MAX 500001
#define LIM 10

using namespace std;

char s[5000];
int m[100];
int res[10];

int init(){
	int cs=1;
	TEST{
		set(m,0);
		set(res,0);
		cin>>s;
		int l = strlen(s);
		for (int i=0;i<l;i++) m[s[i]-65]++;

		res[0] = m['Z'-65];
		m['E'-65]-=m['Z'-65];
		m['R'-65]-=m['Z'-65];
		m['O'-65]-=m['Z'-65];
		m['Z'-65] = 0;

		res[8] = m['G'-65];
		m['E'-65]-=m['G'-65];
		m['I'-65]-=m['G'-65];
		m['H'-65]-=m['G'-65];
		m['T'-65]-=m['G'-65];
		m['G'-65] = 0;

		res[2] = m['W'-65];
		m['T'-65]-=m['W'-65];
		m['O'-65]-=m['W'-65];
		m['W'-65] = 0;

		res[3] = m['T'-65];
		m['H'-65]-=m['T'-65];
		m['R'-65]-=m['T'-65];
		m['E'-65]-=m['T'-65];
		m['E'-65]-=m['T'-65];
		m['T'-65] = 0;

		res[4] = m['U'-65];
		m['F'-65]-=m['U'-65];
		m['O'-65]-=m['U'-65];
		m['R'-65]-=m['U'-65];
		m['U'-65] = 0;

		res[1] = m['O'-65];
		m['N'-65]-=m['O'-65];
		m['E'-65]-=m['O'-65];
		m['O'-65] = 0;

		res[5] = m['F'-65];
		m['I'-65]-=m['F'-65];
		m['V'-65]-=m['F'-65];
		m['E'-65]-=m['F'-65];
		m['F'-65] = 0;

		res[6] = m['X'-65];
		m['S'-65]-=m['X'-65];
		m['I'-65]-=m['X'-65];
		m['X'-65] = 0;

		res[7] = m['S'-65];
		m['E'-65]-=m['S'-65];
		m['V'-65]-=m['S'-65];
		m['E'-65]-=m['S'-65];
		m['N'-65]-=m['S'-65];
		m['S'-65] = 0;

		res[9] = m['I'-65];
		m['N'-65]-=m['I'-65];
		m['N'-65]-=m['I'-65];
		m['E'-65]-=m['I'-65];
		m['I'-65] = 0;


		cout << "Case #" << cs++ << ": " ;
		for (int i=0;i<10;i++){
			for (int j=1;j<=res[i];j++) cout << i;
		}
		cout << endl;
	}
	return 0;
}

int main(){
	//clock_t start = clock();
	init();
	//printf("%.6f\n",double(clock()-start)/CLOCKS_PER_SEC);
	return 0;
}

