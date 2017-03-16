#include <iostream>
#include <algorithm>
#include <math.h>
#include <set>
using namespace std;

int a[1001], b[1001];
int num=0;
int S=0;
int N;

void check_b()
{
	int i=1;
	while (i<=N) {
		if (b[i]!=-1 && b[i]<=S) {
			if (a[i]==-1) {
				b[i]=-1; num++; S++;
			} else {
				a[i]=-1; b[i]=-1; num++; S+=2;
			}
			i=1;
		} else
			i++;
	}
}

int check_a()
{
	int idx = -1;
	int max=0;
	for (int i=1; i<=N; i++) {
		if (a[i]!=-1 && a[i]<=S) {
			if (b[i]>max) {
				idx = i;
				max = b[i];
			}
		}
	}

	return idx;
}	

void tst()
{
	S=0;
	num=0;
	cin >> N;
	for (int i=1; i<=N; i++)
		cin >> a[i] >> b[i];

	while (true) {
		check_b();
		if (S==2*N)
			break;
		int idx;
		idx = check_a();
		if (idx == -1) {
			cout << "Too Bad";
			return;
		} else {
			num++; S++; a[idx]=-1;
		}
	}

	cout << num;

	return;
}

int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++) {
		cout << "Case #" << i+1 << ": ";
		tst();
		cout << endl;
	}
}



