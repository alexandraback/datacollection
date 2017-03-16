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
#include<iterator>
#include<fstream>
using namespace std;

char mapp[26]={'y','h','e','s','o','c','v',
			  'x','d','u','i','g','l','b',
			  'k','r','z','t','n','w',
			  'j','p','f','m','a','q'
};

int main()
{
	ifstream ifs("A-small-attempt0.in");
	ofstream ofs("A-small-attempt0.out");
	int n;
	ifs>>n;
	string s;
	getline(ifs,s);
	int cnt=1;
	while(n--)
	{
		cout<<n<<endl;
		
		getline(ifs,s);
		ofs<<"Case #"<<cnt<<": ";
		for(int i=0;i<s.length();i++)
		{
			char c;
			if(s[i]==' ')
				c=' ';
			else c=mapp[s[i]-97];
			ofs<<c;
		}
		ofs<<endl;
		cnt++;
	}
	ifs.close();
	ofs.close();
	return 0;
}