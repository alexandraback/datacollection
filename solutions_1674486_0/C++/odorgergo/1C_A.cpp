#include <cstdio>
#include <queue>


using namespace std;

int t,n;
int** a;
int* els;
int* d;

int main()
 {
    FILE* be = fopen("small.in","r");
    FILE* ki=fopen("ki.out","w");
    fscanf(be,"%d",&t);
    for(int c=0; c<t; c++)
    {
        fprintf(ki,"Case #%d: ",c+1);
        fscanf(be,"%d",&n);
        a=new int*[n];
        els=new int[n];
        for(int i=0; i<n; i++)
        {
            a[i]=new int[n];
            els[i]=0;
        }
        for(int i=0; i<n; i++)
        {
            fscanf(be,"%d",&els[i]);
           // printf("%d ",els[i]);
            for(int j=0; j<els[i]; j++)
            {
                int tmp;
                fscanf(be,"%d",&tmp);
                tmp--;
                a[i][j]=tmp;
             //   printf("%d ",a[i][j]);
            }
           // printf("\n");
        }

        bool f=true;
        for(int start=0; start<n&&f; start++)
        {
           // printf("S %d: ",start+1);
            d=new int[n];
            for(int i=0; i<n; i++)
            {
                d[i]=-1;
            }
            d[start]=1;

            queue<int> q;
            q.push(start);
            while(!q.empty() && f)
            {
                int tmp= q.front();
                q.pop();
                for(int i=0; i<els[tmp]&&f; i++)
                {
                    if(d[a[tmp][i]]==-1)
                    {
                    d[a[tmp][i]]+=2;
                    q.push(a[tmp][i]);
                    }
                    else
                    {
                        f=false;
                        fprintf(ki,"Yes\n");
                    }
                }

            }
            /*for(int i=0; i<n; i++)
            {
                if(d[i]>1) {printf("BAJ"); return 0;}
                if(d[i]==1) printf("%d ",i+1);
            }
            printf("\n");*/
        }
        if(f) fprintf(ki,"No\n");
    }
 }
