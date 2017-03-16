#include <bits/stdc++.h>
using namespace std;
int a[26];
int main(){
	string s,num[10]= {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
	int T,i,j,k;
	cin>>T;
	int order[10]= {0,8,2,3,4,6,7,5,1,9};
	char dis[10]= {'Z','G','W','H','U','X','S','V','O','N'};
	for(int test=1;test<=T;++test){
		cin>>s;
		memset(a,0,sizeof(a));
		for(i=0;i<s.size();++i)
			a[s[i]-'A']++;
		vector<int> ret;
		for(i=0;i<10;++i){
			k = dis[i]-'A';
			while(a[k]>0){
				string t = num[order[i]];
				for(j=0;j<t.size();++j)
					a[t[j]-'A']--;
				ret.push_back(order[i]);
			}
		}
		sort(ret.begin(),ret.end());
		cout<<"Case #"<<test<<": ";
		for(i=0;i<ret.size();++i)
			cout<<ret[i];
		cout<<endl;
	}
}
