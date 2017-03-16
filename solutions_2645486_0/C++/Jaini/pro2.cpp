#include <iostream>
#include <fstream>

using namespace std;

fstream in, out;
int T , E, R, N;
short v[10000000 + 7]; 
long long ans = 0;

int next_max (int i) 
{
	for (int j = i + 1; j < N; ++j)
		if (v[i] < v[j])
			return j;
	return -1;
}



long long solve() 
{
	int cE = E;
	for (int i = 0; i < N; ++i) 
	{
		int j = next_max(i);
		
		if ( j == -1 || (j - i) * R >= E ) 
		{
			ans += v[i] * cE;
			cE = 0;
		}
		else 
		{
			if (cE + (j-i) * R >= E) 
			{
				ans += v[i] * ( (cE + (j-i) * R ) - E );
				cE =  E - (j-i) * R ;
			}
		}		
		cE = (cE + R) > E ? E : cE + R;
	}
	return ans;
}




int main() 
{

	in.open("in.txt"); out.open("out.txt");
	in >> T;
	for (int i = 1; i <= T ; ++i)
	{
		in >> E >> R >> N;
		ans = 0;
		if (E == R) 
		{
			int t = 0;
			for(int j = 0; j < N; ++j)
			{
				in >> t ;
				ans += t;
			}
			out << "Case #" << i << ": " << ans * E<< endl; 
		}
		else 
		{
			for(int j = 0; j < N; ++j)
				in >> v[j] ;
			
			out << "Case #" << i << ": " << solve () << endl; 
		}
		
	}
	return 0;
}