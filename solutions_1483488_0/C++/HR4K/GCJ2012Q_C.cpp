#include <sstream> 
#include <iostream>
#include <cstdio>
using namespace std;

int digitNum(int n){
	stringstream sst;
	sst << n;
	string num;
	sst >> num;
	return num.size();
}

int main() {
	int T;
	cin>>T;
	for(int i=0; i<T; i++){
		int A, B;
		cin>>A>>B;
		int ans=0;
		for(int j=A; j<B; j++){
			stringstream apd;
			apd<<j<<j;
			string tmp=apd.str();
			for(int k=0; k<digitNum(j); k++){
				if(tmp[k]=='0') continue;
				stringstream numstre;
				numstre<<tmp.substr(k,digitNum(j));
				int num;
				numstre>>num;
				if(j<num && num<=B){
					++ans;
					//printf("%d %d\n", j, num);
				}
			}
		}
		printf("Case #%d: %d\n", i+1, ans);
	}
	return 0;
}
