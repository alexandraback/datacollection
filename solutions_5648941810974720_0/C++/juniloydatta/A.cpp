#include<bits/stdc++.h>

#define xx first
#define yy second
#define LL long long
#define inf 100000000
#define pb push_back
#define vsort(v) sort(v.begin(),v.end())
#define pi acos(-1)
#define clr(a,b) memset(a,b,sizeof a)
#define bclr(a) memset(a,false,sizeof a)
#define pii pair<int,int>
#define MOD 1000000007
#define MP make_pair
#define MX 1005

using namespace std;
string ss[]={"ZZERO", "OONE", "WTWO", "HTHREE", "UFOUR", "FFIVE", "XSIX", "VSEVEN", "GEIGHT", "NNINE"};
int ar[33];
int res[11];

void sub(int pos){
    int id=ss[pos][0]-'A';
    int mn=ar[id];
    if(pos==9) mn/=2;
    for(int i=1;i<ss[pos].length();i++){
        ar[ss[pos][i]-'A']-=mn;
    }
    res[pos]+=mn;
}
void print(){
    for(int i=0;i<26;i++){
        for(int j=0;j<ar[i];j++)
            cout<<(char)(i+'A');
    }
    cout<<endl;
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int test; cin>>test;
    for(int kase=1;kase<=test;kase++){
        memset(ar,0,sizeof ar);
        memset(res,0,sizeof res);
        string s; cin>>s;
        for(int i=0;i<s.length();i++) ar[s[i]-'A']++;
        sub(0);
        sub(2);
        sub(4);
        sub(6);
        sub(8);
        sub(1);
        sub(5);
        sub(7);
        sub(3);
        sub(9);
        cout<<"Case #"<<kase<<": ";
        for(int i=0;i<10;i++){
            for(int j=0;j<res[i];j++)
                cout<<i;
        }
        cout<<endl;
    }
    return 0;
}

