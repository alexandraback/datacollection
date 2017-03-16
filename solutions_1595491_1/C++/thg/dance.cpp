#include<fstream.h>
#include<iostream.h>
#include<conio.h>
int main()
{
    int t,n,s,p,a[101],b[3];
    int i,j,k,l,sno,nno,min,max,num;
    ifstream fin("C://google//dancing//a.in");
    ofstream fout("C://google//dancing//out.out");
    fin>>t;
    for(i=0;i<t;i++)
    {
                    fin>>n;
                    fin>>s;
                    fin>>p;
                    for(j=0;j<n;j++)
                                    fin>>a[j];
                    num=0;
                    for(j=0;j<n;j++)
                    {
                                    sno=0;nno=0;
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
                                                                             nno++;
                                                                else
                                                                             sno++;
                                                      }
                                    }
                                    if(nno)
                                           num++;
                                    else if(sno&&s)
                                    {
                                         num++;
                                         s--;
                                    }
                    }
                    fout<<"Case #"<<i+1<<": "<<num<<endl;
    }
    //getch();
}
