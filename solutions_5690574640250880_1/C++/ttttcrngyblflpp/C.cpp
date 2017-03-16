#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <iterator>

using std::endl;
using std::cout;
using std::cin;
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;
using std::set;
using std::set_intersection;
using std::inserter;
using std::fixed;
using std::stringstream;
using std::begin;
using std::end;
using std::find;

void calc_square(int r, int c, int M,
				 vector<vector<char>>::iterator bgn,
				 vector<vector<char>>::iterator end)
{
	if (r == c) {
		//matrix is square
		if (r == 3) {
			//3x3
			switch (M) {
			case 0:
				while (bgn != end) {
					for (int i=0; i!=3; ++i)
						(*bgn).push_back('.');
					++bgn;
				}
				break;
			case 1:
				(*bgn).push_back('*');
				(*bgn).push_back('.');
				(*bgn).push_back('.');
				++bgn;
				while (bgn != end) {
					for (int i=0; i!=3; ++i)
						(*bgn).push_back('.');
					++bgn;
				}
				break;
			case 3:
				while (bgn != end) {
					(*bgn).push_back('*');
					(*bgn).push_back('.');
					(*bgn).push_back('.');
					++bgn;
				}
				break;
			case 5:
				(*bgn).push_back('*');
				(*bgn).push_back('*');
				(*bgn).push_back('*');
				++bgn;
				(*bgn).push_back('*');
				(*bgn).push_back('.');
				(*bgn).push_back('.');
				++bgn;
				(*bgn).push_back('*');
				(*bgn).push_back('.');
				(*bgn).push_back('c');
				break;
			case 8:
				while (bgn != end) {
					for (int i=0; i!=3; ++i)
						(*bgn).push_back('*');
					++bgn;
				}
				break;
			default:
				break;
			}
			(*(end-1)).back() = 'c';
		} else {
			// r > 3
			if (M <= r-2) {
				//vertical down
				if (M) {
					(*bgn).push_back('*');
					for (int i=1; i!= c; ++i)
						(*bgn).push_back('.');
					--M;
				} else {
					for (int i=0; i!= c; ++i)
						(*bgn).push_back('.');
				}
				++bgn;
				while (bgn != end) {
					if (M) {
						(*bgn).push_back('*');
						--M;
					} else
						(*bgn).push_back('.');
					++bgn;
				}
			} else if (M == r-1) {
				(*bgn).push_back('*');
				(*bgn).push_back('*');
				for (int i=2; i!=c; ++i)
					(*bgn).push_back('.');
				++bgn;
				for (int i=1; i!=r-2; ++i, ++bgn) {
					(*bgn).push_back('*');
				}
				for (int i=r-2; i!=r; ++i, ++bgn) {
					(*bgn).push_back('.');
				}
				M = 0;
			} else if (M == r) {
				//vert line
				(*bgn).push_back('*');
				for (int i=1; i!= c; ++i)
					(*bgn).push_back('.');
				++bgn;
				for (int i=1; i!= r; ++i, ++bgn) {
					(*bgn).push_back('*');
				}
				M=0;
			} else if (M <= 2*r-2) {
				//add horiz
				int mines;
				if (M == 2*r-2) {
					mines = M - r;
					M = 1;
				} else {
					mines = M - (r-1);
					M=0;
				}
				for (int i=0; i!= mines; ++i )
					(*bgn).push_back('*');
				for (int i= mines; i!= c; ++i)
					(*bgn).push_back('.');
				++bgn;
				for (int i=1; i!= r; ++i, ++bgn) {
					(*bgn).push_back('*');
				}
			} else {
				// M >= 2*r-1
				for(int i=0; i!=c; ++i)
					(*bgn).push_back('*');
				++bgn;
				while (bgn != end)
					(*bgn++).push_back('*');
				M -= (2*r-1);
			}
			calc_square(r-1,c-1,M,end-r+1,end);
		}
	} else {
		//matrix is rectangular
		if (M == 0) {
			while (bgn != end)
				(*bgn++).push_back('.');
		} else if (M <= r-2) {
			for(int i=0; i!= M; i++, bgn++)
				(*bgn).push_back('*');
			while (bgn != end)
				(*bgn++).push_back('.');
			M=0;
		} else if (M == r-1) {
			while (bgn != end-2)
				(*bgn++).push_back('*');
			(*bgn++).push_back('.');
			(*bgn).push_back('.');
			M=1;
		} else {
			while (bgn != end)
				(*bgn++).push_back('*');
			M -= r;
		}
		calc_square(r,c-1,M,end-r,end);
	}

}

int main()
{
	ifstream cin("C-large.in");
	ofstream cout("C-large.out");

	int cases;
	cin >> cases;
	cin.ignore();

	for (int case_no = 1; case_no != cases+1; ++case_no) {
		int R, C, M;
		cin >> R >> C >> M;
		int r = R < C ? R : C;
		int c = C > R ? C : R;
		vector<vector<char>> v(r);
		bool impossible = false;
		if (M) {
			switch (r) {
			case 1:
				for (int i=0; i!=M; ++i)
					v[0].push_back('*');
				for (int i=0; i!=c-1-M; ++i)
					v[0].push_back('.');
				v[0].push_back('c');
				break;
			case 2:
				if (M % 2 && M != r*c-1 || M == r*c-2)
					impossible = true;
				else {
					// r == 2 && soln exists
					if (M == r*c-1) {
						//fill the entire grid with mines
						for (int i=0; i!=c-1; ++i) {
							v[0].push_back('*');
							v[1].push_back('*');
						}
						v[0].push_back('*');
						v[1].push_back('c');
					} else {
						for (int i=0; i!=M/2; ++i) {
							v[0].push_back('*');
							v[1].push_back('*');
						}
						for (int i=M/2; i!=c; ++i) {
							v[0].push_back('.');
							v[1].push_back('.');
						}
						v[1].back() = 'c';
					}
				}
				break;
			default:
				
				//M != 0 && r >= 3
				int a[] = {r*c-2,r*c-3,r*c-5,r*c-7};
				if (find(begin(a),end(a),M) != (a+4))
					impossible = true;
				else {
					calc_square(r,c,M,v.begin(),v.end());
				}

				break;
			}
		} else {
			//M=0, no mines
			for (int i=0; i!= r;++i) 
				for (int j=0; j!=c; ++j)
					v[i].push_back('.');
			v[0][0]='c';
		}
		//print stuff
		
		cout << "Case #" << case_no << ':' << endl;
		if (impossible) {
				cout << "Impossible" << endl;
		} else if (r == R) {
			for (int i=0; i!= r; ++i)
				cout << string(v[i].begin(),v[i].end()) << endl;
		} else {
			for (int i=0; i != R; ++i) {
				for (int j=0; j!= C; ++j)
					cout << v[j][i];
				cout << endl;
			}
		}
	}
	return 0;

}