#include<bits/stdc++.h>
using namespace std;
int f[10010];
vector<int> vec;
int main()
{
    ifstream IF;
    IF.open("input.txt");
    ofstream OF;
    OF.open("output.txt");
    int t,i,n;

    IF >> t;
    for(int tc=1;tc<=t;tc++)
    {
       IF>>n;
       int ans=0;
       for(i=1;i<=n;i++)
         IF>>f[i];

         int xx=(1<<n);
         xx--;
         for(i=0;i<=xx;i++)
         {
            if(__builtin_popcount(i)>=2)
            {
                int temp=i;
                int arr[100]={0};
                int j=0;

                while(temp)
                {
                  arr[j++]=temp%2;
                  temp/=2;
                }
                vec.clear();
                for(j=0;j<n;j++)
                {
                  if(arr[j]==1)
                  {
                    vec.push_back(j+1);
                  }
                }

                 int sz=vec.size();


                do
                {


                   int flag=0;
                    for(int k=0;k<sz;k++)
                    {
                        if(f[vec[k]]==vec[(k+1)%sz] || f[vec[k]]==vec[(k-1+sz)%sz])
                        {
                              ;
                        }
                        else
                        {
                          flag=1;break;
                        }
                    }

                    if(flag==0)
                    {
                      ans=max(ans,sz);
                      break;
                    }
                }while(next_permutation(vec.begin(),vec.end()));

            }

         }

        OF <<"Case #" << tc << ": " <<ans << endl;
    }

    OF.close();
    IF.close();
}
