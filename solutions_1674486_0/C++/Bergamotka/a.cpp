#include<cstdio>
#include<vector>

using namespace std;

#define PB push_back
#define VAR(x,a) __typeof(a) x=(a)
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)

bool testcase(){
	short n = -1;
	scanf("%hd", &n);
	vector<short> graf[n+1];
	short i = -1, m = -1, j = -1, x = -1;
	for(i=1;i<=n;++i){
		scanf("%hd", &m);
		for(j=0;j<m;++j){
			scanf("%hd", &x);
			graf[i].PB(x);
		}
	}



	short s=-1;
	short ss = -1;
	for(ss=1;ss<=n;++ss){
//		printf("s = %hd\n", s);
		bool vis[n+1];
		for(i=1;i<=n;++i)
			vis[i] = false;

		short stos[n+1];
		short top = 0;

		stos[top++] = ss;
		vis[ss] = true;

		while(top){
			s = stos[--top];
			FOREACH(it, graf[s]){
				if(vis[*it])
					return true;
				vis[*it] = true;
				stos[top++] = *it;
			}
		}
	
	}

	return false;
}


int t, ti;

int main(){
	scanf("%d", &t);
	for(ti=1;ti<=t;++ti){
		printf("Case #%d: ", ti);
	 	if(testcase())
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
