#include <iostream>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

int index(int N, int i, int j) {
  return i * N + j;
}

int index(int N, int i, int j, int k) {
  return i * N * N + j * N + k;
}

typedef pair<double, double> Interval;

double find_start(int s1, int p1, int s2, int p2) {
  if(s1 == s2)
	return -1;
  if(s1 < s2)
	return find_start(s2, p2, s1, p1);

  double front1_back2 = static_cast<double>(p2 - p1 - 5) / static_cast<double>(s1 - s2);
  return front1_back2;
}

double find_end(int s1, int p1, int s2, int p2) {
  if(s1 == s2)
	return -1;
  if(s1 < s2)
	return find_end(s2, p2, s1, p1);

  double front2_back1 = static_cast<double>(p2 - p1 + 5) / static_cast<double>(s1 - s2);
  return front2_back1;
}

struct Collision {
  float time;
  int i, j;
};

bool operator < (const Collision& a, const Collision& b) {
  return a.time < b.time;
}

double search(vector<int>& lanes, const vector<Interval>& intervals, const vector<Collision>& collisions, int cIdx) {
  if(collisions.size() <= cIdx)
	return -1;

  const int N = lanes.size();
  const Collision& c = collisions[cIdx];

  bool canSwitchI = true;
  for(int i=0;i<N;i++) {
	if(lanes[i] == lanes[c.i])
	  continue;
	const Interval& interval = intervals[index(N, i, c.i)];
	if(interval.first <= c.time && c.time <= interval.second && i != c.j) {
	  canSwitchI = false;
	  break;
	}
	if(interval.first == interval.second && interval.second == 0) {
	  canSwitchI = false;
	  break;
	}
  }

  bool canSwitchJ = true;
  for(int i=0;i<N;i++) {
	if(lanes[i] == lanes[c.j])
	  continue;
	const Interval& interval = intervals[index(N, i, c.j)];
	if(interval.first <= c.time && c.time <= interval.second && i != c.i) {
	  canSwitchJ = false;
	  break;
	}
	if(interval.first == interval.second && interval.second == 0) {
	  canSwitchJ = false;
	  break;
	}
  }

  //  //  cout << "Collision " << cIdx << " at time " << c.time << " between " << c.i << " and " << c.j << ": " << canSwitchI << " | " << canSwitchJ << "\n";
  //  for(int i=0;i<lanes.size();i++)
  //	cout << "  " << lanes[i] << "\n";

  if(!canSwitchI && !canSwitchJ) {
	if(lanes[c.i] == lanes[c.j])
	  return c.time;
	else
	  return search(lanes, intervals, collisions, cIdx+1);
  }

  if(canSwitchI && !canSwitchJ) {
	if(lanes[c.i] == lanes[c.j]) {
	  lanes[c.i] = !lanes[c.i];
	  const double t = search(lanes, intervals, collisions, cIdx+1);
	  lanes[c.i] = !lanes[c.i];
	  return t;
	} else {
	  return search(lanes, intervals, collisions, cIdx+1);
	}
  }

  if(!canSwitchI && canSwitchJ) {
	if(lanes[c.i] == lanes[c.j]) {
	  lanes[c.j] = !lanes[c.j];
	  const double t = search(lanes, intervals, collisions, cIdx+1);
	  lanes[c.j] = !lanes[c.j];
	  return t;
	} else {
	  return search(lanes, intervals, collisions, cIdx+1);
	}
  }

  if(canSwitchI && canSwitchJ) {
	const int lI = lanes[c.i];
	const int lJ = lanes[c.j];
	lanes[c.i] = 0;
	lanes[c.j] = 1;
	const double t1 = search(lanes, intervals, collisions, cIdx+1);
	lanes[c.i] = 1;
	lanes[c.j] = 0;
	const double t2 = search(lanes, intervals, collisions, cIdx+1);
	lanes[c.i] = lI;
	lanes[c.j] = lJ;
	return max(t1, t2);
  }

  assert(false);
  return 0;
}

double search(vector<int>& lanes, const vector<Interval>& intervals, const vector<Collision>& collisions) {
  return search(lanes, intervals, collisions, 0);
}

int main()
{
  int T;
  cin >> T;
  for(int C=1;C<=T;C++) {
	int N;
	cin >> N;
	vector<int> L;
	vector<int> S, P;
	for(int i=0;i<N;i++) {
	  char l;
	  cin >> l;
	  if(l == 'L')
		L.push_back(0);
	  else if(l == 'R')
		L.push_back(1);
	  else
		assert(false);
	  int s, p;
	  cin >> s >> p;
	  S.push_back(s);
	  P.push_back(p);
	}

	vector<Collision> collisions;
	vector<Interval> intervals(N*N, Interval(-1, -1));

	for(int i=0;i<N;i++) {
	  for(int j=0;j<i;j++) {
		Collision c;
		c.i = i;
		c.j = j;
		c.time = find_start(S[i], P[i], S[j], P[j]);
		if(c.time >= 0)
		  collisions.push_back(c);

		double start = c.time;
		double end = find_end(S[i], P[i], S[j], P[j]);
		if(start == end) {
		  start = end = -1;
		  if(abs(P[i] - P[j]) < 10)
			start = end = 0;
		}
		intervals[index(N, i, j)] = Interval(start, end);
		intervals[index(N, j, i)] = Interval(start, end);
		//		cout << i << " x " << j << ": " << start << " --> " << end << "\n";
	  }
	}

	sort(collisions.begin(), collisions.end());
	//	for(int i=0;i<collisions.size();i++)
	//	  printf("%.6f: %d x %d\n", collisions[i].time, collisions[i].i, collisions[i].j);

	double best = search(L, intervals, collisions);

	cout << "Case #" << C << ": ";
	if(best >= 0)
	  cout << best;
	else
	  cout << "Possible";
	cout << "\n";
  }
  return 0;
}
