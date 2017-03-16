#include<fstream>
#define oo 0x7fffffff
#define N 1000000

int t[N+5],n,dap;
int a[N+10];
int flip(int x);
void solve();

int main(void){
    int i,j,x=0,y,z,k,pp;
    FILE *in,*out;

    in=fopen("input.txt","r");
    out=fopen("output.txt","w");

    fscanf(in,"%d",&pp);
    for(i=1;i<=pp;i++){
        fscanf(in,"%d",&a[i]);
        x=x>a[i]?x:a[i];
    }
    n=x;
    solve();

    for(i=1;i<=pp;i++){
        n=a[i];
        fprintf(out,"Case #%d: %d\n",i,t[n]);
    }

    return 0;

}

int flip(int x)
{
    int i=0;

    while(x){
        i=i*10+x%10;
        x/=10;
    }

    return i;
}


void solve()
{
    int i,y;

    t[0]=0;
    for(i=1;i<=n;i++){
        y=flip(i);
        t[i]=t[i-1]+1;
        if(i%10!=0 && y<i) t[i]=t[i]<t[y]+1?t[i]:t[y]+1;
    }

}

