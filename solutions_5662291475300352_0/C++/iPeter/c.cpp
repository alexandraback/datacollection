#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,z;
class man{
public:
	double d,m;
}s[500000];

int main(void){
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
		scanf("%d",&n);
		z=0;
		for(int i=0;i<n;i++){
			int d,h,m;
			scanf("%d%d%d",&d,&h,&m);
			for(int j=0;j<h;j++){
				s[z++] = (man){d,m+j};
			}
		} 
		
		int ans=0;
		double p[4];
		p[0]=(360.0-s[0].d)/(360.0/s[0].m);
		p[1]=(720.0-s[0].d)/(360.0/s[0].m);
		p[2]=(360.0-s[1].d)/(360.0/s[1].m);
		p[3]=(720.0-s[1].d)/(360.0/s[1].m);
        
		if(p[1]<=p[2]) ans=1;
		if(p[3]<=p[0]) ans=1;
		
		// for(int i=0;i<4;i++)
		// 	printf("%lf ",p[i]);
		// puts("");
		
        printf("Case #%d: %d\n", tt, ans);
    }
    return 0;
}

