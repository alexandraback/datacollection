#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

#define LL long long
#define LD long double

#define VI vector<int>

#define sd(x) scanf("%d",&x)

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define PI pair< int , int >
#define PP pair< PI , PI >

int i,j,k,len,d[100],l[100]={0},m,h,ml=0,testnum=0;
string s[51][600000],st;
char in[100];

inline void solve(){
    cin>>st;
    len=st.length();
    d[len]=0;
    for(i=len-1;i>=0;i--){
        d[i]=d[i+1]+1;
        for(j=i;j<len;j++){
            for(k=0;k<l[j-i+1];k++){
                m=d[j+1];
                for(h=0;h<j-i+1;h++){
                    if(st[i+h]!=s[j-i+1][k][h])
                        m++;
                }
                if(m<d[i]){
                    d[i]=m;
                }
            }
        }
    }
    printf("Case #%d: %d\n",testnum,d[0]);
}

int main(){
    freopen("dict.txt","r",stdin);
    while(scanf("%s",in)!=EOF){
        st=in;
        if(st.length()>ml){
            ml=st.length();
        }
        s[st.length()][l[st.length()]++]=in;
    }
    freopen("C-small-attempt3.in","r",stdin);
    freopen("r1bpcs1.txt","w",stdout);
    int t;
    sd(t);
    while(t--){
        testnum++;
        solve();
    }
    return 0;
}
