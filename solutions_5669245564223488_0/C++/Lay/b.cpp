#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <functional>
#include <set>
#include <complex>

using namespace std;

const long long mod=1000000007;

int main()
{
	int t;
	cin>>t;
	
	for(int T=1;T<=t;T++){
		int n;
		long long res=0;
		cin>>n;
	
		if(n==1){
			printf("Case #%d: %d\n",T,1);
			continue;
		}

		vector<int> p;
		for(int i=0;i<n;i++) p.push_back(i);

		vector<string> s(n);
		for(int i=0;i<n;i++) cin>>s[i];

		do{

//			for(int i=0;i<n;i++) cout<<s[p[i]]<<" ";

			bool ok=false,f=true;
			long long num=0;
			for(int i=0;i<n-1&&f;i++){
				if(*(s[p[i]].rbegin())!=*(s[p[i+1]].begin())){
					if(ok){
						num++;
						num%=mod;
						ok=false;
					}else f=false;
				}
				else{
					num++;
					num%=mod;

				 ok=true;
				}
			}
			if(f){ res+=num;}
			res%=mod;
	//		cout<<endl;

		}while(next_permutation(p.begin(),p.end()));

		printf("Case #%d: %d\n",T,res);

	}


	return 0;
}
