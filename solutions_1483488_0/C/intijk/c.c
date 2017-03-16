#include <stdio.h>
int ipow(int a,int b){
    int i;
    int r=1;
    for(i=0;i<b;i++){
        r*=a;
    }
    return r;
}
char visited[2000005];
int main()
{
    int T,n,i,j,k,c,a,A,B,m,w,count;
    scanf("%d",&T);
    for(c=0;c<T;c++){
		memset(visited,0,sizeof(visited));
        scanf("%d%d",&A,&B);
        count=0;
        for(n=A;n<=B;n++){
            a=n;
            w=0;
            while(a!=0){
                w++;
                a/=10;
            }
			int cc=1;
			visited[n]=1;
            for(i=1;i<w;i++){
                if(n%ipow(10,i)/ipow(10,i-1)!=0){
                    m=n/ipow(10,i)+n%ipow(10,i)*ipow(10,w-i);
					if(m>=A && m<=B && !visited[m] ){visited[m]=1; cc++;}	
                }
            }
			count+=cc*(cc-1)/2;
        }
        printf("Case #%d: %d\n",c+1,count);
    }
}
