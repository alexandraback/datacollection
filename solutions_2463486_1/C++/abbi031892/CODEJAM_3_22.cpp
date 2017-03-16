#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<string.h>
#include<fstream>
using namespace std;
long long arr[39]={1,
4,
9,
121,
484,
10201,
12321,
14641,
40804,
44944,
1002001,
1234321,
4008004,
100020001,
102030201,
104060401,
121242121,
123454321,
125686521,
400080004,
404090404,
10000200001,
10221412201,
12102420121,
12345654321,
40000800004,
1000002000001,
1002003002001,
1004006004001,
1020304030201,
1022325232201,
1024348434201,
1210024200121,
1212225222121,
1214428244121,
1232346432321,
1234567654321,
4000008000004,
4004009004004};
int main()
{
    freopen ("C-large-1.in", "rt", stdin);
    freopen ("output_1_2.txt", "wt", stdout);
    ifstream f;
    f.open ("C-large-1.in");
    ofstream ff;
    ff.open ("output_1_2.txt");
    int t;
    cin>>t;
    int g=0;
    while(t--)
    {
        g++;
		long long int a,b;
		cin>>a>>b;
		cout<<"Case #"<<g<<": ";
		int c=0;
		for(int i=0;i<39;i++)
		{
			if(arr[i]>=a && arr[i]<=b)
			{
				c++;
			}
		}
		cout<<c<<endl;
	}
	return 0;
}
