#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <sstream>
#include <fstream>
#include <limits>
#include <eigen3/Eigen/Dense>
using namespace std;

#define LL long long
#define LD long double
#define PR pair<int,int>

#define For(i,m,n) for (int i=m; i<int(n); i++)
#define ForR(i,m,n) for (int i=int(n)-1; i>=m; i--)

#define Sz(s) int((s).size())
#define All(s) (s).begin(),(s).end()
#define Fill(s,v) memset(s,v,sizeof(s))
#define pb push_back
#define mp make_pair

template<typename T> T Abs(T x) { return(x < 0 ? -x : x); }
template<typename T> T Sqr(T x) { return(x*x); }

const LL INF = numeric_limits<LL>::max();
const LD EPS = 1e-9;
const LD PI = acos(-1.0);

#define DEBUG 0
#define LIM 1000

ifstream input;
ofstream output;
int numTest;
int test;

int X, Y;

class State{
public:
	int x, y;
	string path;

	State(int x_=0, int y_=0, string path_ =  ""): x(x_), y(y_), path(path_){
	}
};

bool operator<(const State &A, const State &B){
	return A.path.length()+4*Abs(A.x-X)+Abs(A.y-Y) <
		   B.path.length()+4*Abs(B.x-X)+Abs(B.y-Y);
}

class Point{
public:
	int x, y;
	Point(int x_ = 0, int y_ = 0): x(x_), y(y_){

	}
};

bool operator<(const Point &A, const Point &B){
	if(A.x<B.x)
		return true;
	else if(A.x>B.x)
		return false;
	else if(A.y<B.y)
		return true;
	else
		return false;
}

int main(int argc, char**argv)
{
    clock_t start = clock();
    input.open(argc>1 ? argv[1]: "in.txt");
    output.open(argc>2 ? argv[2]: "out.txt");

    input >> numTest;

    For(test,1,numTest+1){
    	input >> X >> Y;
    	State initial(0,0);
    	set<State> open;
    	open.insert(initial);
    	State current;
    	set<Point> closed;
    	State result;
    	while(!open.empty()){
    		current = *open.begin();
    		if(current.x == X && current.y==Y){
    			cout << "FOUND"<<endl;
    			result = current;
    			break;
    		}
    		open.erase(open.begin());
    		closed.insert(Point(current.x,current.y));

    		int x = current.x;
    		int y = current.y;
    		string path = current.path;
    		int len = path.length();

    		if(len >=500)
    			continue;

    		if(closed.find(Point(x+len+1,y)) == closed.end())
    			open.insert(State(x+len+1,y, path+"E"));
    		if(closed.find(Point(x-len-1,y)) == closed.end())
    			open.insert(State(x-len-1,y, path+"W"));
    		if(closed.find(Point(x,y+len+1)) == closed.end())
    			open.insert(State(x,y+len+1, path+"N"));
    		if(closed.find(Point(x,y-len-1)) == closed.end())
    			open.insert(State(x,y-len-1, path+"S"));

    	}

    	cout << "Case #" << test <<": ";
    	output << "Case #" << test <<": ";

    	cout << result.path << endl;
    	output << result.path << endl;
    }

    cout << "Time: " << (clock()-(double)start)/(double)CLOCKS_PER_SEC << endl;

    return 0;

}
