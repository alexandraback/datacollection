#include <stdio.h>
#include <string.h>

int T,c,N,coder[20],jammer[20],cscore[20],jscore[20],dif;
char S[40],C[20],J[20];

int convc(){
    int m = 1;
    int ans = 0;
    int i;
    for(i=N-1;i>=0;i--){
        ans += coder[i]*m;
        m*=10;
    }
    return ans;
}
int convj(){
    int m = 1;
    int ans = 0;
    int i;
    for(i=N-1;i>=0;i--){
        ans += jammer[i]*m;
        m*=10;
    }
    return ans;
}

int absolute(int x){
    if (x<0)
        return (-1)*x;
    else return x;
}

void dfs(int p){
    if(p==N){
        int cs = convc();
        int js = convj();
        //printf("%d %d\n",cs,js);
        if(absolute(cs-js) < dif){
            for(int i=0;i<N;i++)
                cscore[i] = coder[i];
            for(int i=0;i<N;i++)
                jscore[i] = jammer[i];
            dif = absolute(cs-js);
        }
    }
    else{
        int i,j;
        for(i=0;i<10;i++) {
            for(j=0;j<10;j++){
                if(C[p] != '?')
                    coder[p] = C[p]-'0';
                else
                    coder[p] = i;
                if(J[p] != '?')
                    jammer[p] = J[p]-'0';
                else
                    jammer[p] = j;

                dfs(p+1);

                if(J[p] != '?')
                    break;
            }
            if(C[p] != '?')
                break;
        }
    }
}

int main()
{
    scanf("%d\n",&T);
    int i,mode;
    for(c=1;c<=T;c++){
        gets(S);
        for(i=0;i<strlen(S);i++){
            if(S[i] == ' '){
                N = i;
                break;
            }
        }
        dif = 1000000;
        for(i=0;i<N;i++)
            C[i] = S[i];
        for(i=N+1;i<(2*N)+1;i++)
            J[i-N-1] = S[i];
        dfs(0);
        printf("Case #%d: ",c);
        for(i=0;i<N;i++)
            printf("%d",cscore[i]);
        printf(" ");
        for(i=0;i<N;i++)
            printf("%d",jscore[i]);
        printf("\n");
    }

    return 0;
}
