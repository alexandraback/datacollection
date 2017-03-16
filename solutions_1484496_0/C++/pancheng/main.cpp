#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>

#define MAX 100010

using namespace std;

int N;
int s[21];
int flag[21];

struct Str
{
    int c;
    int flag[21];
}str[2000100];

bool DFS(int depth)
{
    if( depth==N )
    {
        int sum=0;
        for( int i=0; i!=N; i++)
            if( flag[i] )
                sum +=s[i];
        if( sum>0  )
        {
            if( str[sum].c==0)
            {
                str[sum].c=1;
                memcpy(str[sum].flag,flag,21*sizeof(int));
                return false;
            }
            else
            {
                for( int i=0; i!=N; i++)
                    if( str[sum].flag[i] )
                        cout<<s[i]<<" ";
                cout<<endl;
                for( int i=0; i!=N; i++)
                    if( flag[i] )
                        cout<<s[i]<<" ";
                cout<<endl;
                return true;
            }
        }
        return false;
    }
    flag[depth]=0;
    if( DFS(depth+1))
        return true;
    flag[depth]=1;
    if(DFS(depth+1))
        return true;
    return false;
}

void solve()
{

}
int main()
{
    freopen("C-small-attempt1.in","r",stdin);
    //freopen("data.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    cin>>T;

    for( int t=0; t!=T; t++)
    {
        cin>>N;
        for( int i=0; i!=N; i++)
        {
            cin>>s[i];
        }
        memset(str,0,sizeof(Str)*2000100);
        printf("Case #%d:\n",t+1);
        if( !DFS(0) )
            cout<<"Impossible"<<endl;

    }

    return 0;
}
