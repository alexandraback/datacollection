#include <bits/stdc++.h>
#define MAXN 3000
using namespace std;
char s[MAXN];
int cnt,ans,n;

int main(){
		
	int test;
	cin >> test;
	for(int ti=1;ti<=test;++ti){

			cin >> n;
			cin >> s;
		//	cout << s << endl;
			cnt=0;
			ans=0;
			for(int i=0;i<=n;++i){
						if(cnt<i) {
								ans+=(i-cnt);
								cnt=i;
								}
						cnt+=(s[i]-'0');
							
							}

			printf("Case #%d: %d\n",ti,ans);
			}
	return 0;}
