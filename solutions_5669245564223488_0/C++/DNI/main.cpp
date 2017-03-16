#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<bitset>

#include<set>

using namespace std;


int main()
{

	freopen("b.in", "r", stdin);
	
	freopen("b.out", "w", stdout);


	int perm[200];
	for(int i = 0; i <200; i++)
		perm[i]  = i;

	int tt;
	cin >> tt;
	hash<string> hash_;
	
	
	for(int t = 1; t <= tt; t++)
	{
	
		set<size_t> ss;

		int n;
		cin >> n;
		vector<string> tr(n);
		for(int i = 0; i < n; i++)
			cin >> tr[i];


		int perm[200];
		for(int i = 0; i <200; i++)
			perm[i]  = i;

		long long answ = 0;
		do
		{
			bool bok = true;
			string sss;
			bool ar[256] = {0};
			for(int i = 0; i < n; i++)
			{
				sss += tr[perm[i]];
			/*	if(tr[perm[i-1]].back() != tr[perm[i]][0] || )
					bok= false;*/
					
			}
			for(int i = 0; i < sss.size();)
			{
				unsigned char c =  sss[i];
				if(!ar[c])
				{
					ar[c] = true;
				}
				else
				{
					bok = false;
					break;
					
				}

				while(c == sss[i] && i < sss.size() )
					i++;
			}

			if(bok)
				answ++;
			/*else
			{
				bok = true;
				for(int i = 1; i < sss.size(); i++)	
				{
					if(!(sss[i-1] == sss[i] || sss[i-1] == (sss[i]-1)))
						bok = false;
					
				}
				if(bok)
					answ++;
			}*/
		}while(next_permutation(perm, perm+n));

		printf("Case #%d: %d\n", t, answ);
	}


	return 0;
}