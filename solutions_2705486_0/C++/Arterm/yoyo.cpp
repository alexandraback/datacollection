#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#define M 600600
#define INF 10000
#define N 121

using namespace std;

ifstream dict ("dict.txt");
ifstream fin ("input.txt");
ofstream fout("output.txt");

string s[M],t;
int d[10][N],m=0,k,len[M];

void ma(void){
	while (dict>>s[m]){
		len[m]=s[m].length();
		m++;
	}
}

void read(void){
	fin>>t;
}

void man(int k,int j, int b, int id, int n){
	int ans=d[-b][id-n];
	
	for (int i=0; i<n; ++i)
	if (s[j][i]!=t[k+i]){
		if (i-b<5)
		return;
		ans++;
		b=i;
	}
	
	int x=n-b;
	if (x>6)
	x=6;
	
	d[x][id]=min(d[x][id],ans);
	
}

void kill(void){
	int n=t.length();
	for (int i=1; i<=n; ++i){
		
		for (int j=1; j<=6; ++j)
		d[j][i]=INF;
		
		for (int j=0; j<m; ++j)
		if (i>=len[j]){
			int to=i-len[j];
			
			for (int h=1; h<=6; ++h)
			man(to,j,-h,i,len[j]);
		}
		
		for (int h=5; h>=1; --h)
		d[h][i]=min(d[h+1][i],d[h][i]);
		
	}
	
	fout<<d[1][n]<<"\n";
}

int main()
{
	ma();
	int t;
	fin>>t;
	for (int i=1; i<=t; ++i){
		read();
		fout<<"Case #"<<i<<": ";
		kill();
	}
	return 0;
}

