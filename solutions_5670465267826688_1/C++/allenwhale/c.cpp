#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;
#define E 4
#define I 1
#define J 2
#define K 3
map<pair<int,int> ,int>_mp;
struct _num{
	int n;
	_num(int _n=E){
		n=_n;
	}
	_num operator * (const _num &N){
		_num ret;
		ret.n=_mp[make_pair(abs(this->n),abs(N.n))];
		int s=(this->n*N.n)>0?1:-1;
		ret.n*=s;
		return ret;
	}
	_num pow(const long long int &N){
		if(N==0)return _num();
		else if(N==1)return *this;
		else{
			_num ret=this->pow(N/2);
			if(N&1){
				return ret*ret*(*this);
			}else{
				return ret*ret;
			}
		}
	}
};
void init(){
	_mp[make_pair(E,E)]=(E);
	_mp[make_pair(E,I)]=(I);
	_mp[make_pair(E,J)]=(J);
	_mp[make_pair(E,K)]=(K);
	_mp[make_pair(I,E)]=(I);
	_mp[make_pair(I,I)]=(-E);
	_mp[make_pair(I,J)]=(K);
	_mp[make_pair(I,K)]=(-J);
	_mp[make_pair(J,E)]=(J);
	_mp[make_pair(J,I)]=(-K);
	_mp[make_pair(J,J)]=(-E);
	_mp[make_pair(J,K)]=(I);
	_mp[make_pair(K,E)]=(K);
	_mp[make_pair(K,I)]=(J);
	_mp[make_pair(K,J)]=(-I);
	_mp[make_pair(K,K)]=(-E);
}
char in[10010];
int main(){
	int T;
	scanf("%d",&T);
	init();
	for(int t=1;t<=T;t++){
		long long L,X;
		scanf("%lld %lld",&L,&X);
		scanf("%s",in);
		_num ret;
		for(int i=0;i<L;i++){
			if(in[i]=='i'){
				ret=ret*_num(I);
			}else if(in[i]=='j'){
				ret=ret*_num(J);
			}else if(in[i]=='k'){
				ret=ret*_num(K);
			}
		}
		ret=ret.pow(X);
		printf("Case #%d: ",t);
		if(ret.n!=-E){
			puts("NO");
		}else{
			int a,b;
			_num aa,bb;
			for(a=0;a<L*4;a++){
				_num nn;
				if(in[a%L]=='i'){
					nn=_num(I);
				}else if(in[a%L]=='j'){
					nn=_num(J);
				}else if(in[a%L]=='k'){
					nn=_num(K);
				}
				aa=aa*nn;
				if(aa.n==I){
					break;
				}
			}
			for(b=4*L-1;b>=0;b--){
				_num nn;
				if(in[b%L]=='i'){
					nn=_num(I);
				}else if(in[b%L]=='j'){
					nn=_num(J);
				}else if(in[b%L]=='k'){
					nn=_num(K);
				}
				bb=nn*bb;
				if(bb.n==K){
					break;
				}
			}
			if(aa.n!=I||bb.n!=K){
				puts("NO");
			}else if((long long)a+1+4ll*L-(long long)b>L*X){
				puts("NO");
			}else{
				puts("YES");
			}
		}

	}
	return 0;
}
