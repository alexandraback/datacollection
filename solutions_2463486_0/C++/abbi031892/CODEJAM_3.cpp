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
bool arr[1010],arr1[10010];
bool isPalin(long long a)
{
	string s;
	while(a>0)
	{
		int k=a%10LL;
		s=char(k+'0')+s;
		a/=10LL;
	}
	if(s.length()==1)
	return true;
	if(s.length()%2==0)
	{
		int i=0,j=s.length()-1;
		int k=(s.length()-1)/2;
		for(int i=0;i<=k;i++)
		{
			if(s[i]!=s[j])
			return false;
			j--;
		}
		return true;
	}
	else
	{
        int i=0,j=s.length()-1;
		int k=s.length()/2;
		for(int i=0;i<k;i++)
		{
			if(s[i]!=s[j])
			return false;
			j--;
		}
		return true;
	}

}
int main()
{
	freopen ("C-small.in", "rt", stdin);
    freopen ("output_1.txt", "wt", stdout);
    ifstream f;
    f.open ("C-small.in");
    ofstream ff;
    ff.open ("output_1.txt");
	
	for(long long int i=1;i<=1000;i++)
	{
		arr[i]=isPalin(i);
		
		//cout<<g<<" "<<i<<endl;
	}
	for(int i=1;i<=100;i++)
	{
        if(arr[i]==true)
		{
			if(isPalin(i*i))
			arr1[i*i]=true;
		}
	}
	int t;
	cin>>t;
	int g=0;
	while(t--)
	{
		g++;
		int a,b;
		cin>>a>>b;
		cout<<"Case #"<<g<<": ";
		int c=0;
		for(int i=a;i<=b;i++)
		{
			if(arr1[i]==true)
			c++;
		}
		cout<<c<<endl;
	}
		

//	system("pause");
	return 0;
}
