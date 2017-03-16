#include <iostream>
#include <fstream>
#include <map>
using namespace std;
typedef long long ll;
int main(){
	ofstream ofs("out.txt");
	int t;	cin>>t;
	for(int cases=1;cases<=t;cases++){
		int n;	cin>>n;
		map<int,int> mp;
		for(int i=1;i<(n<<1);i++){
			for(int j=0;j<n;j++){
				int a;	cin>>a;
				mp[a]++;
			}
		}
		ofs<<"Case #"<<cases<<":";
		for(auto it:mp){
			if(it.second&1){
				ofs<<" "<<it.first;
			}
		}
		ofs<<endl;
	}
	ofs.close();
	return 0;
}
