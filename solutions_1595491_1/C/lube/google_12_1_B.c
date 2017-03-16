#include<stdio.h>
int main(void)
{
      FILE *fp,*fout;
      fp=fopen("\B-large.in","r");
      fout=fopen("google_12_B_l_out.txt","w");
      int T,i,j;
      int N,S,p,num;
      int t[100]={0};
      fscanf(fp,"%d",&T);
      for(i=1;i<=T;i++)
      {
            fscanf(fp,"%d %d %d",&N,&S,&p);
            for(num=0,j=0;j<N;j++)
            {
                  fscanf(fp,"%d",&t[j]);
                  if((t[j]/3)>=p)
                        num++;
                  else
                  {
                        if(t[j]!=0)
                        {
                              if(t[j]%3==2)
                              {
                                    if((t[j]/3+1)>=p)
                                          num++;
                                    else if((t[j]/3+2)>=p&&S)
                                    {
                                          num++;
                                          S--;
                                    }
                              }
                              else if(t[j]%3==1)
                              {
                                    if((t[j]/3+1)>=p)
                                          num++;
                              }
                              else
                              {
                                    if((t[j]/3+1)>=p&&S)
                                    {
                                          S--;
                                          num++;
                                    }
                              }
                        }
                  }
            }
            fprintf(fout,"Case #%d: %d\n",i,num);
      }
      return 0;
}
