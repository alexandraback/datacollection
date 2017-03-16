
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <time.h>
#include <assert.h>
#define lli long long int
#define pb push_back
#define mod 1000000007
#define pii pair<int,int>

using namespace std;
int n;
string str1,str2;
int ans1,ans2;
string alp1,alp2;
void check(string x,string y){
    int numx=0;
    int numy=0;
    for(int i=0;i<x.size();i++){
        numx=numx*10 + int(x[i]-'0');
        numy=numy*10 + int(y[i]-'0');
    }
    if(abs(numx-numy) < abs(ans1-ans2)){
        ans1=numx;
        ans2=numy;
        alp1=x;
        alp2=y;
    }
    else if(abs(numx-numy) == abs(ans1-ans2)){
        if(x < alp1){
            ans1=numx;
            ans2=numy;
            alp1=x;
            alp2=y;
        }
        else if(x==alp1 && y <alp2){
            ans1=numx;
            ans2=numy;
            alp1=x;
            alp2=y;
        }
    }
    return;
}

void solve(int pos,string x,string y){
    if(pos == n ){
        check(x,y);
        return;
    }
    if(str1[pos]=='?' && str2[pos]=='?'){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                string tmp1=x,tmp2=y;
                tmp1+=char(i+'0');
                tmp2+=char(j+'0');
                solve(pos+1,tmp1,tmp2);
            }
        }
    }
    else if(str1[pos]=='?' && str2[pos]!='?'){
        for(int i=0;i<10;i++){
                string tmp1=x,tmp2=y;
                tmp1+=char(i+'0');
                tmp2+=str2[pos];
                solve(pos+1,tmp1,tmp2);
        }
    }
    else if(str1[pos]!='?' && str2[pos]=='?'){
         for(int i=0;i<10;i++){
                string tmp1=x,tmp2=y;
                tmp2+=char(i+'0');
                tmp1+=str1[pos];
                solve(pos+1,tmp1,tmp2);
        }
    }
    else if(str1[pos]!='?' && str2[pos]!='?'){
                string tmp1=x,tmp2=y;
                tmp2+=str2[pos];
                tmp1+=str1[pos];
                solve(pos+1,tmp1,tmp2);
    }
    return;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t,tc=0;

    cin>>t;
    while(t--){
        ans1=0;ans2=99999;
        cin>>str1>>str2;
        n=str1.size();
        solve(0,"","");
        printf("Case #%d: ",++tc);
        cout<<alp1<<" "<<alp2<<endl;
    }
    return 0;
}

