#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<string>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;

int n,wyn,t;
vector <pair<int,string> >s;
string tmp,tmp1;

int check(){
    bool czy[26];
    for(int i=0;i<26;i++) czy[i]=0;
    int pop;
    pop=s[0].se[0]-'a';
    czy[pop]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<s[i].se.length();j++){
            //printf("%d %d %d %d %d\n",i,j,pop,czy[0],czy[1]);
            if(czy[s[i].se[j]-'a'] && pop!=s[i].se[j]-'a') return 0;
            czy[s[i].se[j]-'a']=1;
            pop=s[i].se[j]-'a';
        }
    }
    return 1;
}

int main(){
    cin>>t;
    for(int tt=1;tt<=t;tt++){
        s.clear();
        cin>>n;
        wyn=0;
        for(int i=0;i<n;i++){
            cin>>tmp;
            tmp1=tmp[0];
            for(int j=1;j<tmp.length();j++) if(tmp[j]!=tmp[j-1]) tmp1+=tmp[j]; 
            s.pb(mp(i,tmp1));
        }
        sort(s.begin(),s.end());
        do{
            wyn+=check();
        }
        while(next_permutation(s.begin(),s.end()));
        printf("Case #%d: %d\n",tt,wyn);
    }
}

