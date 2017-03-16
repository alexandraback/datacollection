#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
#include <map>

using namespace std;

vector<int> decompose(int n, int A)
{
  int l = log2(n);
  vector<int> v(A);
  
  for(int i = A-1; i >=0; --i) {
    v[i] = n%2;
    n >>= 1;
  }
 
  return v;
}

int test(vector<int> &v, vector<tuple<int,int,int>> &triplets, int J, int P, int S, int K) {
  map<pair<int,int>, int> m1, m2, m3;

  for(int j = 1; j <= J; ++j) {
    for(int p = 1; p <= P; ++p) {
      m1[make_pair(j,p)] = 0;
    }
  }

  for(int j = 1; j <= J; ++j) {
    for(int s = 1; s <= S; ++s) {
      m2[make_pair(j,s)] = 0;
    }
  }

  for(int s = 1; s <= S; ++s) {
    for(int p = 1; p <= P; ++p) {
      m3[make_pair(p, s)] = 0;
    }
  }

  int nb = 0;
  for(int i = 0; i < triplets.size(); ++i) {
    if(v[i]) {
      if(m1[make_pair(get<0>(triplets[i]), get<1>(triplets[i]))]++ == K) {
	return 0;
      }
      if(m2[make_pair(get<0>(triplets[i]), get<2>(triplets[i]))]++ == K) {
	return 0;
      }
	if(m3[make_pair(get<1>(triplets[i]), get<2>(triplets[i]))]++ == K) {
	return 0;
      }
      nb++;
    }
  }
  return nb;
}

int main()
{
  int T;
  cin >> T;

  for(int i = 1; i <= T; ++i) {
    int J, P, S, K;
    cin >> J >> P >> S >> K;
    
    vector<tuple<int,int,int>> triplets;

    for(int j = 1; j <= J; ++j) {
      for(int p = 1; p <= P; ++p) {
	for(int s = 1; s <= S; ++s) {
	  triplets.push_back(make_tuple(j,p,s));
	}
      }
    }

    int tot = pow(2, J*P*S);
    int m = 0, nb_max = 0;
    for(int j = 0; j < tot; j++) {

      vector<int> v = decompose(j, J*S*P);

      int nb = test(v, triplets, J, P, S, K);
      if(nb > nb_max)
	m = j, nb_max = nb;
    }

    cout << "Case #" << i << ": " << endl;
    vector<int> v = decompose(m, J*S*P);
    for(int j = 1; j < triplets.size(); ++j) {
      if(v[j]) {
	cout << get<0>(triplets[j]) << " " << get<1>(triplets[j]) << " " << get<2>(triplets[j]) << endl;
      }
    }
  }
}
