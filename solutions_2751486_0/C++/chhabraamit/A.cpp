#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>

#define SZ(c) c.size()
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define SORT(a) sort(a.begin(),a.end())
#define tests int test; scanf("%d",&test); while(test--)
#define dbg(n) cout<<#n<<" = "<<n<<endl;

using namespace std;

int strToInt(string str) {int ans; stringstream s; s<<str; s>>ans; return ans;}
string intToStr(int n) {string str; stringstream s; s<<n; s>>str; return str;}
int MAX(int a,int b) {if(a >b) return a; return b;}
int MIN(int a,int b) {if(a <b) return a; return b;}
int ABS(int a,int b) {if(a >0) return a; return -a;}

int solve(string str, int val)
{
    int len = str.size(), ans=0;;
    for(int i=0;i<len;i++)
    {
        if((str[i]=='a')||(str[i]=='e')||(str[i]=='i')||(str[i]=='o')||(str[i]=='u'))
         ans=0;
        else
            ans++;
    if(ans >=val) return 1;
    }

    return 0;
}
int main()
{
    freopen("read.txt","r",stdin);
    freopen("write.txt","w",stdout);
    int test;
    scanf("%d",&test);
    int caseNo=0;
    while(test--)
    {
        caseNo++;
        int ans=0;
        string str;
        int val,len;
        cin>>str>>val;
        len = str.size();
        string temp="";
        for(int i=1;i<=len;i++)
        {
            for(int j=0;j<=(len-i);j++)
            {
                temp = str.substr(j,i);
                ans += solve(temp, val);
            }
        }
        printf("Case #%d: %d\n",caseNo,ans);

    }
    return 0;
}



