#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<fstream>
#include<vector>
using namespace std;
ifstream fin("Asmall.in");
//ifstream fin("Alarge.in");
ofstream fout("Asmall.out");
//ofstream fout("Alarge.out");
int Sz[110];
int main()
{
    int Asz,N;
    int T;
    fin>>T;
    for(int t=1;t<=T;t++)
    {
         fout<<"Case #"<<t<<": ";
         fin>>Asz>>N;
         cout<<Asz<<" "<<N<<endl;
         for(int i=0;i<N;i++)
         {
             fin>>Sz[i];
             cout<<Sz[i]<<" ";
         }
         sort(Sz,Sz+N);
         int ans=0,op=1<<30;
         bool flag=0;
         for(int i=0;i<N;i++)
         {
              if(Asz>Sz[i])
              {
                  Asz+=Sz[i];
                  continue;
              }
              flag=1;
              if(Asz+Asz-1<=Sz[i])
              {
                 
                 //ans+=N-i+1;
                 //break;
                 op=min(ans+N-i,op);
              }
              if(Asz==1)
              {
                 ans=op;
                 break;
              }
              Asz+=Asz-1;
              ans++;

              i--;
         }
         op=min(ans,op);
         if(!flag)op=0;
         fout<<op<<endl;
         cout<<op<<endl;
//         system("pause");
    }
	return 0;
}
