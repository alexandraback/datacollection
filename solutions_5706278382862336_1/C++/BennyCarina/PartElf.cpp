#include<iostream>
#include<math.h>
#include<vector>
#include<set>
#include<algorithm>
#include<string>
using namespace std;

#define d_pi 57.2957795
#define LL long long

template<class T> inline void ReMin(T &a,T b){if(b<a) a=b;}
template<class T> inline void ReMax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}


long long getfac(long long a,long long b){
        if(a==0 || b==0)return a+b;
		a=(a>0?a:-a);
		b=(b>0?b:-b);
	long long big=a>b?a:b,small=a+b-big,tmp;
	while(small!=0){
		big=big%small;
		tmp=big;
		big=small;
		small=tmp;
	}
	return big;
}

int main(){
	freopen("in.in","r",stdin);
	freopen("out.txt","w",stdout);
	int T_case;
	LL P,Q;
	char r;
	cin>>T_case;
	for(int i_case=1;i_case<=T_case;i_case++){
		printf("Case #%d: ",i_case);
		cin>>P>>r>>Q;
		LL fac=getfac(P,Q);
		P/=fac;
		Q/=fac;
		LL tmp=Q;
		int a=0;
		while(tmp>0){
			if(tmp&1)a++;
			tmp>>=1;
		}
		if(a!=1){
			cout<<"impossible"<<endl;
		}
		else {
			tmp=1;
			while(2*tmp<=Q && tmp<=P){
				tmp*=2;
			}
			tmp/=2;
			Q/=tmp;
			a=0;
			while(Q>0){
				a++;
				Q>>=1;
			}
			cout<<a-1<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}