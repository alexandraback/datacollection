#include<iostream>
#include<stdio.h>
#include<assert.h>
#include<memory.h>
#include<set>
using namespace std;


int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    int T;
    scanf("%d",&T);
    int p[1000];
    int b[1000];
    int c,d,v;

//cout<<"haha"<<endl;
    for(int cas=0;cas<T;cas++)
    {
        set<int> s;
        memset(p,0,sizeof(p));
        memset(b,0,sizeof(b));
        cin>>c>>d>>v;
        for(int i=0;i<d;i++)
            cin>>p[i];
        int L=1<<d;
        for(int i=0;i<L;i++)
        {
            int temp=0;
            for(int j=0;j<d;j++)
            {
                if( ((i>>j) & 1) ==1) // 1
                    temp+=p[j];
            }
            b[temp]=1;
            s.insert(temp);
        }
       // for(int i=0;i<=v;i++)
       //     cout<<i<<"="<<b[i]<<endl;

        int ans=0;
        for(int i=1;i<=v;i++)
        {
                if(b[i]==0)
                {
                    ans++;
                    p[d]=i;
                    d++;
                    b[i]=1;
                    set<int>::iterator it=s.begin();
                    set<int> tt=s;
                    for(;it!=s.end();it++)
                    {
                        b[i+(*it)]=1;
                        tt.insert(i+(*it));
                    }
                    s=tt;
                }
        }


        printf("Case #%d: %d\n",cas+1,ans);

    }
    return 0;
}
