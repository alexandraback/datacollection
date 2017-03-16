#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#define xx first
#define yy second
using namespace std;

char s[1000000];
enum broj{Nula,KEC=1,I,J,K};
typedef pair<bool,int> simb;
map<char,simb> mapa;
vector<vector<int> > mul
{
    {0,0,0,0,0},
    {0,KEC,I,J,K},
    {0,I,-KEC,K,-J},
    {0,J,-K,-KEC,I},
    {0,K,J,-I,-KEC},
};

vector<map<simb,bool> > tabela;

simb pomnozi(simb x,simb y)
{
    pair<int,int> rez(x.xx^y.xx,mul[x.yy][y.yy]);
    if(rez.yy<0)
    {
        rez.xx^=1;
        rez.yy=-rez.yy;
    }
    return simb(rez.xx,rez.yy);
}

simb fast_mul(simb x,long long step)
{
    if(step==0)return simb(0,KEC);
    if(step==1)return x;
    simb t=fast_mul(x,step/2);
    t=pomnozi(t,t);
    if(step&1)t=pomnozi(t,x);
    return t;
}

void ispis(const simb &x,ostream &cout)
{
    cout<<(x.xx?'-':'+');
    if(x.yy==0)cout<<"0";
    if(x.yy==1)cout<<"1";
    if(x.yy==2)cout<<"i";
    if(x.yy==3)cout<<"j";
    if(x.yy==4)cout<<"k";
}

int main()
{
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    int t,l;
    scanf("%d",&t);
    mapa['i']=simb(0,I);
    mapa['j']=simb(0,J);
    mapa['k']=simb(0,K);
    mapa['1']=simb(0,KEC);
//    for(int i=1;i<=4;i++,puts(""))
//        for(int j=1;j<=4;j++)
//            ispis(pomnozi(simb(0,i),simb(0,j)),cout);
    long long x;
    for(int CASE=1;CASE<=t;CASE++)
    {
        scanf("%d %lld",&l,&x);
        scanf(" %s",s);
        simb tren(0,KEC);
        simb treba[]{simb(0,I),simb(0,J),simb(0,K),simb(0,0)};
        int NA=0;
        long long i=0;
        tabela.assign(l+5,map<simb,bool>());
        for(i=0;i<x && NA<3;i++)
        {
            for(int j=0;j<l;j++)
            {
                tren=pomnozi(tren,mapa[s[j]]);
                if(tren==treba[NA])
                {
                    NA++;
                    tren=simb(0,KEC);
                    tabela.assign(l+5,map<simb,bool>());
                }
                if(tabela[j][tren]){
                    NA=5;break;
                }
                tabela[j][tren]=1;
            }
        }
        if(NA!=3)
        {
            printf("Case #%d: NO\n",CASE);
            continue;
        }
        simb svi=simb(0,KEC);
        for(int j=0;j<l;j++)svi=pomnozi(svi,mapa[s[j]]);
        svi=pomnozi(tren,fast_mul(svi,x-i));
        printf("Case #%d: %s\n",CASE,(svi==simb(0,KEC))?"YES":"NO");
    }
    return 0;
}
