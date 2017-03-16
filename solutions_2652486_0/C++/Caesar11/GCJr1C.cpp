#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<vector>
using namespace std;

struct node
{
    int a,b,c;

    node(int x,int y,int z):a(x),b(y),c(z){}
};

int perm[5];
int product[10];
char mark[200];
vector<node>vec;

main()
{
    int t,n,r,m,k,i,j,a,b,c,tmp;

    freopen("C-small-1-attempt0.in","r",stdin);
    freopen("Csmall.out","w",stdout);

    scanf("%d",&t);
    srand(time(NULL));
    while (t--)
    {
        scanf("%d%d%d%d",&r,&n,&m,&k);
        printf("Case #1:\n");
        while (r--)
        {
            vec.clear();
            for (i=0;i<k;i++)
                scanf("%d",&product[i]);

            for (a=2;a<=m;a++)
                for (b=2;b<=m;b++)
                    for (c=2;c<=m;c++)
                    {
                        perm[0]=a;
                        perm[1]=b;
                        perm[2]=c;
                        memset(mark,0,sizeof(mark));

                        for (i=0;i<8;i++)
                        {
                            tmp=1;
                            for (j=0;j<3;j++)
                                if (i&(1<<j))
                                    tmp*=perm[j];
                            mark[tmp]=1;
                        }

                        int flag=1;
                        for (i=0;i<k;i++)
                            if (mark[product[i]]==0)
                            {
                                flag=0;
                                break;
                            }
                        if (flag)
                            vec.push_back(node(a,b,c));
                    }

           int x=rand()%vec.size();
           //printf("t %d\n",vec.size());
           //for (x=0;x<vec.size();x++)
           printf("%d%d%d\n",vec[x].a,vec[x].b,vec[x].c);
        }

    }

    return 0;
}





