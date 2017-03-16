#include<iostream>
#include<cstdio>
#include<string>
#include<fstream>
#include <algorithm>


using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int main ()
{
	ifstream input;
	ofstream output;
	input.open("in.txt");
	output.open("out.txt");
	int test,tests;
	input >> tests;
	//printf("%d", tests);
	forn (test,tests)
	{
		printf("%d\n", test);
		int N;
		input >> N;
		int b[N];
		forn(i, N)
			input >> b[i];
		int a[N];
		forn(i,N)
			a[i] = i;
		int j = 0;
		int ans = 0;
		bool poss = true;
		for(j=0; j<N; j++)
		{
			poss = true;
			int k = 0;
			for(k = 0; k <= j ; k++)		
				if (b[a[k]]-1 == a[(k-1)%(j+1)] || b[a[k]]-1 == a[(k+1)%(j+1)]);
			else
				poss = false;
			if (poss)				
			ans = max(ans,j+1);
		}
		printf("%d " , ans);
		while (next_permutation(a, a+ N))
		{
			for(j=0; j<N; j++)
			{
			int k = 0;
			poss = true;
			for(k = 0; k <= j ; k++)		
				if (b[a[k]]-1 == a[(k-1)%(j+1)] || b[a[k]]-1 == a[(k+1)%(j+1)]);
			else
				poss = false;
			
			if (poss)
			{
				//if (k > ans){
				//	forn (i, j+1)
				//		printf("%d ",a[i]);
				//	printf("\n");
			//}
			ans = max(ans,j+1);
			}
			}
			//printf("%d ", ans);
			
			//printf("\n%d", ans);
			//printf("\n");
		}
		output << "Case #"<< test+1 << ": " << ans << "\n";
	}
}
				
								
		
