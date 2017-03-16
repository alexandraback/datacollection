#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>
#include <string>
#include <iostream>

#define fru(j,n) for(int j=0;j<(n);++j)
#define tr(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();++it)
#define x first
#define y second

using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long LL;

string tos(LL a){
	string e="";
	while(a){
		e=e+string(1,'0'+a%10);
		a/=10;
	}
	reverse(e.begin(),e.end());
	return e;
}
LL toi(string a){
	LL ret=0;
	tr(it,a){
		ret*=10;
		ret+=*it-'0';
	}
	return ret;
}
string rev(string a){
	reverse(a.begin(),a.end());
	return a;
}
LL pot(int a){
	LL ret=1;
	fru(i,a) ret*=10;
	return ret;
}
LL idz(LL A, LL B){
	if(A==B) return 0;
	string a=tos(A),b=tos(B);
	assert(a.size()==b.size());
	string w=b;
	LL ret=0;
	int d=a.size();
	string p1=b.substr(0,(d+1)/2),
		   p2=b.substr((d+1)/2,d-(d+1)/2);
//	cout<<p1<<"   "<<p2<<endl;
	LL x;
	if(toi(p2)) x=toi(rev(p1))+pot(d-1);
	else x=toi(rev(tos(toi(p1)-1)))+pot(d-1);
	ret+=x-A;
	LL y=toi(rev(tos(x)));
	ret+=B-y+1;
//	printf("x = %lld y = %lld\n",x,y);

	//printf("z %lld do %lld ide za %lld\n",A,B,ret);
//	return ret;
	return min(ret,B-A);
}

void solve(){
	LL a;
	scanf("%lld",&a);
	LL q=1;
	LL r=1;
	while(1){
		if(q*10<=a){
			r+=idz(q,10*q-1);
			++r;
			q*=10;
		}
		else{
			r+=idz(q,a);
			break;
		}
	}
	printf("%lld\n",r);
}

int main()
{
	int o;
	scanf("%d",&o);
	fru(oo,o)
	{
		 printf("Case #%d: ",oo+1);
		 solve();
	}
    return 0;
}
