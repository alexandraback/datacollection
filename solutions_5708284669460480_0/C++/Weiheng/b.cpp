#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;
string key, tar;
int ans = 0;
int k,l,s;
int maxn = 0;
vector<string> vec;

void rec(string str){
    if (str.size() == s) {
        vec.push_back(str);
        return;
    }
    int i;
    for (i=0; i<k; i++) {
        rec(str+key[i]);
    }
}

int solve() 
{
    cin>>k>>l>>s;
    cin>>key>>tar;
    vec.clear();
    rec("");
    int i;
    double sum = 0;
    int maxnum = 0;
    for (i=0; i<vec.size(); i++) {
        size_t ind = 0;
        int cnt = 0;
        while( vec[i].find(tar, ind)!=string::npos) {
            ind = vec[i].find(tar, ind)+1;
            cnt += 1;
        }
        if (maxnum < cnt) maxnum = cnt;
        sum += cnt;
    }
    cout.precision(7);
    cout<<maxnum - sum/vec.size()<<endl;
    return 1;
}

int main() {
    int nc, tc;
    tc = 1;
    cin>>nc;
    while (tc<=nc) {
        cout<<"Case #"<<tc<<": ";
        solve();
        tc++;
    }
    return 0;
}
