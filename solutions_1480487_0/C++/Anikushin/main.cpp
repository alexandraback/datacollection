#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int T;
	cin >> T;
	for(int t=0;t<T;t++){
		int n;
		cin >> n;
		vector<int> a(n);
		int s=0;
		for(int i=0;i<n;i++){
			cin >> a[i];
			s+=a[i];
		}
		vector<double> b(n,0);
		for(int i=0;i<n;i++){
			double l=0,r=1;
			while(r-l>1e-10){
				double m=(l+r)/2;
				double x=a[i]+s*m;
				int f=1;
				double ss=0;
				for(int j=0;j<n;j++){
					double d=x-a[j];
					if(d<0)continue;
					double p=d/s;
					if(ss+p>1+1e-10){
						f=0;
						break;
					}
					ss+=p;
				}
				if(f==1)l=m;
				else r=m;
			}
			b[i]=l;
		}
		cout << "Case #" << t+1 << ": ";
		cout.flags(ios::fixed);
		cout.precision(7);
		for(int i=0;i<n;i++){
			cout << b[i]*100 << " ";
		}
		cout << endl;
	}
	return 0;
}