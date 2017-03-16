#include <bits/stdc++.h>
using namespace std;

#define fr(i,a,b) for(int i = a; i < b; i++)
#define fre(i,a,b) for(int i = a; i <= b; i++)
#define frd(i,a,b) for(int i = a; i > b; i--)
#define fred(i,a,b) for(int i = a; i >= b; i--)
#define pb push_back
#define SET(a,v) memset(a,v,sizeof a)

#define INF 1e8
#define N 220

typedef long long ll;
typedef pair<int,int> ii;
int t,n,len,ans;
char str[N];

void solve(){
	ans = 0;
	int first = -1;
	fr(i,0,len) if (str[i] == '-') first = i;
	
	int temp;
	while (first != -1){
		temp = first;
		first = -1;
		fre(i,0,temp){
			if (str[i] == '+') str[i] = '-', first = i;
			else str[i] = '+';
		}
		ans++;
	}
	
}

int main(){
	scanf("%d",&t);
	fr(t2,0,t){
		printf("Case #%d: ",t2+1);
		scanf("%s",str);
		len = strlen(str);
		solve();
		printf("%d\n",ans);
	}

	return 0;
}