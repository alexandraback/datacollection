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
	ifstream is("rp3.txt");
//	std::istream& is = std::cin;
	ofstream os("answer.txt");
	int testcase;
	is >> testcase;
	for ( int tc = 1; tc <= testcase; tc++){
		os << "Case #"<<tc;
		os << ":" << endl;

		int r,c,m;
		is >> r >> c >> m;
		vector<char> rows(c,'*');
		vector<vector<char>> mp;
		for( int i = 0; i < r; i++){
			mp.push_back(rows);
		}

		int s = r*c-m;

		if( m == 0 ){
			for(int i = 0; i < r; i++){
				for( int j = 0; j < c; j++){
					if( i==0 && j==0)
						os<<'c';
					else
						os<<'.';
				}
				os << endl;
			}

			continue;
		}

		mp[0][0] = 'e';
		deque< pair<vector<vector<char> >,int> > dq;

		dq.push_back(make_pair(mp,1));

		bool cando = false;
		while( dq.size() ){
			vector<vector<char>> nowmp = dq.front().first;
			int nowclick = dq.front().second;
			dq.pop_front();
			if( nowclick == s ){
				for(int i = 0; i < r; i++)
					for( int j = 0; j < c; j++)
						if( nowmp[i][j] != '*' )
							nowmp[i][j] = '.';
				nowmp[0][0] = 'c';
				for( int i = 0; i < r; i++)
				{
					for( int j = 0; j < c; j++)
						os << nowmp[i][j];
					os << endl;
				}
				cando = true;
			} 
			if( cando )
				break;
			if(nowclick > s)
			{
				continue;
			}
			for( int i = 0; i < r; i++)
				for( int j = 0; j < c; j++){
					if( nowmp[i][j] == 'e' ){
						vector<vector<char>> newmp = nowmp;
						newmp[i][j] = '.';
						int news = 0;
						for( int ddx = 0; ddx < 3; ddx++ )
							for( int ddy = 0; ddy < 3; ddy++ ){
								int nowh = i + dy[ddy];
								int noww = j + dx[ddx];
								if( nowh >=0 && nowh<r && noww>=0 && noww < c &&  newmp[nowh][noww] == '*' ){
									newmp[nowh][noww] = 'e';
									news++;
								}
							}
						if( news > 0 ){
							dq.push_back(make_pair(newmp,news+nowclick));
						}
					}
					
				}

		}
		
		if( !cando){
			os << "Impossible" <<endl;
		}
		else {
			
		}
	}
	is.close();
	os.close();
}