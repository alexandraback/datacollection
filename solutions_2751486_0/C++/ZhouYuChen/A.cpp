#include<iostream>
#include<string>
#include<cstring>
#include<vector>
using namespace std;

int main(){
	int T,ts=1;
	for(cin >> T;ts<=T;++ts){
		string s;
		int n;
		cin >> s >> n;
		size_t L=s.length();
		vector<int> end;
		for(size_t i=0,t=0;i<L;++i){
			if(strchr("aeiou",s[i])==NULL)
				++t;else t=0;
			if(t>=n)end.push_back(i);
		}
		long long ans = 0;
		for(size_t i=0,j=0;i<L;++i){
			for(;j<end.size()&& i+n-1>end[j];++j);
			if(j==end.size())break;
			ans += L-end[j];
		}
		cout <<"Case #" << ts<<": "<< ans << endl;
	}
}
