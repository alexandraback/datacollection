#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <fstream>
#include <iomanip>

#define FR(i,a) for(int i=1;i<=a;i++)

using namespace std;

int main()
{
    freopen("A-large.in","r+",stdin);
    freopen("output1.txt","w+",stdout);
    int T,it=1;
    cin>>T;
    char arr[1001][1001];
    while(it<=T)
    {
        int N;
        bool check=false;
        memset(arr,0,1000000);
        cin>>N;
        FR(i,N)
        {
            int A,no;
            cin>>A;
            FR(j,A)
            {
                  cin>>no;
                  arr[i][no]++;
            }
        }
        FR(i,N)
        {
           FR(j,N)
           {
                FR(k,N)
                {
                    if(arr[j][i]&&arr[i][k])
                        arr[j][k]++;
                }
            }
        }
        FR(i,N)
        {
            FR(j,N)
            {
                if(arr[i][j]>1)
                {
                    check=true;break;
                }
            }
            if(check)
                break;
        }
        if(check)
            cout<<"Case #"<<it++<<": "<<"Yes"<<endl;
        else
            cout<<"Case #"<<it++<<": "<<"No"<<endl;
    }

}

