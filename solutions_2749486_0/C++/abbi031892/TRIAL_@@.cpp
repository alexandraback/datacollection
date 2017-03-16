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
int ab(int a)
{
	if(a<0)
	return -1*a;
	return a;
}

int arr1[4]={1,-1,0,0};
int arr2[4]={0,0,1,-1};
char arr3[4]={'E','W','N','S'};
using namespace std;
vector<string> v1;
string reach(int x,int y,int x1,int y1,string s,int k)
{
	cout<<s<<endl;
	if(ab(x1)>x+10 || ab(y1)>y+10)
	return "";
	if(x==x1 && y==y1)
	{
		v1.push_back(s);
		return s;
	}
	string s1[4];
	for(int i=0;i<4;i++)
	{
		s1[i]=reach(x,y,x1+arr1[i]*k,y1+arr2[i]*k,s+arr3[i],k++);
	}
	string ans=s1[0];
	int len=s1[0].length();
	for(int i=0;i<4;i++)
	{
		if(s1[i].length()<len && s1[i].length()!=0)
		{
			ans=s1[i];
		}
	}
	return ans;
}

int main()
{
	
   /* freopen ("A-small_1.in", "rt", stdin);
    freopen ("output_trial.txt", "wt", stdout);
    ifstream f;
    f.open ("A-small_1.in");
    ofstream ff;
    ff.open ("output_trial.txt");*/
    int t;
    cin>>t;
    int g=0;
    while(t--)
    {
       
        g++;

		cout<<"Case #"<<g<<": ";
		int x,y;
		cin>>x>>y;
		string temp="";
		cout<<v1.size()<<endl;
		cout<<reach(x,y,0,0,temp,1)<<endl;
		
	}
	return 0;
}
