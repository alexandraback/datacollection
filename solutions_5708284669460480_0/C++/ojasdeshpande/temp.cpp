#include <bits/stdc++.h>
#define MOD 1000000007
#define pb push_back
using namespace std;
int cnt[8];
void enumerate(string a,string t,int s,string k){
	if(s==0){
		int ct = 0;
		int n = k.length();
		for(int i=0;i<n;i++){
			string temp = "";
			for(int j=i;j<min(i+(int)t.length(),n);j++){
				temp+=k[j];
			}
			if(temp == t) ct++;
		}
		cnt[ct]+=1;
		return;
	}
	for(int i=0;i<a.length();i++) enumerate(a,t,s-1,k+a[i]);
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	freopen("a.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	cin >> t;
	for(int tt=1;tt<=t;tt++){
		cout << "Case #" << tt << ": ";
		long long kk,ll,s;
		string a,t;
		cin >> kk >> ll >> s >> a >> t;
		for(int i=0;i<8;i++) cnt[i]=0;
		enumerate(a,t,s,"");
		double res = 0;
		for(int i=0;i<8;i++){
			res = res + ((double)(i))*cnt[i];
		}
		for(int i=0;i<s;i++) res = res/a.length();
		double mm = 0;
		for(int i=0;i<8;i++) if(cnt[i]!=0) mm = i;
		printf("%.9lf\n",mm-res);
	}
	return 0;
}
