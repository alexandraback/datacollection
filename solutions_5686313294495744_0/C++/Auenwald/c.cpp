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
		int res = 0;
		int n;
		cin>>n;
		string f[n], s[n];
		for(int i=0; i<n; i++){
			cin>>f[i]>>s[i];
		}
		for(int sub=1; sub<(1<<n); sub++){
			bool fake[n];
			int num = 0;
			int save = sub;
			set<string> fi,se;
			for(int i=0; i<n; i++){
				if(save%2==1){
					fake[i]=true;
					num++;
				}
				else{
					fake[i]=false;
					fi.insert(f[i]);
					se.insert(s[i]);
				}
				save /=2;
			}
			bool poss = true;
			for(int i=0; i<n; i++){
				if(fake[i]){
					if(fi.find(f[i])==fi.end())
						poss = false;
					if(se.find(s[i])==se.end())
						poss = false;
				}
			}
			if(poss)
				res = max(res,num);
		}
		
		cout<<"Case #"<<case_nr<<": ";
		cout<<res;
		cout<<"\n";
	}
	
}