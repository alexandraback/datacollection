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

string replaceEW(string s1){
	int  l = s1.length();
	cout << "replacing ew"<< endl;
	for(int i=0;i<l;i++){
		if(s1[i]=='E')
			s1[i] = 'W';
		else if(s1[i]=='W')
			s1[i] = 'E';
	}
	return s1;
}
string replaceNS(string s1){
	int  l = s1.length();
	cout << "replacing ns" << endl;
	for(int i=0;i<l;i++){
		if(s1[i]=='N')
			s1[i] = 'S';
		else if(s1[i]=='S')
			s1[i] = 'N';
	}

	return s1;
}
int main()
{
    long x,y,dx,dy, st;
	bool cns, cew;
	string p;
	_case = 1;
	cin >> t;
    while(_case<=t)
    {
		cout <<"Case #"<< _case <<": ";
		cns = false; cew = false; st =0; x =0; y=0;
		p = "";
		cin >> dx >> dy;
		if(dx < 0) {
			dx=  0- dx;
			cew = true;
		}
		if(dy < 0) {
			dy = 0-dy;
			cns = true;
		}
		while(dx!=x || dy!=y){
			st++;
			if(dx!=x && x+st == dx){ 
					x = x+st;
					p = p  + "E";
					continue;
			}
			if(dx!=x && x-st == dx){ 
					x = x-st;
					p = p  + "W";
					continue;
			}
			if(dy!=y && y-st == dy){
					y = y-st;
					p = p  + "S";
					continue;
			}
			if(dy!=y && y+st == dy){
					y = y+st;
					p = p  + "N";
					continue;
			}
			if(dx!=x ){
				if(abs(dx-x) > abs(dx - (x+st))  ){
					x = x+st;
					p = p  + "E";
				}else if(abs(dx-x) > abs(dx - (x-st))  ){
					x = x-st;
					p = p  + "W";
				}
				else {
					if(x>dx){
						p = p  + "E";
						x = x + st;
					}else{
						p = p  + "W";
						x = x - st;
					}
				}
				
				continue;
			}
			if(dy!=y ){
				if(abs(dy-y) > abs(dy - (y+st))  ){
					y = y+st;
					p = p  + "N";
				}else if(abs(dy-y) > abs(dy - (y-st))  ){
					y = y-st;
					p = p  + "S";
				}
				else {
					if(y>dy){
						y = y + st;
						p = p  + "N";
					}else{
						y = y - st;
						p = p  + "S";
					}
				}
				continue;
			}
		}
		if(cns ) {
			//s = replaceNS(p);
			replace( p.begin(), p.end(), 'S', 'K' );
			replace( p.begin(), p.end(), 'N', 'S' );
			replace( p.begin(), p.end(), 'K', 'N' );
        }
		if(cew ) {
			replace( p.begin(), p.end(), 'E', 'K' );
			replace( p.begin(), p.end(), 'W', 'E' );
			replace( p.begin(), p.end(), 'K', 'W' );
        }
        cout <<p<< endl;
        _case++;
        
    } 
	return 0;
}
