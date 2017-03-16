#include <bits/stdc++.h>
using namespace std;

int t,a[30],b[30],c[15],ct,ok,mn,l[15],len; string s,ans;
string x[]={"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX",
"SEVEN","EIGHT","NINE"};

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("getdig.out","w",stdout);
	for (int i=0;i<10;i++) l[i]=x[i].length();
	cin >> t;
	for (int tc=1;tc<=t;tc++){
		cout << "Case #" << tc << ": ";
		cin >> s; len=s.length();
		memset(a,0,sizeof(a));
		for (int i=0;i<len;i++){
			a[s[i]-'A']++;
		}
		for (int i=0;i<(1<<10);i++){
			ct=0;
			for (int j=0;j<10;j++){
				if (i&(1<<j)){
					c[ct]=j; ct++;
				}
			}
			do{
				memset(b,0,sizeof(b)); ans="";
				for (int j=0;j<ct;j++){
					mn=1000000000;
					for (int k=0;k<l[c[j]];k++){
						mn=min(mn,a[x[c[j]][k]-'A']-b[x[c[j]][k]-'A']);
					}
					for (int k=0;k<mn;k++) ans+='0'+c[j];
					for (int k=0;k<l[c[j]];k++){
						b[x[c[j]][k]-'A']+=mn;
					}
				}
				ok=1;
				for (int j=0;j<26;j++) ok&=a[j]==b[j];
				if (ok){
					sort(ans.begin(),ans.end());
					cout << ans << "\n"; break;
				}
			}while (next_permutation(c,c+ct));
			if (ok) break;
		}
	}
}
