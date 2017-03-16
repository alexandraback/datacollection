#include<cmath>
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include<map>
using namespace std;
typedef int mint;
typedef vector<mint> vi;
typedef vector<vi> vvi;


/*Input

The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with a line containing two numbers: N and M. Next follow N lines, with the ith line containing M numbers ai,j each, the number ai,j describing the desired height of the grass in the jth square of the ith row.
Output

For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1) and y is either the word "YES" if it's possible to get the x-th pattern using the lawnmower, or "NO", if it's impossible (quotes for clarity only). */



bool solve(vvi& lawn){//ass
	//each row and col has a min and a max
	//each cell in that column must be at least the min and at most the max.
	//i want to mark it as |1 if it's a min and |2 if it's a max
	//100 is not a max
	
	//if a cell is less than the max in its row AND less than the max in its col this fails.
	//if a cell is MORE than the max in its row then it doesn't.

	int rows=lawn.size(), cols=lawn[0].size();
	
	vi rowmax(rows,0), colmax(cols,0);
	
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			rowmax[i] = max(rowmax[i],lawn[i][j]);
			colmax[j] = max(colmax[j],lawn[i][j]);
		}
	}
	for(int i=0;i<rows;i++)
		for(int j=0;j<cols;j++)
			if(lawn[i][j]<rowmax[i] && lawn[i][j]<colmax[j])
				return false;
	return true;
}

int main(int argc, char** argv){
//*	
	ifstream cin(argv[1]);
/*/	istringstream cin("3 3 3 2 1 2 1 1 1 2 1 2 5 5 2 2 2 2 2 2 1 1 1 2 2 1 2 1 2 2 1 1 1 2 2 2 2 2 2 1 3 1 2 1");
/**/
	ofstream cout("output.txt");
	int t;
	cin>>t;
	for(int i = 0; i<t; i++){
		
		int n,m;
		cin>>n>>m;
		vector<vector<int> > blah(n,vector<int>(m));
		for(auto& row:blah) //whoo c++11
			for(auto& cell:row)
				cin>>cell;
		
		
		cout<<"Case #"<<(i+1)<<": ";
		
		cout<<((solve(blah)?"YES":"NO"));
		
		cout<<endl;
	}
	return 0;
}
