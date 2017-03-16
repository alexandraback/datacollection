#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define pb(v,x) v.push_back(x)
#define REP(i,n) for(i=0;i<n;i++)
using namespace std;
string to_string(int x,int n)
{
    string s = bitset<18>(x).to_string();
    string s1="";
    for(int i=0;i<n;i++) s1 += s[i + 18-n];
    return s1;
}
int cal(char first[][21] , char second[][21] , int index , int n){
    string s = to_string(index,n);
    int counter=0,i,j;
    REP(i,n) if(s[i]=='0'){
        int f1=0,f2=0;
        counter++;
        REP(j,n) if(s[j]=='1'){
            if(strcmp(first[i],first[j])==0) f1=1;
            if(strcmp(second[i],second[j])==0) f2=1;
        }
        if(f1!=1 or f2!=1) break;
    }
    if(i==n) return counter;
    else return 0;
}
int main()
{
    cout<<to_string(7,5);
    int t;
    FILE * fp1 , * fp2;
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    fscanf(fp1,"%d",&t);
    for(int test=1;test<=t;test++){
        int n,i;
        fscanf(fp1,"%d",&n);
        char first[n][21],second[n][21];
        REP(i,n) fscanf(fp1,"%s %s",first[i],second[i]);
        int x = pow(2,n),ans=0;
        for(i=0;i<=x;i++){
            ans = max(ans , cal(first,second,i,n));
        }
        fprintf(fp2,"Case #%d: %d\n",test,ans);
    }
    return 0;
}
