#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int T;
int cnt,N,sur,p,surt;
int score[105];
int main()
{
    freopen("inb.txt","r",stdin);
    freopen("outb.txt","w",stdout);
    cin>>T;
    for(int i=1;i<=T;i++)
    { 
            cnt=0;
            memset(score,0,sizeof(score));
            cin>>N>>sur>>p;
            for(int j=0;j<N;j++)
            cin>>score[j];
            sort(score,score+N);
            surt=sur;
            for(int j=N-1;j>=0;j--)
            if(score[j]>0)
            {
               if(score[j]>=(3*p-2))
                  cnt++;
               else if(score[j]<(3*p-4))
                  continue;
               else 
               {
                    if(surt)
                    {
                        surt--;
                        cnt++;
                    }
               }
                    
                    
            }
            else if(score[j]==0)
                 {
                     if(p==0)
                     cnt++;
                 }
          
            //for(int j=0;j<N;j++)
            //cout<<score[j]<<endl;
            cout<<"Case #"<<i<<": "<<cnt<<endl;
    }
    return 1;   

}    
