#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
#define MAX(x,y) (x > y ? x : y)
#define MIN(x,y) (x > y ? y : x)
long long mod = 1000000007;

string t[105], aa[105];
int l[35], r[35];
long long fac(long long x) {
	return (x < 2 ? 1 : (x * fac(x-1))%mod);
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	int T;
	cin>>T;
	
	
	for (int idx = 1; idx <= T; idx++) {
		int n;
		cin >> n;
		memset(l, 0, sizeof(l));
		long long ans = 1;
		for(int i = 0; i < 40; i++)aa[i]="";
		for (int i = 0; i < n;i++){
			cin>>t[i]; 
			if (t[i][0] == t[i][t[i].length()-1]) {
				l[t[i][0]-'a']++;
				aa[t[i][0]-'a']+=t[i];
			}
		}
		for (int i = 0; 'a'+i <='z'; i++) ans = (ans * fac(l[i]))%mod;
		vector<string> ara;
		ara.clear();
		for (int i = 0; 'a' +i <= 'z'; i++) if (aa[i].length() >0)ara.push_back(aa[i]);
		vector<string> ar;
		ar.clear();
		for (int i = 0; i < n;i++) if(t[i][0] != t[i][t[i].length()-1]) ar.push_back(t[i]);
		while (true) {
			bool ex = true;
			for (int i = 0; i < ar.size(); i++) {
				for(int j =0 ; j< ara.size(); j++) {
					if (ar[i][0] == ara[j][0]) {
						ar[i] = ara[j] + ar[i];
						ara.erase(ara.begin()+j, ara.begin() + j + 1);
						ex=false;
						break;
					}
					if (ar[i][ar[i].length()-1] == ara[j][0]) {
						ar[i] += ara[j];
						ara.erase(ara.begin()+j, ara.begin()+j+1);
						ex =false;
						break;
					}
				}
				if (!ex)break;
			}
			if (ex) break;
		}
		while (true) {
			bool ex=true;
			for(int i =0; i< ar.size();i++) {
				for(int j = i+1;j<ar.size();j++) {
					if(ar[i][0]==ar[j][ar[j].length()-1]) {
						ar[i] = ar[j]+ar[i];
						ar.erase(ar.begin()+j, ar.begin()+j+1);
						ex=false;
						break;
					}
					if(ar[j][0]==ar[i][ar[i].length()-1]) {
						ar[i] += ar[j];
						ar.erase(ar.begin()+j, ar.begin()+j+1);
						ex=false;
						break;
					}
				}
				if(!ex)break;
			}
			if(ex)break;
		}
		int k = ar.size() + ara.size();
		ans = (ans * fac(k))%mod;
		memset(l,0,sizeof(l));
		memset(r,0,sizeof(r));
		string str = "";
		for(int i = 0; i<ar.size();i++)str+=ar[i];
		for(int i = 0; i<ara.size();i++)str+=ara[i];
		//cout<<str<<endl;
		for(int i = 0; i<str.length();i++) {
			if (l[str[i]-'a'] && r[str[i]-'a']) {
				ans = 0;
				break;
			}
			l[str[i]-'a']=1;
			for(int j = 0; 'a'+j<='z';j++)if(l[j]==1 && 'a'+j != str[i])r[j]=1;
		}
		cout<<"Case #"<<idx<<": ";
		if(true)cout<<ans;
		//else cout<<"impossible";
		cout<<endl;
	}
	return 0;
}