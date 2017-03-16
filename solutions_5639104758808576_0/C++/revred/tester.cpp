#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define mod 1000000007
#define inf 1000000007
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define lim 100007

string s;

int main(){
	freopen("file.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t=1,tst = 1;
	cin>>t;
	while(t--){
		int n,tmp = 0,ans = 0;
		cin>>n>>s;
		tmp = s[0]-'0';
		for(int i=1;i<=n;i++){
			if(i>tmp){
				ans += i-tmp;
				tmp += (i-tmp);
			}
			tmp += s[i]-'0';
		}
		printf("Case #%d: %d\n",tst++,ans);
	}
	return 0;
}
