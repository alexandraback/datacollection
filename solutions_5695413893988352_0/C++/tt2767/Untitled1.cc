//MJRT
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
//////////////////////
#include<iostream>
#include<algorithm>
#include<string>
#include <iterator>
#include<sstream>
#include<functional>
#include<numeric>
///////////////////////
#include<vector>
#include<map>
#include <stack>
#include<queue>
#include<set>
#include <bitset>
#include <list>
///////////////////////
//#include<ext/pb_ds/priority_queue.hpp> //pd_bs库,hdu&&poj不支持
using namespace std;
#define lowbit(x) ((x)&(-x))
static int INDEX = 0,BUGs = 0;
template <class T1, class T2>inline void gmax(T1 &a, T2 b) { if (b>a)a = b; }
template <class T1, class T2>inline void gmin(T1 &a, T2 b) { if (b<a)a = b; }
template<class T> T MAX(T a, T b) { return a > b ? a : b; }
template<class T> T MIN(T a, T b) { return a < b ? a : b; }
template<class T> T GCD(T a, T b) { return b ? GCD(b, a%b) : a; }
template<class T> T LCM(T a, T b) { return a / GCD(a,b) * b;    }
#define BUG() cout << "There is BUG No." << BUGs++ <<endl
#define Whats(x)          cout << "{ "<< #x << " }" << " is " << "*** "<< x << " ***" << "  index:" << INDEX++ <<endl
#define Show(x,s,l)      {cout << #x << ": "; for(int i = s ; i < s+l ; i++) cout << x[i] << " ";  cout << "\n";}
#define Show2(x,s,l,h)   {cout << #x << ": " << l-s << "*" <<h-s <<"\n"; for(int j = s ; j < s+h ; j++){for(int i = s ; i < s+l ; i++) cout << x[j][i] << " ";cout << "\n";};  cout << "\n";}

typedef  long long int LL;
const int INF = 0x3f3f3f3f;

const int  N = 5 + 20;
//bool vis[N];
char a[N],b[N];
int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int Case,tot=1;
    scanf("%d",&Case);
    while(Case--)
    {
        scanf("%s%s",a,b);
        int l = strlen(a);
        int x, y ;
        printf("Case #%d: ",tot++);
        if(l == 1)
        {
           a[2] = a[0];
           b[2] = b[0];
           b[0] = a[0] =a[1] =b[1] = '0';
        }
        else if(l == 2)
        {
            b[2] = b[1];
            a[2] = a[1];
            a[1] = a[0];
            b[1] = b[0];
            a[0] =b[0] ='0';
        }


            int rx = 0 , ry = INF;
            for(int i = 0 ; i < 1000 ; i++)
            {
                if(i%10 == a[2]-'0' || a[2] == '?')
                    if( a[1] =='?' || i/10%10 == a[1]-'0' )
                        if(i/100 == a[0]-'0' || a[0]=='?')
                            for(int j = 0 ; j < 1000 ;j++)
                            {
                                if(j%10 == b[2]-'0' || b[2] == '?')
                                    if(b[1] =='?' || j/10%10 == b[1]-'0' )
                                    {
//                                        printf("b[1]:%c\n",b[1]);
                                        if(j/100 == b[0]-'0' || b[0]=='?')
                                        {
//                                                printf("%d %d\n",i,j);
                                                if(abs(i-j) < abs(rx-ry)|| ( (i+j) < (rx+ry) && abs(i-j) == abs(rx-ry)))
                                                {
                                                            rx = i,ry =j;
                                                }
                                        }
                                    }
                            }
            }
            x = rx,y=ry;
            if(l == 3) printf("%03d %03d\n",x,y);
            else if(l == 2) printf("%02d %02d\n",x,y);
            else printf("%01d %01d\n",x,y);

    }
    return 0;
}
