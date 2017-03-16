#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<string.h>
#include<cstring>
#include<stack>
#include<queue>
#include<cassert>
#include<cmath>
#include<unordered_map>
using namespace std;

#define LL long long int 
#define PII pair<int,int> 
#define PB push_back
#define MP make_pair
#define INF 1000000000
int dp[4005][5];
int n;
string a;
unordered_map<string,bool> pres;
//dp[i][j] = what is the minimum answer from i..n if the last character change was at -j.

int getans(int start,int prev){
    int i,j,k;
    char let, let2;
    prev = min(prev,4);
    if(start == n)
        return 0;
    if(dp[start][prev] != -1)
        return dp[start][prev];
    string cur;
    int cans = INF;
    for(i=start;i<min(start+10,n);i++){
        cur = "";
        for(j=start;j<=i;j++)
            cur += a[j];
        if(pres.count(cur) > 0)
            cans = min(cans, getans(i+1,i-start+1+prev));

        for(j=4-prev;j<=i-start;j++){
            char tmp = cur[j];
            for(let = 'a';let <= 'z';let ++){
                cur[j] = let;
                if(pres.count(cur) > 0){
                    cans = min(cans,1 + getans(i+1,i-start-j));
                }
                for(k=j+5;k<=i-start;k++){
                    char tmp2 = cur[k];
                    for(let2 = 'a';let2<='z';let2++){
                        cur[k] = let2;
                        if(pres.count(cur))
                            cans = min(cans,2 + getans(i+1,i-start-k));
                    }
                    cur[k] = tmp2;
                }
            }
            cur[j] = tmp;
        }
    }
    return dp[start][prev] = cans;
}

int main(){
    FILE *in;
    in = fopen("dict.txt","r");
    char s[30];
    while(fscanf(in," %s",s) != EOF){
        pres[s] = 1;
    }
    int t;
    scanf("%d",&t);
    while(t--){
        memset(dp,-1,sizeof(dp));
        cin >> a;
        n = a.size();
        static int ct = 0;
        printf("Case #%d: %d\n",++ct,getans(0,4));
    }
	return 0;
}

