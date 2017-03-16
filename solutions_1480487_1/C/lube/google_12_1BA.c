#include<stdio.h>
#include<math.h>
int main(void)
{
      FILE *fp,*fout;
      fp=fopen("\A-large.in","r");
      fout=fopen("google_12_1BA_out.txt","w");
      int T;
      int n,i,j,sum;
      double every1,every2;
      int N[200]={0};
      fscanf(fp,"%d",&T);
      for(i=1;i<=T;i++)
      {
            fscanf(fp,"%d",&n);
            for(sum=0,j=0;j<n;j++)
            {
                  fscanf(fp,"%d",&N[j]);
                  sum+=N[j];
            }
            int nn=n;
            int sum1=sum;
            every1=(double)sum*2/nn;
            for(j=0;j<n;j++)
            {
                  if(N[j]>every1)
                  {
                        sum1-=N[j];
                        nn--;
                  }
            }
            every2=(double)(sum1+sum)/nn;
            fprintf(fout,"Case #%d: ",i);
            double temp;
            for(j=0;j<n;j++)
            {
                  temp=100*(double)((every2-N[j])/sum);
                  if(N[j]>every1)
                        fprintf(fout,"0.0000000");
                  else
                        fprintf(fout,"%.7lf",temp);
                  if(j!=n-1)
                        fprintf(fout," ");
                  else
                        fprintf(fout,"\n");
            }
      }
      fclose(fp);fclose(fout);
      return 0;
}
