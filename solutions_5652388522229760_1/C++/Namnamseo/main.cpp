#include <cstdio>

void read(int& a){ scanf("%d",&a); }
template<typename T,typename... Args> void read(T& a,Args&... b){ read(a); read(b...); }

bool chk[10];

void drain(int x){
    if(x==0){
        chk[0]=true; return;
    }
    while(x){
        chk[x%10]=true; x/=10;
    }
}

void work(){
    int n;
    read(n);
    if(n==0){
        puts("INSOMNIA");
        return;
    }
    int i,j;
    for(i=0;i<10;++i) chk[i]=0;
    for(i=1;;++i){
        drain(n*i);
        for(j=0;j<10;++j) if(!chk[j]) break;
        if(j==10){
            printf("%d\n",n*i);
            return;
        }
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    read(t);
    for(int tc=1;tc<=t;++tc){
        printf("Case #%d: ",tc); work();
    }
    return 0;
}
