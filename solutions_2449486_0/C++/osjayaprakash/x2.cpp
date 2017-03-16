#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int l[105][105];
int n,m;
int rowmax[105];
int colmax[105];

int sol(){
	cin >> n >> m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> l[i][j];

	for(int i=0;i<n;i++){
		rowmax[i] = 0;
		for(int j=0;j<m;j++)
			rowmax[i] = max(rowmax[i], l[i][j]);
	}

	for(int j=0;j<m;j++){
		colmax[j] = 0;
		for(int i=0;i<n;i++)
			colmax[j] = max(colmax[j], l[i][j]);
	}
	
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			if(l[i][j] != min(rowmax[i], colmax[j])){
				cout << "NO";
				return 0;
			}
		}
	
	cout << "YES"; 
	return 0;
}

int main(){
	int t=0;
	cin >> t;
	for(int i=1;i<=t;i++){
		cout << "Case #"<<i<< ": ";
		sol();
		cout<<endl;
	}		
}
