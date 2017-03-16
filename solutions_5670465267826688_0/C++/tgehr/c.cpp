#include <iostream>
#include <string>
using namespace std;

enum E{o,i,j,k};
E t1[4][4]={{o,i,j,k},{i,o,k,j},{j,k,o,i},{k,j,i,o}};
bool t2[4][4]={{0,0,0,0},{0,1,0,1},{0,1,1,0},{0,0,1,1}};

struct Q{
	E x;
	bool sign=false;
	Q(char c){
		switch(c){
		case '1': x=o; break;
		case 'i': x=i; break;
		case 'j': x=j; break;
		case 'k': x=k; break;
		}
	}
	Q(E x,bool sign):x(x),sign(sign){}
	Q operator*(const Q& r)const{
		return {t1[x][r.x],t2[x][r.x]^sign^r.sign};
	}
};
using LL=long long;
Q pow(Q q,LL x){
	Q r('1');
	Q y=q;
	for(LL k=x;k;k>>=1,y=y*y)
		if(k&1) r=r*y;
	return r;
}
int main(){
	int T;
	cin>>T;
	for(int t=1;t<=T;t++){
		LL l,x;
		string u,s="";
		cin>>l>>x;
		cin>>u;
		Q p='1';
		for(int a=0;a<l;a++)
			p=p*Q(u[a]);
		bool ok=true;
		p=pow(p,x);
		if(p.x!=o||!p.sign) ok=false;
		s=(u+u)+(u+u);
		int a=0,b=s.size()-1;
		Q q='1';
		for(;a<(int)s.size();a++){
			q=q*Q(s[a]);
			if(q.x==i) break;
		}
		if(a==(int)s.size()) ok=false;
		q='1';
		for(;b>=0;b--){
			q=Q(s[b])*q;
			if(q.x==k) break;
		}
		if(b<0) ok=false;
		if((a+1)+((int)s.size()-b)>=(LL)x*l) ok=false;
		cout<<"Case #"<<t<<": "<<(ok?"YES":"NO")<<'\n';
	}
}
