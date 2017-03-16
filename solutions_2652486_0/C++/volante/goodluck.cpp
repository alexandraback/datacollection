#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include <unordered_map>

using namespace std;

void bestGuess (vector<int> products, vector< vector<int> > perms, int maxprod) {
  vector< vector<int> > validGuesses;

  // if we get any valid guesses, make that guess as it's as good as any other.
  for (auto &i : perms) {
    // boolean vector of whether or not this perm can form a given product
    vector<bool> isProduct(maxprod);
    // build a list of all possible products from combinations of this set
    int s = i.size();
    int mask = 1 << s;
    while (mask--) {
      //cout << "MASK " << mask << endl;
      int prod = 1;
      for (int d = 0; d < s; d++) {
        if (mask & (1 << d)) {
          prod = prod * i[d];
        }
      }
      isProduct[prod] = 1;
    }

    bool success = true;
    for (auto &p : products) {
      if (!isProduct[p]) {
        success = false;
        break;
      }
    }

    if (success) {
      // this permutation works!
      for (auto &v : i) {
        cout << v;
      }
      cout << endl;
      return;
    }
  }
  cout << "Found no result mate!" << endl;
}

int main (int argc, char *argv[]) {
  int tests;

  cin >> tests;

  for (int t = 1; t <= tests; t++) {
    int R, N, M, K;
    cin >> R >> N >> M >> K;

    // we will receive R sets of K products
    // for each set, maryam picked N numbers between 2 and M
    cout << "Case #1:" << endl;

    // generate a vector of all possible permutations
    long card = 1, nums = M - 1;
    for (int d = 0; d < N; d++) {
      card = card * nums;
    }
    //cout << "CARD = " << card << endl;
    vector< vector<int> > perms(card);
    for (int i = 0; i < card; i++) {
    //  cout << "IN " << i << endl;
      int rem = i;
      for (int j = 0; j < N; j++) {
     //   cout << "  pushing " << j << endl;
        int d = rem % (nums);
        //cout << "REMAINDER = " << d << endl;
        perms[i].push_back(d+2);
        rem = rem / (nums);
      }
      //cout << "NEXT SEQUENCE" << endl;
    }

    for (int set = 0; set < R; set++) {
    //  cout << "SET " << set << endl;
      vector<int> products;
      for (int j = 0; j < K; j++) {
        int num;
        cin >> num;
        products.push_back(num);
      }
      int maxprod = 1;
      for (int b = nums; b; b--) {
        maxprod = maxprod * M;
      }
      bestGuess(products, perms, maxprod);
    }
  }
}
