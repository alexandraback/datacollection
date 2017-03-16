#include<cstdio>
#include<cstring>
#include<cctype>
#include<string>
#include<iostream>

using namespace std;

#ifdef DEBUG
int _msg_indent,_msg_cnt;
#define msg_head cerr.width(4),cerr<<_msg_cnt++<<__FUNCTION__<<'('<<__LINE__<<')'
#define msg(x) msg_head<<x<<endl
#else
#define msg(x)
#endif

template<typename T>
inline void maximize(T& a,const T b)
{ if (b>a) a=b; }
template<typename T>
inline void minimize(T& a,const T b)
{ if (b<a) a=b; }
template<typename T>
inline T maximum(const T& a,const T& b)
{ return a>b?a:b; }
template<typename T>
inline T minimum(const T& a,const T& b)
{ return a<b?a:b; }

typedef long long ll;

int scan(){
    char ch;
    while (!isdigit(ch=getchar()));
    int x=ch-'0';
    while (isdigit(ch=getchar()))
        x=x*10+ch-'0';
    return x;
}

char map[4][4];
int cnt[128],ans;

void init()
{
    memset(cnt, 0, sizeof(cnt));
    for (int i=0;i<4;++i)
    {
        for (int j=0;j<4;++j)
            map[i][j]=getchar(), ++cnt[map[i][j]];
        getchar();
    }
    getchar();
}

bool check(char a,char b,char c,char d)
{
    memset(cnt, 0, sizeof(cnt));
    ++cnt[a],++cnt[b],++cnt[c],++cnt[d];
    if (cnt['O'] == 4 || (cnt['O']==3 && cnt['T']))
    {
        ans = 3;
        return 1;
    }
    if (cnt['X'] == 4 || (cnt['X']==3 && cnt['T']))
    {
        ans = 2;
        return 1;
    }
    return 0;
}

void work()
{
    bool if_end = cnt['.']==0;
    if (check(map[0][0],map[0][1],map[0][2],map[0][3])) return;
    if (check(map[1][0],map[1][1],map[1][2],map[1][3])) return;
    if (check(map[2][0],map[2][1],map[2][2],map[2][3])) return;
    if (check(map[3][0],map[3][1],map[3][2],map[3][3])) return;
    if (check(map[0][0],map[1][0],map[2][0],map[3][0])) return;
    if (check(map[0][1],map[1][1],map[2][1],map[3][1])) return;
    if (check(map[0][2],map[1][2],map[2][2],map[3][2])) return;
    if (check(map[0][3],map[1][3],map[2][3],map[3][3])) return;
    if (check(map[0][0],map[1][1],map[2][2],map[3][3])) return;
    if (check(map[3][0],map[2][1],map[1][2],map[0][3])) return;
    ans = if_end;
}

void put_ans()
{
    switch (ans)
    {
        case 0:cout<<"Game has not completed"<<endl;break;
        case 1:cout<<"Draw"<<endl;break;
        case 2:cout<<"X won"<<endl;break;
        case 3:cout<<"O won"<<endl;break;
    }
}

int main(){
    int z=scan();
    for (int i=1;i<=z;++i)
    {
        init();
        work();
        cout<<"Case #"<<i<<": ";
        put_ans();
    }
}
