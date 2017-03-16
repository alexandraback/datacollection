#include<bits/stdc++.h>
using namespace std;


int lib[]={0,0,3,2,5,2,7,2,9,2,11};
void solv(int N,int &res,int k)
{
    char f[40];
    int n=N/2-1;
    for(int s=(1<<k)-1,u=1<<n;s<u;)
    {
        if(res==0)
            return ;
        f[0]='1';
        f[N-1]='1';
        f[N]=0;
        for(int i=0,z=1;i<N/2-1;i++,z+=2)
            if(s&(1<<i))
                f[z]=f[z+1]='1';
            else
                f[z]=f[z+1]='0';
        printf("%s",f);
        for(int i=2;i<=10;i++)
            printf(" %d",lib[i]);
        puts("");
        int b=s&-s;
        s=(s+b)|(((s^(s+b))>>2)/b);
        res--;
        if(res==0)
            return ;
    }
}
int main()
{
    //freopen("1.in","r",stdin);
    freopen("2.txt","w",stdout);
    int N=32,J=500;
    int n=7,k=3;
    char f[40];
    printf("Case #1:\n");
    for(int i=1;i<10;i++)
        solv(N,J,i);
	return 0;
}
