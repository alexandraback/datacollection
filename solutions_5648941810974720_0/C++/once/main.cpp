#include<bits/stdc++.h>
using namespace std;
string str[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int num[10];
int ch[26];
char s[2007];
bool uniq[10];
void gen()
{
    srand(time(0));
    int len=0;
    for (int i=0;i<300;++i)
    {
        int x=rand()%10;
        printf("%d",x);
        for (auto t:str[x])
            s[len++]=t;
    }
    printf("\n");
    random_shuffle(s,s+len);
    s[len]=0;
    puts(s);
}
bool dfs(int x,int res)
{
    //printf("%d, %d\n",x,res);
    if (res==0) return true;
    if (x==10) return false;
    if (dfs(x+1,res)) return true;
    if (uniq[x]) return false;
    while (true)
    {
        bool ok=true;
        for (auto t:str[x])
        {
            --ch[t-'A'];
            if (ch[t-'A']<0)
                ok=false;
        }
        ++num[x];
        if (!ok)
            break;
        if (dfs(x+1,res-str[x].length()*num[x])) return true;
    }
    for (auto t:str[x])
        ch[t-'A']+=num[x];
    num[x]=0;
    return false;
}
bool solve()
{
    for (int i=0;s[i];++i)
        ++ch[s[i]-'A'];
    int res=strlen(s);
    int ord='Z'-'A';
    num[0]=ch[ord];
    res-=num[0]*str[0].length();
    for (auto x:str[0])
        ch[x-'A']-=num[0];
    ord='W'-'A';
    num[2]=ch[ord];
    res-=num[2]*str[2].length();
    for (auto x:str[2])
        ch[x-'A']-=num[2];
    ord='X'-'A';
    num[6]=ch[ord];
    res-=num[6]*str[6].length();
    for (auto x:str[6])
        ch[x-'A']-=num[6];
    ord='G'-'A';
    num[8]=ch[ord];
    res-=num[8]*str[8].length();
    for (auto x:str[8])
        ch[x-'A']-=num[8];
    return dfs(0,res);
}
int main()
{
    freopen("A.in","r",stdin);
    freopen("A.txt","w",stdout);
    memset(uniq,0,sizeof uniq);
    uniq[0]=true;
    uniq[2]=true;
    uniq[6]=true;
    uniq[8]=true;
    int cas;
    scanf("%d",&cas);
    for (int run=1;run<=cas;++run)
    {
        scanf("%s",s);
        memset(num,0,sizeof num);
        memset(ch,0,sizeof ch);
        if (!solve())
            puts("NO");
        printf("Case #%d: ",run);
        for (int i=0;i<10;++i)
            for (int j=0;j<num[i];++j)
                putchar('0'+i);
        putchar('\n');
    }
    return 0;
}
