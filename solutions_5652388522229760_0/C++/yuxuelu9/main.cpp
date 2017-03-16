#include<fstream>
#include<set>
using namespace std;

int main(){
	ifstream fin("A-small-attempt0.in");
	ofstream fout("A-small-attempt0.out");
	int t=0;
	fin>>t;
	int ans=0;
	int n,tmp;
	set<int> num;
	for(int k=1;k<=t;k++){
		fin>>n;
		if(n==0){
			fout<<"Case #"<<k<<": "<<"INSOMNIA"<<endl;
			continue;
		}
		ans=0;
		for(int i=0;i<10;i++){
			num.insert(i);
		}
		while(num.size()!=0){
			ans+=n;
			tmp=ans;
			while(tmp>0){
				num.erase(tmp%10);
				tmp/=10;
			}
		}
		fout<<"Case #"<<k<<": "<<ans<<endl;
	}
	return 0;
}