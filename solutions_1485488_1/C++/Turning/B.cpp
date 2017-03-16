#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <sstream>
#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <queue>

using namespace std;
#define PI 3.14159265358979323846264338327950288
#define fill_(x,v) memset(x,v,sizeof(x))
#define for_(i,a,b) for (__typeof(b) i=(a); i<(b); i++)
#define min(x,y) (((x)>(y)) ? (y) :(x))
#define max(x,y) (((y)>(x)) ? (y) :(x))

ifstream fin("c:\\1B\\B-large.in");
ofstream fout("c:\\1B\\B_large.out");

int dx[] ={0,0,1,-1};
int dy[] ={1,-1,0,0};
double run()
{
	int H,M,N;
	double C[200][200];
	double F[200][200];
	bool good[200][200];
	double t[200][200];
	fin >> H >> N >> M;
	for ( int i = 0; i < N; i ++ )
	for ( int j = 0; j < M; j ++ )
		fin >> C[i][j];
	
	for ( int i = 0; i < N; i ++ )
	for ( int j = 0; j < M; j ++ )
		fin >> F[i][j];

	
	
	for ( int i = 0; i < N; i ++ )
	for ( int j = 0; j < M; j ++ )
	{
		if ( C[i][j] - F[i][j] < 50 ) good[i][j] = false;
		else good[i][j] = true;
		t[i][j] = -1;
	}
	
	queue<int> x, y;
	t[0][0] = 0;
	x.push(0); y.push(0);
	while ( !x.empty())
	{
		int cx = x.front();
		int cy = y.front();
		x.pop(); y.pop();
		for ( int p = 0; p < 4; p++)
		{
			int nx = cx + dx[p];
			int ny = cy + dy[p];
			if ( nx < 0 || nx >= N || ny < 0 || ny >= M )
				continue;
			if ( !good[nx][ny] ) continue;
			if ( C[nx][ny] - F[cx][cy]  < 50 ) continue;
			if ( C[cx][cy] - F[nx][ny]  < 50 ) continue;
			
			double accTime = 0;
			if ( H + 50 > C[nx][ny] ) 
				accTime = (H - ( C[nx][ny] - 50 ) ) / 10;
			double tmp = -1;
			if ( t[cx][cy] < 0.0000001 )
			{
				if ( accTime < 0.0000001 )
					tmp = 0;
				else 
				if ( H - 10 * accTime - F[cx][cy] >= 20 )
					tmp = accTime + 1;
				else tmp = accTime + 10;
			}
			else
			{
				if (t[cx][cy] > accTime)
					accTime =t[cx][cy];
				
				if ( H - 10 * accTime - F[cx][cy] >= 20 )
					tmp = accTime + 1;
				else tmp = accTime + 10;
			}
			
			if ( tmp >= 0 && (t[nx][ny] < 0 || t[nx][ny] > tmp ) )
			{
			//	cout<<cx<<' '<<cy<<"->"<<nx<<' '<<ny<<' '<<t[cx][cy]<<' '<<tmp<<endl;
				x.push(nx);
				y.push(ny);
				t[nx][ny] = tmp;
			}
		}
	}
	
	/*for ( int i = 0; i < N; i ++ ) {
	for ( int j = 0; j < M; j ++ )
	cout<<t[i][j]<<' '; 
	cout<<endl;
	}*/
	return t[N-1][M-1];
}
int main() {
  
	int N;
	fin>> N;
	
	for( int n = 1; n <= N; n++)
	{
		double ret = run();
		//printf("Case #%d: %d\n", n, ret);
		//cout<<"Case #"<<n<<": "<<ret<<endl;
		fout << fixed;
		fout<<"Case #"<<n<<": "<<setprecision(10)<<ret<<endl;
   }
   return 0;
}