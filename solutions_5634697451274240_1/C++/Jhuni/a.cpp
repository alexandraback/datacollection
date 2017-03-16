#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
#define INF 2147483647
#define mod 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;


int T;
int main(){
	scanf("%d",&T);
	for(int TT=1;TT<=T;TT++){
		char a[111];
		int ans=0;
		scanf("%s",a);
		int l=strlen(a);
		a[l++]='+';
		for(int i=1;i<l;i++){
			if(a[i]!=a[i-1])ans++;
		}
		printf("Case #%d: %d\n",TT,ans);
	}
}