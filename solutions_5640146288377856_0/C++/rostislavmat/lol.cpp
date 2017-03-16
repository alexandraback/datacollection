#include <algorithm>
#include <bitset>
#include <math.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <iomanip>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;



int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
    int qq;
	cin>>qq;
	for (int q=0;q<qq;q++)
	{
		cout<<"Case #"<<q+1<<": ";
		int r,c,w;
		cin>>r>>c>>w;
		int k=0;
		int y=c+1;
		if (w==c)
		{
			cout<<(r-1)+(c)<<endl;
		}
		else
		{
			while (2*w<c)
			{
				c-=w;
				k++;
			}
			int ff=(r-1)*(k+1);
			int gg=k+w+1;
			cout<<ff+gg<<endl;
		}
	}
    return 0;
}