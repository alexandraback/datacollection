/*
AUTHOR: THANABHAT KOOMSUBHA
LANG: C++
*/

#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<functional>
#include<vector>
#include<list>
#include<set>
#include<queue>
#include<map>
#include<cctype>
#include<cstring>
#include<string>
#include<sstream>
#include<iostream>
#include<ctime>

using namespace std;

long long XXX[16] = {
    0LL,1LL,
    9LL,19LL,
    109LL,199LL,
    1099LL,1999LL,
    10999LL,19999LL,
    109999LL,199999LL,
    1099999LL,1999999LL,
    10999999LL,19999999LL};

int solve(int cc){
    long long N,sol=0;
    scanf("%lld",&N);
    while(N%10!=1){
        N--;
        sol++;
    }
//    printf("N %lld, sol %lld\n",N,sol);

    char tmp_str[16];
    sprintf(tmp_str,"%lld",N);
    int len_tmp_str = strlen(tmp_str);
    for(int i=len_tmp_str/2;i<len_tmp_str-1;i++){
        tmp_str[i]='0';
    }
    long long tmp_ll;
    sscanf(tmp_str,"%lld",&tmp_ll);
    if(N!=tmp_ll){
        sol+=(N-tmp_ll);
        N=tmp_ll;
    }
//    printf("N %lld, sol %lld\n",N,sol);

    char tmp_str2[16];
    for(int i=len_tmp_str-1,j=0;i>=0;i--,j++){
        tmp_str2[j]=tmp_str[i];
    }
    tmp_str2[len_tmp_str]=0;
    long long tmp_ll2;
    sscanf(tmp_str2,"%lld",&tmp_ll2);
    if(N!=tmp_ll2){
        sol++;
        N=tmp_ll2;
    }
//    printf("N %lld, sol %lld\n",N,sol);

    char tmp_str3[16];
    strcpy(tmp_str3,tmp_str2);
    for(int i=1;i<len_tmp_str;i++){
        tmp_str3[i]='0';
    }
    long long tmp_ll3;
    sscanf(tmp_str3,"%lld",&tmp_ll3);
    if(N!=tmp_ll3){
        sol+=(N-tmp_ll3);
        N=tmp_ll3;
    }
//    printf("N %lld, sol %lld\n",N,sol);

    for(int i=len_tmp_str;i>=1;i--){
        sol+=XXX[i];
    }

    printf("Case #%d: %lld\n",cc,sol);

    return 1;
}

int main(){

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        solve(i);
    }

	return 0;
}
