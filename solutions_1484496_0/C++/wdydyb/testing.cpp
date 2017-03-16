#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main(){
	int t;
	cin>>t;
	int cnt=1;
	while(t--){
		cout<<"Case #"<<cnt<<":"<<endl;
		bool flag=false;
		int n;
		cin>>n;
		vector<int> v(n);
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		map<int,int> mp;
		for(int i=1;i<(1<<n);i++){
			int s=0;
			for(int j=0;j<n;j++){
				if((1<<j)&i)
				s+=v[j];
			}
			if(!mp[s]){
				mp[s]=i;
			}else{
				flag=true;
				
				map<int,int> not;
				bool f=false;
				for(int j=0;j<n;j++){
					if(((1<<j)&mp[s])&&((1<<j)&i)){
						
						mp[s]=~(1<<j)&mp[s];
						i=~(1<<j)&i;
					}
					
				}
				for(int j=0;j<n;j++){
					
					if((1<<j)&mp[s]){
						if(f)
						cout<<" ";
						f=true;
						cout<<v[j];
					}
				}
				cout<<endl;
				f=false;
				for(int j=0;j<n;j++){
					
					if((1<<j)&i){
						if(f)
						cout<<" ";
						f=true;
						cout<<v[j];
					}
				}
				cout<<endl;
				break;
			}
		}
		if(!flag)
		cout<<"Impossible"<<endl;
		cnt++;
	}
	return 0;
}