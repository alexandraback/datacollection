#include <sstream> 
#include <iostream>
#include <cstdio>
#include <set>
#include <fstream>
using namespace std;

int digitNum(int n){
	stringstream sst;
	sst << n;
	string num;
	sst >> num;
	return num.size();
}

int main() {
	static const string emptystr;
	int T;
	cin>>T;
	for(int i=0; i<T; i++){
		int A, B;
		cin>>A>>B;
		int dgt=digitNum(A);
		//int ans=0;
		set< pair< int,int > > recycled;
		stringstream apd, numstre;
		for(int n=A; n<B; n++){
			apd.str(emptystr);
			apd.clear();
			apd<<n<<n;
			string tmp;
			apd>>tmp;
			for(int k=0; k<dgt; k++){
				if(tmp[k]=='0') continue;
				numstre.str(emptystr);
				numstre.clear();
				numstre<<tmp.substr(k,dgt);
				int m;
				numstre>>m;
				if(n<m && m<=B){
					//++ans;
					if(recycled.find(pair<int,int>(n,m)) == recycled.end()){
						recycled.insert(pair<int,int>(n,m));
					}
				}
			}
		}
		//for(set< pair< int,int > >::iterator i=cycles.begin(); i!=cycles.end(); i++)
		//	cout<<i->first<<'\t'<<i->second<<endl;
		printf("Case #%d: %d\n", i+1, recycled.size());
	}
	return 0;
}
