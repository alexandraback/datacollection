#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <map>
#include <list>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

int a[1001][1001];
map< int , int > visited;
map < int,int> visited2;
int main()
{
	int t;
	scanf("%d",&t);
	int g = 1;
	
	while ( t-- ) {
			

			
			int n;			
			cin >> n;
			int d,k;
			for ( int i =1 ;i <=n;i++) 
			for ( int j =1 ; j<=n;j++)
				a[i][j] = 0;
			
			for ( int i = 1; i <= n; i++) {
				cin >> d;
//				cout << d << endl;
				for ( int j = 0; j < d; j++) {				
					cin >> k;
					a[i][k] = 1;
				}
				
			}
			int flag = 0;
			visited.clear();	
			for ( int i = 1; i <= n; i++) {
				if ( visited2[i] == 1)
					continue;
				queue < int > q;
					
				q.push(i);			
			
				
				while ( !q.empty()) {

					int u = q.front();
					visited2[u] = 1;
//					cout <<"hh "<< u <<  visited[u] << endl;	
//					cout <<"u is "<< u << endl;		
					if ( visited[u] == 1){	
//						cout <<"kite "<<u << endl;
						flag = 1;
						break;
					}
					visited[u] = 1;
					//cout << u << endl;
					for ( int j = 1; j <= n ; j++)  {
							if ( j == u)
								continue;	
							if ( a[u][j] == 1 ) {
												
								q.push(j);
//							cout <<"i "<<i <<" "<< j << endl;
							}
							
					}
					if ( flag == 1)
						break;
					q.pop();
				}
				if ( flag == 1)
					break;
				visited.clear();
				
			}			
			if ( flag == 1)
				cout <<"Case #"<<g<<":"<<" "<<"Yes"<< endl;
			else
				cout <<"Case #"<<g<<":"<<" "<<"No"<< endl;
			g++;
			visited2.clear();
		}
		return 0;
}	





			
					






	
		
		
		
			
		
		
	


