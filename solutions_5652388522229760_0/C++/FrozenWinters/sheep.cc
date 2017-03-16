#include <fstream>

using namespace std;

int main(int argc, char* argv[]){
	ifstream in(argv[1]);
	ofstream out("sheep.out");
	int T;
	unsigned long long N, M, temp;
	in >> T;
	for(int i=1; i<=T; i++){
		in >> N;
		bool hit[10] = {};
		if(N == 0){
			out << "Case #" << i << ": INSOMNIA" << endl;
		} else{
			M = 0;
			while(true){
				temp = M += N;
				while(temp != 0){
					hit[temp % 10] = true;
					temp /= 10;
				}
				bool done = true;
				for(int j = 0; j<10; j++){
					if(!hit[j]){
						done = false;
						break;
					}
				}
				if(done){
					out << "Case #" << i << ": " << M << endl;
					break;
				}
			}
		}
	}
}
