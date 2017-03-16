#include <iostream>
using namespace std;
char l[111]={0};
int mas[111]={0};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int m, n;
	cin >> m;
	int res, col;
	for (int i=1; i<=m; ++i)
	{
		cin >> l >> n;
		res=0;
		int len=strlen(l);
		for (int p=0; p<len; ++p)
			if (l[p] == 'a' || l[p] == 'o' || l[p] == 'i' || l[p] == 'e' || l[p] == 'u')
				mas[p]=1;
			else
				mas[p]=0;
		for (int j=0; j<len; ++j)
			for (int k=j; k<len; ++k)
			{
				col=0;
				for (int p=j; p<=k; ++p)
					if (mas[p] == 1)
					{	
						if (col>=n)
						{
							res++;
							col=0;
							break;
						}
						else
							col=0;
					}
					else
						col++;
				if (col>=n)
					res++;
			}
			cout << "Case #" << i << ": " << res << "\n";

	}
	return 0;
}