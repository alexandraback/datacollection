// Google Code Jam 2012
// Problem C. Box Factory

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

typedef long long int number_t;

class Items {
public:
	number_t number;
	int type;
};

typedef vector<Items> Line;

number_t calculate_max_boxes(Line &A, Line &B) {
	if(A.empty() || B.empty()) return 0;

	if(A[0].type == B[0].type) {
		// Send as many boxes as posible
		number_t number = min(A[0].number, B[0].number);

		Line A1 = A, B1 = B;

		A1[0].number -= number;
		if(A1[0].number <= 0) A1.erase(A1.begin());
		B1[0].number -= number;
		if(B1[0].number <= 0) B1.erase(B1.begin());

		return number + calculate_max_boxes(A1, B1);
	}

	// take best of 2 strategies
	number_t boxes;

	Line A1 = A;
	A1.erase(A1.begin());
	boxes = calculate_max_boxes(A1, B);

	Line B1 = B;
	B1.erase(B1.begin());
	boxes = max(boxes, calculate_max_boxes(A, B1));

	return boxes;
}

int main(int argc, char* argv[])
{
	int T;
	cin >> T;
	for(int t=0; t<T; t++)
	{
		int N, M;
		cin >> N >> M;

		Line A(N);
		for(int n=0; n<N; n++) {
			cin >> A[n].number >> A[n].type;
		}

		Line B(M);
		for(int m=0; m<M; m++) {
			cin >> B[m].number >> B[m].type;
		}

		cout << "Case #" << t+1 << ": " << calculate_max_boxes(A, B) << endl;
	}

	return 0;
}
