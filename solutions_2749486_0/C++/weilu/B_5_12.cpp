#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;
#define ll long long 
int main(){

		freopen ("C:/Users/weilu/Downloads/B-small-attempt0.in","r",stdin);
		freopen("test.out", "w", stdout);
//	freopen("test.in", "r", stdin);

	int T;
	cin >> T;

	for (int ii = 0; ii < T; ii++)
	{
		ll x;
		ll y;
		cin >> x >> y;
		vector<char> result;
		for (int i = 1; i < 500; i++)
		{
			if ( x > 0 && x >= i ){
				x -= i;
				//increase
				result.push_back('E');
			}
			else if( x <0 && x <= -i){
				x += i;
				result.push_back('W');
			}
			else if  ( y > 0 && y >= i ){
				y -= i;
				//increase
				result.push_back('N');
			}
			else if( y <0 && y <= -i){
				y += i;
				result.push_back('S');
			}
			else
				break;
	//		cout<<"s"<<endl;
		}
		while( x> 0)
		{
			result.push_back('W');
			result.push_back('E');
			x--;
		}
		while( x< 0)
		{
			result.push_back('E');
			result.push_back('W');
			x++;
		}
		while( y> 0)
		{
			result.push_back('S');
			result.push_back('N');
			y--;
		}
		while( y< 0)
		{
			result.push_back('N');
			result.push_back('S');
			y++;
		}
		cout<< "Case #"<<ii+1<<": ";
		for (int i = 0; i < result.size(); i++)
		{
			cout<<result[i];
		}
		cout<<endl;
	}
	return 0;
}