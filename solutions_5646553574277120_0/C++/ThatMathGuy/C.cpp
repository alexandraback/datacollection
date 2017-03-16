#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <bitset>
#include <string.h>

using namespace std;

typedef long long ll;

ifstream fin("input.txt");
ofstream fout("output.txt");

int tc;

int x;
int y;

int c,d,v;

int a[33];

int rez;

void rev(int z,int l, int le)
{
    if (l>=rez+d) return;
    if (z==v && le) return;
    if (!le)
    {
        if ((y&x)!=y) return;
        memset(a,0,sizeof(a));
        a[0]=1;
        for (int i=0; i<31; i++)
			if (x&(1<<i))
			{
				for (int j=v; j>=0; j--)
				{
					if (a[j] && j+i+1<=v) a[j+i+1]=1;
				}
			}
		bool flag=true;
		for (int i=0; i<=v; i++) if (!a[i]) {flag = false; break;}
		if (!flag) return;
		rez = min(rez, l-d);
		return;
    }

    rev(z+1,l,le);
    x|=(1<<z);
    rev(z+1,l,le-1);
    x^=(1<<z);
}

int main()
{
	fin>>tc;

	for (int tt=1; tt<=tc; tt++)
	{
		y=0;
		fin>>c>>d>>v;
		rez=v;

		for (int i=0; i<d; i++)
			{
				int t;
				fin>>t;
				t--;
				y|=(1<<t);
			}

		for (int i=d; i<=v && rez==v; i++)
            rev(0,i,i);

		fout<<"Case #"<<tt<<": ";
		fout<<rez;
		fout<<'\n';
		cout<<"Case #"<<tt<<": ";
		cout<<rez;
		cout<<'\n';
	}

	return 0;
}
