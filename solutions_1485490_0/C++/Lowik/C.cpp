#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <map>
#include <algorithm>

using namespace std;


typedef unsigned __int64	u64 ;
typedef signed	 __int64	si64 ;
typedef unsigned int		u32 ;


u64 GetBest(const u32 idBox, const u32 idToy, const vector<u64>& typeBox, const vector<u64>& nBox, const vector<u64>& typeToy, const vector<u64>& nToy, const u32 N, const u32 M) {
	if(idBox >=N || idToy >= M) {
		return 0;
	}

	if(typeBox[idBox] == typeToy[idToy]) {
		u64 result = 0;
		vector<u64> nBox_cpy = nBox;
		vector<u64> nToy_cpy = nToy;

		if(nBox[idBox] < nToy[idToy]) {
			result += nBox[idBox];
			nToy_cpy[idToy] -= nBox[idBox];
			result += GetBest(idBox+1, idToy, typeBox, nBox_cpy, typeToy, nToy_cpy, N, M);
		}
		else if(nBox[idBox] > nToy[idToy]) {
			result += nToy[idToy];
			nBox_cpy[idBox] -= nToy[idToy];
			result += GetBest(idBox, idToy+1, typeBox, nBox_cpy, typeToy, nToy_cpy, N, M);
		}
		else {
			result += nBox[idBox];
			result += GetBest(idBox+1, idToy+1, typeBox, nBox_cpy, typeToy, nToy_cpy, N, M);
		}
		return result;
	}
	else {
		/* We can throw the box */
		/* Throw box until we found the same toy type */
		//u32 new_box = idBox;
		//while(new_box < N && typeBox[new_box] != typeToy[idToy]) {
		//	new_box++;
		//}
		//u64 result1 = GetBest(new_box, idToy, typeBox, nBox, typeToy, nToy, N, M);

		///* OR throw the toy */
		//u32 new_toy = idToy;
		//while(new_toy < M && typeBox[idBox] != typeToy[new_toy] ) {
		//	new_toy++;
		//}
		//u64 result2 = GetBest(idBox, new_toy, typeBox, nBox, typeToy, nToy, N, M);

		u64 result1 = GetBest(idBox+1, idToy, typeBox, nBox, typeToy, nToy, N, M);
		u64 result2 = GetBest(idBox, idToy+1, typeBox, nBox, typeToy, nToy, N, M);
		
		return max(result1, result2);
	}
}

int main(int argc, char* argv[]) {
	string inTestName, outTestName;

	cout << "Enter the in test file name : " << endl;
	cin >> inTestName;
	cout << endl;

	size_t found = inTestName.find_last_of(".");
	outTestName = inTestName.substr(0, found) + ".out";

	/* Open file */
	ifstream inFile(inTestName.c_str());
	if(!inFile.is_open()) {
		cout << "Can't open input file" << endl;
		system("PAUSE");
		return 1;
	}

	ofstream outFile(outTestName.c_str());
	if(!outFile.is_open()) {
		cout << "Can't open output file" << endl;
		system("PAUSE");
		return 1;
	}

	int T; /*number of tests */
	inFile >> T;
	for(int t = 0; t < T; t++) {
		u32 N, M;
		inFile >> N >> M;
		vector<u64> nBox(N, 0);
		vector<u64> typeBox(N, 0);
		vector<u64> nToy(M, 0);
		vector<u64> typeToy(M, 0);

		for(int n = 0; n < N; n++) {
			inFile >> nBox[n];
			inFile >> typeBox[n];
		}

		for(int m = 0; m < M; m++) {
			inFile >> nToy[m];
			inFile >> typeToy[m];
		}

		u32 idBox = 0;
		u32 idToy = 0;
		u64 result = GetBest(idBox, idToy, typeBox, nBox, typeToy, nToy, N, M);

		outFile << "Case #" << t+1 << ": " << result << endl;
	}
	outFile.close();
	inFile.close();

	system("PAUSE");
	return 0;
}
