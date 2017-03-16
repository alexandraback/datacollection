#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,cas=0;
	cin>>n;
	while(n--){
		int t;cin>>t;
		double tt;
		
		vector<int> she(t),she2,he(t),he2;
		for(int i=0;i<t;i++){cin>>tt;she[i]=round(tt*1000000);}
		for(int i=0;i<t;i++){cin>>tt;he[i]=round(tt*1000000);}
		
		//cout<<"t="<<t<<endl;
		
		//for(int i=0;i<t;i++){cout<<he[i]<<" ";}cout<<endl;
		sort(she.begin(),she.end());
		sort(he.begin(),he.end());
		
		//for(int i=0;i<t;i++){cout<<he[i]<<" ";}cout<<endl;
		
		she2 = she;he2=he;
		int sol1=0;
		
		while(she2.size()){
			if(she2[she2.size()-1] < he2[he2.size()-1]){
				she2.erase(she2.begin());
				he2.pop_back();
			}else{
				she2.pop_back();
				he2.pop_back();
				sol1++;
			}
		}
		
		she2 = she;he2=he;
		int sol2=0;
		
		while(she2.size()){
			if(she2[she2.size()-1] > he2[he2.size()-1]){
				he2.erase(he2.begin());
				she2.pop_back();
				sol2++;
			}else{
				she2.pop_back();
				he2.pop_back();
				
			}
		}
		
		cout<<"Case #"<<++cas<<": "<<sol1<<" "<<sol2<<endl;
	}
}
