#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	char c;
	int n,i,j,k,sm,L,t;
	int mat[2005];
		
	ifstream ii("4.txt");
	ofstream oo("o.txt");
	ii >> n;
	for (k=1; k<n+1; k++){
		ii >> sm;
		for (i = 0; i < sm + 1; i++){
			ii >> c;
			mat[i]=c-'0';
		}
		L = 0;
		t = 0;
		for (i = 0; i < sm + 1; i++){
			if (L < i && t < i - L)t = i - L;
			L = L + mat[i];
		}
		oo << "Case #" << k << ": " << t;
		if (k == n)break;
		oo << "\n";


	}

	ii.close();
	oo.close();


}