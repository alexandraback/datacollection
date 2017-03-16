#include "iohelper.h"
#include <set>
#include <sstream>
using namespace std;

vector<string> result1;

bool canSpand(vector<string>& mmap,int x,int y,int remain)
{
	if(remain == 0)
	{
		stringstream ss("");
		for(int i = 0;i < mmap.size();i++)
		{
			ss<<endl<<mmap[i];
		}
		result1.push_back(ss.str());
		return true;
	}
	bool cans = false;
	vector<pair<int,int>> next;
	for(int i = x-1;i <= x+1;i++)
	{
		for(int j = y-1;j <= y+1;j++)
		{
			if(i >= 0 && i < mmap.size() && j >= 0 && j < mmap[0].size() && (i != x || j!= y))
			{
				if(mmap[i][j] == '*'){
					mmap[i][j] = '.';
					next.push_back(pair<int,int>(i,j));
				}
			}
		}
	}
	if(next.size() <= 0 || next.size() > remain)
	{
		cans = false;
	}
	else if(next.size() == remain)
	{
		cans = true;
		stringstream ss("");
		for(int i = 0;i < mmap.size();i++)
		{
			ss<<endl<<mmap[i];
		}
		result1.push_back(ss.str());
	}else{
		for(int i = 0;i < next.size();i++)
		{
			if(canSpand(mmap,next[i].first,next[i].second,remain-next.size()))
			{
				cans = true;
				break;
			}
		}	
	}
	for(int i = 0;i < next.size();i++)
	{
		mmap[next[i].first][next[i].second] = '*';
	}	
	return cans;
}

void readFunc1(ifstream& in)
{
	int R,C,M;
	in>>R>>C>>M;
	int n = R*C;
	int s = n-M;
	vector<string> mmap;
	for(int i = 0;i < R;i++)
	{
		string str(C,'*');
		mmap.push_back(str);
	}
	int remain = s;
	bool cans = false;
    for(int i = 0;i < R;i++)
	{
		for(int j =0;j < C;j++)
		{
			mmap[i][j] = 'c';
			if(canSpand(mmap,i,j,remain-1))
			{
				cans = true;
				break;
			}
			mmap[i][j] = '*';
		}
		if(cans) break;
	}
	if(!cans)
	{
		stringstream ss("");
		ss<<endl<<"Impossible";
		result1.push_back(ss.str());
	}
}

int main()
{
	IOHelper io;
	io.readFile("C-small-attempt2.in",readFunc1);
	io.writeFile("C-small-attempt2.out",result1);
	return 0;
}