#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
using namespace std;
int main(){
	int t,te,n,i,j,k,ans;
	ifstream f1;
	ofstream f2;
	f1.open("input.txt");
	f2.open("output.txt");
	f1>>t;
	for(te=0;te<t;te++){
		f1>>n;
		int ans=0,a[n];
		string arr[n];
		for(i=0;i<n;i++)f1>>arr[i];
		for(i=0;i<n;i++)a[i]=i;
		do{
			string s="";
			for(i=0;i<n;i++)s+=arr[a[i]];
			int vis[26];
			for(i=0;i<26;i++)vis[i]=0;
			for(i=0;i<s.size();i++){
				if(vis[s[i]-'a']==1)break;
				vis[s[i]-'a']=1;
				j=i+1;
				while(s[j]==s[i])j++;
				i=j-1;
			}
			if(i==s.size())ans++;
		}while(next_permutation(a,a+n));
		cout<<"Case #"<<te+1<<": "<<ans<<"\n";
		f2<<"Case #"<<te+1<<": "<<ans<<"\n";
	}
	return 0;
}
