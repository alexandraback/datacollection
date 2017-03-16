#include <stdio.h>
int v[10];
int E;
int e;
int R;
int N;
int n;
int rec(){
    if(n==N) return 0;
    int i,max=0,ara,temp;
    for(i=0;i<=e;i++){
                      temp=e;
                      e+=R-i;
                      if(e>E) e=E;
                      n++;
                      ara=v[n-1]*i+rec();
                      if(ara>max) max=ara;
                      e=temp;
                      n--;
    }
    return max;
}
int main(){
	int T,i,ii;
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
		scanf("%d %d %d",&E,&R,&N);
		for(ii=0;ii<N;ii++){
                            scanf("%d",&v[ii]);
}
e=E;
n=0;
		printf("Case #%d: %d\n",i+1,rec());
	}
	scanf("%d",&T);
	return 0;
}
