#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <stdlib.h>
#include <iomanip>
#include <locale>
#include <sstream>
#include <deque>


#define FOR(i,a,b) for(int(i)=a;i<b;i++)
#define MAX 200004
#define mp make_pair
using namespace std;

typedef long long ll;

int main() {
	int t;
	cin>>t;
	int n,m;
	vector<vector<int> > lawn;
	vector<bool> row;
	vector<bool> column;
	int num = 1;
	while(t--) {
		cin>>n>>m;
		lawn.clear();
		lawn.resize(n);
		row.clear();
		row.resize(n,false);
		column.clear();
		column.resize(m,false);
		for(int i=0;i<n;i++)
			lawn[i].resize(m,0);
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				cin>>lawn[i][j];
			}
		}
		
		for(int i=0;i<n;i++) {
			bool yup = true;
			for(int j=0;j<m&&yup;j++) {
				if(lawn[i][j] != 1)
					yup  = false;
			}
			if(yup)
				row[i] = true;
		}

		for(int i=0;i<m;i++) {
			bool yup = true;
			for(int j=0;j<n&&yup;j++) {
				if(lawn[j][i] != 1)
					yup  = false;
			}
			if(yup)
				column[i] = true;
		}
		bool ans = true;
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				if(lawn[i][j] == 1) {
					if (!(row[i] || column[j]))
						ans = false;
				}
					
			}
		}
		if(ans)
			cout<<"Case #"<<num<<": YES"<<endl;
		else
			cout<<"Case #"<<num<<": NO"<<endl;
		num++;
	}
	return 0 ;
}