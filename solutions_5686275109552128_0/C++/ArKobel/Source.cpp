#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	int K, N;
	int max=-1;
	int n,nn,i,j,k,sum;
	int s;
	int mat[2005], mm[2005];
	cout << "AAA";
	
	ifstream ii("2.in");
	ofstream oo("o.txt");
	ii >> N;
	for (K=1; K<N+1; K++){
		max = -1;
		sum = 0;
		ii >> n;
		for (i = 0; i < n; i++){
			ii>>mat[i];
			if (mat[i]>max)max = mat[i];
		}
		for (k = max - 1; k > 0; k--){
			s = 0;
			nn = n;
			for (i = 0; i < nn; i++){
				if (mat[i]>k){
					mat[nn] = mat[i] - k;
					nn++;
					s++;
				}
			}
			if (max>s + k){
				max = s + k;
			}
		}
		oo << "Case #" << K << ": " << max ;
		if (K == N)break;
		oo << "\n";


	}

	ii.close();
	oo.close();


}