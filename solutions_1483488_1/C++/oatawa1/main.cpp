#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<deque>
#include<set>
#include<string>
#include<sstream>

using namespace std;
#define pii pair<int , int>
#define vii vector<pii >

#define FOR(i , a , b) for(__typeof(b)i=a;i<b;i++)
#define FORE(i , a , b) for(__typeof(b)i=a;i<=b;i++)
#define FOR_INV(i , a , b) for(__typeof(b)i=a;i>b;i--)
#define FORE_INV(i , a , b) for(__typeof(b)i=a;i>=b;i--)
#define TR(it , c) for(__typeof((c).end())it = (c).begin();it != (c).end();it++)

int tCase,a,b;
int ans;
int chk(int p)
{
    stringstream ss;
    ss << p;
    set<int> set_re ;
    unsigned long size = ss.str().size();
    string s = ss.str()+ss.str(); 
//    cout << s << endl;
    set_re.clear();
    FOR(i,0,size)
    {
        stringstream ss(s.substr(i,size));
        int tmp;
        ss >> tmp;
        if(tmp >= a && tmp <= b && tmp > p)
        {
            set_re.insert(tmp);
        }
    }
    return (int)set_re.size();
}
int main()
{
    freopen("C-large.in","r",stdin);
    freopen("out.out","w",stdout);
    //    scanf("%[^\n]%*[\n]",&in);
    scanf("%d",&tCase);
    FORE(tt , 1 , tCase)
    {
        scanf("%d %d",&a,&b);
        ans = 0;
        FORE(i,a,b)
        {
            ans += chk(i);
        }
        printf("Case #%d: %d\n",tt,ans);
    }

    return 0;
}