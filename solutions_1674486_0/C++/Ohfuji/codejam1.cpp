#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>
#include <string.h>

using namespace std;

int Inherit[1001][1001];
int Icount[1001];
bool Visit[1001];
int Idcount[1001];
int N;

void calc(int i)
{
	if ( Visit[i] == true ) return;
	for ( int j = 0; j < Icount[i]; j++ ) {
		Idcount[Inherit[i][j]]++;
		calc(Inherit[i][j]);
	}
	Visit[i] = true;
}

int main(int argc, char* argv[])
{
	int	casenum;

	cin >> casenum;
	string g;
	for ( int c = 1; c <= casenum; c++ ) {
		int N;
		cin >> N;
		for ( int i = 0; i < N; i++ ) {
			cin >> Icount[i];
			for ( int j = 0; j < Icount[i]; j++ ) {
				cin >> Inherit[i][j];
				Inherit[i][j]--;
			}
		}
		bool ret = false;
		for ( int i = 0; i < N && ret == false; i++ ) {
			for ( int j = 0; j < N; j++ ) {
				Visit[j] = false;
				Idcount[j] = 0;
			}
			calc(i);
			for ( int j = 0; j < N; j++ ) {
				if ( Idcount[j] > 1 ) { 
					ret = true; 
					break; 
				}
			}
		}
		cout << "Case #" << c << ": " << (ret==true ? "Yes" : "No") << endl;
	}

	return 0;
}

