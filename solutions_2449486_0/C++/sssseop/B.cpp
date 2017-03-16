#include <fstream>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");


int a[101][101];


void prs()
{
	int i, j;
	int n, m;
	in >> n >> m;
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			in >> a[i][j];
		}
	}
	int row[101] = {0,};
	int col[101] = {0,};
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			if(a[i][j] == 2){
				row[i] = 1;
				col[j] = 1;
			}
		}
	}
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			if(a[i][j] == 1){
				if(row[i] == 1 && col[j] == 1){
					out <<"NO"<<endl;
					return;
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
		if(i == 99){
			i=i;
		}
		out << "Case #"<<i+1<<": ";
		prs();
	}
	return 0;
}

