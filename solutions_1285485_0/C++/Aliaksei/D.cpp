#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <fstream>
#include <algorithm>
using namespace std;

int gcd (int a, int b) {
	return b ? gcd (b, a % b) : a;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	cin>>T;
	for (int cs=0; cs<T; ++cs)
	{
		set <pair<int, int> > ans;
		int h, w, d;
		cin>>h>>w>>d;
		pair<int, int> start;
		char a;
		for(int i=0; i<h; ++i)
			for(int j=0; j<w; ++j) {
				cin>>a;
				if (a=='X') {
					start.first=i;
					start.second=j;
				}
			}


		
		h=(h-2)*2;
		w=(w-2)*2;
		int x=h-(start.first*2-1);
		int y=(start.second*2-1);
		d*=2;
		d*=d;
		int xx, yy, gs;

		for (int i=-110; i<110; ++i)
			for (int j=-110; j<110; ++j)
			{		
				if (i==0&&j==0) continue;
				if(i%2) xx=h*i+h-x;
				else xx=h*i+x;

				if(j%2) yy=w*j+w-y;
				else yy=w*j+y;

				if ((xx-x)*(xx-x)+(yy-y)*(yy-y)<=d) {
					if (xx-x>=0&&yy-y>=0) {
					gs=gcd(xx-x, yy-y);
					ans.insert(make_pair((xx-x)/gs, (yy-y)/gs));
					}
					else if (xx-x>=0&&yy-y<=0) {
					gs=gcd(xx-x, y-yy);
					ans.insert(make_pair((xx-x)/gs, (yy-y)/gs));
					}
					else if (xx-x<=0&&yy-y>=0) {
					gs=gcd(x-xx, yy-y);
					ans.insert(make_pair((xx-x)/gs, (yy-y)/gs));
					}
					else  {
					gs=gcd(x-xx, y-yy);
					ans.insert(make_pair((xx-x)/gs, (yy-y)/gs));
					}
				}
			}
			cout<<"Case #"<<cs+1<<": "<<ans.size()<<endl;
			
				
	}
}