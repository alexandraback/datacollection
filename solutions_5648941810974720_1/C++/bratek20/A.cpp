#include<bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
string S;
string god[]={
    "ZERO", "EIGHT", "TWO", "THREE", "FOUR",
    "ONE", "SIX", "SEVEN",   "FIVE", "NINE"
};
int kol[]={0,8,2,3,4,1,6,7,5,9};
void scal(vector<pair<char,int> > &cos){
    sort(cos.begin(),cos.end());
    for(int i=0;i<cos.size();i++)
        if(i+1!=cos.size() && cos[i]==cos[i+1]){
            swap(cos[i],cos.back());
            cos[i+1].s++;
            cos.pop_back();
        }
}
void solve(){
    vector<int>ile(300);
    for(int i=0;i<S.size();i++)
        ile[S[i]]++;

    vector<pair<int,int> >odp;
    for(int i=0;i<10;i++){
        string szuk=god[i];
        vector<pair<char,int> >cos;
        for(int j=0;j<szuk.size();j++)
            cos.pb(mp(szuk[j],1));

        scal(cos);
        int minn=1e9;
        for(int j=0;j<cos.size();j++)
            minn=min(ile[ cos[j].f ]/cos[j].s, minn);

        odp.pb(mp(kol[i],minn));
        for(int j=0;j<cos.size();j++)
            ile[ cos[j].f ]-=minn*cos[j].s;
    }
    sort(odp.begin(),odp.end());
    for(int i=0;i<odp.size();i++){
        int cnt=odp[i].s;
        while(cnt--)cout<<odp[i].f;
    }
    cout<<"\n";
}
int main(){
    cout.sync_with_stdio(0);
    int t; cin>>t;
    for(int test=1;test<=t;test++){
        cin>>S;
        cout<<"Case #"<<test<<": ";
        solve();
    }
    return 0;
}
