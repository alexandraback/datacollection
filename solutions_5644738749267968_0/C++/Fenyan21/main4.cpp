#include <fstream>
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <deque>
#include <utility>
using namespace std;


int dx[3] = {-1,0,1};
int dy[3] = {-1,0,1};

int main()
{
	ifstream is("rp4.txt");
//	std::istream& is = std::cin;
	ofstream os("answer.txt");
	int testcase;
	is >> testcase;
	for ( int tc = 1; tc <= testcase; tc++){
		int n;
		is >> n;
		vector<double> p1(n);
		vector<double> p2(n);
		for( int i = 0; i < n; i++)
			is >> p1[i];
		for( int i = 0; i < n; i++)
			is >> p2[i];
		int score1 = 0;
		sort(p1.begin(), p1.end());
		sort(p2.begin(), p2.end());

		vector<double>pp1 = p1;
		vector<double>pp2 = p2;
		for( int i = 0; i < n; i++){
			double nownum = pp2[i];
			vector<double>::iterator it = upper_bound(pp1.begin(), pp1.end(), nownum);
			if( it == pp1.end() )
				break;
			else
			{
				score1++;
				pp1.erase(it);
			}
		}

		int score2 = 0;
		for( int i = n-1; i >=0; i--){
			double nownum = p1[i];
			vector<double>::iterator it = upper_bound(p2.begin(), p2.end(), nownum);
			if( it == p2.end() ){
				p2.erase(p2.begin());
				score2++;
			} else
			{
				p2.erase(it);
			}
		}
		os << "Case #"<<tc;
		os << ": ";
		os << score1 << " " << score2 << endl;

	}
	is.close();
	os.close();
}