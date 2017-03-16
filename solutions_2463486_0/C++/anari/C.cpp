#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int sum[150];
int d[150];
int l;
bool add(int i, int D){
    bool violation=false;
    for (int j=0;j<l;++j)
        if (d[j]!=-1){
            sum[j+i]+=2*D*d[j];
            if (sum[j+i]>=10)
                violation=true;
        }
    sum[i+i]+=D*D;
    if (sum[i+i]>=10)
        violation=true;
    d[i]=D;
    return violation;
}
vector<string> answers;
void solve(int i=0){
    if (i>=(l+1)/2){
        string t="";
        for (int j=149;j>=0;--j)
            t+=string(1,'0'+sum[j]);
        answers.push_back(t);
        return;
    }
    int j=l-i-1;
    for (int D=(i==0?1:0);D<=9;++D){
        bool violation=false;
        violation|=add(i, D);
        d[i]=D;
        if (j!=i){
            violation|=add(j, D);
            d[j]=D;
        }
        if (!violation){
            solve(i+1);
        }
        if (j!=i){
            add(j, -D);
            d[j]=-1;
        }
        add(i, -D);
        d[i]=-1;
    }
}
string fix(string s){
    return string(150-s.size(),'0')+s;
}
int main(){
    for (l=1;l<=51;++l){
        for (int i=0;i<150;++i){
            sum[i]=0;
            d[i]=-1;
        }
        solve();
    }
    sort(answers.begin(), answers.end());
    answers.resize(unique(answers.begin(), answers.end())-answers.begin());
    int tnum;cin>>tnum;
    int tcou=0;
    while (tnum--){
        string a, b;
        cin>>a>>b;
        a=fix(a);
        b=fix(b);
        int ans=upper_bound(answers.begin(), answers.end(), b)-lower_bound(answers.begin(), answers.end(), a);
        cout<<"Case #"<<++tcou<<": "<<ans<<endl;
    }
    return 0;
}
