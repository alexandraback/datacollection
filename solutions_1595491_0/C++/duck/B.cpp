#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
	int ca,N,S,p,g,i,ss,ans;

	freopen( "in.txt", "r", stdin );
	freopen( "out.txt", "w", stdout );
	scanf("%d\n", &ca);
	for (int ci = 1; ci <= ca; ++ci) {
		printf("Case #%d: ", ci);
		scanf("%d%d%d",&N,&S,&p);
		ss=0;ans=0;
		for (i = 1 ; i <= N ; ++i){
			scanf("%d",&g);
			if(g==0){
				if(p==0) ans++;
				continue;
			}
			switch(g%3)
			{
			case 0:{if (g/3>=p)ans++;else if(g/3+1>=p){ans++;ss++;};break;}
			case 1:{if (g/3+1>=p)ans++;break;}
			case 2:{if (g/3+1>=p)ans++;else if(g/3+2>=p){ans++;ss++;};break;}
			}
		}
		if(ss>S) ans = ans - ss + S;
		printf("%d",ans);
		printf("%c",'\n');
	}
	return 0;
}