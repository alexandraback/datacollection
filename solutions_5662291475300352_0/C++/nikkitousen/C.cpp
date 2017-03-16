#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <set>

using namespace std;

#define FOR(i, A, B) for(int i=(A); i<(B); i++)
#define REP(i, N) for(int i=0; i<(N); i++)
#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(), (v).end()
#define SORT(v) sort(ALL(v))
#define CLEAR(v) memset((v), 0, sizeof(v))
#define MP make_pair
#define PB push_back
#define PII pair<int, int>
#define LL long long

int N;

int H;
int start[20], speed[20];


int main()
{
  int T;
  cin >> T;
  REP(caso, T) {
    cout << "Case #" << caso+1 << ": ";
   	cin >> N;
   	
   	H = 0;
   	REP(i, N) {
   		int d, h, m;
   		cin >> d >> h >> m;
   		REP(j, h) {
   			start[H] = d;
   			speed[H] = m;
   			m++;
   			H++;
   		}
   	}
   	
   	if(H == 1) {
   		cout << 0 << endl;
   		continue;
   	}
   	
   	int slow = 0;
   	if(speed[0] < speed[1]) slow = 1;
   	int fast = 1 - slow;
   	
   	if(speed[slow] == speed[fast]) {
   		cout << 0 << endl;
   		continue;
   	}
   	
   	double timeSlow = (360-start[slow]) * (double)speed[slow] / 360.0;	
   	double timeFast = (360-start[fast]) * (double)speed[fast] / 360.0;	
   	
   	if(timeSlow < timeFast) {
   		cout << 0 << endl;
   		continue;
   	}
   	
   	double timeFast2 = (720-start[fast]) * (double)speed[fast] / 360.0;	
   	if(timeFast2 > timeSlow) {
   		cout << 0 << endl;
   		continue;
   	}
   	
   	cout << 1 << endl;
   	
   	
  }
}

