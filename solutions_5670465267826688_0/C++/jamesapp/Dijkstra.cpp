#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Vertex{
public:
	int i, j, k;
	Vertex(int ii, int jj, int kk) :i(ii), j(jj), k(kk){
	}
	int next(int index){
		if (index == 0){
			return i;
		}
		else if (index == 1){
			return j;
		}
		else{
			return k;
		}
	}
};

enum Status{
	status_start = 0,
	status_i_found = 1,
	status_j_found = 2,
	status_k_found = 3,
};

int main(){
	cin.sync_with_stdio(false);

	int T, L, X;
	string pattern;
	int patterntable[10000];
	cin >> T;

	vector<Vertex> v;
	v.push_back(Vertex(2, 4, 6)); // 1, start
	v.push_back(Vertex(3, 5, 7)); // -1
	v.push_back(Vertex(1, 6, 5)); // i
	v.push_back(Vertex(0, 7, 4)); // -i
	v.push_back(Vertex(7, 1, 2)); // j
	v.push_back(Vertex(6, 0, 3)); // -j
	v.push_back(Vertex(4, 3, 1)); // k
	v.push_back(Vertex(5, 2, 0)); // -k

	for (int t = 1; t <= T; t++){
		string result = "NO";
		Status status = Status::status_start;
		int currentVertex = 0;
		cin >> L >> X >> pattern;
		for (int l = 0; l < L; l++){
			patterntable[l] = pattern.at(l) - 'i';
		}
		for (int x = 0; x < X; x++){
			for (int l = 0; l < L; l++){
				currentVertex = v[currentVertex].next(patterntable[l]);
				if (status == Status::status_start && currentVertex == 2){
					status = Status::status_i_found;
					currentVertex = 0;
				}
				else if(status == Status::status_i_found && currentVertex == 4) {
					status = Status::status_j_found;
					currentVertex = 0;
				}
				else if (status == Status::status_j_found && currentVertex == 6) {
					status = Status::status_k_found;
					currentVertex = 0;
				}
			}
		}
		if (status == Status::status_k_found && currentVertex == 0){
			result = "YES";
		}
		cout << "Case #" << t << ": " << result << endl;
	}

	return 0;
}
