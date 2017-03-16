#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

#define rep(i,n) for (int i=1;i<=(n);++i)
#define rep2(i,x,y) for (int i=(x);i<=(y);++i)
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VII;

void MAIN()
{
    int n;
    string s;
    cin>>s;
    char cur=s[0]; int cnt=1;
    rep(i,s.length()-1)
    {
        if (s[i]!=cur){
            cur=s[i];
            ++cnt;
        }
    }
    if (cur=='+') --cnt;
    cout << cnt<<endl;
};

int main() {
    //freopen("C:\\Users\\Administrator\\ClionProjects\\gcj\\B-small-attempt0.in","r",stdin);
    //freopen("C:\\Users\\Administrator\\ClionProjects\\gcj\\B-small-attempt0.out","w",stdout);
    int tt;
    scanf("%d",&tt);
    rep(i,tt)
    {
        printf("Case #%d: ",i);
        MAIN();
    }
    return 0;
}