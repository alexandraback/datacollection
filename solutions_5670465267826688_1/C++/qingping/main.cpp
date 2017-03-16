#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
//#include <unordered_map>
#define N 90100
using namespace std;
typedef pair<long long,long long> PII;
const long long INF=0x3f3f3f3f;

void Open()
{
    //#ifndef ONLINE_JUDGE
        freopen("C-large.in","r",stdin);
        freopen("C-large.out","w",stdout);
    //#endif // ONLINE_JUDGE
}

char ijk[N];
char tmp[N];
char mul[200][200];
bool minu[200][200];
int main()
{
    Open();

    mul['1']['1']='1',mul['1']['i']='i',mul['1']['j']='j',mul['1']['k']='k';
    mul['i']['1']='i',mul['i']['i']='1',mul['i']['j']='k',mul['i']['k']='j';
    mul['j']['1']='j',mul['j']['i']='k',mul['j']['j']='1',mul['j']['k']='i';
    mul['k']['1']='k',mul['k']['i']='j',mul['k']['j']='i',mul['k']['k']='1';
    minu['i']['i']=1,minu['i']['k']=1,minu['j']['i']=1,minu['j']['j']=1,minu['k']['j']=1,minu['k']['k']=1;

    long long T;
    scanf("%I64d",&T);
    long long cas=1;
    while(T--)
    {
        memset(ijk,0,sizeof(ijk));
        memset(tmp,0,sizeof(tmp));
        long long l,x;
        scanf("%I64d%I64d",&l,&x);
        long long tmpx=x;
        if(x>4){
            x%=4;
            x+=4;
        }
        scanf("%s",tmp);
        for(long long i=0;i<x;i++)
            strcat(ijk,tmp);
        long long len=strlen(ijk);
        bool fuhao=0;
        char pre='1';
        for(long long i=0;i<len;i++)
        {
            fuhao = fuhao ^ minu[pre][ijk[i]];
            pre=mul[pre][ijk[i]];
        }
        if(pre != '1' || !fuhao)
        {
            printf("Case #%I64d: NO\n",cas++);
            continue;
        }
        fuhao=0;
        pre='1';
        long long iidx=-1;
        long long kidx=-1;
        for(long long i=0;i<len;i++)
        {
            fuhao^=minu[pre][ijk[i]];
            pre=mul[pre][ijk[i]];
            if(pre=='i' && !fuhao)
            {
                iidx=i;
                break;
            }
        }
        pre='1';
        fuhao=0;
        for(long long i=len-1;i>=0;i--)
        {
            fuhao^=minu[ijk[i]][pre];
            pre=mul[ijk[i]][pre];
            if(pre=='k' && !fuhao)
            {
                kidx=i;
                break;
            }
        }
        if(iidx!=-1 && kidx!=-1 && iidx+1<kidx+(l*tmpx-len))
            printf("Case #%I64d: YES\n",cas++);
        else
            printf("Case #%I64d: NO\n",cas++);
    }
    return 0;
}
