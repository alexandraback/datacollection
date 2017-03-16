#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

#define SIZE 51

void Init(int A[],int Size) {
for( int i = 0 ; i < Size ; ++i)
	A[i] = 0;
}

void Init(int A[][SIZE],int Size) {
	for(int i = 0 ; i < Size ; ++i) 
		for(int j = 0 ; j < Size ; ++j) 
			A[i][j] = 0;
}

void GetValidSP(vector<int>& vsp,int od[],int s) {
	for(int i = 1 ; i <= s ; ++i) 
			if(od[i] > 1)
				vsp.push_back(i);

}

// dfs find a path
bool findPath(int S,int E, int matrix[][SIZE],int path[][SIZE],int Size) {
	
	if(S == E)
		return true; // path found
	else {
		
		int i = 0;
		for(i = 1 ; i <= Size ; ++i) {
			
			if(i == S)
				continue;
			if(matrix[S][i]  && (path[S][i] == 0)) {
				path[S][i] = 1;
				bool status = findPath(i,E,matrix,path,Size);
				if( status)
					return true;
				path[S][i] = 0;
			}
	
		}
		return false;
	}

}


bool Solve1(int S,int E, int matrix[][SIZE],int Size) {
	
	bool status = false;

	int path[SIZE][SIZE];
	Init(path,SIZE);

	bool pathExist = findPath(S,E,matrix,path,Size);
	bool anotherPath = false;
	// got a path from S to E
	if(pathExist) {
		// find another path fro S to E
		anotherPath = findPath(S,E,matrix,path,Size);
	}

	return pathExist && anotherPath;
}

bool Solve(int matrix[][SIZE],int Size,int oDegree[]) {
	
	// all those cell which have oDegree greater than 1 can be a start point.
	vector<int>vsp;
	GetValidSP(vsp,oDegree,Size);
	
	if(vsp.empty())
		return false;

	int vspS = vsp.size();
	bool done = false;
	for(int i = 0 ; i < vsp.size() ; ++i) {
		int start = vsp[i]; // take an end point and figure out if two paths exists to a particular node.
		
		for(int j = 1 ; j <= Size; ++j) {
			
			if( j == start)
				continue;

		//	if( matrix[start][j] == 1)
		//		continue; // ignore immediate parent.

			bool twoPathExist = Solve1(start,j,matrix,Size);
			if(twoPathExist)
				return true;
		}
	}

	return false;
}

int main() {

	ifstream istrm;
	istrm.open("input.txt",ifstream::in);
	ofstream ostrm;
	ostrm.open("output.txt",ofstream::out);
	int T;
	istrm>>T;
		
	int caseNo = 1;
	while(T--) {
		

		int matrix[SIZE][SIZE];
		int oDegree[SIZE];
		Init(matrix,SIZE);
		Init(oDegree,SIZE);
		int N;
		istrm>>N;
		
		for(int i = 1 ; i <= N ; ++i) {
			int X;
			istrm>>X;
			oDegree[i] = X;
			while(X--) {
				int A;
				istrm>>A;
				matrix[i][A] = 1;
			}
		}
		
		bool ans = Solve(matrix,N,oDegree);
		ostrm<<"Case #"<<caseNo++<<": ";
		if(ans) {
 			ostrm<<"Yes\n";
		}
		else {
			ostrm<<"No\n";
		}
	}

	istrm.close();
	ostrm.close();
	return 0;
}


