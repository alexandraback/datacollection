/*template by : Dewangga Winardi*/
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX(a,b) a=max(a,b)
#define MIN(a,b) a=min(a,b)	
#define mp make_pair
#define fi first
#define sc second
#define ll long long
#define pb push_back
#define RESET(v,a) memset(v,a,sizeof(v))	
#define pause system("pause")
#define INF 1000000000
#define INFL 1000000000LL
#define debug_time1 time_start(&asd);
#define debug_time2 print_time(asd);

using namespace std;

void time_start(clock_t *asd) {
	*asd=clock();
} 

void print_time(clock_t asd) {
	asd=clock()-asd;
	printf("waktu=%.fmilisecond\n", (float)asd/CLOCKS_PER_SEC*1000);
}

inline string GetString()
{
	char S[1000005];
	scanf("%s",S);
	string ret=S;
	return ret;
}

template<typename t>
t getnum()
{
 t res=0;
 char c;
 int sign=1;
 while(1){
	c=getchar_unlocked();
	if(c==' '||c=='\n')continue;
	else break;}
 if(c=='+'){}
 else if(c=='-')sign=-1;
 else res=c-'0';
 while(1){
	c=getchar_unlocked();
	if(c>='0'&&c<='9')res=res*10+c-'0';
	else break;}
return res*sign;
}

/*end of template*/

int main(int argc , char** argv)
{		
	clock_t asd;
	//freopen("input.txt","r",stdin);
	freopen("b_small.out","w",stdout);
	int t=getnum<int>();
	for (int tc=1; tc<=t; tc++) {
		int ans=0;
		int a=getnum<int>(),b=getnum<int>(),c=getnum<int>();		
		for (int i=0; i<a; i++) {
			for (int j=0; j<b; j++) {				
				if ((i & j) < c) ans++;				
			}						
		}
		printf("Case #%d: %d\n",tc,ans);
	}
	return 0;
}