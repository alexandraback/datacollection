#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <limits.h>
#include <vector>
#include <map>
#include <string>
#include <iterator>
#include <set>
#include <utility>
#include <queue>
#include <numeric>
#include <functional>
#include <ctype.h>
#include <stack>
#include <algorithm>
#include <cstdlib>
#define MAX 100100
#define mod 1000000007
#define MS0(x) memset(x, 0, sizeof(x))
#define ll long long int
#define in(x) scanf("%I64d", &x)
#define ind(x) scanf("%d", &x)

using namespace std;

int main()
{
	//#ifndef ONLINE_JUDGE
//#endif
	//freopen("input1.in", "r", stdin);
   //freopen("output.txt","w",stdout);
	 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 int t,tc;
 cin>>tc;
 for(t=1;t<=tc;t++)
 {
 	int n,x,i,j;
 	int d[2502]={0};
 	
 	int e[2501]={0};
 	cin>>n;
 	for(i=0;i<(2*n)-1;i++)
 	{
 		for(j=0;j<n;j++)
 		{
 			cin>>x;
 			d[x]++;

 		}
 	}
 	int k=0;
 	for(i=1;i<=2500;i++)
 	{
 		if(d[i]%2==1)
 		{
 			e[k]=i;
 			k++;
 		}
 	}
 	
 	sort(e,e+k);
    cout<<"Case #"<<t<<": ";
    for(i=0;i<k;i++)
    {
    	cout<<e[i]<<" ";
    }
    cout<<"\n";
 }
	return 0;
}