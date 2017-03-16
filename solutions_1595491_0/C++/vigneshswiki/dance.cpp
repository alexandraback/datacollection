#include<fstream.h>
#include<iostream.h>
int main()
{
    int iter;
    int t,i,j,k,l,surp,cant,min,max,tot;
    ifstream fin("C://wiki//dancing//a.in");
    ofstream fout("C://wiki//dancing//out.out");
    int n,s,p,a[101],b[3];
    fin>>t;
    for(i=0;i<t;i++)
    {
                    fin>>n;
                    fin>>s;
                    fin>>p;
                    for(j=0;j<n;j++)
                                    fin>>a[j];
                    tot=0;
                    for(j=0;j<n;j++)
                    {
                                    surp=0;cant=0;
                                    for(k=-2;k<=2;k++)
                                    {
                                                      b[0]=a[j]/3+k;
                                                      b[1]=a[j]/3;
                                                      b[2]=a[j]-b[0]-b[1];
                                                      min=max=b[0];
                                                      if(b[0]<0||b[1]<0||b[2]<0)
                                                                continue;
                                                      for(l=1;l<3;l++)
                                                      {
                                                                      if(b[l]<min)
                                                                                  min=b[l];
                                                                      if(b[l]>max)
                                                                                  max=b[l];
                                                      }
                                                      if(b[0]+b[1]+b[2]!=a[j])
                                                                              continue;
                                                      if(max-min>2)
                                                                   continue;
                                                      if(max>=p)
                                                      {
                                                                if(max-min<2)
                                                                             cant++;
                                                                else
                                                                             surp++;
                                                      }
                                    }
                                    if(cant)
                                           tot++;
                                    else if(surp&&s)
                                    {
                                         tot++;
                                         s--;
                                    }
                    }
                    fout<<"Case #"<<i+1<<": "<<tot<<endl;
    }
}
