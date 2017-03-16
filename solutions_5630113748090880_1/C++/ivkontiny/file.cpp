#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
ofstream fout("file.out");
const int MAX_LEN=2510;
int used[MAX_LEN],t,n;
int main()
{
    int a;
    cin>>t;
    for(int k=1;k<=t;++k)
    {
        cin>>n;
        for(int i=1;i<=2*n-1;++i)
        {
            for(int j=1;j<=n;++j)
            {
                cin>>a;
                ++used[a];
            }
        }
        fout<<"Case #"<<k<<": ";
        for(int i=1;i<=2500;++i)if(used[i]%2)fout<<i<<" ";
        fout<<"\n";
        memset(used,0,sizeof(used));
    }
    return 0;
}
