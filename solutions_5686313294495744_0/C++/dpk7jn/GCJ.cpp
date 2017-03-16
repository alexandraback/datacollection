#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%I64d",&x)
#define fora(x,y,z) for(int x=y;x<=(z);x++)
#define PNL printf("\n")
#define FL(a,n,x) fill(a,a+n,x)
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define MOD 1000000007
#define debug(x) cout<<"here"<<x<<endl;

string arr[20][3];

int recur(int in,map<string,int> &mp1,map<string,int> &mp2,int n){
if(in==n)
    return 0;
int x=recur(in+1,mp1,mp2,n);
string s1=arr[in][0],s2=arr[in][1];
if(mp1[s1]>1 && mp2[s2]>1){
    mp1[s1]--; mp2[s2]--;
    x=max(x,1+recur(in+1,mp1,mp2,n));
    mp1[s1]++; mp2[s2]++;
}
return x;
}

int main(){
   freopen("Input.in","r",stdin);
   freopen("Output.txt","w",stdout);
   int te;
   si(te);
   int ts=0;
   while(te--){
        ts++;
    int n;
    si(n);
    fora(i,0,n-1){
    cin>>arr[i][0];
    cin>>arr[i][1];
    }
    map<string,int> mp1,mp2;
    fora(i,0,n-1){
    string s1=arr[i][0];
    string s2=arr[i][1];
    mp1[s1]++;
    mp2[s2]++;
    }
    printf("Case #%d: %d\n",ts,recur(0,mp1,mp2,n));
   }
   return 0;
}
