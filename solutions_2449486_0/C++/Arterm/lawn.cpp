#include <fstream>

#define M 121

using namespace std;

ifstream cin ("input.txt");
ofstream cout("output.txt");

int n,m,a[M][M];

bool good(int x, int y){
	bool f=1;
	for (int i=0; i<n; ++i)
	f&=(a[i][y]<=a[x][y]);
	if (f)
	return 1;
	f=1;
	for (int j=0; j<m; ++j)
	f&=(a[x][j]<=a[x][y]);
	return f;
}

void read(void){
	cin>>n>>m;
	for (int i=0; i<n; ++i)
	for (int j=0; j<m; ++j)
	cin>>a[i][j];
}

void kill(void){
	for (int i=0; i<n; ++i)
	for (int j=0; j<m; ++j)
	if (!good(i,j)){
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n";
}

int main()
{
	int t;
	cin>>t;
	for (int i=1; i<=t; ++i){
		read();
		cout<<"Case #"<<i<<": ";
		kill();
	}
	return 0;
}

