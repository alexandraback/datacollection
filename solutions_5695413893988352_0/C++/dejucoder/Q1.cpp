#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define pb(v,x) v.push_back(x)
#define REP(i,n) for(i=0;i<n;i++)
using namespace std;
int C[1001],D[1001];
vector<string> A,B;
vector<string> rec(string s , int i , int n)
{
    vector<string> B;
    int j,k;
    if(i==n-1){
        if(s[i]!='?'){
            string x = "";x += s[i];
            pb(B,x);
            return B;
        }
        for(j=0;j<=9;j++){
            string x="";x+=(j+'0');pb(B,x);
        }
        return B;
    }
    if(s[i]!='?'){
        vector<string> A = rec(s,i+1,n);
        REP(j,A.size()) pb(B,s[i]+A[j]);
        A.erase(A.begin(),A.end());
        return B;
    }
    vector<string> A = rec(s,i+1,n);
    for(j=0;j<=9;j++){
        REP(k,A.size()){
            string x = "";x += (j+'0');x+=A[k];
            pb(B,x);
        }
    }
    A.erase(A.begin(),A.end());
    return B;
}
int main()
{
    int t;
    FILE * fp1 , * fp2;
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    fscanf(fp1,"%d",&t);
    for(int test=1;test<=t;test++){
        char a[19],b[19];
        fscanf(fp1,"%s %s",a,b);
        int n=strlen(a),x=0,y=0,i,j;
        A = rec(a,0,n);
        B = rec(b,0,n);
        x=A.size();y=B.size();
        REP(i,x){
            stringstream convert(A[i]);
            convert>>C[i];
        }
        REP(i,y){
            stringstream convert(B[i]);
            convert>>D[i];
        }
        int coder=C[0],jammer=D[0],ans=abs(C[0]-D[0]);
        string deju1=A[0],deju2=B[0];
        REP(i,x) REP(j,y){
            if(abs(C[i]-D[j])<ans){
                coder=C[i];jammer=D[j];ans=abs(C[i]-D[j]);
                deju1=A[i];deju2=B[j];
            }
            else if(abs(C[i]-D[j])==ans){
                if(C[i]<coder){
                    coder=C[i];jammer=D[j];
                    deju1=A[i];deju2=B[j];
                }
                else if(C[i]==coder and D[j]<jammer){
                    coder=C[i];jammer=D[j];
                    deju1=A[i];deju2=B[j];
                }
            }
        }

        fprintf(fp2,"Case #%d: ",test);
        REP(i,n) fprintf(fp2,"%c",deju1[i]);
        fprintf(fp2," ");
        REP(i,n) fprintf(fp2,"%c",deju2[i]);
        fprintf(fp2,"\n");
        //A.clear();B.clear();
    }
    return 0;
}
