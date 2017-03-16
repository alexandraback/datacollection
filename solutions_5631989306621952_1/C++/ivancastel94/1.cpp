#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int i,t,cases,mi,can;
    string s,res;
    cin>>cases;
    for(t=1;t<=cases;t++){
        cin>>s;
        vector< pair<int, char> > res;
        res.push_back(make_pair(0,s[0]));
        mi=0;
        can=1;
        for(i=1;i<s.length();i++){
            if(s[i]>=s[mi]){
                res.push_back(make_pair(res[mi].first - 1 , s[i]));
                mi=i;
            }
            else{
                res.push_back(make_pair(can, s[i]));
                can++;
            }
        }
        sort(res.begin(), res.end());
        cout<<"Case #"<<t<<": ";
        for(i=0;i<res.size();i++){
            cout<<res[i].second;
        }
        cout<<endl;
    }
}
