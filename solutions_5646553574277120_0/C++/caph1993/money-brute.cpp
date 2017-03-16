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
#define LEN 1000

using namespace std;
typedef long long int large;
typedef pair<int,int> ii;

char line[LEN], p[LEN],t[LEN];
int plen,tlen,K,S;

int max_bananas(){ // How many times is p in t?
	return 0;
}



double solve(){
	int mb = max_bananas();
	
	return 0;
}

int main(){
	int ntc,test=1;
	freopen("money.txt","r",stdin);
	//freopen("large.in","r",stdin);
	//freopen("large.out","w",stdout);
	gets(line);
	sscanf(line,"%d",&ntc);
	while(ntc--){
		gets(line)
		sscanf(line,"%d %d %d",&K,&plen,&slen);
		printf("Case #%d: %lf\n",test++,solve());
	}
	return 0;
}

