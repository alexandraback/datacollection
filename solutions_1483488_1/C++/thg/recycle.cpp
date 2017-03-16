#include<fstream.h>
#include<iostream.h>
#include<ctype.h>
#include<conio.h>
int sum=0;
int arr[8],n,tmpno[8],tmpnumber[200000];
int flag[8];
int supera,superb,finda;
int total=0;
int cnt;
int compute(int *arr,int pos)
{
    
    int j,k;
    for(j=0;j<n;j++)
    {
                    tmpnumber[cnt]=0;
                    for(k=0;k<n;k++)
                                    tmpnumber[cnt]=tmpnumber[cnt]*10+arr[(j+k)%n];
                    cnt++;
    }
}
int find(int a)
{
             finda=a;
          n=0;
          int i,j,k,addflag;
          cnt=0;
          //cout<<"num bef"<<a<<endl;
          while(a)
          {
                  arr[n++]=a%10;
                  a/=10;
          }
          for(i=0;i<n/2;i++)
          {
                          int tmp=arr[i];
                          arr[i]=arr[n-i-1];
                          arr[n-i-1]=tmp;
          }//cout<<"\nperm\n";
          for(i=0;i<8;i++)
                          flag[i]=1;
          
          compute(arr,0);
          addflag=1;
          for(i=0;i<cnt;i++)
                            if(tmpnumber[i]>finda&&tmpnumber[i]<=superb)
                            {
                                                                       addflag=0;
                                                                       break;
                            }
          for(i=0;i<cnt;i++)
          {
                            if(tmpnumber[i]>finda||tmpnumber[i]>superb||tmpnumber[i]<supera)
                                            {
                                                                          for(k=i;k<cnt-1;k++)
                                                                                              tmpnumber[k]=tmpnumber[k+1];
                                                                          i--;
                                                                          cnt--;
                                            }
                            for(j=0;j<i;j++)
                                            if(tmpnumber[j]==tmpnumber[i])
                                            {
                                                                          for(k=i;k<cnt-1;k++)
                                                                                              tmpnumber[k]=tmpnumber[k+1];
                                                                          i--;
                                                                          cnt--;
                                            }
          }/*cout<<"\nnumber=";
          for(i=0;i<n;i++)
                          cout<<arr[i];
          for(i=0;i<cnt;i++)
          {
                            cout<<endl<<tmpnumber[i];
                            
          }cout<<endl;*/
          if(addflag)
                     total+=(cnt*(cnt-1))/2;
          
          //getch();
}
main()
{
      int t;
      int a[50],b[50];
      int i,j;
      ifstream fin("C://google//recycle//a.in");
      ofstream fout("C://google//recycle//out.out");
      fin>>t;
      for(i=0;i<t;i++)
      {
                      fin>>a[i]>>b[i];
      }
      for(i=0;i<t;i++)
      {
                      total=0;
                      for(j=a[i];j<=b[i];j++)
                      {
                                       superb=b[i];
                                       supera=a[i];
                                       find(j);
                                       
                      }
                      cout<<"Case #"<<i+1<<": "<<total<<endl;
                      fout<<"Case #"<<i+1<<": "<<total<<endl;
                      
      }

      getch();
}
