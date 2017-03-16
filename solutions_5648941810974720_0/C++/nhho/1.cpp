#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#include <deque>
#include <cstring>
#include <functional>
#include <climits>
#include <list>
#include <ctime>
#include <complex>

#define F1(x,y,z) for(int x=y;x<z;x++)
#define F2(x,y,z) for(int x=y;x<=z;x++)
#define F3(x,y,z) for(int x=y;x>z;x--)
#define F4(x,y,z) for(int x=y;x>=z;x--)
#define pb push_back
#define LL long long
#define co complex<double>

#define MAX 100005
#define AMAX 1500
#define MOD 1000000007

#define f(c,d) ((1<<(c))*(d))

using namespace std;

int t,n,cnt[26],y[10];
char x[2005];

int main(){
	scanf("%d",&t);
	F2(a,1,t){
		n=0;
		F1(b,0,26)cnt[a]=0;
		F1(b,0,10)y[a]=0;
		scanf("%s",x);
		while(x[n]){
			cnt[x[n]-'A']++;
			x[n++]=0;
		}
		y[0]=cnt['Z'-'A'];
		cnt['Z'-'A']-=y[0];
		cnt['E'-'A']-=y[0];
		cnt['R'-'A']-=y[0];
		cnt['O'-'A']-=y[0];
		y[2]=cnt['W'-'A'];
		cnt['T'-'A']-=y[2];
		cnt['W'-'A']-=y[2];
		cnt['O'-'A']-=y[2];
		y[4]=cnt['U'-'A'];
		cnt['F'-'A']-=y[4];
		cnt['O'-'A']-=y[4];
		cnt['U'-'A']-=y[4];
		cnt['R'-'A']-=y[4];
		y[6]=cnt['X'-'A'];
		cnt['S'-'A']-=y[6];
		cnt['I'-'A']-=y[6];
		cnt['X'-'A']-=y[6];
		y[8]=cnt['G'-'A'];
		cnt['E'-'A']-=y[8];
		cnt['I'-'A']-=y[8];
		cnt['G'-'A']-=y[8];
		cnt['H'-'A']-=y[8];
		cnt['T'-'A']-=y[8];
		y[1]=cnt['O'-'A'];
		cnt['O'-'A']-=y[1];
		cnt['N'-'A']-=y[1];
		cnt['E'-'A']-=y[1];
		y[3]=cnt['H'-'A'];
		cnt['T'-'A']-=y[3];
		cnt['H'-'A']-=y[3];
		cnt['R'-'A']-=y[3];
		cnt['E'-'A']-=y[3];
		cnt['E'-'A']-=y[3];
		y[5]=cnt['F'-'A'];
		cnt['F'-'A']-=y[5];
		cnt['I'-'A']-=y[5];
		cnt['V'-'A']-=y[5];
		cnt['E'-'A']-=y[5];
		y[7]=cnt['S'-'A'];
		cnt['S'-'A']-=y[7];
		cnt['E'-'A']-=y[7];
		cnt['V'-'A']-=y[7];
		cnt['E'-'A']-=y[7];
		cnt['N'-'A']-=y[7];
		y[9]=cnt['E'-'A'];
		cnt['N'-'A']-=y[9];
		cnt['I'-'A']-=y[9];
		cnt['N'-'A']-=y[9];
		cnt['E'-'A']-=y[9];
		F1(b,0,26)if(cnt[b])assert(cnt[b]);
		printf("Case #%d: ",a);
		F1(b,0,10)F1(c,0,y[b])printf("%d",b);
		printf("\n");
	}
	//system("pause");
	return 0;
}
