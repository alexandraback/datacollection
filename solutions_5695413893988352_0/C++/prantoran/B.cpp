#include<bits/stdc++.h>
#define ll long long
using namespace std;

int t,lenS,lenT,pS[69],pT[69],sdx,tdx,nS[69],nT[69],mxm,ansS[69],ansT[69];
char S[69],T[69];

int findS(){
    int sum = 0;
    for(int i = 0 ; i < lenS;i++){
        sum*=10;
        sum+=nS[i];
    }
    return sum;
}

int findT(){
    int sum = 0;
    for(int i = 0 ; i < lenT;i++){
        sum*=10;
        sum+=nT[i];
    }
    return sum;
}


void dfs2(int p){
    if(p>=tdx){
        int numS = findS();
        int numT = findT();


        if(abs(numT-numS)<mxm){
            //    cout<<"\t\tnumS:"<<numS<<"\tnumT:"<<numT<<endl;
            for(int i = 0 ; i < lenS;i++){
                ansS[i]=nS[i];
            }
            for(int i = 0 ;  i < lenT;i++){
                ansT[i]=nT[i];
            }
            mxm= abs(numT-numS);
        }
        return;
    }
    for(int i = 0 ; i < 10;i++){
        nT[pT[p]]=i;
        dfs2(p+1);
    }
}

void dfs(int p){
    if(p>=sdx){
        dfs2(0);
        return;
    }
    for(int i = 0 ; i < 10;i++){
        nS[pS[p]]=i;
        dfs(p+1);
    }
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    scanf("%d ",&t);
    for(int ca=1;ca<=t;ca++){
        scanf("%s",&S);
        lenS = strlen(S);
        scanf("%s",&T);
        lenT = strlen(T);
        sdx=0,tdx=0;

        for(int i = 0 ;i<lenS;i++){
            if(S[i]=='?'){
                pS[sdx++]=i;
            }
            else nS[i]=S[i]-'0';
        }

        for(int i = 0 ;i<lenT;i++){
            if(T[i]=='?'){
                pT[tdx++]=i;
            }
            else nT[i]=T[i]-'0';
        }

//        for(int i = 0 ; i < sdx;i++)cout<<"i:"<<i<<"\tval:"<<pS[i]<<endl;
//        cout<<endl;
//        for(int i = 0 ; i < tdx;i++)cout<<"i:"<<i<<"\tval:"<<pT[i]<<endl;
//        cout<<endl;


        mxm = 1<<30;
        dfs(0);
        printf("Case #%d: ",ca);
        for(int i = 0 ; i < lenS;i++)printf("%d",ansS[i]);
        printf(" ");
        for(int i = 0 ; i < lenT;i++)printf("%d",ansT[i]);
        printf("\n");

    }


    return 0;
}
