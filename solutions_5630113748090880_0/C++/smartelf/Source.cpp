#include <fstream>
#include <string>
#include <vector>

using namespace std;




int main(){
	ifstream in("B-small-attempt0.in");
	ofstream out("out.txt");
	unsigned cases(0), size(0), n(0);
	in >> cases;
	for(int c = 1; c <= cases; ++c){
		vector<int> count(2501,0);
		in >> size;
		for(int j = 0; j < size * 2 * size - size ; ++j){
			in >> n;
			count[n]++;
		}
	
		out << "Case #" << c << ":" ;
		for(int i = 0; i < 2501; ++i){
			if(count[i] % 2 == 1)out << " " << i;
		}
		out << "\n";
	}
	out.flush();
	return 0;
}