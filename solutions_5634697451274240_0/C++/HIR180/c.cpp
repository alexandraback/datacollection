#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef pair<int,int> P;
typedef long long ll;
#define mp make_pair
#define fi first
#define sc second

int main(){
	int t; scanf("%d",&t);
	for(int q=1;q<=t;q++){
		printf("Case #%d: ",q);
		char s[105]; scanf("%s",&s); int n = strlen(s);
		for(int ans=0;;ans++){
			int j=-1;
			for(int i=0;i<n;i++){
				if(s[i] != s[0]){
					j=i; break;
				}
			}
			if(j==-1 && s[0] == '+'){
				printf("%d\n",ans); break;
			}
			else if(j==-1){
				printf("%d\n",++ans); break;
			}
			for(int i=0;i<j;i++){
				s[i] = (s[i]=='+'?'-':'+');
			}
		}
	}
}