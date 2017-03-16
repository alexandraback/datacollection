#include<stdio.h>
#include<string.h>
#include<vector>
#include<stack>
using namespace std;

#define maxm 1010
#define maxn 1003

int c[maxm];
void gen();
int chck(int num);

int main(){

    int i,j,k,l,test,t=1;

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    gen();

    scanf("%d",&test);

    while(test--){

        scanf("%d %d",&k,&l);
        printf("Case #%d: %d\n",t++,c[l]-c[k-1]);

    }


    return 0;
}

void gen(){

    int i,j;

    for(i=1;i<=maxn;i++){
        if(!chck(i)) continue;
        j=i*i;
        if(j>maxn) break;
        //printf("i= %d\n",i);
        if(chck(j)) c[j]++;
        else continue;
        //printf("i= %d j= %d\n",i,j);
    }
    for(i=1;i<=maxn;i++){
        if(c[i])c[i]=c[i-1]+1;
        else c[i]=c[i-1];
    }
}

int chck(int num){

    int i,j,k,l;
    stack<int>st;

    int n=num;
    while(n){
        st.push(n%10);
        n/=10;
    }
    n=num;
    while(n){
        j=n%10;
        if(j!=st.top()) return 0;
        st.pop();
        n/=10;
    }
    return 1;
}
