/* 	Language C++
	Email xmlyqing00@gmail.com
	Copyright Liang Yongqing all
*/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>

using namespace std;
#define fi first
#define se second
#define ll long long
#define INF 2000000000
#define eps 1e-12

ll r,t,Left,Right,mid;
long double temp;

int main()
{
	freopen("temp.in","r",stdin);
	freopen("temp.out","w",stdout);

    int Test,test;

    scanf("%d",&Test); test=0;
    while (Test--)
    {
        cin>>r>>t;

        Left=1; Right=1000000000000000000LL;
        //Right=10;
        while (Left<Right)
        {
            mid=(Left+Right+1)>>1;

            temp=t;
            temp=temp/mid;
            temp=temp-(2*r-1);
            if ((temp/2)>=mid) Left=mid;
                else Right=mid-1;
        }
        printf("Case #%d: ",++test);
        cout<<Left<<endl;
    }

	return 0;
}
