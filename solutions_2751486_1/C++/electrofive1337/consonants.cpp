#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Name{
public:
  Name(){};

  Name(string x1, int n1){
    x = x1;
    n = n1;
  }

  long long GetNumOfSeq(){
    long long ans = 0;
    left[0] = 0;
    fist[0] = -1;
    if(!isvow(x[0]))
      ++left[0];
    for(int i = 0; i < x.size(); ++i){
      if(!isvow(x[i])) if(i > 0)
        left[i] = left[i - 1] + 1;
        else;
      else
        left[i] = 0;
      if(left[i] >= n)
        fist[i] = i;
      else if(i > 0)
        fist[i] = fist[i - 1];

      if(fist[i] != -1){
        int t = fist[i] - n + 2;
        ans += (long long)t;
      }
    }
    return ans;
  }
private:
  string x;
  int n, left[1000005], fist[1000005];

  bool isvow(char c){
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
  }
};

int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");

  int tests, test = 0;

  in >> tests;

  while(tests--){
    ++test;
    string x;
    int n;
    in >> x >> n;
    Name t(x, n);

    out << "Case #" << test << ": " << t.GetNumOfSeq();
    if(tests)
      out << "\n";
  }

  return 0;
}
