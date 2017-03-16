#include<stdio.h>
#include<queue>
#include<string>
#include<iostream>
#include<utility>
#include<string.h>
using namespace std;
int a,b,c,d,e,f,x,y;
string s;
queue<pair<pair<int,int>,string> > q;
pair<pair<int,int>,string> p,p2;
int zz[10005][10005];
int main()
{
    freopen("B-small-attempt2.in","r",stdin);
    freopen("B-small-attempt2.out","w",stdout);

    scanf("%d",&a);
    for (b=1;b<=a;b++)
    {
        memset(zz,0,sizeof(zz));
        scanf("%d %d",&c,&d);
        s="";
        p.first.first=p.first.second=0;
        p.second=s;
        zz[500][500]=1;
        q.push(p);
        while(!q.empty())
        {
            p=q.front();
            //printf("%d %d\n",p.first.first,p.first.second);
            if (p.first.first==c && p.first.second==d){
                cout << "Case #" << b << ": "<< p.second << endl;
                break;
            }
            //if (q.size()>1000000)
            //printf("%d\n",q.size());
            q.pop();
            p2=p;
            e=p.second.length()+1;
            if (p2.first.first <=8000 && p2.first.second<=8000 && p2.first.first>=-8000 && p2.first.second>=-8000 && e<50)
            {
                p2.first.first=p.first.first+e;
                p2.second+='E';
                if (zz[p2.first.first+5000][p2.first.second+5000]==0)
                {
                    zz[p2.first.first+5000][p2.first.second+5000]=1;
                    q.push(p2);
                }

                p2=p;

                p2.first.first=p.first.first-e;
                p2.second+='W';
                if (zz[p2.first.first+5000][p2.first.second+5000]==0)
                {
                    zz[p2.first.first+5000][p2.first.second+5000]=1;
                    q.push(p2);
                }

                p2=p;

                p2.first.second=p.first.second+e;
                p2.second+='N';
                if (zz[p2.first.first+5000][p2.first.second+5000]==0)
                {
                    zz[p2.first.first+5000][p2.first.second+5000]=1;
                    q.push(p2);
                }

                p2=p;

                p2.first.second=p.first.second-e;
                p2.second+='S';
                if (zz[p2.first.first+5000][p2.first.second+5000]==0)
                {
                    zz[p2.first.first+5000][p2.first.second+5000]=1;
                    q.push(p2);
                }
            }
        }
        while(!q.empty()) q.pop();
    }
    return 0;
}
