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
using namespace std;

#define LL long long int 
#define PII pair<int,int> 
#define PB push_back
#define MP make_pair
#define INF 1000000000
char inp[140];
LL cpow[1000];
LL chk(LL a){
    sprintf(inp,"%Ld",a);
    string s,g;
    s.assign(inp);
    g = s;
    reverse(g.begin(),g.end());
    return (g==s)*a;
}
LL chkpalin(int num,int digs){
    int p1,p2,cdig;
    p2 = digs-1;
    p1 = 0;
    LL cnum = 0;
    while(p1<=p2){
        cdig = num%10;
        num/=10;
        cnum += cdig * cpow[p1];
        if(p1 != p2)
            cnum +=  cdig*cpow[p2];
        p1 ++;
        p2 --;
    }
    return chk(cnum*cnum);
}
int main(){
    int t,i,dig,lim,j;
    LL n;
    scanf("%d",&t);
    cpow[0] = 1;
    for(i=1;i<=15;i++)
        cpow[i] = cpow[i-1]*10;
    vector<LL> v;
    for(dig=1;dig<=9;dig++){
        lim = pow(10,(dig+1)/2);
        for(j=1;j<lim;j++){
            LL x;
            if(x=chkpalin(j,dig)){
                v.PB(x);
        //        cout<<x<<endl;
            }
        }
    }
    sort(v.begin(),v.end());
    LL a,b;
    int ct = 0;
    while(t--){
        printf("Case #%d: ",++ct);
        scanf("%Ld %Ld",&a,&b);
        cout<<(upper_bound(v.begin(),v.end(),b) - upper_bound(v.begin(),v.end(),a-1))<<endl;
    }

	return 0;
}

