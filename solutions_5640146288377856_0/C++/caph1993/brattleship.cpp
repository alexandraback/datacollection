#include <bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b) for(i=a;i>=b;i--)
#define itloop(i,a) for(i=a.begin();i!=a.end();i++)
#define x first
#define y second
#define pushb(a) push_back(a)
#define pushf(a) push_front(a)
#define popb()   pop_back()
#define popf()   pop_front()
#define setmem(a,val) memset(a,val,sizeof(a))
#define LEN 1000005

using namespace std;
typedef long long int large;
typedef pair<int,int> ii;

int r,c,w;

large solve(){
	large ans = r*(c/w); // Hitted!
	if(w==1) return ans;
	return ans+w-1 + (c%w!=0);
}

int main(){
	int ntc,test=1;
	//freopen("brattleship.txt","r",stdin);
	freopen("small.in","r",stdin);
	freopen("small.out","w",stdout);
	scanf("%d",&ntc);
	while(ntc--){
		scanf("%d %d %d",&r,&c,&w);
		printf("Case #%d: %lld\n",test++,solve());
	}
	return 0;
}

