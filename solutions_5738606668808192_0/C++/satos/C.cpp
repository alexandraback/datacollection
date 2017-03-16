#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<((int)(n));i++)
#define reg(i,a,b) for(int i=((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i=((int)(n))-1;i>=0;i--)
#define ireg(i,a,b) for(int i=((int)(b));i>=((int)(a));i--)
typedef long long int lli;
typedef pair<int,int> mp;
#define fir first
#define sec second
#define IINF INT_MAX
#define LINF LLONG_MAX
#define eprintf(...) fprintf(stderr,__VA_ARGS__)


vector<int> prs;
const int har = (1<<17);
int bs[har]={};

void init(){
	reg(i,2,har){
		if(bs[i])continue;
		prs.push_back(i);
		for(int j=i;j<har;j+=i)bs[j]=i;
	}
	fprintf(stderr,"inited prim %d\n",prs.size());
}

void maked(int n,int d){
	/*
	char fn[20];
	sprintf(fn,"dat-%d-%d.txt",n,d);
	freopen(fn, "w", stdout);*/
	int m = n-2;
	printf("Case #1:\n");
	int ansn=0;
	rep(i,1<<m){
		lli c = (1LL<<(n-1)) + i*2 + 1;
		bool ok=false;
		int b2=-1;
		rep(j,prs.size()){
			if(prs[j]>=c)break;
			if(c%prs[j]==0){
				b2 = prs[j]; ok=true; break;
			}
		}
		if(!ok)continue;
		
		lli bn = 0;
		lli b6=0,b8=0;
		{
			lli p = c;
			rep(i,n+1){
				if(p%2){
					bn++;
					b6 += (i%2?6:1);
					b8 += (i%2?2:1);
				}
				p/=2;
			}
		}
		if(bn%6 || b6%7 || b8%3)continue;
		
		string s = "";
		while(c){
			if(c%2)s='1' + s;
			else s='0'+s;
			c/=2;
		}
		printf("%s ",s.c_str());
		
		printf("%d 2 3 2 7 2 3 2 3\n",b2);
		
		ansn++;
		if(ansn>=d)break;
	}
}

int main(void){
	init();
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	maked(b,c);
	//maked(16,50);
	//maked(32,500);
	return 0;
}




