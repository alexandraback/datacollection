#include<iostream>
#include<iomanip>
using namespace std;

long double getprob(int x, int n) {
	long double p = 1;
	int remained = n;
	for(int i=1;i<=x;i++) {
		p= (p*(n-i+1))/i;
		while(remained>0 && p>=1) {
			p/=2;
			remained--;
		}
	}
	while(remained>0) {
		p/=2;
		remained--;
	}
	return p;
}

int main() {
	int t;
	cin>>t;
	for(int tn=0;tn<t;tn++) {
		int n,x,y;
		cin>>n>>x>>y;
		if (x<0)
			x = -x;
		int level = (x+y)/2;
		int required = 0;
		for(int i=0;i<level;i++)
			required+=4*i+1;
		long double prob;
		if((n<=required+y && x!=0) || (x==0 && n<required+level*4+1))
			prob = 0;
		else if(n>=required+y+1+level*2)
			prob = 1;
		else {
			n -= required;
			prob = 0;
			for(int i=y+1;i<=n;i++)
				prob += getprob(i,n);
		}
		cout<<"Case #"<<tn+1<<": "<<fixed<<setprecision(7)<<prob<<endl;
	}

}

