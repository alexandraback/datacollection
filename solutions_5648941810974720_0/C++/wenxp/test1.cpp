#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;

int n;
int cnt[26];
int num[10];

char s[20];

inline int idx(char c) {return c-'A';}

void sub(string ss,int t)
{
    int sz=ss.size();
    for(int i=0;i<sz;i++)
    {
        int c=idx(ss[i]);
        cnt[c]-=t;
    }
}

void work()
{
    int tc; scanf("%d",&tc);
    int T_T=0;
    while(tc--)
    {
        memset(num,0,sizeof(num));
        memset(cnt,0,sizeof(cnt));
        scanf("%s",s);
        for(char *p=s;*p;p++)
        {
            int c=idx(*p);
            cnt[c]++;
        }

        int x;
        //ZERO
        x=cnt[idx('Z')];
        sub("ZERO",x);
        num[0]+=x;


        //SIX
        x=cnt[idx('X')];
        sub("SIX",x);
        num[6]+=x;

        //EIGHT
        x=cnt[idx('G')];
        sub("EIGHT",x);
        num[8]+=x;

        //FOUR
        x=cnt[idx('U')];
        sub("FOUR",x);
        num[4]+=x;

        //TWO
        x=cnt[idx('W')];
        sub("TWO",x);
        num[2]+=x;

        //THREE
        x=cnt[idx('T')];
        sub("THREE",x);
        num[3]+=x;

        //ONE
        x=cnt[idx('O')];
        sub("ONE",x);
        num[1]+=x;

        //FIVE
        x=cnt[idx('F')];
        sub("FIVE",x);
        num[5]+=x;

        //SEVEN
        x=cnt[idx('S')];
        sub("SEVEN",x);
        num[7]+=x;

        //NINE
        x=cnt[idx('I')];
        sub("NINE",x);
        num[9]+=x;

        printf("Case #%d: ",++T_T);
        for(int i=0;i<10;i++)
        {
            while(num[i]--) printf("%d",i);
        }
        printf("\n");
    }
}

//--------------end------------------

int main()
{
    #ifdef DouBi
    //freopen("in.cpp","r",stdin);
    //freopen("out.cpp","w",stdout);
    #endif // DouBi
    work();
    return 0;
}
