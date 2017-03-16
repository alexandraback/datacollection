#include<stdio.h>
#include<string.h>
#include<vector>
#include<stack>
using namespace std;

#define maxm 1010
#define ii __int64

ii lim;
vector<ii>ans;

void gen();
int chck(ii num);

int main(){

    int i,j,test,t=1;
    ii k,l;

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    gen();

    scanf("%d",&test);

    while(test--){

        scanf("%I64d %I64d",&k,&l);
        int now=0;
        for(i=0;i<ans.size();i++){
            if(ans[i]>=k && ans[i]<=l) now++;
        }
        printf("Case #%d: %d\n",t++,now);

    }


    return 0;
}

void gen(){

    ii i,j;

    lim=2001002+10;

    for(i=1;i<=lim;i++){
        j=i*i;

        if(!chck(i)) continue;
        if(chck(j)) ans.push_back(j);
        else continue;

        //printf("i= %I64d j= %I64d\n",i,j);
    }
}

int chck(ii num){

    int i,j,k,l;
    stack<int>st;

    ii n=num;
    while(n){
        st.push(n%(ii)10);
        n/=(ii)10;
    }
    n=num;
    while(n){
        j=n%(ii)10;
        if(j!=st.top()) return 0;
        st.pop();
        n/=(ii)10;
    }
    return 1;
}

