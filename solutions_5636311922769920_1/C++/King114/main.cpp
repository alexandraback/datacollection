#include <stdio.h>

int t,k[101],c[101],s[101];

long long int f(int x,int n,int i)
{
    long long int ret;
    if(n<=1) return x;
    ret=(f(x,n-1,i)-1)*k[i];
    if(x+n-1<k[i]) ret+=x+n-1;
    else ret+=k[i];
    return ret;
}

int main()
{
    int i,j;

    FILE  *in, *out;

    in=fopen("D-large.in","r");
	out=fopen("output.txt","w");

	fscanf(in,"%d",&t);
	for(i=1;i<=t;i++){
        fscanf(in,"%d %d %d",&k[i],&c[i],&s[i]);
	}

	for(i=1;i<=t;i++){
        fprintf(out,"Case #%d: ",i);

        if(c[i]*s[i]<k[i]){
            fprintf(out,"IMPOSSIBLE\n");
            continue;
        }

        for(j=1;j<=k[i];j+=c[i]) fprintf(out,"%lld ",f(j,c[i],i));

        fprintf(out,"\n");
	}

	return 0;
}
