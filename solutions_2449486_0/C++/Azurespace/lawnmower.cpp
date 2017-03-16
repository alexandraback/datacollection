#include<fstream>
#include<algorithm>
using namespace std;

int N, M;
int data[100][100];

int max_row[100];
int max_col[100];

bool is_ok(){
	int i, j;
	for(i=0;i<N;++i){
		for(j=0;j<M;++j){
			if(max_row[i] > data[i][j] && max_col[j] > data[i][j]){
				return false;
			}
		}
	}
	return true;
}

int main(){
	ifstream in("lawnmower.in");
	ofstream out("lawnmower.out");

	int num_cases;
	in >> num_cases;

	for(int no = 1; no <= num_cases; ++no){
		int i, j;
		in >> N >> M;
		
		fill_n(max_row, N, 0);
		fill_n(max_col, M, 0);
		
		for(i=0;i<N;++i){
			for(j=0;j<M;++j){
				in >> data[i][j];
				
				max_row[i] = max( max_row[i], data[i][j] );
				max_col[j] = max( max_col[j], data[i][j] );
			}
		}		

		out << "Case #" << no << ": ";
		
		if(is_ok()) out << "YES";
		else out << "NO";

		out << endl;
	}
	
	
	out.close();
	in.close();
	return 0;
}