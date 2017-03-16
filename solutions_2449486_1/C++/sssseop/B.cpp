#include <fstream>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");


int a[101][101];


void prs()
{
	int i, j, k;
	int n, m;
	int row[101] = {0,};
	int col[101] = {0,};

	in >> n >> m;
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			in >> a[i][j];
		}
	}
	
	for(k=100; k>=1; k--){
		for(i=0; i<n; i++){
			for(j=0; j<m; j++){
				if(a[i][j] == k){
					if(row[i] == 1 && col[j] == 1){
						out <<"NO"<<endl;
						return;
					}
				}
			}
		}
		for(i=0; i<n; i++){
			for(j=0; j<m; j++){
				if(a[i][j] == k){
					row[i] = 1;
					col[j] = 1;
				}
			}
		}
	}
	out << "YES"<<endl;
}
int main()
{
	int t;
	in >> t;
	for(int i = 0; i < t; i++){
		out << "Case #"<<i+1<<": ";
		prs();
	}
	return 0;
}

