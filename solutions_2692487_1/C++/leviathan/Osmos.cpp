#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	
	long long t;
	cin>>t;
	for(long long tt=1;tt<=t;tt++){
		long long a,n,x;
		cin>>a>>n;
		vector <long long> v;
		for(long long i=0;i<n;i++){
			cin>>x;
			v.push_back(x);
		}
		cout<<"Case #"<<tt<<": ";
		if(a>1){
			sort(v.begin(),v.end());
			vector <long long> q;
			q.push_back(0);
			long long r =0;
			long long i=0;
			while(i<n){
			
				if(a > v[i])
					a+=v[i];
				else{
					while(a <= v[i]){
						r++;
						a+=a-1;
					}
					a+=v[i];
				}
				q.push_back(r);
				i++;
			}
			long long m = 300;
			for(i=0;i<=n;i++){
				m = min(m,q[i]+n-i);
				//cout<<m<<" - "<<q[i]+n-i<<endl;
			}
			cout<<m<<endl;
		}
		else{
			cout<<n<<endl;
		}
	}
	
}