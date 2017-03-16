#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <limits>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;

char sol[50][50];

bool solve(int r, int c, int free)
{
	bool to_transpose = false;

	// c must be greater than r
	if(c < r){
		to_transpose = true;
		swap(r, c);
	}
	// Find a solution to 
	// free = l1*(b-1) + l2
	// subject to l1, l2, b >= 2
	// and l1 <= c, l2 <= c, b <= r
	// and that l1 and l2 can only be different if b >= 3

	bool not_found = true;
	int l1, l2, l3, b;
	for(l1=2; (l1<=c)&&not_found; ++l1)
		for(l2=2;  (l2<=l1)&&not_found; ++l2)
			for(b=3; (b<=r)&&not_found; ++b)
				if(l1*(b-1)+l2 == free)
					not_found = false;

	if(!not_found){
		--l1;
		--l2;
		--b;
		l3 = 0;
	}
	else{
		for(l1=2; (l1<=c)&&not_found; ++l1){
			if(l1*2 == free)
				not_found = false;
		}
		if(!not_found){
			--l1;
			l2 = l1;
			b = 2;
			l3 = 0;
		}
		else{
			for(l1=2; (l1<=c)&&not_found; ++l1)
				for(l2=2;  (l2<=l1)&&not_found; ++l2)
					for(l3=2; (l3<=l2)&&not_found; ++l3)
						for(b=4; (b<=r)&&not_found; ++b)
							if(l1*(b-2)+l2+l3 == free)
								not_found = false;
			if(!not_found){
				--l1;
				--l2;
				--l3;
				--b;
			}
			else
				return false;
		}
	}

	// Create a board with l1, l2, b
	int i, j;
	for(i=0; i<r; ++i)
		for(j=0; j<c; ++j)
			sol[i][j] = '*';
	if(l3 == 0){
		for(i=0; i<=b-2; ++i)
			for(j=0; j<=l1-1; ++j)
				sol[i][j] = '.';
		for(j=0; j<=l2-1; ++j)
			sol[b-1][j] = '.';
	}
	else{
		for(i=0; i<=b-3; ++i)
			for(j=0; j<=l1-1; ++j)
				sol[i][j] = '.';
		for(j=0; j<=l2-1; ++j)
			sol[b-2][j] = '.';
		for(j=0; j<=l3-1; ++j)
			sol[b-1][j] = '.';
	}

	if(to_transpose){
		char temp[50][50];
		for(i=0; i<50; ++i)
			for(j=0; j<50; ++j)
				temp[i][j] = sol[j][i];
		for(i=0; i<50; ++i)
			for(j=0; j<50; ++j)
				sol[i][j] = temp[i][j];
	}

	return true;
}

void print(int r, int c)
{
	sol[0][0] = 'c';
	int i, j;
	for(i=0; i<r; ++i){
		for(j=0; j<c; ++j){
			cout << sol[i][j];
		}
		cout << endl;
	}
}

int main(void)
{
	freopen("C-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	std::ios_base::sync_with_stdio(false);
	int i, j, k;

	int t, r, c, m;
	int free;

	cin >> t;
	for(i=1; i<=t; ++i)
	{
		cin >> r >> c >> m;
		cout << "Case #" << i << ":\n";

		free = r*c-m;
		if(free == 1){
			// Possible
			for(j=0; j<r; ++j)
				for(k=0; k<c; ++k)
					sol[j][k] = '*';
			print(r, c);
		}
		else if(r == 1){
			for(j=0; j<=free-1; ++j)
				sol[0][j] = '.';
			for(j=free; j<c; ++j)
				sol[0][j] = '*';
			print(r, c);
		}
		else if(c == 1){
			for(k=0; k<=free-1; ++k)
				sol[k][0] = '.';
			for(k=free; k<r; ++k)
				sol[k][0] = '*';
			print(r, c);
		}
		else if(free >= 4){
			if(solve(r, c, free))
				print(r, c);
			else
				cout << "Impossible\n";
		}
		else
			cout << "Impossible\n";
	}

	return 0;
} 


/*

5 5 4
21

.....
.....
.....
....*
..***
*/