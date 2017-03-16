#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <stdint.h>
#include <cassert>
using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)

const int64_t PRIME = 1000000007;
                     
int64_t factorial_prime(const int64_t n) {
  int64_t res = 1;

  for (int64_t i = 2; i <= n; ++i) {
    res *= i;
    res %= PRIME;
  }

  return res;
}

struct Car {
  Car(): bannedSet(), lastChar('\0'), s(""), combinations(1) {}

  bool tryAddString(const string &str) {
    s += str;

    for (const char c : str) {
      if (c != lastChar) {
	lastChar = c;
	if (!bannedSet.insert(c).second) {
	  return false;
	}
      }
    }

    return true;
  }

  bool tryAddCar(const Car &car) {
    if (!tryAddString(car.s)) {
      return false;
    }
    combinations *= car.combinations;
    combinations %= PRIME;

    return true;
  }

  set<char> bannedSet;
  char lastChar = '\0';
  string s;
  int64_t combinations;
};

bool isStringValid(const string &s) {
  char lastChar = '\0';
  set<char> bannedSet;

  for (const char c : s) {
    if (c != lastChar) {
      lastChar = c;
      if (!bannedSet.insert(c).second) {
	return false;
      }
    }
  }
  
  return true;
}


void solve2(int testcaseIndex) {
  int N;
  cin >> N;

  cout << "Case #" << 1 + testcaseIndex << ": ";

  vector<Car> cars;
  map<char, int> oneColCarMap;

  vector<string> vs;

  rep(i, N) {
    string s;
    cin >> s;
    vs.push_back(s);
  }

  vector<int> idxs;
  rep(i, N) {
    idxs.push_back(i);
  }

  int64_t res = 0;
  do {
    string str;
    
    for (const int i : idxs) {
      str += vs[i];
    }

    if (isStringValid(str)) {
      res += 1;
    }

  } while ( next_permutation(idxs.begin(), idxs.end()) );

  cout << res % PRIME << endl;
}


void solve(int testcaseIndex) {
  int N;
  cin >> N;

  cout << "Case #" << 1 + testcaseIndex << ": ";

  vector<Car> cars;
  map<char, int> oneColCarMap;

  rep(i, N) {
    string s;
    cin >> s;

    Car car;
    if (!car.tryAddString(s)) {
      cout << "0" << endl;
      return;
    }

    if (car.bannedSet.size() == 1) {
      oneColCarMap[car.s.front()] += 1;
    }
    else {
      cars.push_back(car);
    }
  }

  for (const pair<char, int> p : oneColCarMap) {
    Car car;
    car.tryAddString( string(1, p.first) );
    car.combinations = factorial_prime(p.second);
    cars.push_back(car);
  }

  map<char, Car*> carStartMap;

  rep(i, cars.size()) {
    if ( !carStartMap.insert( make_pair(cars[i].s.front(), &cars[i]) ).second ) {
      //      cout << "not unique start!" << endl;
      //cout << "0" << endl;
      //return;
    }
  }

  for (auto it = carStartMap.begin(); it != carStartMap.end(); ) {
    Car &currentCar = *it->second;

    while (true) {
      auto jt = carStartMap.find(currentCar.s.back());
      if (it != jt && jt != carStartMap.end()) {
	const Car &car = *jt->second;
	carStartMap.erase(jt);
	
	if (!currentCar.tryAddCar(car)) {
	  cout << 0 << endl;
	  return;
	}
      }
      else {
	++it;
	break;
      }
    }
  }  

  assert( !carStartMap.empty() );

  auto it = carStartMap.begin(); 
  Car &car = *it->second;
  ++it;

  for (; it != carStartMap.end(); ++it) {
    if (!car.tryAddCar( *it->second  )) {
      cout << 0 << endl;
      return;
    }
  }

  int64_t res = car.combinations;
  res *= factorial_prime(carStartMap.size());  
  res %= PRIME;

  cout << res << endl;
}

int main() {
  int n;
  cin >> n;

  rep(i, n) {
    solve(i);
  }

  return 0;
}
