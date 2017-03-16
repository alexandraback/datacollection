#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

class Operand
{
public:
    char ch;
    int sign;   //1 or -1
};
const int MAXN=10001;

Operand multiply(Operand a,Operand b)
{
    Operand ans;
    ans.sign=a.sign*b.sign;
    if (a.ch=='1')
    {
        ans.ch=b.ch;
    }else if (a.ch=='i')
    {
        if (b.ch=='1')
        {
            ans.ch='i';
        }else if (b.ch=='i')
        {
            ans.ch='1';
            ans.sign=-ans.sign;
        }else if (b.ch=='j')
        {
            ans.ch='k';
        }else if (b.ch=='k')
        {
            ans.ch='j';
            ans.sign=-ans.sign;
        }
    }else if (a.ch=='j'){
        if (b.ch=='1')
        {
            ans.ch='j';
        }else if (b.ch=='i')
        {
            ans.ch='k';
            ans.sign=-ans.sign;
        }else if (b.ch=='j')
        {
            ans.ch='1';
            ans.sign=-ans.sign;
        }else if (b.ch=='k')
        {
            ans.ch='i';
        }
    }else if (a.ch=='k')
    {
        if (b.ch=='1')
        {
            ans.ch='k';
        }else if (b.ch=='i')
        {
            ans.ch='j';
        }else if (b.ch=='j')
        {
            ans.ch='i';
            ans.sign=-ans.sign;
        }else if (b.ch=='k')
        {
            ans.ch='1';
            ans.sign=-ans.sign;
        }
    }
    return ans;
}
Operand head[MAXN],rear[MAXN];
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C_output_small.txt","w",stdout);
    int T,L,X;
    Operand tmp;
    char s[MAXN];
    scanf("%d",&T);
    for (int index=1;index<=T;index++)
    {
        scanf("%d%d",&L,&X);
        scanf("%s",s);
        head[0].ch=s[0];
        head[0].sign=1;
        int N=L*X;
        for (int i=1;i<N;i++)
        {
            tmp.ch=s[i%L]; tmp.sign=1;
            head[i]=multiply(head[i-1],tmp);
        }
        rear[N-1].ch=s[L-1];
        rear[N-1].sign=1;
        for (int i=N-2;i>=0;i--)
        {
            tmp.ch=s[i%L]; tmp.sign=1;
            rear[i]=multiply(tmp,rear[i+1]);
        }
        bool exist=false;
        for (int i=0;i<=N-3;i++)
        {
            if (head[i].ch!='i' || head[i].sign!=1) continue;
            for (int j=i+1;j<=N-2;j++)
            {
                if (rear[j+1].ch!='k' || rear[j+1].sign!=1) continue;
                tmp=multiply(head[i],head[j]);
                if (head[i].ch!='1') tmp.sign=-tmp.sign;
                if (tmp.ch=='j' && tmp.sign==1 )
                {
                    exist=true; break;
                } 
            }
            if (exist) break;
        }
        if (exist) printf("Case #%d: YES\n",index);
        else printf("Case #%d: NO\n",index);
    }
    return 0;
}
