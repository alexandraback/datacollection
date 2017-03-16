#include <cstdio>

using namespace std;

int t,n;
int* a;

int main()
{
    FILE* be = fopen("large.in","r");
    FILE* ki=fopen("ki.out","w");
    fscanf(be,"%d",&t);
    for(int c=0; c<t; c++)
    {
        fprintf(ki,"Case #%d:",c+1);
        double sum=0;
        fscanf(be,"%d",&n);
        a=new int[n];
        for(int i=0; i<n; i++)
        {
            fscanf(be,"%d",&a[i]);
            sum+=a[i];
        //    printf("%d ",a[i]);
        }
        for(int i=0; i<n; i++)
        {
            int n2=n-1;
            double sum2=0;
            sum2=sum-a[i];
            double x,tmp;
            x=(((sum2+sum)/(n2)-a[i])/(sum+sum/(n2)));
            tmp=(sum2+sum*(1-x))/(n2);
           // if ((c==4) && (i==0)) printf("%f %f\n", tmp,x,sum2);
           // for(int k=0; k<n; k++)
            for(int j=0; j<n; j++)
            {
                if(j!=i)
                {
                    if(a[j]>tmp)
                    {
                        sum2-=a[j];
                        n2--;
                        x=(((sum2+sum)/(n2)-a[i])/(sum+sum/(n2)));
                        tmp=(sum2+sum*(1-x))/(n2);
             //           if ((c==4) && (i==0)) printf("%d %d %f %f %f\n",j,a[j], tmp,x,sum2);
                    }
                }
            }

            if(x<0) fprintf(ki," 0.000000");
            else fprintf(ki," %f", x*100);
        }
        fprintf(ki,"\n");
    }
}
