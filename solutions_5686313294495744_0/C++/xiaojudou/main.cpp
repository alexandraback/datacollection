#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<vector>
#include<fstream>
#define eps 1e-5
#define mod 1000000007
using namespace std;
int t,n;

map<string,int>fake,sf,ss;
string s1,s2;
string w1[20],w2[20];
int main(){
    freopen("C-small-attempt0.in-2.txt","r",stdin);
    freopen("c.out","w",stdout);

    cin>>t;
    for(int _=1;_<=t;++_){
        cin>>n;
        fake.clear();sf.clear();ss.clear();
        for(int i=0;i<n;++i)
        {
            cin>>s1>>s2;
            w1[i]=s1;
            w2[i]=s2;
            sf[s1]=1;
            ss[s2]=1;
            s1+=" "+s2;
            fake[s1]=1;
        }
        int ans=0;
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
            {
                s1=w1[i]+" "+w2[j];
                if(fake[s1]==0 && sf[w2[j]]==0 && ss[w1[i]]==0)
                    ans++;
            }
        cout<<"Case #"<<_<<": "<<ans;

                cout<<endl;
    }
    return 0;
}