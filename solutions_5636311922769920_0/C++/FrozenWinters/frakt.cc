#include <fstream>

using namespace std;

unsigned long long pow(int A, int B){
  if(B == 0){
    return 1;
  } else{
    return pow(A, B-1) * A;
  }
}

int main(int argc, char* argv[]){
	ifstream in(argv[1]);
	ofstream out("frakt.out");
  int T, K, C, S;
  unsigned long long pos;
  in >> T;
  for(int i=1; i<=T; i++){
    in >> K >> C >> S;
    if(K > C * S){
      out << "Case #" << i << ": IMPOSSIBLE" << endl;
    } else{
      out << "Case #" << i << ":";
      int m = (K+C-1) / C;
      int z = 0;
      for(int j=0; j<m; j++){
        pos = 1;
        for(int l=C-1; l>=0; l--){
          pos += pow(K, l) * z;
          if(z < K-1){
            z++;
          }
        }
        out << " " << pos;
      }
      out << endl;
    }
  }
}
