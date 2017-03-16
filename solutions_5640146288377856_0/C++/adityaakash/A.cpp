#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <list>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;

#define fore(i, l, r) for(int i = l; i < r; i++)
#define forn(i, n) fore(i, 0, n)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define INF 2000000000

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<pii> vpii;
typedef vector<ll> vll;

int main(){
  int t;
  scanf("%d", &t);
  fore(cs, 1, t + 1){
    int r, c, w;
    scanf("%d %d %d", &r, &c, &w);
    int count = 0;
    if (c % w == 0){
      count = c/w + w - 1;
    }
    else {
      count = c/w + w;
    }
    // vi arr;
    // arr.pb(c);
    // make_heap(arr.begin(), arr.end());
    // int last = c;
    // int count = 0;
    // while (1){
    //   int num = arr.front();
    //   pop_heap(arr.begin(), arr.end()); arr.pop_back();
    //   if (num < w){
    // 	break;
    //   }
    //   last = num;
    //   if (num & 1){
    // 	arr.push_back((num - 1) >> 1);
    // 	push_heap(arr.begin(), arr.end());
    // 	arr.push_back((num - 1) >> 1);	
    // 	push_heap(arr.begin(), arr.end());
    //   }
    //   else {
    // 	arr.push_back((num - 1) >> 1);
    // 	push_heap(arr.begin(), arr.end());
    // 	arr.push_back(num >> 1);
    // 	push_heap(arr.begin(), arr.end());
    //   }
    //   count++;
    // }
    
    // if (last == w) count += w - 1;
    // else count += w;
    
    printf("Case #%d: %d\n", cs, count);
  }
}
