#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool solve()
{
	int X, R, C;
	cin>>X>>R>>C;
	if(X==4&&((R==2&&C==4) || (R==4&&C==2)))
		return 0;
	if( R*C%X!=0)
	{
		return 0;
	}
	for(int i=X; i>=1; --i)	
	{
		int j=X-i+1;
		if( max(i, j) > max(R, C))
		{
			return 0;
		}
		if( min(i, j) > min(R, C))
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	//freopen("sample.txt", "r", stdin);
	freopen("D-small-attempt1.in", "r", stdin);
	FILE * p; p = fopen ("result.txt","w"); 
	int N;
	cin>>N;
	for( int i=0; i<N; ++i)
	{
		bool flag = solve();
		fprintf(p, "Case #%d: %s\n", i+1, flag?"GABRIEL":"RICHARD");
	}
	return 0;
}