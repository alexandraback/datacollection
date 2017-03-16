#include <fstream>
#include <iostream>

using namespace std;

int getReverseMaxLen(bool reverseRelate[][1200], int start, int len);
int getReverseMaxLenOne(bool reverseRelate[][1200], int start, int len);

int main() {
	//set input/output stream
	ifstream input;
	ofstream output;
	input.open("input.txt");
	output.open("output.txt");

	int T;
	int N;
	int relate[1200];
	bool reverseRelate[1200][1200];
	bool visit[1200];

	input >> T;
	for(int x = 1; x <= T; x++) {
		input >> N;
		//init reverseRelate
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= N; j++) {
				reverseRelate[i][j] = false;
			}
		}
		for(int i = 1; i <= N; i++) {
			int friendID;
			input >> friendID;
			relate[i] = friendID;
			reverseRelate[friendID][i] = true;
		}

		int maxNum = 2;
		for(int i = 1; i <= N; i++) {
			int sum;
			if(reverseRelate[i][relate[i]] == true) { // i is relate[i]'s friend
				//set reverseRelate
				reverseRelate[relate[i]][i] = false;
				reverseRelate[i][relate[i]] = false;
				sum = getReverseMaxLen(reverseRelate, i, N) + getReverseMaxLen(reverseRelate, relate[i], N);
				maxNum = maxNum > sum ? maxNum : sum;
				//unset reverseRelate
				reverseRelate[relate[i]][i] = true;
				reverseRelate[i][relate[i]] = true;
			} else {
				sum = getReverseMaxLenOne(reverseRelate, i, N);
			}	

			maxNum = maxNum > sum ? maxNum : sum;
		}

		//output
		output << "Case #" << x << ": " << maxNum << endl;
	}
	return 0;
}

int getReverseMaxLen(bool reverseRelate[][1200], int start, int len) {
	int maxLen = 0;
	int visit[1200];
	int m[1200];
	int pos = 0, end = 1;

	//init visit
	for(int i = 1; i <= len; i++) {
		visit[i] = 0;
	}
	visit[start] = 1;
	m[0] = start;

	while(pos < end) {
		int s = m[pos];
		for(int i = 1; i <= len; i++) {
			if(reverseRelate[s][i] && visit[i] == 0) {
				m[end++] = i;
				visit[i] = visit[s] + 1;	
			}
		}
		pos++;
	}

	//get maxLen
	for(int i = 1; i <= len; i++) {
		maxLen = maxLen > visit[i] ? maxLen : visit[i];
	}

	return maxLen;
}


int getReverseMaxLenOne(bool reverseRelate[][1200], int start, int len) {
	int visit[1200];
	int m[1200];
	int pos = 0, end = 1;

	//init visit
	for(int i = 1; i <= len; i++) {
		visit[i] = 0;
	}
	visit[start] = 1;
	m[0] = start;

	while(pos < end) {
		int s = m[pos];
		for(int i = 1; i <= len; i++) {
			if(reverseRelate[s][start]) {
				return visit[s];
			}
			if(reverseRelate[s][i] && visit[i] == 0) {
				m[end++] = i;
				visit[i] = visit[s] + 1;	
			}
		}
		pos++;
	}

	return 0;
}
