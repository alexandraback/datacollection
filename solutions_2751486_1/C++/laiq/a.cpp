#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstdlib>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <ctime>
#include <cstring>
#define FOR(x,y,z) for(int (x)=(y);(x)<(z);(x)++)
#define FORQ(x,y,z) for(int (x)=(y);(x)<=(z);(x)++)
#define FORD(x,y,z) for(int (x)=(y);(x)>(z);(x)--)
#define FORDQ(x,y,z) for(int (x)=(y);(x)>=(z);(x)--)
#define REP(x,z) for(int (x)=1;(x)<=(z);(x)++)
#define UNIQUE(x) sort(ALL((x))); (x).resize(unique(ALL((x)))-(x).begin());
#define PB push_back
#define MP make_pair
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define PII pair<int,int>
#define PACKS(Z,IdzieSobieBladWielbladMaWrotkiNaKopytachJESTNIENORMALNY) int Z;scanf("%d",&Z);FORQ(IdzieSobieBladWielbladMaWrotkiNaKoptyachJESTNIENORMALNY,1,Z)
using namespace std;
char in[1000100];
int n;
long long val[1000100];
long long hax[1000100];
bool isCons(char x){
	return ((x!='a')&&(x!='e')&&(x!='i')&&(x!='o')&&(x!='u'));
}
int main(){
	int Z;
	scanf("%d",&Z);
	FORQ(test,1,Z){
		scanf("%s%d",in,&n);
		int len = strlen(in);
		FOR(i,0,len)val[i]=hax[i]=0;
		int cosecu=0;
		FOR(i,0,len){
			if(isCons(in[i]))
				cosecu++;
			else cosecu=0;
			if(cosecu>=n)
				hax[i]=1;
		}
		long long out=val[0];
		int bro=0;
		FOR(i,0,len){
			if(hax[i]==1){
				val[i]=i+1-n+1;
				out+=val[i];
				bro=i;
				break;
			}	
		}
		FOR(i,bro+1,len){
			val[i]=val[i-1];
			if(hax[i])
				val[i]+=i+1-n+1-val[i-1];
			out+=val[i];
			//printf("%lld %d\n",val[i],i+1-n+1);
		}
		printf("Case #%d: %lld\n",test,out);
	}
	return 0;
}

