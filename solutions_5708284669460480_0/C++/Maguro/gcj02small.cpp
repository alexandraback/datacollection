#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define X first
#define Y second
using namespace std;
char sA[120];
char sB[120];
char result[120];
int hsh[120];
int ha[520];
double prob[520];
vector<char> v;
vector<double> out;
int lA,lB,times;
void gen(int idx,double val)
{
    int i,j;
    if(idx==times)
    {
        int sum=0;
        for(i=0;i<=times-lB;i++)
        {
            int fu=0;
            for(j=0;j<lB;j++)
            {
                if(result[i+j]!=sB[j])
                {
                    fu=1;
                    break;
                }
            }
            if(fu==0)
            {
                sum++;
            }
        }
        //sum*val;
        if(sum>=1)
        {
            double x=sum*(1-val);
            out.PB(x);
        }

        //printf("[%lf] %s\n",1-sum*val,result);
        return;
    }

    for(i=0;i<lA;i++)
    {
        result[idx]=sA[i];
        gen(idx+1,val*prob[sA[i]]);

    }
    return;
}
int main()
{
    //freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t,T,i,j,k;

    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        v.clear();
        out.clear();
        memset(ha,0,sizeof ha);
        memset(hsh,0,sizeof hsh);
        memset(sA,0,sizeof sA);
        memset(sB,0,sizeof sB);
        memset(result,0,sizeof result);
        scanf("%d %d %d",&lA,&lB,&times);
        scanf("%s %s",sA,sB);

        for(i=0;i<lA;i++)
        {
            if(ha[sA[i]]==0)
                v.PB(sA[i]);
            ha[sA[i]]++;
        }
        for(i=0;i<v.size();i++)
        {
            prob[v[i]]=double(ha[v[i]])/double(lA);
            //printf("%lf\n",prob[v[i]]);
        }
        gen(0,1.0);
        double ss=0;
        for(i=0;i<out.size();i++)
        {
            ss+=out[i];
        }
        if(!out.empty())
            printf("Case #%d: %lf\n",t,ss/out.size());
        else
            printf("Case #%d: 0.0\n",t);

    }
}

