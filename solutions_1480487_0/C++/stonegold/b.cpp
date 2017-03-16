#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <list>
#include <sstream>
#include <stdio.h>

int a[202];

using namespace std;




int main()
{
	int t;
	scanf("%d",&t);
	int c = 1;
	while ( t--) {
		 	
		int n;
		scanf("%d",&n);
		int sum = 0;
		for ( int i = 0; i < n; i++) {
			scanf("%d",&a[i]);
			sum += a[i];
		}
		int count = 0;
		map < int,int> m;
		int sum2 = 0;
		cout << "Case #"<<c<<":";
		for ( int i = 0; i < n; i++) {
			int b = n -1;
			int k = sum + sum - a[i] ;
			int d = sum;
			int l = b*a[i];
			int x = (b)*sum;
			d = d +	x;
			k = k - l;
			double g = (double)k;
			double f = ( double)d;
			double ans = k/f;
			ans = ans*100.0;
			
			if ( ans < 0.0) {
				ans = 0.0;
				m[i] = 1;
				count++;
				
				
			}
			else
				sum2 += a[i];
		//	printf("%0.6f",ans); 

		}
			int q = n - count;
			
		for ( int i = 0; i < n; i++) {
				if ( m[i] == 1) {
					cout << " ";
					printf("%0.6f",0.0);
					continue;
				}
                        int b = q -1;
                        int k = sum2 - a[i] +  sum ;
                        int d = sum;
                        int l = b*a[i];
                        int x = (b)*sum;
                        d = d + x;
                        k = k - l;
                        double g = (double)k;
                        double f = ( double)d;
                        double ans = k/f;
                        ans = ans*100.0;
                        cout << " ";
                      
                     printf("%0.6f",ans); 

                }















		cout << endl;
		c++;
	}
	return 0;



			
	
	
	
	
	





}
