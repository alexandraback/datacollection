/*                                                           //
//                          _oo0oo_                          //
//                         088888880                         //
//                         88" . "88                         //
//                         (| -_- |)                         //
//                          0\ = /0                          //
//                       ___/'---'\___                       //
//                     .' \\|     |// '.                     //
//                    / \\|||  :  |||// \                    //
//                   /_ ||||| -:- |||||- \                   //
//                  |   | \\\  -  /// |   |                  //
//                  | \_|  ''\---/''  |_/ |                  //
//                  \  .-\__  '-'  __/-.  /                  //
//                ___'. .'  /--.--\  '. .'___                //
//             ."" '<  '.___\_<|>_/___.' >'  "".             //
//            | | : '-  \'.;'\ _ /';.'/ - ' : | |            //
//            \  \ '_.   \_ __\ /__ _/   .-' /  /            //
//        ====='-.____'.___ \_____/___.-'____.-'=====        //
//                          '=---='                          //
//                                                           //
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#define lson l,mid,u << 1
#define rson mid + 1,r,u << 1 | 1
#define ls u << 1
#define rs u << 1 | 1
#define mid ((l + r) >> 1)

using namespace std;

typedef long long ll;
const int M = 110;
char s[M],t[M],k[M];
int f[M];

void get(char *t){
    int i = 0,j = -1;
    int len = strlen(t);
    f[0] = -1;
    while(i < len){
        if(j == -1 || t[i] == t[j])
            f[++i] = ++j;
        else j = f[j];
    }
}

int kmp(char *s,char *t){
    int ans = 0;
    int i = 0,j = 0;
    int len = strlen(s);
    int n = strlen(t);
    while(i < len){
        if(j == -1 || s[i] == t[j]){
            ++j;
            ++i;
        }
        else{
            j = f[j];
        }
        if(j == n) ans++;
    }
    return ans;
}

int T,K,L,S,ans,cnt,maxx;
void dfs(int pos)
{
    if(pos == S)
    {
        s[pos] = '\0';
        cnt++;
        int tmp = kmp(s,t);
        ans += tmp;
        maxx = max(maxx,tmp);
        return;
    }
    for(int i = 0; i < K; i++)
    {
        s[pos] = k[i];
        dfs(pos + 1);
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out","w",stdout);
    int ct = 0;
    cin>>T;
    while(T--)
    {
        scanf("%d %d %d",&K,&L,&S);
        scanf("%s %s",k,t);
        get(t);
        maxx = cnt = ans = 0;
        dfs(0);
        //cout<<ans<<": "<<cnt<<endl;
        printf("Case #%d: ",++ct);
        printf("%.8f\n",maxx - (double)ans/cnt);
    }
    return 0;
}

