#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<math.h>
#define MOD 1000000007
using namespace std;
int T,N,ret,a[11];
char x[11],y[11];
string s[11];
bool v[11],viz[26], dr[26], st[26];

void backy(int k)
{
    if(k==N) {

        string t;
        for(int i=1;i<=N;++i) {
            t = t+s[a[i]];
        }

        for(int i=0;i<26;++i) {
            viz[i]=0;
        }

        bool ok = 1;
        viz[t[0]-'a']=1;
        for(int i=1;i<t.size();++i) {
            if(t[i]!=t[i-1]) {
                if(viz[t[i]-'a']) {
                    ok =0;
                }
                viz[t[i]-'a']=1;
            }
        }
        if(ok==1) {
            ++ret;
        }
        return;
    }

    for(int i=1;i<=N;++i) {
        if(v[i]==0 && (k==0 || y[a[k]]==x[i] || dr[x[i]-'a']==0 || st[y[a[k]]-'a']==0)) {
            a[k+1]=i;
            v[i]=1;
            backy(k+1);
            v[i]=0;
        }
    }
}


int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    scanf("%d",&T);
    for(int t=1;t<=T;++t) {
        ret = 0;
        for(int i=0;i<26;++i) {
            dr[i]=0;
            st[i]=0;
        }
        for(int i=1;i<=10;++i) {
            v[i]=0;
        }
        printf("Case #%d: ",t);
        scanf("%d",&N);
        for(int i=1;i<=N;++i) {
            cin>>s[i];
            x[i]=s[i][0];
            y[i]=s[i][s[i].size()-1];
            if(x[i]!=y[i]) {
                st[x[i]-'a']=1;
                dr[y[i]-'a']=1;
            }
        }
        backy(0);
        printf("%d\n",ret);
    }
    return 0;
}


