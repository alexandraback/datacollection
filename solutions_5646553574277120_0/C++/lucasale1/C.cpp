//C
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int main(){
	int c,d,u;
	int t,t1;	
	cin>>t;
	t1 = t;
	while(t--){
		cin>>c>>d>>u;
		
		vector<int> v;
		vector<int> v1(u+1);
		
		for(int i=0;i<d;i++){
			int x;
			cin>>x;						
			v1[x]=1;
			v.push_back(x);
		}
		queue<int>q;
		
		map<int,bool> m;
		m[0]=true;		
		int r=0;
		bool ok=true;
		while(ok){
			q.push(0);
			//m.clear();
			while(!q.empty()){
				int p = q.front();q.pop();
				//cout<<p<<endl;
				int sum=0;
				for(int i=0;i<(int)v.size();i++){
					if(!(p & 1<<i)){
						if(v[i]+sum<u+1){
							v1[v[i]+sum]=1;
							if(!m[p|1<<i]){
								q.push(p|1<<i);
							}
						}
					}else sum+=v[i];
				}
			}
			bool ad=false;
			for(int i=1;i<=u;i++){
				if(!v1[i]){
					r++;
					//cout<<i<<endl;
					v.push_back(i);
					ad=true;
					break;
				}
			}
			if(!ad)ok=false;
		}
		cout<<"Case #"<<t1-t<<": "<<r<<endl;
	}
	return 0;
}
