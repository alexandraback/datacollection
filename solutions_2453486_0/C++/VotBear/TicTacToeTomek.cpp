#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cfloat>
#include<bitset>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#define Joshua using
#define ganteng namespace
#define sekali std
Joshua ganteng sekali;

typedef long long			ll;
typedef long double                     ld;
typedef pair<int,int>	  	        pi;
typedef pair<ll,ll>			pl;
typedef pair<double,double>	        pd;
typedef vector<int>			vi;
typedef vector<ll>			vl;
typedef vector<pi>			vii;
typedef vector<pl>			vll;
typedef vector<pd>			vdd;
typedef priority_queue<int>	        pq;

#define fi first
#define se second
#define pq priority_queue
#define SORT(a) sort(a.begin(),a.end())
#define DEBUG(a) printf("DEBUG %s\n",#a)
#define VALUE(a) printf("value of %s is %d\n",#a,a)
#define VALUELL(a) printf("value of %s is %lld\n",#a,a)
#define FORU(a,b,c) for(int a=b;a<c;++a)
#define FORD(a,b,c) for(int a=b-1;a>=c;--a)
#define MP(a,b) make_pair(a,b)
#define bikin_popcorn __builtin_popcount
#define iswhite(a) (a==' '||a=='\n')
#define pb push_back
#define db pop_back
#define PI 3.14159265
#define INF 100000000
#define MOD 1000
#define EPS 1E-9
#define MXN 1000
//#define getchar getchar_unlocked

template <class T> inline void getint(T &num)
{
	bool neg=0;
	num=0;
	char c;
	while ((c=getchar()) && (!isdigit(c) && c!='-'));
	if (c=='-'){
		neg=1;
		c=getchar();
	}
	do num=num*10+c-'0';
	while ((c=getchar()) && isdigit(c));
	num*=(neg)?-1:1;
}

int check(char a,char b,char c,char d){
	int last=-1; bool same=true;
	char tmp[6]={a,b,c,d};
	//puts(tmp);
	FORU(i,0,4){ 
		if (tmp[i]=='.') {same=false; break;}
		else if (tmp[i]=='T') continue;
		else if (tmp[i]=='O') {
			if (last==-1||last==0) {last=0; continue;}
			else {same=false; break;}	
		} else if (tmp[i]=='X'){
			if (last==-1||last==1) {last=1; continue;}
			else {same=false; break;}	
		} 
	}
//	printf("%d",last);
	if (same) return last; else return -1;
}

int n;
char inp[6][6];
int main(){
    scanf("%d\n",&n);
    FORU(i,0,n){
		FORU(j,0,4) scanf("%s",&inp[j]);
		//FORU(j,0,4) puts(inp[j]);	
		bool complet=true, xwin=false, owin=false;
		int ret;
		FORU(j,0,4) FORU(k,0,4) if (inp[j][k]=='.') complet=false;	
		FORU(j,0,4){
			ret=check(inp[j][0],inp[j][1],inp[j][2],inp[j][3]);
			if (ret==0) owin=true; else if (ret==1) xwin=true;
			ret=check(inp[0][j],inp[1][j],inp[2][j],inp[3][j]);
			if (ret==0) owin=true; else if (ret==1) xwin=true;
		}
		ret=check(inp[0][0],inp[1][1],inp[2][2],inp[3][3]);
		if (ret==0) owin=true; else if (ret==1) xwin=true;
		ret=check(inp[0][3],inp[1][2],inp[2][1],inp[3][0]);
		if (ret==0) owin=true; else if (ret==1) xwin=true;
		printf("Case #%d: ",i+1);
		if (owin) printf("O won\n");
		else if (xwin) printf("X won\n");
		else if (complet) printf("Draw\n");
		else printf("Game has not completed\n");
	}
    return(0);
}
