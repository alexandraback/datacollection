#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(void){
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
		int a,b,k;
        scanf("%d%d%d",&a,&b,&k);
		
		int ans = 0;
		for(int i=0;i<a;i++)
			for(int j=0;j<b;j++)
				if((i&j) < k) ans ++;
		
        printf("Case #%d: %d\n", tt, ans);
    }
    return 0;
}

