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
	vector<int> row;
	vector<int> column;
	int num = 1;
	while(t--) {
		cin>>n>>m;
		lawn.clear();
		lawn.resize(n);
		row.clear();
		row.resize(n,0);
		column.clear();
		column.resize(m,0);
		for(int i=0;i<n;i++)
			lawn[i].resize(m,0);
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				cin>>lawn[i][j];
			}
		}
		
		for(int i=0;i<n;i++) {
			int maxi = 0;
			for(int j=0;j<m;j++) {
				if(lawn[i][j] > maxi)
					maxi = lawn[i][j];
			}
			row[i] = maxi;
		}
		
		for(int i=0;i<m;i++) {
			int maxi = 0;
			for(int j=0;j<n;j++) {
				if(lawn[j][i] > maxi)
					maxi = lawn[j][i];
			}
			column[i] = maxi;
		}
		
		bool ans = true;
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
					if (!(row[i] == lawn[i][j] || column[j] == lawn[i][j]))
						ans = false;
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