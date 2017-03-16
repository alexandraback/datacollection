#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> bff;
vector<int> component;
vector<int> cs;
vector<bool> special;
vector<int> dtc; //distance to cicle
vector<int> fc; // first member of the circle i see
int n;
int cc;


void mark() {
  vector<int> color(n,-2);
  vector<int> number(n,0);

  special.clear();
  dtc.clear();
  cs.clear();
  component.clear();
  fc.clear();


  special.resize(n);
  dtc.resize(n);
  cc = 0;
  for (int i = 0;i < n;i++) {
    if (color[i] == -2) {
      int id = i;
      int count = 0;
      vector<int> trail;
      while (color[id] == -2) {
        trail.push_back(id);
        color[id] = -1;
        number[id] = count++;
        id = bff[id];
      }
      if (color[id] != -1) {
        //found ealier component
        for (auto x : trail) {
          color[x] = color[id];
          dtc[x] = count - number[x] + dtc[id];
        }
      } else {
        //found new circle
        int circle_size = count - number[id];
        cs.push_back(circle_size);
        for (auto x : trail) {
          color[x] = cc;
          dtc[x] = count - number[x] - circle_size;
          if (dtc[x] < 0) dtc[x] = 0;
        }
        cc++;
      }
      if (bff[bff[id]] == id) {
        special[id] = true;
        special[bff[id]] = true;
      }

    }
  }
  component = color;
}

void debug() {
  printf("--- node ---\n");
  for (int i = 0;i < n;i++) {
    printf("id: %d\n",i);
    printf("  component: %d\n",component[i]);
    printf("  dtc: %d\n",dtc[i]);
    printf("  special: %s\n",(special[i] ? "YES" : "NO"));
  }
  printf("--- circle ---\n");
  for (int i = 0;i < cc;i++) {
    printf("circle %d: %d\n",i,cs[i]);
  }
}

int main() {
  int T;
  cin >> T;
  for (int t = 1;t <= T;t++) {
    cin >> n;
    bff.clear();
    bff.resize(n);
    for (int i = 0;i < n;i++) {
      cin >> bff[i];
      bff[i]--;
    }
    
    //find circle
    mark();
    //debug();

    int ans = 0;
    //check largest circle
    for (int i = 0;i < cc;i++) {
      if (cs[i] > ans) ans = cs[i];
    }

    //check bunch of size 2
    int two = 0;
    for (int i = 0;i < cc;i++) {
      if (cs[i] == 2) two += 2;
    }
    if (two > ans) ans = two;

    //check special
    int sum = 0;
    for (int k = 0;k < cc;k++) {
      int best = 0;
      for (int i = 0;i < n;i++) {
        if (component[i] != k) continue;
        int a = i; //circle member of a
        while (dtc[a] != 0) {
          a = bff[a];
        }
        for (int j = i+1;j < n;j++) {
          if (component[j] != k) continue;
          int b = j; //circle member of a
          while (dtc[b] != 0) {
            b = bff[b];
          }
          if (special[a] && special[b] && component[a] == component[b] && a != b) {
            if (dtc[i] + dtc[j] > best) {
              best = dtc[i] + dtc[j];
            }
          }
        }
      }
      sum += best;
    }
    if (sum + two > ans) ans = sum + two;


    printf("Case #%i: %d\n",t,ans);
  }
} 
