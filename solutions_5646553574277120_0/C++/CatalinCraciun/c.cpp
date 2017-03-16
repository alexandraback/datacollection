#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstring>
#include <iomanip>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <bitset>
#include <ctime>

#define NMax 100005

#define pb push_back
#define po pop_back

#define mp make_pair

using namespace std;

ifstream f("input");
ofstream g("output");

// Global properties
int c,d,v;
vector<int> coins;
vector<int> toAdd;
int values[50];
bitset<50> used[10];
int canBeFilled[50][50];
int freq[50];
int answer = 0;

// Functions
bool goodToAdd(int x) {
      for (unsigned i=0;i<coins.size();i++)
            if (coins[i] == x)
                  return false;

      return true;
}

void solveSmall() {
      for (unsigned i=0;i<coins.size();i++) {
            values[coins[i]] = 1;
            used[coins[i]][i] = 1;
      }

      // Preprocess
      for (unsigned i=1;i<=v;i++) {
            if (values[i] == 1) {
                  for (unsigned j=0;j<coins.size();j++) {
                        if (values[i + coins[j]] == 0 && !used[i][j]) {
                              values[i + coins[j]] = 1;
                              for (unsigned k=0;k<=d;k++)
                                    used[i+coins[j]][k] = used[i][k];
                              used[i+coins[j]][j] = 1;
                        }
                  }
            }
      }

      // Filling empty values
      for (int i=1;i<=v;i++) {
            if (values[i] == 0) {
                  for (int j=1;j<v;j++) {
                        if (values[j] == 1 && goodToAdd(i-j)) {
                              freq[i-j]++;
                              canBeFilled[i][i-j] = 1;
                        }
                  }
            }
      }

      while (1) {
            int maximum = 0, poz = -1;
            for (int i=0;i<=v;i++) {
                  if (freq[i] > maximum) {
                        maximum = freq[i];
                        poz = i;
                  }
            }

            if (maximum == 0)
                  break;
            freq[poz] = 0;
            answer++;
            for (int i=0;i<50;i++)
                  if (canBeFilled[i][poz]) {
                        for (int j=0;j<50;j++) {
                              canBeFilled[i][j] = 0;
                              freq[j]--;
                        }
                  }
      }

      g<<answer;
}

void read() {
      f>>c>>d>>v;
      answer = 0;
      coins.resize(0);
      toAdd.resize(0);
      for (int i=0;i<50;i++)
            for (int j=0;j<50;j++)
                  canBeFilled[i][j] = 0;
      for (int i=0;i<50;i++)
            freq[i] = 0;
      for (int i=1;i<=d;i++) {
            int x; f>>x;
            coins.pb(x);
      }

      if (c == 1) {
            // Solving small
            for (int i=0;i<=v;i++)
                  values[i] = 0;
            for (int i=0;i<=v;i++)
                  for (int j=0;j<=d;j++)
                        used[i][j] = 0;
            solveSmall();
      } else {
            // Something more inteligent
      }
}

int main() {

      // Main code
      float oldTime = clock();

      int t; f>>t;
      for (int i=1;i<=t;i++) {
            g<<"Case #"<<i<<": ";
            read();
            g<<'\n';
      }

      cout<<"\nExecution took "<<fixed<<setprecision(5)<<(clock()-oldTime)/CLOCKS_PER_SEC<<"\n\n";


      f.close(); g.close();
      return 0;
}
