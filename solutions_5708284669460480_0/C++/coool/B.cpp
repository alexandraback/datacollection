#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
int K,l,l1,t;
string str,str1;
double ans;
pair<int,int> sol(int x,string s)
{
    if(x == l1) {
        int res = 0;
        for(int i = 0; i <= l1-l; i++) {
            if(!s.compare(i,l,str1))res++;
        }
        return make_pair(res,res);
    }
    pair<int,int> res = make_pair(0,-inf);
    for(int i = 0; i <= K-1; i++) {
        pair<int,int> tmake_pair = sol(x+1,s+str[i]);
        res.second = max(res.second,tmake_pair.second);
        res.first += tmake_pair.first;
    }
    return res;
}
 
int main()
{
	freopen("B-small-attempt2.in","r",stdin);
	freopen("output2.txt","w",stdout);
    int tc = 1;
    cin>>t;
    while(t--) {
        cin>>K>>l>>l1>>str>>str1;
        pair<int,int> res = sol(0,"");
        printf("Case #%d: ",tc++);
        ans = (double)res.second-double(res.first)/double(pow(K,l1));
        cout<<setprecision(8)<<ans<<endl;
    }
    return 0;
}
 
