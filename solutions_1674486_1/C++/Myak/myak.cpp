#include <iostream>

using namespace std;

int a[1010][1010]={{0}};
int use[1010]={0};
int que[100100]={0};

int main()
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	int t, n, col, temp, f, l;
	bool fl;
	cin >> t;
	for (int i=1; i<=t; i++)
	{
		for (int q=0; q<=1000; q++)
			for (int w=0; w<=1000; w++)
				a[q][w]=0;
		cin >> n;
		for (int j=1; j<=n; j++)
		{
			cin >> col;
			for (int k=0; k<col; k++)
			{
				cin >> temp;
				a[j][temp]=1;
			}
		}
		cout << "Case #" << i << ": ";
		//
		for (int j=1; j<=n; j++)
		{
			for (int k=1; k<=1000; k++)
				use[k]=0;
			f=0, l=0;
			que[f]=j;
			f++;
			fl=false;
			while (l<f)
			{
				for (int k=1; k<=n; k++)
					if (a[que[l]][k]==1)
						if (use[k]==1)
						{
							cout << "Yes";
							fl=true;
							break;
						}
						else
						{
							use[k]=1;
							que[f]=k;
							f++;
						}
				l++;
				if (fl)
					break;
			}
			if (fl)
				break;
		}
		if (!fl)
			cout << "No";
		//
		cout << "\n";
	}

	
	return 0;
}