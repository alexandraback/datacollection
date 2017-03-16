#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll total,can;
int k,l,s;
int mx;
string str;
string a,b;
void dfs(int len){
    if(len ==  s){
        ++total;
        int cur = 0;
        for(int i=0;i+l<=len;i++){
            bool ok = true;
            //cout<<"iiii"<<i<<endl;
            for(int j=0;j<l;j++){
                if(str[i+j]!=b[j]){
                    ok = false;
                    //cout<<i<<" "<<j<<" "<<str[i+j]<<" "<<b[j]<<endl;
                    break;
                }
            }
            if(ok){
                //cout<<"ok"<<endl;
                ++cur;
            }
        }
        can+=cur;
        if(cur>mx)
            mx = cur;
        //acout<<str<<" "<<b<<total<<can<<endl;
        return ;
    }
    for(int i=0;i<k;i++){
        str+=a[i];
        dfs(len+1);
        str.pop_back();
    }

}
int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out_b.txt","w",stdout);


    int t;
    cin>>t;


    for(int cs=1;cs<=t;cs++){
        cin>>k>>l>>s;
        cin>>a>>b;
        total = can = 0;
        mx = 0;
        dfs(0);
        double ans = double(mx) - double(can)/double(total);


        cout<<"Case #"<<cs<<": "<<fixed<<setprecision(10)<<ans<<endl;
    }

}
