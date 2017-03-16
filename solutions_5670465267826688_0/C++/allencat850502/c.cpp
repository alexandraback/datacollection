#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;
#define E 4
#define I 1
#define J 2
#define K 3
map<pair<int,int> ,int>mp;
struct num{
	int n;
	int sign;
	num(int _n=E,int _s=1){
		n=_n;
		sign=_s;
	}
	num operator * (const num &N){
		num res;
		res.n=mp[make_pair(abs(this->n),abs(N.n))];
		int s=(this->n*N.n)>0?1:-1;
		res.n*=s;
		return res;
	}
	num pow(const long long int &N){
		if(N==0)return num();
		else if(N==1)return *this;
		else{
			num res=this->pow(N/2);
			if(N&1){
				return res*res*(*this);
			}else{
				return res*res;
			}
		}
	}
};
void init(){
	mp[make_pair(E,E)]=(E);
	mp[make_pair(E,I)]=(I);
	mp[make_pair(E,J)]=(J);
	mp[make_pair(E,K)]=(K);
	mp[make_pair(I,E)]=(I);
	mp[make_pair(I,I)]=(-E);
	mp[make_pair(I,J)]=(K);
	mp[make_pair(I,K)]=(-J);
	mp[make_pair(J,E)]=(J);
	mp[make_pair(J,I)]=(-K);
	mp[make_pair(J,J)]=(-E);
	mp[make_pair(J,K)]=(I);
	mp[make_pair(K,E)]=(K);
	mp[make_pair(K,I)]=(J);
	mp[make_pair(K,J)]=(-I);
	mp[make_pair(K,K)]=(-E);
}
char in[10010];
int main(){
	init();
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		long long L,X;
		scanf("%lld %lld",&L,&X);
		scanf("%s",in);
		num res;
		for(int i=0;i<L;i++){
			if(in[i]=='i'){
				res=res*num(I);
			}else if(in[i]=='j'){
				res=res*num(J);
			}else if(in[i]=='k'){
				res=res*num(K);
			}
		}
		res=res.pow(X);
		printf("Case #%d: ",t);
		if(res.n!=-E){
			puts("NO");
		}else{
			int a,b;
			num aa,bb;
			for(a=0;a<L*4;a++){
				num now;
				if(in[a%L]=='i'){
					now=num(I);
				}else if(in[a%L]=='j'){
					now=num(J);
				}else if(in[a%L]=='k'){
					now=num(K);
				}
				aa=aa*now;
				if(aa.n==I){
					break;
				}
			}
			for(b=4*L-1;b>=0;b--){
				num now;
				if(in[b%L]=='i'){
					now=num(I);
				}else if(in[b%L]=='j'){
					now=num(J);
				}else if(in[b%L]=='k'){
					now=num(K);
				}
				bb=now*bb;
				if(bb.n==K){
					break;
				}
			}
			if(aa.n!=I||bb.n!=K){
				puts("NO");
			}else if((long long)a+1+4ll*(long long)L-(long long)b>(long long)L*(long long)X){
				puts("NO");
			}else{
				puts("YES");
			}
		}

	}
	return 0;
}
