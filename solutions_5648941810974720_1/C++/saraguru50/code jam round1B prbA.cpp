#include<iostream>
#include<algorithm>
#include<string.h>
#include<cmath>
#include<cstdio>

using namespace std;

int main(){

    freopen("gcj_round1B_prbA_input.txt","r",stdin);
    freopen("gcj_round1B_prbA_output.txt","w",stdout);

    int t,l;
    cin>>t;
    for(l=1;l<=t;l++){
        string s;
        cin>>s;
        long long len,a[28]={0},i,ans[15]={0};
        len=s.length();
        for(i=0;i<len;i++){
            a[s[i]-'A']++;
        }
        ans[0]+=a['Z'-'A'];
        a['O'-'A']-=ans[0];
        if(a['U'-'A']>0)
        ans[4]+=a['U'-'A'];
        a['F'-'A']-=ans[4];
        a['O'-'A']-=ans[4];
        if(a['F'-'A']>0)
        ans[5]+=a['F'-'A'];
        a['V'-'A']-=ans[5];
        if(a['V'-'A']>0)
        ans[7]+=a['V'-'A'];
        if(a['X'-'A']>0)
        ans[6]+=a['X'-'A'];
        if(a['W'-'A']>0)
        ans[2]+=a['W'-'A'];
        a['O'-'A']-=ans[2];
        if(a['O'-'A']>0)
        ans[1]+=a['O'-'A'];
        a['N'-'A']-=ans[7];
        a['N'-'A']-=ans[1];
        if(a['N'-'A']>0)
        ans[9]+=a['N'-'A'];
        ans[9]/=2;
        if(a['G'-'A']>0)
        ans[8]+=a['G'-'A'];
        a['H'-'A']-=ans[8];
        if(a['H'-'A']>0)
        ans[3]+=a['H'-'A'];




        cout<<"Case #"<<l<<": ";
        for(i=0;i<10;i++){
            while(ans[i]>0){ans[i]--;cout<<i;}
        }
        cout<<"\n";
    }

    return 0;






}
