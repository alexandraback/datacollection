#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int w, h, d;
char fld[133][133];
int w1, w2, h1, h2;

int hd[1000];

bool check(int a, int b, bool fw, bool aw, bool fh, bool ah)
{
	if (a==0 && b==0 && !aw && !ah) return false;
	//cout << a << " " << b << " " << (fw?"w1":"w2") << " " << (aw?"add":"not") << " " << (fh?"h1":"h2") << " " << (ah?"add":"not") << endl;
	int wt = (w1+w2)*a + w1*(aw && fw) + w2*(aw && !fw);
	int ht = (h1+h2)*b + h1*(ah && fh) + h2*(ah && !fh);
	if (wt*wt+ht*ht>d*d)
		return false;
	
	if (a==0 && !fw && !aw) return false;
	if (b==0 && !fh && !ah) return false;
	
	if (a==0 && !aw) return b==0 && ah;
	if (b==0 && !ah) return a==0 && aw;
	
	int hl=0, hp=0;
	bool first = fw;
	for (int i=(first?w1:w2);i<wt;i+=(first?w2:w1),first=!first)
	{
		if (i*ht%wt==0)
			hd[hl++]=i*ht/wt;
	}
	first = fh;
	for (int i=(first?h1:h2);hp<hl && i<ht;i+=(first?h2:h1),first=!first)
	{
		while (hp<hl && i>hd[hp]) ++hp;
		if (hp<hl && hd[hp]==i)
			return false;
	}
	return true;
}

void solve()
{
	int m=0;
	
	for (int i=1;i+1<h;++i)
	{
		for (int j=1;j+1<w;++j)
		{
			if (fld[i][j]=='X')
			{
				w1 = 2*(j-1) + 1;
				w2 = 2*(w-j-2) + 1;
				h1 = 2*(i-1) + 1;
				h2 = 2*(h-i-2) + 1;
			}
		}
	}
	
	for (int a = 0;a<50; ++a)
	{
		int b;
		for (b=0;b<50;++b)
		{
			for (int x=0;x<=3;++x)
				for (int y=0;y<=3;++y)
					if (check(a,b,x%2==0,x>1,y%2==0,y>1))
					{
						//cout << " true" << endl;
						++m;
					}
		}
	}
	fout << m;
}

int main()
{
	int T;
	fin >> T;
	for (int i=0;i<T;++i)
	{
		fin >> h >> w >> d;
		
		fin.getline(fld[0], 33);
		for (int j=0;j<h;++j)
		{
			fin.getline(fld[j], 33);
		}
		
		fout << "Case #" << i+1 << ": ";
		solve();
		fout << endl;
	}
	return 0;
}