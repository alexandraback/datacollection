#include <cstdio>

using namespace std;

inline bool get(int var, int pos)
{
    return (var & (1<<pos))>0;
}

inline int set(int var, int pos, bool value)
{
    if(value)
        return (var | (1<<pos));
    else
        return (var & (~(1<<pos)));
}

int t,n;
int* a;
int* b;

int main()
{
    FILE* be = fopen("small.in","r");
    FILE* ki=fopen("ki.out","w");
    fscanf(be,"%d",&t);
    for(int c=0; c<t; c++)
    {
        fprintf(ki,"Case #%d:\n",c+1);
        fscanf(be,"%d",&n);
        a=new int[n];
        int m=20*100000;
        b=new int[m];
        for(int i=0; i<n; i++)
        {
            fscanf(be,"%d",&a[i]);
         //    printf("%d ",a[i]);
        }
        for(int i=0; i<m; i++)
        {
            b[i]=-1;
        }
        b[0]=0;
        bool f=true;
        for(int i=0; i<n&&f; i++)
        {
            for(int j=0; j<m&&f; j++)
            {
                if((b[j]!=-1) && !(get(b[j],i)))
                {
                    if(b[j+a[i]]!=-1)
                    {
                        for(int k=0; k<n; k++)
                        {
                            if(get(b[j+a[i]],k)) fprintf(ki,"%d ",a[k]);
                        }
                        fprintf(ki,"\n");
                        for(int k=0; k<n; k++)
                        {
                            if(get(b[j],k)) fprintf(ki,"%d ",a[k]);
                        }
                        fprintf(ki,"%d\n", a[i]);
                        f=false;
                    }
                    else
                    {
                        b[j+a[i]]=set(b[j],i,true);
                      //  printf("%d %d\n", j+a[i], b[j+a[i]]);
                    }

                }
            }
        }
    }

}
