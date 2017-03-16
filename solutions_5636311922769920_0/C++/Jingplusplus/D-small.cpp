#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;



class BigInt {
public:
  BigInt() {
    sequence.push_back(1);
  }
  BigInt(int a, int b) {
    sequence.push_back(1);
    for (int i = 0; i < b; i++) {
      this->multiply(a);
    }
  }
  BigInt(const BigInt &big) {
    sequence = big.sequence;
  }

  void add(const BigInt &big) {
    int res;
    int i;
    for (i = 0; i < big.sequence.size(); i++) {
      sequence[i] += big.sequence[i];
      if (sequence.size() <= i + 1) {
        sequence.push_back(0);
      }
      sequence[i+1] += sequence[i] / 10;
      sequence[i] = sequence[i] % 10;
    }
    
    while(sequence[i] >= 10) {
      if (sequence.size() <= i+1) {
        sequence.push_back(0);
      }
      sequence[i+1] += sequence[i] / 10;
      sequence[i] = sequence[i] % 10;
      i++;
    }
    
    if (sequence.back() == 0) {
      sequence.pop_back();
    }
  }

  void multiply(int x) {
    BigInt dup = *(this);
    for (int i = 0; i < x - 1; i++) {
      this->add(dup);
    }
  }

  void print(ofstream &ofile) {
    //cout << sequence.size() << endl;
    for (int i = sequence.size() - 1; i >= 0; i--) {
      cout << sequence[i];
      ofile << sequence[i];
    }
  }


  vector<int> sequence;
};



int main(int argc, char *argv[]) {

  
  

  if (argc != 3) {
    cout << "Usage: a.out file_in file_out" << endl;
    return -1;
  }

  ifstream file_in;
  ofstream file_out;
  file_in.open(argv[1]);
  file_out.open(argv[2]);

  /*
  BigInt a(3,4);
  BigInt b(2,4);
  BigInt c(3,2);
  a.add(b);
  a.add(c);
  a.print(file_out);
  cout << endl;
  */

  int T;
  file_in >> T;

  int K, C, S;
  int min;
  int count;
  

  for (int t = 1; t <= T; t++) {
    file_in >> K >> C >> S;
    file_out << "Case #" << t << ": ";
    cout << "Case #" << t << ": ";

    min = (K-1) / C + 1;
    if (S < min) {
      file_out << "IMPOSSIBLE" << endl;
      cout << "IMPOSSIBLE" << endl;
    }
    else {
      count = 0;
      for (int i = 0; i < min; i++) {
        BigInt index;
        for (int j = C-1; j>=0; j--) {
          //index += count * pow(K,j);
          BigInt a(K, j);
          if (count != 0) {
            a.multiply(count);
            index.add(a);
          }
          count += 1;
          if (count >= K) break;
        }
        index.print(file_out);
        cout << " ";
        file_out << " ";
      }
      file_out << endl;
      cout << endl;
    }
  }

  return 0;
}
