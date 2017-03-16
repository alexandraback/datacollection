#include<stdio.h>
#include<vector>
#include<map>
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define tr(c,it) for(typeof(c.begin()) it=c.begin();it!=c.end();it++)
using namespace std;
struct abc
{
    int a,b,c;
};
map< pair<int,int> , int> m1,m2,m3;
vector<pair< int, pair<int,int> > > v1;
vector<abc> v2,finall;
int main()
{
  //     freopen("inputc1.in","r",stdin);
//    freopen("outputc.txt","w",stdout);
    int t=0;
    scanf("%d",&t);
    int l=0;
    while(l<t)
    {
        l++;
        int j,p,s,k;
        scanf("%d%d%d%d",&j,&p,&s,&k);
        int x,y,z;
        for(x=1;x<=j;x++)
        {
            for(y=1;y<=p;y++)
            {
                for(z=1;z<=s;z++)
                {
          //          printf("%d %d %d\n",x,y,z);
                    abc p1;

                    p1.a=x;
                    p1.b=y;
                    p1.c=z;
                    v2.push_back(p1);
         //           printf("%d %d %d\n",p1.a,p1.b,p1.c);
                }
            }
        }
        tr(v2,it)
        {

            int q=(*it).a;
            int w=(*it).b;
            int e=(*it).c;
  //          printf("%d %d %d\n",q,w,e);
            if((m1[mp(q,w)]==k)||(m2[mp(w,e)]==k)||(m3[mp(q,e)]==k))
            {
                continue;
            }
            m1[mp(q,w)]++;
            m2[mp(w,e)]++;
            m3[mp(q,e)]++;
            abc ll={q,w,e};
            finall.pb(ll);
        }
        m1.clear();
        m2.clear();
        m3.clear();
        printf("Case #%d: %d\n",l,finall.size());
        tr(finall,it)
        {
             int q=(*it).a;
            int w=(*it).b;
            int e=(*it).c;
            printf("%d %d %d\n",q,w,e);
        }
        finall.clear();
        v2.clear();
    }
    return 0;
}
