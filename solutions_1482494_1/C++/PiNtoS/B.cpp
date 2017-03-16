#include <iostream>
#include <vector>
#include <string>
using namespace std;

int go(int stars, const vector<int>& req1, const vector<int>& req2, vector<int>& done) {
  int N = req1.size();
  // try to beat 2-star levels
  for(int i=0;i<N;i++) {
	if(req2[i] <= stars && done[i] < 2) {
	  int prev = done[i];
	  done[i] = 2;
	  return 2 - prev;
	}
  }
  
  // try to beat 1-star levels, ordered from the top
  int best = -1;
  for(int i=0;i<N;i++) {
	if(req1[i] <= stars && done[i] < 1) {
	  if(best == -1 || req2[i] > req2[best])
		best = i;
	}
  }
  if(best != -1) {
	int prev = done[best];
	done[best] = 1;
	return 1 - prev;
  }

  return 0;
}

int main()
{
  int T;
  cin >> T;
  for(int C=1;C<=T;C++) {
	int N;
	cin >> N;
	vector<int> req1;
	vector<int> req2;
	for(int i=0;i<N;i++) {
	  int s1, s2;
	  cin >> s1 >> s2;
	  req1.push_back(s1);
	  req2.push_back(s2);
	}

	int stars = 0;
	int count = 0;
	vector<int> done(N, 0);
	while(1) {
	  int earned = go(stars, req1, req2, done);
	  stars += earned;
	  if(earned == 0)
		break;
	  count++;
	}

	cout << "Case #" << C << ": ";
	if(stars == 2 * N)
	  cout << count;
	else
	  cout << "Too Bad";

	cout << "\n";
  }
  return 0;
}
