#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
//#include <ctime>
#include <map>

using namespace std;

char s[101];
int a[101];
int b[101];
int p[101];
char ch[101][101];
char num[101][101];

int compare(const void *a,const void *b)
{
     return *(int*)b-*(int*)a;
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
	ios :: sync_with_stdio(false);
    int t,n;
    cin>>t;
    int a,b,p;
    for (int k=1;k<=t;k++)
    {
        cin>>a>>b>>p;
        int num=0;
        for (int i=0;i<=a-1;i++)
        for (int j=0;j<=b-1;j++)
        if ((i & j)<p)
        {
     //       cout<<i<<" "<<j<<" "<<(i and j)<<endl;
            num++;
        }
        cout<<"Case #"<<k<<": "<<num<<endl;
    }

    return 0;
}
