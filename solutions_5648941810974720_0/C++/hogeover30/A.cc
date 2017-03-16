#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int T; cin>>T;
    for(int t=1; t<=T; ++t) {
        string s; cin>>s;
        vector<int> cnt(128);
        for(c: s) cnt[c]++;

        vector<int> res(10);
        { int x=cnt['Z']; res[0]+=x; for(c: "ZERO") cnt[c]-=x; }
        { int x=cnt['W']; res[2]+=x; for(c: "TWO") cnt[c]-=x; }
        { int x=cnt['X']; res[6]+=x; for(c: "SIX") cnt[c]-=x; }
        { int x=cnt['G']; res[8]+=x; for(c: "EIGHT") cnt[c]-=x; }
        { int x=cnt['T']; res[3]+=x; for(c: "THREE") cnt[c]-=x; }
        { int x=cnt['R']; res[4]+=x; for(c: "FOUR") cnt[c]-=x; }
        { int x=cnt['F']; res[5]+=x; for(c: "FIVE") cnt[c]-=x; }
        { int x=cnt['V']; res[7]+=x; for(c: "SEVEN") cnt[c]-=x; }
        { int x=cnt['O']; res[1]+=x; for(c: "ONE") cnt[c]-=x; }
        { int x=cnt['I']; res[9]+=x; for(c: "NINE") cnt[c]-=x; }

        cout<<"Case #"<<t<<": ";
        for(int i=0; i<10; ++i)
            for(int j=0; j<res[i]; ++j) cout<<i;
        cout<<endl;
    }
}
