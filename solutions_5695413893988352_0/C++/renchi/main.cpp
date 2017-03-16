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

int result;
string s3,s4;
void dfs(string a, string b, int i) {
    if (i >= a.size()) {
        if (result > abs(atoi(a.c_str()) - atoi(b.c_str()))) {
            result = abs(atoi(a.c_str()) - atoi(b.c_str()));
            s3 = a;
            s4 = b;
        }
        return;
    }
    if(a[i] == '?' && b[i] == '?') {
        for(int j = '0'; j <= '9'; j++) {
            for (int k = '0'; k <= '9'; k++) {
                a[i] = j;
                b[i] = k;
                dfs(a, b, i+1);
            }
        }
    } else if (a[i] == '?') {
        for(int j = '0'; j <= '9'; j++) {
            a[i] = j;
            dfs(a, b, i+1);
        }
    } else if (b[i] == '?') {
        for(int j = '0'; j <= '9'; j++) {
            b[i] = j;
            dfs(a, b, i+1);
        }
    } else {
        dfs(a, b, i+1);
    }
    
}

int main() {
    int i,j,t,h,Case = 1;
    string s1,s2;
    
    cin>>t;
    while(t--)
    {
        cin>>s1>>s2;
        result = MAXN;
        dfs(s1, s2, 0);
        
        cout<<"Case #"<<Case++<<": "<<s3<<" "<<s4<<endl;

    }
    return 0;
}
