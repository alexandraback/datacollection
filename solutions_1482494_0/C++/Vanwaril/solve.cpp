#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

struct game{
	int one;
	int two;
	int cur;
};

bool cmp_one(game g1, game g2) {
	return g1.one < g2.one;
}

bool cmp_two(game g1, game g2) {
	return g1.two < g2.two;
}

bool sort_total(game g1, game g2) {
	int a = (g1.cur == 2)?g1.two:g1.one;
	int b = (g2.cur == 2)?g2.two:g2.one;

	if( a == b ) return g1.cur < g2.cur;
	return a < b;
}

int main()
{
	int N;
	
	cin>>N;
	// Case-independent stuff?
	
	// Cases:
	for(int t=1; t<=N; t++)
	{
		// Each Case:
		int output=0;
		
		// random variables
		int max_stars = 0, stars=0;
		bool too_bad = false;
		
		// input variables
		int N;
		
		cin>>N;
		vector<game> g(N);
		for(int i=0; i<N; i++) {
			cin>>g[i].one>>g[i].two;
			g[i].cur = 2;
			if( g[i].two > max_stars ) max_stars = g[i].two;
		}
		if(max_stars > 2*N-1) {
			printf("Case #%d: Too Bad\n", t);
		} else {
		
		vector<int> played_one(N,0);
		
		// compute
		sort(g.begin(), g.end(), cmp_two);

		for(int i=0; i<N && !too_bad; i++)
		{
			if(g[i].two <= stars) // have enough stars
			{
				if(played_one[i]) stars++;
				else stars += 2;
				played_one[i] = 1; // as though its been played
				output ++; // I played ONE game.
			//	cout<<"Played "<<i<<endl;
		/*	} else if((g[i].two <= stars + 1) && g[i].one <= stars){ // play MY L1
				stars+=2;
				played_one[i] = 1;
				output +=2; // played TWO games.
				cout<<"Double-played "<<i<<endl;
		*/	} else {
				int j, diff = stars - g[i].two;
				for(j=N-1; j>=i && diff>0 ;j--) {
					if(g[j].one <= stars && played_one[j] == 0) {
						if(diff <= 0)
							break;
						else {
							played_one[j] = 1;
							diff--;
							stars ++;
							output++;
			//				cout<<"Using "<<j<<", ";
						}
					}
				}
				if( j == i-1 ) {
					//too bad
					too_bad=true;
				} else {
					if(played_one[i] == 0) stars++;
					stars ++;
					output ++; //played TWO games.
			//		cout<<"Played "<<i<<endl;
				}
			}
		}
		
		if( !too_bad )
			printf("Case #%d: %d\n", t, output);
		else
			printf("Case #%d: Too Bad\n", t);

		}
	}
	return 0;
}
