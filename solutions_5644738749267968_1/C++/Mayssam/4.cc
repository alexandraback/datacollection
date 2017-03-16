
#include <iostream>
#include <string.h>

#define	MAXN	1000

using namespace std;

double nao[1+MAXN], ken[1+MAXN];
double tmp[1+MAXN];

void order(double arr[], int fi, int li) {
    if (li <= fi) return;
    if (fi + 1 == li) {
	if (arr[fi] <= arr[li]) return;
	double tmp2 = arr[fi];
	arr[fi] = arr[li];
	arr[li] = tmp2;
	return;
    }
    int mi = (fi+li) / 2;
    order(arr, fi, mi);
    order(arr, mi+1, li);
    int p1 = fi;
    int p2 = mi+1;
    int ptr = fi;
    while (p1 <= mi && p2 <= li) {
	if (arr[p1] < arr[p2]) tmp[ptr++] = arr[p1++];
	else tmp[ptr++] = arr[p2++];
    }
    while (p1 <= mi) tmp[ptr++] = arr[p1++];
    while (p2 <= li) tmp[ptr++] = arr[p2++];
    for (int i=fi; i<=li; i++)
	arr[i] = tmp[i];
}

int main() {

    int t = -1;
    cin >> t;
    
    for (int i=0; i<t; i++) {
	int N = 0;
	cin >> N;
	memset(nao, 0, sizeof(nao));
	memset(ken, 0, sizeof(ken));
	for (int j=0; j<N; j++)
	    cin >> nao[j];
	for (int j=0; j<N; j++)
	    cin >> ken[j];

	order(nao, 0, N-1);
	order(ken, 0, N-1);
	cout << "Case #" << (1+i) << ": ";
	
	
	int nptr = 0;
	int kptr = 0;
	int score = 0;

	for (int j=0; j<N; j++) {
	    if (nao[nptr] < ken[kptr]) nptr++;
	    else {
		nptr++;
		kptr++;
		score++;
	    }
	}
	cout << score << " ";

	nptr = kptr = N-1;
	score = 0;
	for (int j=0; j<N; j++) {
	    if (nao[nptr] > ken[kptr]) {
		nptr--;
		score++;
	    } else {
//		cout << nao[nptr] << " < " << ken[kptr] << endl;
		nptr--;
		kptr--;
	    }
	}
	cout << score << endl;
	
    }

    return 0;
}
