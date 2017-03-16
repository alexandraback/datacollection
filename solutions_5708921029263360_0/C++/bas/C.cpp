#include<iostream>
#include<vector>
#include<string>

using namespace std;
	int T;
	int J,P,S, K;
int main(){

	cin>>T; 
	for(int j=0; j<T; j++){
	    cin>>J>>P>>S>>K;
	    vector<int> js(1000,0);
	    vector<int> ps(1000,0);
	    vector<vector<int> > res(0); int tot=0;
	    for(int i=1; i<=J; i++){
		for(int k=1; k<=P; k++){
		int su=0;
		    for(int l=1; l<=S && su<K; l++){
			if(js[i*11+l]<K && ps[k*11+l]<K){
			su++;
			res.push_back({i, k, l});
			js[i*11+l]++;ps[k*11+l]++;
			tot++;
			}
		    }		    
		}
	    }
		
	    cout<<"Case #"<<j+1<<": " <<tot<<"\n";
	    for(int i=0; i<tot; i++){
		for(int k=0; k<3; k++)
		    cout<<res[i][k]<<" ";
	    cout<<"\n";
	    }
		
	}
	
}
