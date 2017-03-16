#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <math.h>
//---------- macros ----------
#define fp(i,a,b) for(long i=a; i<b; i++)
#define fm(i,a,b) for(long i=a; i>b; i--)

using namespace std;

string s;
int t,n,_case;

bool isC(char c){
	switch (c){
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			return false;
		default :
			return true;
	}
}
int main()
{
    int l, i, last,j ; bool is;
	long long tot;
	_case = 1;
	cin >> t;
    while(_case<=t)
    {
       cout <<"Case #"<< _case <<": ";
       cin >> s >> n;
		i =0; tot = 0; 
		last =0;
		l = s.length();
		//cout<< endl; //
		while(i<=l-n){
			is = true;
			for(j=i;j<i+n;j++){
				
				if(!isC(s[j])) {
					//cout<< endl << "checked and vo=" << s[j] << endl; //
					is = false;
					break;
				}
				//cout<< endl << "checked " << s[j] << endl; //
			}
			if(is){
				//cout <<"formed"<< i<<", " << l << "," << last << ", " << tot << endl; // 
 				tot +=  l - i - n + i - last + (l - i - n) * (i - last) + 1;
				i = i + 1;
				last = i;
			}else{
				//cout  <<"Not formed"<< i<<", " << l << "," << last << ", " << tot<< endl; //
				i++;
			}
		}
        cout <<tot<< endl;
        _case++;
        
    } 
	return 0;
}
