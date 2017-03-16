#include <cstdio>

using namespace std;

void multi(int sign_a,char a,int sign_b,char b, int &sign,char &c){
    sign=sign_a*sign_b;
    if(a=='1'){
        c=b;
        return;
    }
    if(b=='1'){
        c=a;
        return;
    }
    if(a==b){
        c='1';
        sign*=-1;
        return;
    }
    if(a=='i'){
        if(b=='j'){
            c='k';
            return;
        }
        else{
            c='j';
            sign*=-1;
            return;
        }
    }
    if(a=='j'){
        if(b=='i'){
            c='k';
            sign*=-1;
            return;
        }
        else{
            c='i';
            return;
        }
    }
    if(b=='i'){
        c='j';
        return;
    }
    else{
        c='i';
        sign*=-1;
        return;
    }
}

int main()
{
    int N;
    long L,X;
    char s[11000];
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    scanf("%d",&N);
    for(int T=1;T<=N;T++){
        scanf("%ld %ld\n",&L,&X);
        for(int i=0;i<L;i++)
            scanf("%c",&s[i]);
        if(X>8)
            X=X%4 + 8;
        int k=0,sign=1;
        char c='1';
        for(k=0;k<X*L;k++){
            if(sign==1 && c=='i'){
                break;
            }
            multi(sign,c,1,s[k%L],sign,c);
        }
        if(k==X*L){
            printf("Case #%d: NO\n",T);
            continue;
        }
        //printf("i found at %d\n",k);
        sign=1;
        c='1';
        for(;k<X*L;k++){
            if(sign==1 && c=='j'){
                break;
            }
            multi(sign,c,1,s[k%L],sign,c);
        }
        if(k==X*L){
            printf("Case #%d: NO\n",T);
            continue;
        }
        //printf("j found at %d\n",k);
        sign=1;
        c='1';
        for(;k<X*L;k++)
            multi(sign,c,1,s[k%L],sign,c);
        if(sign==1 && c=='k')
            printf("Case #%d: YES\n",T);
        else
            printf("Case #%d: NO\n",T);
    }
    return 0;
}
