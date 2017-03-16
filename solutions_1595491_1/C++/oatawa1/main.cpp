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
#define vi vector<int >
#define vii vector<pii >
#define FOR(i , a , b) for(__typeof(b)i=a;i<b;i++)
#define FORE(i , a , b) for(__typeof(b)i=a;i<=b;i++)
#define FOR_INV(i , a , b) for(__typeof(b)i=a;i>b;i--)
#define FORE_INV(i , a , b) for(__typeof(b)i=a;i>=b;i--)
#define TR(it , c) for(__typeof((c).end())it = (c).begin();it != (c).end();it++)

int tCase;
int n,s,p;
vi v;
int in;
int ans;
int main()
{
        freopen("B-large.in","r",stdin);
        freopen("out.out","w",stdout);
    scanf("%d",&tCase);
    FORE(tt , 1 , tCase)
    {
        scanf("%d %d %d",&n,&s,&p);
        v.clear();
        FOR(i , 0 , n)
        {
            scanf("%d",&in);
            v.push_back(in);
        }
        sort(v.rbegin() , v.rend());
        ans = 0;
        //printf("%d(%d)->",p,s);
        TR(it , v)
        {
            //printf("(%d %d) ",(*it+2)/3,(*it+4)/3);
            if(p == 0){
                ans = n;
                break;
            }
            if(*it > 0 && (*it+2)/3 >= p)    ans++;
            else if(s > 0 && *it > 1 && (*it+4)/3 >= p)
            {
                ans++;
                s--;
            }
            else break;
        }
        printf("Case #%d: %d\n",tt,ans);
    }
    return 0;
}