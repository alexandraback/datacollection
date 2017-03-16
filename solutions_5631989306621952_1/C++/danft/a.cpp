#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef vector<bool> vb;

map<string, string> dp;

string f(string s) {
    if(s.size()==1)
        return s;
    if(dp.count(s))
        return dp[s];
    string ret=s;
    for(int i=1;i<s.size();i++) {
        string s1=s.substr(0,i); 
        //cout<<s1<<"!\n";
        string s2="";
        s2.pb(s[i]);
        s1=f(s1);
        s2+=s1;
        s2+=(s.substr(i+1, s.size()-i));
        ret=max(ret, s2);
    }
    dp[s]=ret;
    return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
    int T;
    cin>>T;
    for(int tt=0;tt<T;tt++) {
        string s;
        dp.clear();
        cin>>s;
        //s.clear();
        //for(int i=0;i<1000;i++)
         //   s.pb(rand()%26+'a');
        cout<<"Case #" << 1+tt<<": ";
        cout<<f(s)<<endl;
    }
	
	
	return 0;
}
