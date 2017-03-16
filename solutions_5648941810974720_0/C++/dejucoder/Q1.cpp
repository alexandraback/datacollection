#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define pb(v,x) v.push_back(x)
#define REP(i,n) for(i=0;i<n;i++)
using namespace std;
int main()
{
    int t;
    FILE * fp1 , * fp2;
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    fscanf(fp1,"%d",&t);
    for(int test=1;test<=t;test++){
        char s[2001];
        fscanf(fp1,"%s",s);
        int f[10],f2[26],i,j;
        int n = strlen(s);
        REP(i,26) f2[i]=0;
        REP(i,n) f2[s[i]-'A']++;
        f[2]=f2[22];f[0]=f2[25];f[4]=f2[20];f[6]=f2[23];f[8]=f2[6];f[3]=f2[19]-f[2]-f[8];
        f[1]=f2[14]-f[2]-f[0]-f[4];f[5]=f2[5]-f[4];
        f[7]=f2[18]-f[6];f[9]=f2[8]-f[6]-f[5]-f[8];
        fprintf(fp2,"Case #%d: ",test);
        for(i=0;i<=9;i++){
            for(j=0;j<f[i];j++) fprintf(fp2,"%d",i);
        }
        fprintf(fp2,"\n");
//        fprintf(fp2,"Case #%d: %d\n",test,ans);
    }
    return 0;
}
