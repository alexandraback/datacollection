#include<bits/stdc++.h>
using namespace std;
#define FZ(i,n) for(int i=0;i<(n);i++)
#define FB(i,n) for(int i=(n)-1;i>=0;i--)
#define FV(i,st,ed) for(int i=(st);i<(ed);i++)
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()

#define RI(x) scanf("%d",&(x))
#define RII(x,y) scanf("%d %d",&(x),&(y))
#define RS(x) scanf("%s",x)
#define RI64(x) scanf("%I64d",&(x))
#define RII64(x,y) scanf("%I64d%I64d",&(x),&(y))

#define FIR first
#define SEC second
#define pritnf printf
#define N 100514
typedef long long int lnt;
typedef double dou;
typedef pair<int,int> P;

char s[N];
void sol(int uuu){
    RS(s);
    int l=0;
    for(;s[l];l++);
    l = unique(s,s+l)-s;
    printf("Case #%d: ",uuu);
    if(s[0]=='+'){
        //l==1 => 0 l/2*2
        //l==2 => 2
        //l==3 => 2
        //l==4 =>
        printf("%d\n",l/2*2);
    }else{
        //l==1 => 1 , (l-1)/2*2+1
        //l==2 => 1,  
        //l==3 => 3
        printf("%d\n",(l-1)/2*2+1);
    }
}
int main(){
	freopen("B-large.in","r",stdin);
	freopen("BLout.txt","w",stdout);
	int t;
	if(RI(t)!=EOF){
		for(int ti=1;ti<=t;ti++)sol(ti);
	}
	return 0;
}

