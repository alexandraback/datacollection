#include<iostream>
#include<vector>

using namespace std;
	int T;
 
int main(){

	cin>>T; 
	for(int j=0; j<T; j++){
	    long long b, m;
	    cin>>b>>m;
	    if(m>((b-2)*(b-1))/2+1){
		cout<<"Case #"<<j+1<<": IMPOSSIBLE\n";
		continue;
	    }
	    
	    cout<<"Case #"<<j+1<<": POSSIBLE\n";
	    vector<string> res(b, string(b, '0'));
	    for(int i=0; i<b; i++){
		for(int k=i+1; k<b; k++)
		    res[i][k]='1';
	    }
	    long long tot = ((b-2)*(b-1))/2+1;
	    for(int i = b-2; i>=1; i--){
		if(tot-m>=i){
		    tot-=i;
		    res[i][b-1]='0';
		    int rem = 1;
		    for(int k=0; k<b; k++) if(res[i][k]=='1')rem=0;
		    if(rem)
		    for(int k=0; k<b; k++)res[k][i]='0';
		}
	    }
	    if(tot-m){res[0][b-1]='0';tot--;}
	    if(tot-m)cout<<"NNNNNN"<<tot-m;
	    for(int i=0; i<b; i++)cout<<res[i]<<"\n";
	}
	
}
