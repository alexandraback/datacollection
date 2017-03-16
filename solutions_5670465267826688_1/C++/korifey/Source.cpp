#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int mult(int a, int b)
{
  int res;
  int sign_ = 1;
  if (a < 0)
  {
    sign_ = -1;
    a = -a;
  }

  switch (a)
  {
  case 1:
    res = b;
    break;
  case 2:
    if (b == 2) res = -1;
    else if (b == 3) res = 4;
    else res = -3;
    break;
  case 3:
    if (b == 2) res = -4;
    else if (b == 3) res = -1;
    else res = 2;
    break;
  case 4:
    if (b == 2) res = 3;
    else if (b == 3) res = -2;
    else res = -1;
    break;
  default:
    throw "defalut@!!!#@$@$";
    break;
  }

  return sign_ * res;
}

int main() {
  ifstream in("c-large.in");
  ofstream out("c-large.out");


  int ncases = 0;
  in >> ncases;
  cout << sizeof(long long) << endl;
  
  int exp[4];
  exp[0] = 2;
  exp[1] = 3;
  exp[2] = 4;
  exp[3] = 10;
 
  for (int icase = 0; icase < ncases; icase++)
  {
    int l;
    long long x;
    string s;
    in >> l;
    in >> x;
    in >> s;
    //cout << (icase + 1) << ": '"<<s <<"'"<< endl;

    int xx = x % 100;
    int expIdx = 0;
    int a = 1;

    for (int i = 0; i < xx; i++)
    {
      for (int j = 0; j < l; j++) {
        int b = s[j] - 'i' + 2;
        a = mult(a, b);
        if (a == exp[expIdx])
        {
          expIdx++;
          a = 1;
        }
      }
    }

    bool answer = a == 1 && expIdx == 3;

    out << "Case #"<<(icase+1)<<": " << (answer ? "YES" : "NO") << endl;
    

    //out << "Case #"<<(icase+1)<<": " <<hi << endl;
  }

  in.close();
  out.close();
  return 0;
}

