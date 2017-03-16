#include <bits/stdc++.h>

using namespace std;

#define INTMAX 0x7FFFFFFF
#define INTMIN -0x80000000
#define LONGMAX 0x7FFFFFFFFFFFFFFF
#define LONGMIN -0x8000000000000000

int main(){
	ios_base::sync_with_stdio(false);
	
	int T;
	cin>>T;
	for(int case_nr=1; case_nr<=T; case_nr++){
		cout<<"Case #"<<case_nr<<": "<<"\n";
		
		int N,J;
		cin>>N>>J;
		vector<string> jams;
		jams.push_back("");
		for(int l=2; l<=N-2; l+=2){
			int js = jams.size();
			for(int i=0; i<js; i++){
				if(jams.size()<J)
					jams.push_back("11"+jams[i]);
				jams[i] = "00" + jams[i];
			}
		}
		for(int i=0; i<jams.size(); i++){
			cout<<"1"<<jams[i]<<"1 ";
			for(int j=2; j<=10; j++)
				cout<<j+1<<" ";
			cout<<"\n";
		}
	}
}