#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<set>

struct star{
    int a;
    int b;
    int c;
};
using namespace std;

int compare (const void * a, const void * b)
{
  return ( (*(star*)b).b - (*(star*)a).b );
}


int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n, b[1000]={0},j, stars[1000]={0}, total=0,k=0,st=0, passos=0;
        star s[1000];
        bool ok=false;
        cin>>n;
        for(j=0;j<n;j++)
        {
            cin>>s[j].a>>s[j].b;
            s[j].c=0;
        }
        qsort (s, n, sizeof(star), compare);
        while(true)
        {
            ok=false;
            for(k=0;k<n;k++)
            {
                if(s[k].c==2)continue;
                if(s[k].b<=total)
                {
                    //cout<<"Quem:"<<k<<" stars:"<<total<<endl;

                    total += 2-s[k].c;
                    s[k].c=2;
                    k=-1;
                    ok=true;
                    st++;
                    passos++;
                    continue;
                }
            }
            for(k=0;k<n;k++)
            {
                if(s[k].c>=1)continue;
                if(s[k].a<=total)
                {
                    //cout<<"Quem>:"<<k<<" stars:"<<total<<endl;
                    total++;
                    passos++;
                    s[k].c=1;
                    ok=true;
                    break;
                }
            }
            if(!ok)break;
        }
        cout<<"Case #"<<i+1<<": ";
        if(st==n)cout<<passos<<endl;
        else cout<<"Too Bad"<<endl;
    }
    return 0;
}
