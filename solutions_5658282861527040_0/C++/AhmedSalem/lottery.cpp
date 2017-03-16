#include<bits/stdc++.h>
using namespace std ;

#define LESS 0
#define EQUAL 1
#define MORE 2

long long best[40][3][3][3];
vector<int> A,B,K;
int L;

int getCmp(int oldCmp,int orgDig,int newDig){
    if (oldCmp != EQUAL)return oldCmp;
    if (newDig > orgDig)return MORE;
    if (newDig < orgDig)return LESS;
    return EQUAL;
}

long long solve(int ind,int cmpA,int cmpB,int cmpK){
    if (ind == L) return cmpA == LESS && cmpB == LESS && cmpK == LESS;
    long long& ret = best[ind][cmpA][cmpB][cmpK];
    if (~ret)return ret;
    ret = 0;
    for (int a=0;a<2;a++)
        for (int b=0;b<2;b++)
            ret += solve(ind + 1, getCmp(cmpA,A[ind],a), getCmp(cmpB,B[ind],b), getCmp(cmpK,K[ind],a&b));
    return ret;
}


void digitize(int num,vector<int>& ret,int radix = 10){
    ret.clear();
    while (num){
        ret.push_back(num%radix);
        num /= radix;
    }
    return ;
}
void padZeros(vector<int>& ret,int L){
    int zeros = L - ret.size();
    for (int c=0;c<zeros;c++)
        ret.push_back(0);
    return ;
}
void print(vector<int> &ret){
    for (int c=0;c<ret.size();c++)
        printf("%d",ret[c]);
    printf("\n");
    
}


int main(){
    freopen("lottery.in","r",stdin);
    freopen("lottery.out","w",stdout);
    int c,c2;
    int a,b,k;
    int tests;
    scanf("%d",&tests);
    for (int test=1;test<=tests;test++){
        scanf("%d%d%d",&a,&b,&k);
        digitize(a,A,2);  digitize(b,B,2);  digitize(k,K,2);
        L = max(A.size(),max(B.size(),K.size()));
        padZeros(A,L);  padZeros(B,L);  padZeros(K,L);
        reverse(A.begin(),A.end());     reverse(B.begin(),B.end());     reverse(K.begin(),K.end());
        
        printf("Case #%d: ",test);
        
        memset(best,-1,sizeof(best));
        long long ret = solve(0,EQUAL,EQUAL,EQUAL);
        cout << ret << endl;
        
    }
    
    
    return 0;
}
