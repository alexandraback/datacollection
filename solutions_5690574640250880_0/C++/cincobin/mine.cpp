#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

bool calc(vector<vector<char> > &table, pair<int, int> &x)
{
	if(x.first-1 >= 0 && table[x.first-1][x.second] == '*')
		return false;
	if(x.first-1 >= 0 && x.second - 1>= 0 && table[x.first-1][x.second - 1] == '*')
		return false;
	if(x.second-1>= 0  && table[x.first][x.second - 1] == '*')
		return false;
	return true;

}

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("mine.in", std::ifstream::in);
    fout.open("mine.out", std::ifstream::out);
    int count;
    fin>>count;
    for(int i = 0; i < count; i++)
    {
		int m, r, c;
		fin>>r>>c>>m;
		int tm, tr, tc;
		int levelr, levelc;
		levelr = levelc = 0;
		int left = r * c;
		tm = m;
		tr = r;
		tc = c;
		vector<vector<char> > table;
		table.resize(r);
		for(int j = 0; j< r; j++)
			table[j].resize(c);
		for(int j = 0; j < r; j++)
			for(int k = 0; k < c; k++)
				table[j][k] = '.';
		while(tm > 0){
			if(tc <= tr)
			{
				if(tm >= tc)
				{
					for(int j = levelc; j < c; j++)
						table[levelr][j] = '*';
					levelr++;
					tm -= tc;
					tr--;
				}
				else
				{
					int a = 0;
					while(tm > 0)
					{
						table[levelr+a][levelc] = '*';
						tm --;
						if(tm == 0)
							break;
						table[levelr][levelc+a] = '*';
						if(a != 0) tm--;
						a++;
					}
					
				}
			}
			if(tr < tc){
				if(tm >= tr)
				{
					for(int j = levelr; j < r; j++)
						table[j][levelc] = '*';
					levelc++;
					tm -= tr;
					tc --;
				}
				else
				{
					int a = 0;
					while(tm > 0)
					{
						table[levelr][levelc+a] = '*';
						tm --;
						if(tm == 0)
							break;
						table[levelr+a][levelc] = '*';
						if(a != 0) tm--;
						a++;
					}
				}
			}
		}
		int num;
		for(int j = 0; j < r; j++)
		{
			for(int k = 0; k < c; k++)
			{
				cout<<table[j][k];
			}
			cout<<endl;
		}
		stack< pair<int, int> > f;
		f.push(make_pair<int, int>(r-1, c-1));
		while(!f.empty())
		{
			pair<int, int> b = f.top();
			f.pop();
			table[b.first][b.second] = 'x';
			if(calc(table, b)){
				if(b.first - 1 >= 0)
				{
					f.push(make_pair(b.first-1, b.second));
				}
				if(b.first - 1 >= 0 && b.second -1 >= 0)
				{
					f.push(make_pair(b.first-1, b.second-1));
				}
				if(b.second - 1 >= 0)
				{
					f.push(make_pair(b.first, b.second-1));
				}
			}
		}
		for(int j = 0; j < r; j++)
		{
			for(int k = 0; k < c; k++)
			{
				cout<<table[j][k];
			}
			cout<<endl;
		}
		bool flag = true;
		for(int j = 0; j < r; j++)
		{
			for(int k = 0; k < c; k++)
			{
				if(table[j][k] == '.')
					flag = false;
			}
		}
        
		if(flag)
		{
			fout<<"Case #"<<i+1<<": "<<endl;
			for(int j = 0; j < r; j++)
			{
				for(int k = 0; k < c; k++)
				{
					if(j == r -1 && k == c-1)
						fout<<'c';
					else if(table[j][k] == 'x')
						fout<<'.';
					else 
						fout<<'*';
				}
				fout<<endl;
			}
			
		}
		else
		{
			fout<<"Case #"<<i+1<<": "<<endl;
			fout<<"Impossible"<<endl;
		}
			
    }
    fin.close();
    fout.close();
    return 0;
}
