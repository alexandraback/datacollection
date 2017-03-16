#include <iostream>
#include <vector>

using namespace::std;

bool consecutive_horizontal(vector<vector<int> > &m,
			    int x,
			    int num) {
  for (int i = 0; i < m[x].size(); i++) 
    if (m[x][i] != num) return false;  
  return true;
}

bool consecutive_vertical(vector<vector<int> > &m,
			  int y,
			  int num) {
  for (int i = 0; i < m.size(); i++) 
    if (m[i][y] != num) return false;
  return true;
}

void fill_horizontal(vector<vector<int> > &m,
		     int x,
		     int num) {
  for (int i = 0; i < m[x].size(); i++) 
    m[x][i] = num;
}

void fill_vertical(vector<vector<int> > &m,
		   int y, 
		   int num) {
  for (int i = 0; i < m.size(); i++) 
    m[i][y] = num;
}

bool flat(vector<vector<int> > &m) {
  int peek = m[0][0];

  for (int i = 0; i < m.size(); i++) {
    for (int j = 0; j < m[i].size(); j++) {
      if (m[i][j] != peek) return false;
    }
  }

  return true;
}

void printvect(vector<vector<int> > &m) {
  for (int i = 0; i < m.size(); i++) {
    for (int j = 0; j < m[i].size(); j++) {
      cout << m[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void solve(vector<vector<int> > &m) {
  for (int min = 1; min <= 100; min++) {
    vector<int> hor_candidates;
    vector<int> vert_candidates;

    for (int i = 0; i < m.size(); i++) 
      if (consecutive_horizontal(m, i, min))
	hor_candidates.push_back(i);

    for (int i = 0; i < m[0].size(); i++) 
      if (consecutive_vertical(m, i, min))
	vert_candidates.push_back(i);

    for (int i = 0; i < hor_candidates.size(); i++) 
      fill_horizontal(m, hor_candidates[i], min+1);
    
    for (int i = 0; i < vert_candidates.size(); i++) 
      fill_vertical(m, vert_candidates[i], min+1);
  }

  if (flat(m)) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}

int main(int argc, char *argv[]) {
  int n_cases = 0;
  cin >> n_cases;

  for (int i = 0; i < n_cases; i++) {
    int xdim, ydim;
    cin >> xdim >> ydim;

    vector<vector<int> > m;

    for (int j = 0; j < xdim; j++) {
      vector<int> row;
      for (int k = 0; k < ydim; k++) {
	int num;
	cin >> num;

	row.push_back(num);
      }
      m.push_back(row);
    }
    
    cout << "Case #" << i+1 << ": ";
    solve(m);
  }
}
