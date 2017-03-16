#include<iostream>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<sstream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<functional>
#include<numeric>
#include<utility>
#include<cstdlib>
#include<cstring>
#include<ctime>
using namespace std;

const int MAXN = 10005;

void print(int num, int a) {
    for (int i = 0; i < num; i++) {
        cout<<a;
    }
}
int main() {
    int i,j,t,h,Case = 1;
    string s;
    
    cin>>t;
    while(t--)
    {
        cin>>s;
        vector<int> a(26,0);
        vector<int> count(10, 0);
        for(int i = 0; i < s.size(); i++) {
            a[s[i]-'A']++;
        }
        
        cout<<"Case #"<<Case++<<": ";
        
        count[0] = a['Z'-'A'];
        a['Z'-'A'] -= count[0];
        a['E'-'A'] -= count[0];
        a['R'-'A'] -= count[0];
        a['O'-'A'] -= count[0];
        
        count[2] = a['W' - 'A'];
        a['W' - 'A'] -= count[2];
        a['T' - 'A'] -= count[2];
        a['O' - 'A'] -= count[2];
        
        count[4] = a['U' - 'A'];
        a['F'-'A'] -= count[4];
        a['O'-'A'] -= count[4];
        a['U'-'A'] -= count[4];
        a['R'-'A'] -= count[4];
        
        count[1] = a['O' - 'A'];
        a['O'-'A'] -= count[1];
        a['N'-'A'] -= count[1];
        a['E'-'A'] -= count[1];
        
        count[5] = a['V' - 'A'];
        a['F'-'A'] -= count[5];
        a['I'-'A'] -= count[5];
        a['V'-'A'] -= count[5];
        a['E'-'A'] -= count[5];
        
        count[6] = a['X' - 'A'];
        a['S'-'A'] -= count[6];
        a['I'-'A'] -= count[6];
        a['X'-'A'] -= count[6];
        
        count[7] = a['S' - 'A'];
        a['S'-'A'] -= count[7];
        a['E'-'A'] -= count[7];
        a['V'-'A'] -= count[7];
        a['E'-'A'] -= count[7];
        a['N'-'A'] -= count[7];
        
        count[9] = (a['N' - 'A'])/2;
        a['N'-'A'] -= count[9];
        a['I'-'A'] -= count[9];
        a['N'-'A'] -= count[9];
        a['E'-'A'] -= count[9];
        
        count[8] = a['G' - 'A'];
        a['E'-'A'] -= count[8];
        a['I'-'A'] -= count[8];
        a['G'-'A'] -= count[8];
        a['H'-'A'] -= count[8];
        a['T'-'A'] -= count[8];
        
        count[3] = a['R' - 'A'];
        a['T'-'A'] -= count[3];
        a['H'-'A'] -= count[3];
        a['R'-'A'] -= count[3];
        a['E'-'A'] -= count[3];
        a['E'-'A'] -= count[3];
        
        for(int i = 0; i < 10; i++) {
            if (count[i] > 0) {
                for (int j = 0; j < count[i]; j++)
                    cout<<i;
            }
        }
        cout<<endl;
        
        
        
        

    }
    return 0;
}
