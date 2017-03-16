#include <cstdio>
int n;
int a[1005], b[1005], lvl[1005];;
int main()
{
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		scanf("%d", &n);
		int wynik = 0, proby = 0;
		for(int i = 0; i < n; i++)
		{
			scanf("%d %d", &a[i], &b[i]);
			lvl[i] = 0;
		}
		bool potrz = true, dasie = true;;
		for(int q = 0; q<3*n && potrz; q++)
		{
			int ind = -1;
			if(dasie == false)
			{
				for(int i = 0; i < n; i++)
					if(a[i] <= wynik && lvl[i] == 0)
						if(ind == -1 || (b[i] > b[ind]))
							ind = i;
			}
			if(ind != -1)
			{
				wynik++;
				proby++;
				lvl[ind] = 1;
			}
			potrz = false;
			dasie = false;
			for(int i = 0; i < n; i++)
			{
				if((a[i] <= wynik || b[i] <= wynik) && lvl[i] < 2)
					potrz = true;
				if(b[i] <= wynik && lvl[i]<2)
				{
					proby++;
					wynik += 2-lvl[i];
					lvl[i] = 2;
					dasie = true;
				}
			}
		}
		bool toobad = false;
		for(int i = 0; i < n; i++)
			if(lvl[i] != 2)
				toobad = true;
		if(toobad)
			printf("Case #%d: Too Bad\n", t);
		else
			printf("Case #%d: %d\n", t, proby);
	}
	return 0;
}
