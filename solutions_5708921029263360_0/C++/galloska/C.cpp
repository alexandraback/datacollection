#include <bits/stdc++.h>
#define pii pair<int,int>
#define psi pair<int,pii>
#define endl '\n'

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t,a,b,c,k,u=1;
	cin>>t;
	
	while(t--){
		cin>>a>>b>>c>>k;
		
		vector<pii> par;
		
		for(int h=0;h<k;h++)		
		for(int i=0;i<b;i++)
			for(int j=0;j<c;j++)
					par.push_back( pii( i , j) );
					
		map<psi,int> check;
		vector<psi> res;
		
		for(int i=0;i<a;i++)
			for(int j=0;j<par.size();j++){
				int uno = check[ psi( 2 , pii( par[j].first , par[j].second ) ) ];
				int dos = check[ psi( 1 , pii( i , par[j].first ) ) ];
				int tres = check[ psi( 0 , pii( i , par[j].second ) ) ];
				if( uno<k && dos<k && tres<k ){
					check[ psi( 2 , pii( par[j].first , par[j].second ) ) ]++;
					check[ psi( 1 , pii( i , par[j].first ) ) ]++;
					check[ psi( 0 , pii( i , par[j].second ) ) ]++;
					
					res.push_back( psi( i + 1 , pii( par[j].first + 1 , par[j].second + 1 ) ) );
				}
			}
			
		vector<psi> res2;
		psi prev = psi( -1 , pii( -1 , -1 ) );
		
		/*for(int i=0;i<res.size();i++)
			cout<<res[i].first<<" "<<res[i].second.first<<" "<<res[i].second.second<<endl;*/
		
		while(1){
			
			int f = 0,id;
			
			for(int i=0;i<res.size();i++)
				if(res[i]!=prev){
					id = i;
					//cout<<prev.first<<" "<<prev.second.first<<" "<<prev.second.second<<endl;
					prev = res[i];
					//cout<<res[i].first<<" "<<res[i].second.first<<" "<<res[i].second.second<<endl;
					f = 1;
					break;
				}
				
			if(!f) break;
			
			res.erase( res.begin() + id );
			res2.push_back( prev );
		}
			
		res = res2;
		cout<<"Case #"<<u++<<": "<<res.size()<<endl;
			
		for(int i=0;i<res.size();i++)
			cout<<res[i].first<<" "<<res[i].second.first<<" "<<res[i].second.second<<endl;
	}
	return 0;
}
