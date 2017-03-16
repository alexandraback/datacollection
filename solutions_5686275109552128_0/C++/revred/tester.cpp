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

int a[1007];

int main(){
	freopen("file.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t=1,tst = 1;
	cin>>t;
	while(t--){
		int n,max = 0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(max<a[i]){
				max = a[i];
			}
		}
		int i = 1,tmp,ans = 1000;
		while(i<=max){
			tmp = 0;
			for(int j=0;j<n;j++){
				tmp += (a[j]-1)/i;
			}
			tmp += i;
			if(ans>tmp){
				ans = tmp;
			}
			i++;
		}
		printf("Case #%d: %d\n",tst++,ans);
	}
	return 0;
}
