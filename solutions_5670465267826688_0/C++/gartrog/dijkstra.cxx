#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <map>

int sgn(int i);

class quaternion
{
  public:
    int val;

    quaternion() : val(1) {}
    quaternion(int v) : val(v) {}
    quaternion(const quaternion& o) : val(o.val) {}
    quaternion(quaternion&& o) = default;

    void mult(int v) {
      if(v==1) return;
      if(val==1) {val=v; return;}
      if(v==-1) {val = -val; return;}
      if(val==-1) {val = -v; return;}
      int res = sgn(val)*sgn(v);
      switch(abs(val)) {
        case 'i':
          switch(abs(v)) {
            case 'i':
              res *= -1;
              break;
            case 'j':
              res *= 'k';
              break;
            case 'k':
              res *= -'j';
              break;
          }
          break;
        case 'j':
          switch(abs(v)) {
            case 'i':
              res *= -'k';
              break;
            case 'j':
              res *= -1;
              break;
            case 'k':
              res *= 'i';
              break;
          }
          break;
        case 'k':
          switch(abs(v)) {
            case 'i':
              res *= 'j';
              break;
            case 'j':
              res *= -'i';
              break;
            case 'k':
              res *= -1;
              break;
          }
          break;
      }
      val = res;
    }
};

int studyCase();
quaternion quatsum(const std::string& patt);
int quadsolver(int L, int X, const std::string& patt);
std::map<int, std::vector<int>> runningProds(int L, const std::string& patt);
bool findj(int rstart, int pstart, int L, int X, const std::string& patt, const std::map<int, std::vector<int>>& prods);
bool isk(int rstart, int pstart, int L, int X, const std::string& patt, const std::map<int, std::vector<int>>& prods);


int main(int argc, char** argv) {

  int nCases;
  std::cin >> nCases;
  std::string line;
  for(int i=1; i<=nCases; i++) {
    int time = studyCase();
    std::string res;
    if(time == 1) res = "YES";
    else if(time == 0) res = "NO";
    else res = "BLIH";
    std::cout << "Case #" << i << ": " << res << std::endl;
  }

  return 0;
}

int studyCase() {
  int L;
  unsigned long long X;
  std::string patt;
  std::cin >> L >> X;
  std::cin >> patt;

  // at least 2 letters
  bool hasi = patt.find('i')!=std::string::npos;
  bool hasj = patt.find('j')!=std::string::npos;
  bool hask = patt.find('k')!=std::string::npos;
  if( (!hasi && !hasj) || (!hasj && !hask) || (!hask && !hasi)) return 0;

  if(X%4 == 0) return 0;
  if(X>12) {
    X = (X%4)+8;
  }

  quaternion sumL = quatsum(patt);
  //std::cout << "Product of pattern: " << sumL.val << std::endl;

  if(sumL.val == 1) return 0;
  if(X%2==1 && sumL.val!=-1) return 0;
  if(sumL.val == -1) {
    if(X%2 == 0) return 0;
    if(X>6) {
      X = (X%2)+4;
    }
  }

  return quadsolver(L, X, patt);
  //return -1;
}

int sgn(int i) {
  return (i > 0) - (i < 0);
}

quaternion quatsum(const std::string& patt) {
  quaternion q(patt[0]);
  int end = patt.size();
  for(int i=1; i<end; i++) {
    q.mult(patt[i]);
  }
  return q;
}

int quadsolver(int L, int X, const std::string& patt) {
  //std::cout << "in quadsolver" << std::endl;
  auto prods = runningProds(L, patt);
  //std::cout << "computed prods" << std::endl;

  // let's find i places
  int rowtype = 1;
  for(int r=0; r<X; r++) {
    const std::vector<int>& row = prods.at(rowtype);
    //std::cout << "got row " << rowtype << std::endl;
    for(int p=0; p<L; p++) {
      if(row[p] == 'i') {
        // look for j
        bool hasmatch = findj(r, p+1, L, X, patt, prods);
        if(hasmatch) return 1;
      }
    }
    rowtype = row[L-1];
  }
  return 0;
}

std::map<int, std::vector<int>> runningProds(int L, const std::string& patt) {
  std::map<int, std::vector<int>> resmap;
  std::vector<int> quatnames { 1, -1, 'i', -'i', 'j', -'j', 'k', -'k'};
  for(auto qn : quatnames) {
    std::vector<int> res(L);
    quaternion q(qn);
    for(int i=0; i<L; i++) {
      q.mult(patt[i]);
      res[i] = q.val;
    }
    resmap.emplace(qn, res);
  }
  return resmap;
}


bool findj(int rstart, int pstart, int L, int X, const std::string& patt, const std::map<int, std::vector<int>>& prods) {
  //std::cout << "in findj" << std::endl;
  quaternion q(1);
  for(int p=pstart; p<L; p++) {
    q.mult(patt[p]);
    if(q.val == 'j') {
      bool ismatch = isk(rstart, p+1, L, X, patt, prods);
      if(ismatch) return true;
    }
  }
  int rowtype = q.val;
  for(int r=rstart+1; r<X; r++) {
    const std::vector<int>& row = prods.at(rowtype);
    for(int p=0; p<L; p++) {
      if(row[p] == 'j') {
        // check for k
        bool ismatch = isk(r, p+1, L, X, patt, prods);
        if(ismatch) return true;
      }
    }
    rowtype = row[L-1];
  }
  return false;
}

bool isk(int rstart, int pstart, int L, int X, const std::string& patt, const std::map<int, std::vector<int>>& prods) {
  //std::cout << "in isk" << std::endl;
  quaternion q(1);
  for(int p=pstart; p<L; p++) {
    q.mult(patt[p]);
  }
  int rowtype = q.val;
  for(int r=rstart+1; r<X; r++) {
    const std::vector<int>& row = prods.at(rowtype);
    rowtype = row[L-1];
  }
  if(rowtype == 'k') return true;
  return false;
}

