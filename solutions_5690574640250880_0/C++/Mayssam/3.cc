
#define	MAX	50

#include <iostream>
#include <string.h>

using namespace std;

char sym[] = {'*','.','c'};
unsigned arr[1+MAX][1+MAX];

bool possible(int r, int c, int f) {
    if (f == 0) return false;
    if (f > r*c) return false;
    if (r > c) return possible(c, r, f);
    memset(arr, 0, sizeof(arr));
    if (f == 1) {
	arr[0][0] = 2;
	return true;
    }
    if (r == 1) {
	arr[0][0] = 2;
	for (int s=1; s<f; s++)
	    arr[0][s] = 1;
	return true;
    }
    if (r == 2) {
	if (f < 4) return false;
	if (f%2 == 1) return false;
	for (int s=0; s<2; s++)
	for (int t=0; t<f/2; t++)
	    arr[s][t] = 1;
	arr[0][0] = 2;
	return true;
    }
    if (f > 2*r + 1) {
	int rem = f % r;
	int col = f / r;
	for (int s=0; s<r; s++)
	for (int t=0; t<col; t++)
	    arr[s][t] = 1;
	for (int s=0; s<rem; s++)
	    arr[s][col] = 1;
	if (rem == 1) {
	    arr[1][col] = 1;
	    arr[r-1][col-1] = 0;
	}
	arr[0][0] = 2;
	return true;
    }
    if (f < 4) return false;
    for (int i=2; i<r; i++)
    for (int j=2; j<c; j++) {
	for (int s=0; s<i; s++)
	for (int t=0; t<j; t++)
	    arr[s][t] = 1;
	arr[0][0] = 2;
	if (f == i*j) {
	    return true;
	}
	if (f == i*j + 5) {
	    arr[i][j] = arr[i-1][j] = arr[i-2][j] = arr[i][j-1] = arr[i][j-2] = 1;
	    return true;
	}
	for (int k=2; k<=i; k++)
	    if (f == i*j + k) {
		for (int s=0; s<k; s++)
		    arr[s][j] = 1;
		return true;
	    }
	for (int l=2; l<=j; l++)
	    if (f == i*j + l) {
		for (int t=0; t<l; t++)
		    arr[i][t] = 1;
		return true;
	}
	for (int k=2; k<=i; k++)
	for (int l=2; l<=j; l++)
	    if (f == i*j+k+l) {
		for (int s=0; s<k; s++)
		    arr[s][j] = 1;
		for (int t=0; t<l; t++)
		    arr[i][t] = 1;
		return true;
	    }
    }
    return false;
}


bool check(int r, int c) {
    int x[] = { 0, 0, 1, 1, 1, -1, -1, -1};
    int y[] = { 1, -1, 0, 1, -1, 0, 1, -1};
    int tab[r][c];
    memset(tab, 0, sizeof(tab));
    arr[0][0] = 1;
    for (int i=0; i<r; i++)
    for (int j=0; j<c; j++) 
    for (int k=0; k<8; k++) {
	int xn = i + x[k];
	int yn = j + y[k];
	if (xn>=0 && xn<r)
	if (yn>=0 && yn<c) {
	  if (r<=c && arr[xn][yn]==0)
	    tab[i][j]++;
	  if (r>c && arr[yn][xn]==0)
	    tab[i][j]++;
	}
    }
    for (int i=0; i<r; i++)
    for (int j=0; j<r; j++)
	if (tab[i][j]>0) {
	    if (r <= c && arr[i][j] == 0) continue;
	    if (r > c && arr[j][i] == 0) continue;
	    bool found = false;
	    if (i+j == 0) found = true;
	    for (int k=0; !found && k<8; k++) {
		int xn = i + x[k];
		int yn = j + y[k];
		if (xn>=0 && xn<r)
		if (yn>=0 && yn<c)
		if (tab[xn][yn]==0)
		    found = true;
	    }
	    if (!found) {
		cout << "----------------------------\n";
		cout << (r) << " x " << (c) << endl;
		cout << (1+i) << " , " << (1+j) << endl;
		for (int ii=0; ii<r; ii++, cout<<endl)
		for (int jj=0; jj<c; jj++)
		    cout << tab[ii][jj] << " ";
		return false;
	    }
	}
    return true;
}

int main() {

/*    for (int r=1; r<=5; r++)
    for (int c=1; c<=5; c++)
    for (int m=0; m<r*c; m++) {
	if (possible(r, c, r*c-m)) {
	    if (!check(r,c)) {
		cout << r << " " << c << " " << m << " : " << r*c-m << endl;
		for (int i=0; i<r; i++, cout<<"\n")
		for (int j=0; j<c; j++)
		    if (r<=c) cout << sym[arr[i][j]];
		    else cout << sym[arr[j][i]];
	    }
	} else {
	    cout << "Impossible: " << r << " " << c << " " << m << " : " << r*c-m << endl;
	}
    }
    return 0;*/

    int t = 0;
    cin >> t;
    for (int i=0; i<t; i++) {
	int r, c, m=-1;
	cin >> r >> c >> m;
	if (m < 0) break;
	int f = r * c - m;
	cout << "Case #" << (1+i) << ":\n";
	if (!possible(r, c, f)) cout << "Impossible\n";
	else if (r <= c) {
	    for (int j=0; j<r; j++, cout<<"\n")
	    for (int k=0; k<c; k++)
		cout << sym[arr[j][k]];
	} else {
	    for (int j=0; j<r; j++, cout<<"\n")
	    for (int k=0; k<c; k++)
		cout << sym[arr[k][j]];
	}
    }
    return 0;
}
