#include <cstdio>
#include <algorithm>

using namespace std;


int n,t,A,el,bl;
int* a;
int* b;
int** v;
int* e;

bool compare(int p, int q)
{
    return(p<q);
}


bool megcs(int* x,int l)
{
    if (l==0)
        return true;
    int m=A;
    for(int i=0;i<l;i++)
    {
        if(m<=x[i])
            return false;
        m+=x[i];
    }
    if (m>x[l-1])
        return true;
    return false;
}


int main()
{
    FILE* be=fopen("A-small-attempt1.in","r");
    FILE* ki=fopen("out.txt","w");
    fscanf(be,"%d",&t);
    for(int c=0; c<t; c++)
    {
        fscanf(be,"%d %d",&A,&n);
        a=new int[n];
        b=new int[10000000];
        e=new int[10000000];

        for(int i=0; i<n;i++)
        {
            fscanf(be,"%d",&a[i]);
            b[i]=a[i];
        }
        sort(a,a+n,compare);

        /*for(int i=0; i<n;i++)
        {
            printf("%d ",a[i]);
        }*/
        //printf("%d\n",megcs(a,1));
        int elmin=n+1;
        for(int ii=n; ii>0;ii--)
        {

            for(int i=0; i<ii;i++)
            {
                b[i]=a[i];
            }
            bl=ii;
            el=0;

            int i=0;
            while((i<bl)&&(el<ii))
            {
                int m=A;
                for(int j=0;j<i;j++)
                {
                    m+=b[j];
                }
                while(!megcs(b,i+1))
                {
                  //  printf("%d %d\n",i,m);
                    e[el]=m-1;
                    b[bl]=m-1;
                    m+=m-1;
                    bl++;
                    el++;
                    sort(b,b+bl,compare);
                }
                i++;
            }
            if (((n-ii)+el)<elmin)
                elmin=((n-ii)+el);
            /*for(int i=0; i<el;i++)
            {
                printf("%d: %d ",c,e[i]);
            }*/
        }
        fprintf(ki,"Case #%d: %d\n",c+1,elmin);
    }

    fclose(be);
    fclose(ki);
    return 0;
}
