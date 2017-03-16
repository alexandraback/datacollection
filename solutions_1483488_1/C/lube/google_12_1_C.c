#include<stdio.h>
int main(void)
{
      FILE *fp,*fout;
      fp=fopen("\C-large.in","r");
      fout=fopen("google_12_C_out_l.txt","w");
      int T,a,b,temp,dig,i,j,k,c,pair,l,m,f;
      fscanf(fp,"%d",&T);
      for(i=1;i<=T;i++)
      {
            fscanf(fp,"%d %d",&a,&b);
            temp=a;dig=1;
            while(temp/10)
            {
                  temp/=10;
                  dig++;
            }
            int p[dig];
            for(k=1,l=1;k<dig;k++)
                  l*=10;
            for(pair=0,j=a;j<=b;j++)
            {
                  p[0]=j;
                  for(c=j,k=1;k<dig;k++)
                  {
                        c=l*(c%10)+(c/10);
                        p[k]=c;
                        if(c>=a&&c<=b)
                        {
                              for(f=0,m=0;m<k;m++)
                              {
                                    if(p[m]==c)
                                    {
                                          f=1;
                                          break;
                                    }
                              }
                              if(f==0)
                                    pair++;
                        }
                  }
            }
            fprintf(fout,"Case #%d: %d\n",i,pair/2);
      }
      fclose(fp);fclose(fout);
      return 0;
}
