#include <iostream>
#include <algorithm>
using namespace std;

#define LIM 111
#define MOD
#define INF

typedef long long int ll;

int N;
int lines[LIM][LIM];
int orig[LIM][LIM];
int nums[LIM];
int elem;

bool rowFit(int ind, int l1) {
  int i;
  for(i = 0; i < N; i++) {
    if(orig[ind][i] == -1) return true;
    if(lines[l1][i] != orig[ind][i]) return false;
  }
  return true;
}

bool colFit(int ind, int l1) {
  int i;
  for(i = 0; i < N; i++) {
    if(orig[i][ind] == -1) return true;
    if(lines[l1][i] != orig[i][ind]) return false;
  }
  return true;
}

void fitRow(int ind, int l1) {
  for(int i = 0; i < N; i++) {
    orig[ind][i] = lines[l1][i];
  }
}

void fitCol(int ind, int l1) {
  for(int i = 0; i < N; i++) {
    orig[i][ind] = lines[l1][i];
  }
}

bool sorter(int l1, int l2) {
  return lines[l1][elem] < lines[l2][elem];
}

void printOrig() {
  int i, j;
  for(i = 0; i < N; i++) {
    for(j = 0; j < N; j++) {
      cout << orig[i][j] << " ";
    }
    cout << endl;
  }

}

void printNums() {
  cout << "printing nums" << endl;
  int i;
  for(i = 0; i < (2 * N) - 1; i++) {
    cout << nums[i] << " ";
  }
  cout << endl;
}



bool arrange(int i) {
  elem = i;
  sort(nums, nums + (2 * N) - 1, sorter);
  //printNums();
  int j, l1, l2, a_ind, a_rc;
  for(j = 0; j < (2 * N) - 1; j++) {
    if(lines[nums[j]][N] == -1) break;
  }
  l1 = nums[j];
  if((j == ((2 * N) - 2)) || lines[nums[j + 1]][i] != lines[nums[j]][i]) { // missing
    //cout << "entered single" << endl;
    if(rowFit(i, l1)) {
      fitRow(i, l1);
      a_ind = i;
      a_rc = 2;
    }
    else {
      fitCol(i, l1);
      a_ind = i;
      a_rc = 1;
    }
    lines[l1][N] = 0;
  }
  else {
    l2 = nums[j + 1];
    if(rowFit(i, l1) && colFit(i, l2)) {
      fitRow(i, l1);
      fitCol(i, l2);
      lines[l1][N] = 0;
      lines[l2][N] = 0;
    }
    else {
      fitRow(i, l2);
      fitCol(i, l1);
      lines[l1][N] = 0;
      lines[l2][N] = 0;
    }
  }
}

void work(int index) {
  cin >> N;
  int i, j;
  for(i = 0; i < (2 * N) - 1; i++) {
    for(j = 0; j < N; j++) {
      cin >> lines[i][j];
    }
    lines[i][N] = -1;
    nums[i] = i;
  }

  for(i = 0; i < N; i++) {
    for(j = 0; j < N; j++) {
      orig[i][j] = -1;
    }
  }

  int a_ind, a_rc;
  int l1, l2;
  for(i = 0; i < N; i++) {
    //cout << "Before " << i << endl;
    //printOrig();
    elem = i;
    sort(nums, nums + (2 * N) - 1, sorter);
    //printNums();
    for(j = 0; j < (2 * N) - 1; j++) {
      if(lines[nums[j]][N] == -1) break;
    }
    l1 = nums[j];
    if((j == ((2 * N) - 2)) || lines[nums[j + 1]][i] != lines[nums[j]][i]) { // missing
      //cout << "entered single" << endl;
      if(rowFit(i, l1)) {
	fitRow(i, l1);
	a_ind = i;
	a_rc = 2;
      }
      else {
	fitCol(i, l1);
	a_ind = i;
	a_rc = 1;
      }
      lines[l1][N] = 0;
    }
    else {
      l2 = nums[j + 1];
      if(rowFit(i, l1) && colFit(i, l2)) {
	fitRow(i, l1);
	fitCol(i, l2);
	lines[l1][N] = 0;
	lines[l2][N] = 0;
      }
      else {
	fitRow(i, l2);
	fitCol(i, l1);
	lines[l1][N] = 0;
	lines[l2][N] = 0;
      }
    }

  }
  

  //printOrig();

  cout << "Case #" << index << ": ";
  for(i = 0; i < N; i++) {
    if(a_rc == 1) {
      cout << orig[a_ind][i] << " ";
    }
    else {
      cout << orig[i][a_ind] << " ";
    }
  }
  cout << endl;
}

int main() {
  int T;
  cin >> T;
  int i;
  for(i = 1; i <= T; i++) work(i);
  return 0;
}
