#include <vector>
#include <algorithm>

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;
struct In
{
    int x;
    int y;
}s[1001];
int cmp( const void *a , const void *b ) 
{ 
    struct In *c = (In *)a; 
    struct In *d = (In *)b; 
    if(c->x != d->x) return c->x - d->x; 
    else return d->y - c->y; 
} 
bool b[1001];
int main()
{
    	freopen("D:\\GCJ 2012\\B-small-attempt0.in","r",stdin);freopen("D:\\GCJ 2012\\B-small-attempt0.out","w",stdout);
    //	freopen("D:\\GCJ 2012\\B-small-attempt1.in","r",stdin);freopen("D:\\GCJ 2012\\B-small-attempt1.out","w",stdout);
    //	freopen("D:\\GCJ 2012\\B-large.in","r",stdin);freopen("D:\\GCJ 2012\\B-large.out","w",stdout);
    int testcase;
    char flag[100];
    cin>>testcase;
    cin.getline(flag,100);
    for (int caseId=1;caseId<=testcase;caseId++)
    {
        int N,now=0,asw=0;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            cin>>s[i].x>>s[i].y;
            b[i]=true;
        }
        qsort(s,N,sizeof(s[0]),cmp); 
        int num=0,flag=0;
        while(num<=2*N)
        {
            flag=0;
            for(int i=0;i<N;i++)
            {
                if(b[i]&&s[i].y<=now)
                {
                    now+=2;
                    b[i]=false;
                    if(s[i].x==-1)now--;
                    flag=1;
                    asw++;
                    num++;
                }
            }
            if(flag==0)
            {
                for(int i=0;i<N;i++)
                {
                    if(b[i]&&s[i].x!=-1&&s[i].x<=now)
                    {
                        now++;
                        s[i].x=-1;
                        i=N;
                        asw++;
                        flag=1;
                        num++;
                    }
                }
            }
            if(flag==0)
            {
                for(int i=0;i<N;i++)
                {
                    if(b[i])
                    {
                        flag=-2;
                    }
                }
                num=2*N+1;
            }
        }
        printf("Case #%d: ",caseId);
        if(flag==-2)cout<<"Too Bad"<<endl;
        else cout<<asw<<endl;

    }
    return 0;
}