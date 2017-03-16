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
		cout<<"Case #"<<case_nr<<": ";
		
		int N;
		cin>>N;
		if(N==0){
			cout<<"INSOMNIA"<<"\n";
			continue;
		}
		bool cnt[10];
		for(int i=0; i<10; i++)
			cnt[i] = false;
		long long m = 1;
		while(true){
			long long n = m*N;
			while(n!=0){
				cnt[n%10] = true;
				n /=10;
			}
			bool fin = true;
			for(int j=0; j<10; j++){
				if(!cnt[j])
					fin = false;
			}
			if(fin){
				cout<<m*N<<"\n";
				break;
			}
			m++;
		}
	}
}