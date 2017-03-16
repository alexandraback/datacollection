#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector< pair<int, int> > vii;

int ans(int r,int c, int w){

	if (w == 1)
		return c;

	if(w == c)
		return c;

	if( w > c/2)
		return w+1;

	return ceil(1.0*c/w) + w - 1;
}
int main(){

	int t;

	cin >> t;

	for(int tt=1;tt<=t;tt++){

		int r,c,w;

		cin >> r >> c >> w;

		cout << "Case #" << tt << ": " <<  ans(r,c,w) <<   endl;
	}
}