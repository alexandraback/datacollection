#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stdio.h>
using namespace std;


int a[22];


int main()
{
	int t;
	
	int g = 1;
	map< int,int > m;
		scanf("%d",&t);
		while ( t-- ) {
						
					
		
			int k;			
			cin >> k;
			for ( int i = 0; i < 20; i++) {
				scanf("%d",&a[i]);
			}
		//	cout << a[0]<< endl;
			int  n = 1 << k;
			int flag = 0;
			cout <<"Case #"<<g<<":"<<endl;
	
			for ( int i = 1; i < n; i++) {
				int sum = 0;
				for ( int j = 0; j < k; j++) {

					if ( i & ( 1<<j)) {
						sum += a[j];
					}
				}	
				if ( m[sum] == 0) {
					m[sum] = i;
				}
				else {
		//			cout << "D "<<i << endl;
		//			cout << "d "<<m[sum] << endl;
					flag = 1;
					int c = m[sum] ;
					int h = 0;
						for ( int j = 0; j < k; j++) {
	
							if ( c & ( 1<<j)) {
								if ( h == 0)  {
//									cout <<"j " << j << endl;
									cout << a[j];
									h = 1;
								}
								else {
		//						cout <<"J IS "<< j << endl;
								cout <<" "<< a[j]; 
								}
							}
						 }
						cout << endl;
						 h = 0;
						for ( int j = 0; j < k; j++) {

                                                        if ( i & ( 1<<j)) {
                                                                if ( h == 0)  {
                                                                        cout << a[j];
                                                                        h = 1;
                                                                }
                                                                else
                                                                cout <<" "<< a[j]; 
                                                        }
                                                 }
                                                cout << endl;
						break;
				}
			}
			if ( flag == 0 )
				cout <<"Impossible"<< endl;
			g++;
			m.clear();
		}
		return 0;
}	 




