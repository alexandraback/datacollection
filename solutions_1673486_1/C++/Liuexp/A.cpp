#include "mylib.h"
//#define SMALL
#define LARGE
int A,B;
double p[100002];
ull stoi(string &t)
{
    ull ret=0;
    sscanf(t.c_str(),"%lld",&ret);
    return ret;
}
string itos0(ull t)
{
    stringstream sout;
    sout<<t;
    return sout.str();
}

double solve(){
	double curp=1;
	double ret=B+2;
	for(int l=A;l>=0;l--){
		ret=min(ret,curp*(2*l+B-A+1)+(1-curp)*(2*l+B-A+2+B));
		curp*=p[A-l];
	}
	return ret;
}
int main() {
#ifdef SMALL
	freopen("A-small-attempt1.in","rt",stdin);
	freopen("A-small.out","wt",stdout);
#endif
#ifdef LARGE
	freopen("A-large.in","rt",stdin);
	freopen("A-large.out","wt",stdout);
#endif
	int T;cin>>T;
	for(int t=1;t<=T;t++){
		cin>>A>>B;
		double ans=0;
		for(int i=0;i<A;i++){
			cin>>p[i];
		}
		ans = solve();	
		//cout.setprecision(9);
		cout<<"Case #"<<setprecision(15)<<t<<": ";
		cout<<ans<<endl;
	}

	return 0;
}
