#include <iostream>
#include <cstdio>
using namespace std;

double nao[1024], ken[1024];
pair<double, int> comb[2048];

int main()
{
	freopen("D-large.in", "r", stdin);
	freopen("D-large.out", "w", stdout);
	int T;
	cin >> T;
	for(int tc=1; tc<=T; tc++)
	{
		int N;
		cin >> N;
		for(int i=0; i<N; i++)
		{
			cin >> nao[i];
			comb[i]=make_pair(nao[i],1);
		}
		
		for(int i=0; i<N; i++)
		{
			cin >> ken[i];
			comb[i+N]=make_pair(ken[i],-1);
		}
		
		sort(nao, nao+N);
		sort(ken, ken+N);
		sort(comb, comb+2*N);
		//cout << "TODO BIEN" << endl;
		
		int sum=0, best=0;
		for(int i=2*N-1; i>=0; i--)
		{
			sum+=comb[i].second;
			//cout << comb[i].first << " " << comb[i].second << endl;
			best=max(sum, best);
		}
		
		int best2=0;
		for(int i=1; i<=N; i++)
		{
			int valid=1;
			for(int j=0; j<i; j++)
			{
				if(ken[j]>nao[N-i+j]) valid=0;
			}
			if(valid) best2=i;
		}
		
		cout << "Case #" << tc << ": ";
		cout << best2 << " " << best;
		cout << endl;
	}
}
