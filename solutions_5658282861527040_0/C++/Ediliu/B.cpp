#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<bitset>
#include<map>
#include<utility>
#include<ctime>
#include<cmath>
//TEMPLATE V1
#define nl printf("\n")
#define sp printf(" ")
#define i_ scanf
#define o_ printf
#define ini(x) scanf("%d",&x)
#define outi(x) printf("%d",x)
#define inf(x) scanf("%f",&x)
#define outf(x) printf("%f",x)
#define ind(x) scanf("%lf",&x)
#define outd(x) printf("%lf",x)
#define inll(x) scanf("%I64d",&x)
#define outll(x) printf("%I64d",x)
#define inc(x) scanf("%c",&x)
#define outc(x) printf("%c",x)
#define ins(x) scanf("%s",&x)
#define outs(x) printf("%s",x)

#define loop(var,x,y) for(int var=x;var<y;var++)
#define loopn(var,x,y) for(int var=x;var<=y;var++)
#define rloop(var,x,y) for(int var=x-1;var>=y;var--)
#define rloopn(var,x,y) for(int var=x;var>=y;var--)
#define reset(x,y) memset(x,y,sizeof(x));
#define stop fflush(stdin);getchar()
#define PB push_back
#define MP make_pair
#define st first
#define nd second
#define ALL(x) x.begin(),x.end()
#define ALLR(x) x.rbegin(),x.rend()
using namespace std;

typedef long long Int;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

//I/O
   inline void cins(string &x){
   	char temp[1000000];
   	scanf("%s",&temp);
	x=temp;
   }
   inline void couts(string x){
   	printf("%s",x.c_str());
   }
//I/O

//CONVERT
   inline string ITOS(int x){
   	char temp[1000000];
   	sprintf(temp,"%d",x);
   	return temp;
   }
   inline string ITOLL(Int x){
   	char temp[1000000];
   	sprintf(temp,"%I64d",x);
   	return temp;
   }
   inline int STOI(string x){
	char temp[1000000];
	strcpy(temp,x.c_str());
	int ret;sscanf(temp,"%d",&ret);
	return ret;
   }
   inline Int STOLL(string x){
    char temp[1000000];
	strcpy(temp,x.c_str());
	Int ret;sscanf(temp,"%I64d",&ret);
	return ret;
   }
//CONVERT

//FILE
inline void OPEN(const string &s) {
freopen((s + ".in").c_str(), "r", stdin);
freopen((s + ".out").c_str(), "w", stdout);
}
//FILE
int px[]={-1,0,1,0,-1,-1,1,1};
int py[]={0,1,0,-1,-1,1,1,-1};

int main(){
	OPEN("B");
	int T;ini(T);
	int kasus=1;
	while(T--){
		Int sum=0;
		int A,B,K;
		ini(A);ini(B);ini(K);
		for(int i=A-1;i>=0;i--){
			for(int j=B-1;j>=0;j--){
				if((i&j)<K)sum++;
			}
		}
		printf("Case #%d: %lld\n",kasus++,sum);
	}
	
}
