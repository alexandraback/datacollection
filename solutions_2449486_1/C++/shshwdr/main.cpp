#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include<cstdlib>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <utility>
#include <fstream>
#define INF     9999999
using namespace std;

int m,n;
        int a[202][117];
int te(int i,int tj)
{

    for(int jj=0;jj<n;jj++)
    {
    //    cout<<"what"<<i<<tj<<a[i][j]<<a[i][tj]<<endl;
        if(a[i][jj]>a[i][tj])return 0;
    }

    return 1;
}
int te2(int ti,int j)
{

    for(int ii=0;ii<m;ii++)
    if(a[ii][j]>a[ti][j])return 0;
    return 1;
}

int test(int i,int j)
{
    //cout<<"aa"<<i<<j<<te(i,j)<<te2(i,j)<<endl;
    if(te(i,j)||te2(i,j))return 0;
//cout<<"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n";

    return 1;
}

int main()
{
    int num;
    ifstream cin("B-large.in");
    ofstream cout("out.out");
    cin>>num;
    for(int nn=1;nn<=num;nn++)
    {

        int f=0;
        cin>>m>>n;

        for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            {cin>>a[i][j];}

        for(int i=0;i<m;i++)
        {


        for(int j=0;j<n;j++)
        {
     //   cout<<test(i,j)<<endl;
       // f=test(i,j);
      //  cout<<f<<endl;
        if(test(i,j)==1){f=1;break;}
        }
        if(f==1)break;
        }

        cout<<"Case #"<<nn<<": ";
        if(f==1)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;

    }
      return 0;
}




