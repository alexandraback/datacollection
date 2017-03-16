#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main(){
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	int t;
	cin>>t;
	cin.ignore();
	for(int i = 0; i < t ; i++){
		cout<<"Case #"<<i + 1<<": ";
		int a,b,k,ans = 0;
		cin>>a>>b>>k;
		for(int j = 0 ; j < a; j++)
			for(int z = 0; z < b; z++){
				int val = j & z;
				if(val < k)
					ans++;
			}
		cout<<ans<<endl;
	}
}