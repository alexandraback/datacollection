#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;

const int rate = 10;
const int speedhigh = 1*rate;
const int speedlow = 10*rate;
const int highspeedwater = 20;
const int space = 50;
const int Max = 100;
int c[Max][Max], f[Max][Max];
int t[Max][Max], q[Max];
struct entry
{
	int x, y;
	int value;
	bool operator < (const entry& c) const {return value != c.value ? value < c.value : x!=c.x ? x<c.x : y<c.y; }
};
int H, N, M;
void move(int x0, int y0, int x1, int y1, int value, set<entry>& s);
int main()
{
	int T;
	cin>>T;
	for(int _=1;_<=T;_++)
	{
		cin>>H>>N>>M;
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				cin>>c[i][j];
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				cin>>f[i][j];
		entry temp;
		temp.x = temp.y = temp.value = 0;
		set<entry> s;
		s.insert(temp);
		memset(t,0x3f,sizeof(t));
		t[0][0] = 0;
		//0-0 -> (n-1,m-1)
		while(!s.empty())
		{
			temp = *s.begin();
			s.erase(s.begin());
			if(temp.value > t[temp.x][temp.y])
			{
				//cout<<temp.x<<","<<temp.y<<" having value "<<temp.value<<", expecting "<<t[temp.x][temp.y]<<endl;
				continue;
			}
			if(temp.x > 0)
				move(temp.x,temp.y,temp.x-1,temp.y,temp.value,s);
			if(temp.y > 0)
				move(temp.x,temp.y,temp.x,temp.y-1,temp.value,s);
			if(temp.x < N-1)
				move(temp.x,temp.y,temp.x+1,temp.y,temp.value,s);
			if(temp.y < M-1)
				move(temp.x,temp.y,temp.x,temp.y+1,temp.value,s);
		}
		cout<<"Case #"<<_<<": "<<t[N-1][M-1]*0.1<<endl;
	}
}
void move(int x0, int y0, int x1, int y1, int value, set<entry>& s)
{
	int result = value;
	int ceil = min(c[x0][y0], c[x1][y1]);
	int floor = max(f[x0][y0], f[x1][y1]);
	int requiredbottom = ceil - space;
	if(ceil-floor < space)
	{
		//cout<<"("<<x0<<","<<y0<<")->("<<x1<<","<<y1<<") not reachable"<<endl;
		return;
	}
	int curwater = H-value;
	int curbottom = max(curwater, f[x0][y0]);
	if(curbottom < requiredbottom)
		requiredbottom = curbottom;
	else
		result += curbottom - requiredbottom; //waiting time
	int newfloor = f[x0][y0]+highspeedwater;
	if(requiredbottom >= newfloor)
	{
		//go with high-speed
		if(result > 0)
			result += speedhigh; //moving time
	}
	else
	{
		if(result > 0)
			result += speedlow; //moving time
	}
	if(result < t[x1][y1])
	{
		t[x1][y1] = result;
		entry e;
		e.x = x1;
		e.y = y1;
		e.value = result;
		s.insert(e);
		//cout<<"("<<x0<<","<<y0<<")->("<<x1<<","<<y1<<") time "<<result<<endl;
	}
}
