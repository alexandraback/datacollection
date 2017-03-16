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
map<char,int> m;
int m1[110][110];
int main()
{
	memset(m1,0,sizeof(m1));
	m['a']=1;
	m['e']=1;
	m['i']=1;
	m['o']=1;
	m['u']=1;
    freopen ("A-small_1.in", "rt", stdin);
    freopen ("output_trial.txt", "wt", stdout);
    ifstream f;
    f.open ("A-small_1.in");
    ofstream ff;
    ff.open ("output_trial.txt");
    int t;
    cin>>t;
    int g=0;
    while(t--)
    {
        memset(m1,0,sizeof(m1));
        g++;
		
		cout<<"Case #"<<g<<": ";
		string s;
		int n;
		cin>>s>>n;
		int c=0,f=0;
		int flag=0;
		for(int i=0;i<s.length();i++)
		{
			c=0;
			for(int j=i;j<s.length();j++)
			{
				if(m[s[j]]==0)
				{
					//cout<<s[j]<<" ";
					c++;
					if(c==n)
					{
						for(int k=0;k<s.length();k++)
						{
							for(int l=k;l<s.length();l++)
							{
								if(i>=k && j<=l)
								{
									if(m1[k][l]==0)
									{
										f++;
										m1[k][l]=1;
									}
								}
							}
						}
						break;
					}
				}
				else
				break;
			}
			
		}
		cout<<f<<endl;

	}
	return 0;
}
