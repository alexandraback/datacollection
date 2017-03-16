#include<iostream>
#include<set>
using namespace std;

typedef pair<int,int> pii;

set<pii> ans;

void getans(int x,int a, int b) {
	//cerr<<"getans "<<x<<' '<<a<<' '<<b<<endl;
	int pow1 = 1;
	int pow2 = 1;
	int temp = x;
	while(temp>0) {
		pow2 *=10;
		temp/=10;
	}
	temp = x;
	pow1 = 10;
	temp/=10;
	while(temp>0) {
		int num = temp+(x%pow1)*(pow2/pow1);
		//cerr<<num<<endl;
		if(a<=num && num<=b && x<num) {
			ans.insert(pii(x,num));
		}
		temp/=10;
		pow1*=10;
	}
}

int main() {
	int t;
	cin>>t;
	for(int tn=0;tn<t;tn++) {
		int a,b;
		cin>>a>>b;
		ans.clear();
		for(int i=a;i<=b;i++)
			getans(i,a,b);
		cout<<"Case #"<<tn+1<<": "<<ans.size()<<endl;
	}

}

