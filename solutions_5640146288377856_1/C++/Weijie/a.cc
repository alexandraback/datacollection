#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int solve(int r,int c,int w){
	int ret = 0;
	ret += (r - 1) * (c / w);
	ret += c / w - 1 + w;
	if(c % w != 0)
		++ret;
	return ret;
}

int main(){
	int T;
    scanf("%d",&T);
    for(int cas = 1;cas <= T;++cas){
		int r,c,w;
		scanf("%d%d%d",&r,&c,&w);
        printf("Case #%d: %d\n",cas,solve(r,c,w));
    }
    
    return 0;
}
