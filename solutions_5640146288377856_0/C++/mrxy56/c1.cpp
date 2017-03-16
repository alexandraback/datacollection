#include<cstdio>
using namespace std;
int main(){
    int T,kase=0,r,c,w;
    freopen("a.in","r",stdin);
    freopen("b.out","w",stdout);
    scanf("%d",&T);
    while(T--){
	scanf("%d%d%d",&r,&c,&w);
	int n1=c/w,n2=0,n3=n1*w,n4=c-w+1;
	int now=n3-n4+1,then=w-now;
	n2+=n3-n4;
	if(c%w==0) n2+=n1+then;
	else n2+=n1+then+1;
	printf("Case #%d: %d\n",++kase,n2);
    }
    return 0;
}

