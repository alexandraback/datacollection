#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
using namespace std;
/*struct node
{
    int x,y,tim;
    node *from,*n1,*n2,*n3,*n4;
    node(int xx,int yy,int tt):x(xx),y(yy),tim(tt) {from=NULL;n1=n2=n3=n4=NULL;}
};
int t;node *root;int tx,ty;
int c[1000];int l=0;char ans[5];
int main()
{
    ans[1]='E';ans[2]='W';ans[3]='N';ans[4]='S';
    freopen("B-small-attempt0 (1).in","r",stdin);
    freopen("B-small-attempt0 (1).out","w",stdout);
    scanf("%d",&t);
    queue<node*> q;node *p,*nn;
    for(int tt=1;tt<=t;++tt)
    {
        scanf("%d%d",&tx,&ty);
        root=new node(0,0,0);l=0;
        q.push(root);
        while(!q.empty())
        {
            p=q.front();q.pop();
            if(p->x==tx&&p->y==ty)
            {
                node *tmp=p;
                while(1)
                {
                    if(tmp->from->x<tmp->x) c[++l]=1;
                    else if(tmp->from->x>tmp->x) c[++l]=2;
                    else if(tmp->from->y<tmp->y) c[++l]=3;
                    else if(tmp->from->y>tmp->y) c[++l]=4;
                    tmp=tmp->from;
                    if(tmp==root) break;
                }
                while(!q.empty())
                {
                    q.pop();
                }
                q.push(root);
                while(!q.empty())
                {
                    node *tmp=q.front();q.pop();
                    if(tmp->n1) q.push(tmp->n1);
                    if(tmp->n2) q.push(tmp->n2);
                    if(tmp->n3) q.push(tmp->n3);
                    if(tmp->n4) q.push(tmp->n4);
                    delete tmp;
                }
                break;
            }
            int step=p->tim+1;
            nn=new node(p->x+step,p->y,step);nn->from=p;p->n1=nn;q.push(nn);
            nn=new node(p->x,p->y+step,step);nn->from=p;p->n2=nn;q.push(nn);
            nn=new node(p->x-step,p->y,step);nn->from=p;p->n3=nn;q.push(nn);
            nn=new node(p->x,p->y-step,step);nn->from=p;p->n4=nn;q.push(nn);
        }
        printf("Case #%d: ",tt);
        for(int i=l;i>=1;--i)
        {
            printf("%c",ans[c[i]]);
        }
        printf("\n");
    }
    return 0;
}*/
int main()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small-attempt1.out","w",stdout);
    int t,x,y;scanf("%d",&t);
    for(int tt=1;tt<=t;++tt)
    {
        scanf("%d%d",&x,&y);
        printf("Case #%d: ",tt);
        if(x>0)
            for(int i=1;i<=x;++i)
            {
                printf("WE");
            }
        else if(x<0)
            for(int i=1;i<=-x;++i)
            {
                printf("EW");
            }
        if(y>0)
            for(int i=1;i<=y;++i)
            {
                printf("SN");
            }
        else if(y<0)
            for(int i=1;i<=-y;++i)
            {
                printf("NS");
            }
        printf("\n");
    }
}
