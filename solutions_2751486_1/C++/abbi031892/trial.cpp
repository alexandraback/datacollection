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
    freopen ("A-large (1).in", "rt", stdin);
    freopen ("output_trial.txt", "wt", stdout);
    ifstream f;
    f.open ("A-large (1).in");
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
		long long answer=0;
		long long last=-1;
		long long cnt=0;
		long long nn=s.size();
		for(int i=0;i<nn;i++)
		{
			if(m[s[i]]==0)
			{
				cnt++;
				if(cnt>=n)
				{
					answer+=((i-n+1)-last)*(nn-i);
					last=i-n+1;
				}
			}
			else
			{
				cnt=0;
			}
		}
		cout<<answer<<endl;

	}
	return 0;
}
