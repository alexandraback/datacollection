#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define for0( i, n) for(int i = 0; i < (n); i++)
int main()
{
	int T;
	cin >> T;

	for( int i = 0; i < T; i++)
	{
		long long me;
		long long N;
		

		cin >> me >> N;

		
		vector< long long > motes(N, 0);

		for(int n = 0; n < N; n++)
		{
			cin >> motes[n];
		}

		sort(motes.begin(), motes.end());
		long long biggest = motes[motes.size() - 1];
		long long curBest = 1000000000;
		long long curMote = 0;
		long long curMoves = 0;
		do
		{
			while(  curMote < motes.size() && me > motes[curMote] )
			{
				me += motes[curMote];
				curMote++;
			}
			long long newBest = curMoves + (motes.size() - curMote);
			curBest = (newBest < curBest) ? newBest : curBest;
			while( curMote < motes.size() && me <= motes[curMote] )
			{
				if( me == 1) 
				{
						curMote = 999999999;
						curBest = motes.size();
						break;
				}
				me += (me - 1);
				curMoves++;
			}

		} while (curMote < motes.size() && me < biggest);
		if( me != 1)
			curBest = (curMoves < curBest) ? curMoves : curBest;
		cout << "Case #" << i + 1 << ": " << curBest << endl;

		
	}


}