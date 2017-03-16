#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include<set>
#include<stack>
#include<map>
#include<ctime>
#include<bitset>
#define LL long  long
#define db double
#define EPS 1e-15
#define inf 1e10

using namespace std;

void put(vector<int> &q,int n){
    vector<int> tmp(n);
    for (int i=0;i<n;i++)
        tmp[i]=q[i];
    for (int i=0;i<n;i++)
        q[i]=1-tmp[n-i-1];
}
int main(){
    freopen("1.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T,cas=1;
    scanf("%d",&T);
    while (T--){
        string s;
        cin>>s;
        vector<int>q(s.length());
        int n=s.length();
        for (int i=0;i<n;i++){
            if (s[i]=='+') q[i]=1;
            else q[i]=0;
        }
        int sum=0;
        for (int i=0;i<n;i++)
            sum+=q[i];
        int i;
        for (i=0;;i++){
            int j;
            bool flag=1;
            for (j=0;j<n;j++)
                if (q[j]==0) flag=0;
            if (flag) break;
            for (j=1;j<n;j++)
                if (q[j]!=q[0]) break;
            put(q,j);
        }
        printf("Case #%d: %d\n",cas++,i);
    }
    return 0;
}
