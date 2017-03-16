#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<stdio.h>
#include<string.h>
using namespace std;
#define sz 100
int a[sz][sz];
map<int, bool>Mp;
vector<int>V;

bool IsRowClear(int value, int i, int pin, int M)
{
    for(int j=0;j<M;j++)
        if(a[i][j]>=pin)
            return false;
    return true;
}

bool IsColumnClear(int value, int j, int pin, int N)
{
    for(int i=0;i<N;i++)
        if(a[i][j]>=pin)
            return false;
    return true;

}

int FindAnswer(int N, int M)
{
    sort(V.begin(), V.end());

    //for(int i=0;i<V.size();i++) cout<<V[i]<<" "; cout<<endl;

    int b[sz][sz],value;
    bool flag;
    memset(b, 0, sizeof(b));
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            b[i][j]=V[V.size()-1];


    for(int p=V.size()-2;p>=0;p--)
    {
        value=V[p];
        for(int i=0;i<N;i++)
        {
            flag = IsRowClear(value, i, V[p+1], M);
            if(flag)
                for(int j=0;j<M;j++)
                    b[i][j]=value;
        }

        for(int j=0;j<M;j++)
        {
            flag = IsColumnClear(value, j, V[p+1], N);
            if(flag)
                for(int i=0;i<N;i++)
                    b[i][j]=value;
        }



    }

    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(a[i][j]!=b[i][j])
                return 0;
    return 1;

}

int main()
{
    freopen("B-large.in","r", stdin);
    freopen("BLargeoutput.out", "w", stdout);
    int T, N, M, MaxNum, result;


    cin>>T;
    for(int t=1;t<=T;t++)
    {
        cin>>N>>M;
        memset(a, 0, sizeof(a));
        Mp.clear();
        V.clear();
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
            {
                cin>>a[i][j];
                if(Mp[a[i][j]]==false)
                {
                    Mp[a[i][j]]=true;
                    V.push_back(a[i][j]);
                }

            }

        result=FindAnswer(N, M);
        cout<<"Case #"<<t<<": ";
        if(result==1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;


    }
}
