#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	
	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++){
		int a,n,x;
		cin>>a>>n;
		vector <int> v;
		for(int i=0;i<n;i++){
			cin>>x;
			v.push_back(x);
		}
		cout<<"Case #"<<tt<<": ";
		if(a>1){
			sort(v.begin(),v.end());
			vector <int> q;
			q.push_back(0);
			int r =0;
			int i=0;
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
			int m = 300;
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