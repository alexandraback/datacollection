//#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<fstream>
using namespace std;
int arr[110][110];
bool test[110][110];

int m,n,h,l;
void CLEAR()
{

    for(int i=0; i<110; i++)
        for(int j=0; j<110; j++)
        {
            arr[i][j]=0;
            test[i][j]=false;

        }
    h=l=0;
}
bool dfs1(int H,int idx)
{
    bool check=true;
    for(int i=0; i<n; i++)
    {
        if(arr[i][idx]>H)
        {
            check=false;
            break;
        }
    }
    return check;
}
bool dfs(int H,int idx)
{
    bool check=true;
    for(int i=0; i<m; i++)
    {
        if(arr[idx][i]>H)
        {
            check=false;
            break;
        }
    }

    if(check)
    {
//cout<<"returning true of "<<idx<<endl;
        return true;

    }

    bool c=false;
    for(int i=0; i<m; i++)
        if(arr[idx][i]==H)
        {
//cout<<idx<<" "<<i<<" "<<H<<endl;
//cout<<" calling "<<i<<endl;

            c= dfs1(H,i);
            if(c==false)
                break;
        }
    return c;
}

int main()
{
    int t,c;
    c=0;
    ifstream cin("B-small-attempt0.in");
    ofstream cout("B-small-attempt0.out");
    cin>>t;
    while(t--)
    {
        h=0;
        l=110;


        cin>>n>>m;
        CLEAR();

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                cin>>arr[i][j];
                l=min(l,arr[i][j]);
                h=max(h,arr[i][j]);
                test[arr[i][j]][i]=true;
            }
        bool check=true;;
        for(int i=l; i<=h&&check; i++)
            for(int j=0; j<n; j++)
            {
//cout<<"checking"<<endl;
// cout<<i<<" "<<j<<endl;

                if(test[i][j])
                {
//////////////////////////////
// cout<<"checking"<<endl;
// cout<<i<<" "<<j<<endl;

                    check=dfs(i,j);
// cout<<"checked "<<check<<endl;
                    if(!check)
                    {
// cout<<j<<endl;
                        break;
                    }
                }
            }
        if(check)
            cout<<"Case #"<<++c<<": YES"<<endl;
        else
            cout<<"Case #"<<++c<<": NO"<<endl;

    }
    return 0;
}
