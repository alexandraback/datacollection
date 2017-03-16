/*
 * osmos.cpp
 *
 *  Created on: May 4, 2013
 *      Author: saha
 */


#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long mylong;

int main()
{
	int T;
	int n, L;
	string s;
	char c[256];

	memset(c,0,sizeof(c));
	c['a']=c['e']=c['i']=c['o']=c['u']=1;

	cin >> T ;
//	cout << "Number of test cases = " << T << endl;
	for(int t=1; t<=T ; t++) {
		cin >> s  >> n ;
//		cout << "****** test case number  = " << t << endl;
//		cout << "s = " << s << ", n = " << n << endl;

		mylong count = 0;
		int found = 0;
		int len = s.length();
		int b=0,e=0;
		int n1,n2;
		int lb=0;
		for(size_t i=0; i<len ; i++) {
			if(0 == c[s[i]]) {
				e=i;
				if((e-b+1) == n) {
//					cout << "One sub-string of length " << n << " is : ";
//					for(int j=b; j<=e ; j++)
//						cout << s[j];
//					cout << endl;

					/*********************************************/
					n1 = b+1;
					n2 = len-e;
					if(0 == found)
						count += n1*n2 ;
					else
						count += (b-lb)*n2;

					lb=b;
					found++;
					/*********************************************/

					b++;
				} else if ((e-b+1) < n) {
					e++;
				} else {
					cout << "This case should not arise!!!" << endl;
				}
			} else {
				b=i+1;
			}
		}

		cout << "Case #" << t <<": " << count << endl;
	}
	return 0;
}




