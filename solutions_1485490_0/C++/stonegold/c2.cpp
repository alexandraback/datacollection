#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <map>
#include <list>
#include <stdio.h>

using namespace std;

map < long long,long long> boxes;
map <long long,long long> toys;
int q,p;
long long to[101];
long long bo[102];

int n,m;
long long kin[10][102];
long long count( long long i, long long j)
{
	long long x = 0;
	long long z,w;
//	cout << i << " " << j << endl;
	if ( i > n || j > m)
		return 0;
	if ( kin[i][j] != -1)
		return kin[i][j];

	if ( bo[i] == to[j] )  {
		int k = 0;
		if ( toys[j] > boxes[i]) { 
			toys[j] = toys[j] - boxes[i];
			k = (boxes[i] + count( i+1,j));
			
			toys[j] = toys[j] + boxes[i];
			z = count(i+1,j+1);
			w = count( i,j+1);
			if ( k < z)
				k = z;
			if ( k < w)
				k = w;
			
		}	

		else if ( toys[j] < boxes[i]) {
			boxes[i] = boxes[i] - toys[j];
			k =   toys[j]  + count(i,j+1);
			boxes[i] = boxes[i] + toys[j];
			z = count(i+1,j+1);
			w = count(i+1,j);
			if ( k < z)
				k = z;
			if ( k < w)
				k = w;
		}
		else {
			k = toys[j] + count(i+1,j+1);
			
		}
		x= k;
	}	
//		if ( i == 1 && j ==1)
//			cout << x << endl;
		long long l =   count(i+1,j) ;
		long long zx = count(i,j+1);
		
		 z = count(i+1,j+1);	
			if ( l < zx)
				l = zx;
			if ( l < z)
				l = z;
			if ( l < x)
				l = x;

		kin[i][j] = l;
		return kin[i][j];
}		









int main()
{
	int t;
	scanf("%d",&t);
	int g = 1;
	
	while ( t-- ) {
				
			cin >> n >> m;
			int b,k;
			for ( int i = 1; i <=n;i++) {
				cin >> b >> k;	
				bo[i] = k;
				boxes[i] = b;
			}

			for ( int j = 1; j <=m;j++) {
				cin >> b >> k;
				to[j] = k;
				toys[j] = b;
			}
			for ( int i =1 ; i <= n; i++) 
				for ( int j =1 ; j <= m; j++)  		
					kin[i][j] = -1; 
			long long ans = 0;
			 ans = count(1,1);	
		
			cout << "Case #"<<g<<":"<<" "<< ans << endl;
		
			toys.clear();
			boxes.clear();
			g++;
		}
		return 0;
}	
		
			
		
		
	


