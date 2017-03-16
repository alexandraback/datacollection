#include <fstream>

using namespace std;

int main(int argc, char* argv[]){
	ifstream in(argv[1]);
	ofstream out("cake.out");
  int T, k;
  string s;
  in >> T;
  for(int i=1; i<=T; i++){
    k = 0;
    in >> s;
    int L = s.length();
    if(s[L-1] == '-'){
      k++;
    }
    char c = s[0];
    for(int j=0; j<L; j++){
      if(s[j] != c){
        c = s[j];
        k++;
      }
    }
    out << "Case #" << i << ": " << k << endl;
  }
}
