#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<memory.h>
#include<math.h>
using namespace std;
int main()
{
  fstream myf,f2;
  myf.open("input.txt",ios::in|ios::app);
  f2.open("output.txt",ios::out);
    int t;
    if(myf.is_open())
    {
        myf>>t;
        //cin>>t;
        //getline(cin,line);
        int test=0;
        while(t--)
        {
            test++;
            int A,N;
            myf>>A>>N;
            long long ar[N+1];
            ar[0]=-1;
            for(int i=1;i<=N;i++)
            myf>>ar[i];
            sort(ar,ar+N+1);
            long long sm[N+1];
            sm[0]=(long long)A;
            int nm[N+1];
            memset(nm,0,sizeof(nm));
            for(int i=1;i<=N;i++)
            {
                if(sm[i-1]>ar[i])
                {
                    sm[i]=sm[i-1]+ar[i];
                    nm[i]=nm[i-1];
                    //cout<<"a";
                }
                else if(sm[i-1]==ar[i]&&sm[i-1]>1LL)
                {
                    //cout<<"b";
                    sm[i]=sm[i-1]+ar[i]+sm[i-1]-1LL;
                    nm[i]=nm[i-1]+1;
                }
                else
                {
                    //cout<<(double)(ar[i]-sm[i-1])<<" "<<(double)(sm[i-1]-1)<<"\n";
                   //double n=log2((double)(ar[i]-sm[i-1])/(double)(sm[i-1]-1));
                    //cout<<sm[i-1]<<"\n";
                    int flg=0;
                    long long tot=sm[i-1];
                    //if(sm[i-1]!=0LL)
                    for(int j=0;j<=100;j++)
                    {
                        tot+=(tot-1LL);
                        //cout<<tot<<"\n";
                        if(tot>ar[i])
                        {
                            sm[i]=tot+ar[i];
                            nm[i]=nm[i-1]+(j+1);
                            flg=1;
                            //cout<<"yes\n";
                            break;
                        }
                    }
                    if(flg==0)
                    sm[i]=0LL,nm[i]=nm[i-1]+1;
                    //cout<<nm[i]<<"k";
                }
                //cout<<nm[i]<<" ";
            }
            int ans=1000000000;
            for(int i=0;i<=N;i++)
            {
                //cout<<nm[i]<<" ";
                ans=min(ans,nm[i]+N-i);
            }
            cout<<ans<<"\n";
            f2<<"Case #"<<test<<": ";
            f2<<ans<<"\n";
            //cout<<gain<<"\n";
        }
    }
    myf.close();
    f2.close();
    return 0;
}

