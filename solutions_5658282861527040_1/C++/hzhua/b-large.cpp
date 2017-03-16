#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
long long bitA[50],bitB[50],bitK[50];

long long maxLen;
long long calced[50][2][2][2];
long long dp[50][2][2][2];
void transBit(long long num ,long long *arr){
    long long len = 0;
    while(num){
        arr[len++] = (num&1);
        num>>=1;
    }
    maxLen = max(maxLen, len);
}
long long calc(long long pos, long long bA, long long bB,long long bK){
    if(pos == maxLen){
        if(bA || bB || bK) return 0;
        return 1;
    }
    if(calced[pos][bA][bB][bK]) return dp[pos][bA][bB][bK];

    long long ret = 0;

    for(long long aK = 0; aK <=1; aK++){
        bool bowA = (bA && (bitA[pos] == 0));
        bool bowB = (bB && (bitB[pos] == 0));
        bool bowK = (bK && (bitK[pos] == 0));
        if(aK == 0){
            ret += calc(pos+1,bowA, bowB, bowK);//00
            ret += calc(pos+1,bowA || (bA && (bitA[pos]==1)) || (bitA[pos] == 0), bowB, bowK); //10
            ret += calc(pos+1,bowA, bowB  || (bB && (bitB[pos]==1)) || (bitB[pos] == 0), bowK); //01
        }else{
            ret += calc(pos+1,
                        bowA || (bA && (bitA[pos]==1)) || (bitA[pos] == 0),
                        bowB  || (bB && (bitB[pos]==1)) || (bitB[pos] == 0),
                        bowK || (bK && (bitK[pos] ==1) || (bitK[pos] == 0))); //11
        }
    }
    calced[pos][bA][bB][bK] = 1;
    return dp[pos][bA][bB][bK] = ret;
}
long long calced2[50][2];
long long dp2[50][2];
long long calc2(long long pos, long long bK){
    if(pos == maxLen){
        if(bK) return 0;
        return 1;
    }
    if(calced2[pos][bK]) return dp2[pos][bK];

    long long ans = 0;
    bool bowK = (bK && (bitK[pos] == 0));
    //aK = 0
    bool exist =false;
    for(long long rA = 0 ;rA <=1 && exist == false;rA++)
    for(long long rB= 0 ;rB <=1;rB++){
        long long t = calc(pos,rA,rB,bowK);
        if(t > 0){
            exist = true;
            break;
        }
    }
    if(exist){
        ans += calc2(pos+1,bowK);
    }
    //aK = 1;
    bowK = (bowK || (bK && (bitK[pos] ==1) || (bitK[pos] == 0)));

    exist =false;
    for(long long rA = 0 ;rA <=1 && exist == false;rA++)
    for(long long rB= 0 ;rB <=1;rB++){
        long long t = calc(pos,rA,rB,bowK);
        if(t > 0){
            exist = true;
            break;
        }
    }
    if(exist){
        ans += calc2(pos+1,bowK);
    }

    calced2[pos][bK] = true;
    return dp2[pos][bK] = ans;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int _ = 1; _<=T; _++)
    {
        printf("Case #%d: ",_);
        int A,B,K;
        scanf("%d%d%d",&A,&B,&K);
        A--;B--;K--;

        memset(bitA,0,sizeof(bitA));
        memset(bitB,0,sizeof(bitB));
        memset(bitK,0,sizeof(bitK));
        memset(calced,0,sizeof(calced));
        memset(calced2,0,sizeof(calced2));
        maxLen = 0;

        transBit(A,bitA);
        transBit(B,bitB);
        transBit(K,bitK);

        //long long ans = calc2(0,0);
        long long ans = calc(0,0,0,0);

        cout << ans <<endl;
    }
}

