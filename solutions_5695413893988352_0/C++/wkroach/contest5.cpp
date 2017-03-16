#include<cstdio>
#include<cstdlib>
#include<time.h>
#include<cmath>
#include<cstring>
#include<string>
#include<iostream>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<vector>
#include<algorithm>

//#include<bits/c++std.h>

#define Size 1000005
#define inf 2e9
#define INF 2e18
#define LL long long int
#define i64 __int64
#define ULL unsigned long long
#define Mod 1000000007
#define pi 4*atan(1)
#define eps 1e-8
#define lson now*2,l,l+(r-l)/2
#define rson now*2+1,l+(r-l)/2+1,r
using namespace std;
int n,m,k;
int ql,qr,pos;
int vis[20];

string solve(int n)
{
    stack<int>s;
    while(!s.empty())
        s.pop();
    int tmp = n;
    while(tmp)
    {
        s.push(tmp%10);
        tmp /= 10;
    }
    string str;
    while(!s.empty())
    {
        str.push_back(s.top() + '0');
        s.pop();
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
//        freopen("input.txt","r",stdin);
//        freopen("output.txt","w",stdout);
    #endif // ONLINE_JUDGE
    int t;
    int x,y,z;
    int Case=0;
    cin>>t;
    while(t--)
//    while(scanf("%d",&n)==1)
    {
        string s1;
        string s2;
        cin>>s1;
        cin>>s2;
        int flag = 0;
        printf("Case #%d: ", ++Case);
//        for(int i=0; i < s1.size() ;++i)
//        {
//            if(s1[i] == '?' && s2[i] == '?')
//            {
//                if(i == 0 || s1[i-1] == s2[i-1])
//                    s1[i] = s2[i] = '0';
//                else if(s1[i-1] )
//            }
//            else if(s1[i] == '?')
//            {
//
//            }
//        }
        if(s1.size() == 1)
        {
            if(s1[0] == '?' && s2[0] == '?')
            {
                printf("0 0");
            }
            else if(s1[0] == '?')
            {
                printf("%c %c",s2[0],s2[0]);
            }
            else if(s2[0] == '?')
            {
                printf("%c %c",s1[0],s1[0]);
            }
        }
        else if(s1.size() == 2)
        {
            int m1 = 0, m2 = 0;
            int Min = 10000;
            string tmp = "00",tmp2 = "00";
            string ans1 = "00", ans2 = "00";
            for(int i=0;i<100;++i)
            {
                tmp[1] = i%10 + '0';
                tmp[0] = i/10 + '0';
                if(s1[0] != '?' && s1[0] != tmp[0])
                    continue;
                if(s1[1] != '?' && s1[1] != tmp[1])
                    continue;
                for(int j=0;j<100;++j)
                {
                    tmp2[1] = j%10 + '0';
                    tmp2[0] = j/10 + '0';
                    if(s2[0] != '?' && s2[0] != tmp2[0])
                        continue;
                    if(s2[1] != '?' && s2[1] != tmp2[1])
                        continue;
                    int tmp3 = abs(tmp[0]*10 + tmp[1] - tmp2[0]*10 - tmp2[1]);
                    if(tmp3 < Min)
                    {
                        Min = tmp3;
                        ans1 = tmp;
                        ans2 = tmp2;
                    }
                }
            }
            cout<<ans1<<" "<<ans2;
        }
        else if(s1.size() == 3)
        {
            int m1 = 0, m2 = 0;
            int Min = 100000;
            string tmp = "000",tmp2 = "000";
            string ans1 = "000", ans2 = "000";
            for(int i=0;i<1000;++i)
            {
                tmp[2] = i%10 +'0';
                tmp[1] = (i/10)%10 + '0';
                tmp[0] = i/100 + '0';
                if(s1[0] != '?' && s1[0] != tmp[0])
                    continue;
                if(s1[1] != '?' && s1[1] != tmp[1])
                    continue;
                if(s1[2] != '?' && s1[2] != tmp[2])
                    continue;
                for(int j=0;j<1000;++j)
                {
                    tmp2[2] = j % 10 + '0';
                    tmp2[1] = (j / 10) % 10 + '0';
                    tmp2[0] = j / 100 + '0';

                    if(s2[0] != '?' && s2[0] != tmp2[0])
                    {
                        continue;
                    }

                    if(s2[1] != '?' && s2[1] != tmp2[1])
                    {
                        continue;
                    }

                    if(s2[2] != '?' && s2[2] != tmp2[2])
                    {
                        continue;
                    }
                    int tmp3 = abs(tmp[0]*100 + tmp[1]*10 + tmp[2] - tmp2[0]*100 - tmp2[1]*10 - tmp2[2]);
                    if(tmp3 < Min)
                    {
                        Min = tmp3;
                        ans1 = tmp;
                        ans2 = tmp2;
                    }
                }
            }
            cout<<ans1<<" "<<ans2;
        }
        cout<<endl;
    }
    return 0;
}

