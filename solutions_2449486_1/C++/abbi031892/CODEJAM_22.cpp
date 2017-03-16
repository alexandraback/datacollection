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
int main()
{
    freopen ("B-large.in", "rt", stdin);
    freopen ("output_2.txt", "wt", stdout);
    ifstream f;
    f.open ("B-large.in");
    ofstream ff;
    ff.open ("output_2.txt");
	int t;
	cin>>t;
	int g=0;
	while(t--)
	{
		g++;
		cout<<"Case #"<<g<<": ";
		int n,m;
		cin>>n>>m;
		int arr[n][m];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>arr[i][j];
			}
		}
		int max_row[n],max_col[m];
		for(int i=0;i<n;i++)
		{
			int m1=-1;
			for(int j=0;j<m;j++)
			{
				if(arr[i][j]>m1)
				m1=arr[i][j];
			}
			max_row[i]=m1;
		}
		for(int i=0;i<m;i++)
		{
			int m1=-1;
			for(int j=0;j<n;j++)
			{
				if(arr[j][i]>m1)
				m1=arr[j][i];
			}
			max_col[i]=m1;
		}
		int flag=0;
		for(int i=0;i<n;i++)
		{
			if(flag==1)
			break;
			for(int j=0;j<m;j++)
			{
				if(arr[i][j]==max_row[i] || arr[i][j]==max_col[j])
				{
				}
				else
				{
				//8	cout<<i<<" "<<j<<" "<<max_row[i]<<" "<<max_col[j]<<endl;
				flag=1;
				break;
			    }
			}
		}
		if(flag==1)
		printf("NO\n");
		else
		printf("YES\n");
	}
	
//	system("pause");
	return 0;
}
