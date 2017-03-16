#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <cctype>

using namespace std;

bool outOfRange(int rows,int cols,int i,int j){
  return (i<rows && j<cols)?false:true;
}

bool DFS( int* visited, int** classes, int cNum, int cRow ){

	if( visited[cRow] == 1 )
		return true;

	visited[cRow] = 1;
	for( int i=0; i<cNum; i++ ){
		if( classes[cRow][i] == 1 ){
			bool r = DFS( visited, classes, cNum, i );
			if( r == true )
				return true;
		}
	}
	return false;
}

bool checkDiamonds( int** classes, int cNum, int* inhs ){

	int* visited = new int[cNum];

	for( int r=0; r<cNum; r++ ){
		if( inhs[r] != 0 ){
			for(int i=0; i<cNum; i++){
				visited[i]=0;
			}
			if( DFS( visited, classes, cNum, r ) == true )
				return true;
		}
	}

	return false;
}

int main(){

  freopen("A-small-attempt0.in","r",stdin);
  //freopen("A-large.in","r",stdin);
  freopen("outA.txt","w",stdout);
	
  int cases;
  cin >> cases;


  string result;

  for(int i=1;i<=cases;i++){
    cout << "Case #"<<i<<": ";

	int cNum;
	cin >> cNum;

	int** classes = new int*[cNum];
	int *inhs = new int[cNum];

	for( int j=0;j<cNum;j++ ){
		classes[j] = new int[cNum];
	}

	for( int j=0;j<cNum;j++ ){
		for( int k=0;k<cNum; k++ )
			classes[j][k] = 0;
	}

	// for each class
	for( int j=0; j<cNum; j++ ){
		cin >> inhs[j];
		for(int k=0; k<inhs[j]; k++){
			int nI;
			cin >> nI;
			classes[j][--nI] = 1;
		}
	}
    
	// check for diamonds
	result = ( checkDiamonds(classes, cNum, inhs) )?"Yes":"No";

    
    // print result
    cout << result << endl;
  }


  return 0;
}
