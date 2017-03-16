#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <cassert>
using namespace std;
#define FILE "C"
int main(){
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	int Tests;
	cin>>Tests;
	//cout<<Tests<<endl;
	for(int numTest = 1; numTest <= Tests; ++numTest){
		int R,C,M;
		cin>>R>>C>>M;
		int last = R*C - M;
		//cout<<"ok"<<endl;
		cout<<"Case #"<<numTest<<":"<<endl;
		if(R == 1){
			cout<<'c';
			for(int i = 1; i < last; ++i){
				cout<<".";
			}
			for(int i = 0; i < M; ++i){
				cout<<'*';
			}
			cout<<endl;
			continue;
		}
		if(C == 1){
			cout<<'c'<<endl;
			for(int i = 1; i < last; ++i){
				cout<<"."<<endl;
			}
			for(int i = 0; i < M; ++i){
				cout<<'*'<<endl;
			}
			continue;
		}
		if(last == R*C){
			cout<<'c';
			for(int i = 1; i < C; ++i)
				cout<<".";
			cout<<endl;
			for(int i = 1; i < R; ++i){
				for(int j = 0; j < C; ++j){
					cout<<'.';
				}
				cout<<endl;
			}
			continue;
		}
		if(last == 1){
			cout<<'c';
			for(int i = 1; i < C; ++i)
				cout<<"*";
			cout<<endl;
			for(int i = 1; i < R; ++i){
				for(int j = 0; j < C; ++j){
					cout<<'*';
				}
				cout<<endl;
			}
			continue;
		}
		if(last == 2){
            cout<<"Impossible"<<endl;
            continue;
		}

		char res[R][C];
		for(int i = 0; i < R; ++i){
			for(int j = 0; j < C; ++j){
				res[i][j] = '*';
			}
		}
		if(R == 2){
			if(last % 2 != 0){
				cout<<"Impossible"<<endl;
				continue;
			}
			else{
				for(int i = 0; i < 2; ++i){
					for(int j = 0; j < (last/2); ++j){
						res[i][j] = '.';
					}
				}
				res[0][0] = 'c';
			}
			for(int i = 0; i < R; ++i){
				for(int j = 0; j < C; ++j)
					cout<<res[i][j];
				cout<<endl;
			}
			continue;
		}
		if(C == 2){
			if(last % 2 != 0){
				cout<<"Impossible"<<endl;
				continue;
			}
			else{
				for(int i = 0; i < (last/2); ++i){
					for(int j = 0; j < (2); ++j){
						res[i][j] = '.';
					}
				}
				res[0][0] = 'c';
			}
			for(int i = 0; i < R; ++i){
				for(int j = 0; j < C; ++j)
					cout<<res[i][j];
				cout<<endl;
			}
			continue;
		}
        if(last <= 3 || last == 5 || last == 7){
			cout<<"Impossible"<<endl;
			continue;
		}
		/*if(last == 6){
			int first = 2;
			int second = 3;
			if(R > C)
				swap(first, second);
			for(int i = 0; i < first; ++i){
				for(int j = 0; j < second; ++j){
					res[i][j] = '.';
				}
			}
			res[0][0] = 'c';
			for(int i = 0; i < R; ++i){
				for(int j = 0; j < C; ++j)
					cout<<res[i][j];
				cout<<endl;
			}
			continue;
		}*/
            //DEBUG

		int colsz = 0;
		for(int i = 1; i <= C; ++i){
			if(i*2 <= last)
				colsz = i;
		}
		//cout<<colsz<<endl;
		int sum = 0;
		for(int i = 0; i < R; ++i){
			for(int j = 0; j < colsz; ++j){
				res[i][j] = '.';
				if(i == 0 && j == 0)
					res[i][j] = 'c';
				++sum;
				if(sum >= last)
					goto endi;
			}
		}
		endi:;
		if(last % colsz == 1){
            //cout<<"ok"<<endl;
            int del = last / colsz;
            //cout<<del<<endl;
            if(del >= 3){
                res[del][1] = '.';
                res[del-1][colsz-1] = '*';
            }
            else if(del == 2){
                res[del][1] = '.';
                res[del][2] = '.';
                res[1][colsz-1] = '*';
                res[0][colsz-1] = '*';
                //cout<<"moth"<<endl;
                //cout<<res[del][1]<<endl;
            }
            else
                assert(false);
		}
		for(int i = 0; i < R; ++i){
			for(int j = 0; j < C; ++j)
				cout<<res[i][j];
			cout<<endl;
		}

	}
	return 0;
}
