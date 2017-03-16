#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<cmath>
#include<bitset>
#define rep(i,a,b) for(int i=a,_b=b;i<=_b;i++)
#define per(i,a,b) for(int i=a,_b=b;i>=_b;i--)
#define For(i,b) for(int i=0,_b=b;i<_b;i++)
#define upmax(a,b) if ((a)<(b)) (a)=(b)
#define upmin(a,b) if ((a)>(b)) (a)=(b)
using namespace std;

int T,c[500],a[500];
string s;

void del(string s,int k){
    For(i,s.size()) a[s[i]]-=k;
}

int main(){
//freopen("A.in","r",stdin);
//freopen("A.out","w",stdout);
    cin>>T;
    rep(ca,1,T){
        cin>>s;
        For(i,s.size()) a[s[i]]++;
        c[0]=a['Z'];
        del("ZERO",c[0]);
        c[2]=a['W'];
        del("TWO",c[2]);
        c[4]=a['U'];
        del("FOUR",c[4]);
        c[6]=a['X'];
        del("SIX",c[6]);
        c[8]=a['G'];
        del("EIGHT",c[8]);
        c[3]=a['T'];
        del("THREE",c[3]);
        c[5]=a['F'];
        del("FIVE",c[5]);
        c[7]=a['S'];
        del("SEVEN",c[7]);
        c[9]=a['I'];
        del("NINE",c[9]);
        c[1]=a['O'];
        del("ONE",c[1]);

        cout<<"Case #"<<ca<<": ";
        For(i,10) while(c[i]--) cout<<i;
        cout<<endl;
    }
}