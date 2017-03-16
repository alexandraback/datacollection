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
#include <string>
#include <cstring>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

typedef long long ll;

string res;
int X;
int Y;

int main()
{
	int T;
	cin>>T;

	int idx = 0;
	string goLeft = "EW";
	string goRight = "WE";
	string goUp = "SN";
	string goDown = "NS";
	string curX = "";
	string curY = "";

	while(++idx <= T) {
		cin>>X>>Y;
		res = "";

		curX = (X < 0) ? goLeft : goRight;
		curY = (Y < 0) ? goDown : goUp;


		// generate X
		if(X < 0) X = -X;
		for(int i=0; i < X; i++)
			res = res + curX;

		// generate Y
		if(Y < 0) Y = -Y;
		for(int i=0; i < Y; i++)
			res = res + curY;

		cout<<"Case #"<<idx<<": "<<res<<endl;
	}
	
    return 0;

}