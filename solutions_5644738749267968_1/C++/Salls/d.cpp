#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <bitset>
#include <iomanip>

using namespace std;

void solve() {
int N;
cin >> N;
vector<double> Ke(N);
vector<double> Na(N);
vector<double> Ke2;
vector<double> Na2;

for(int i = 0; i < N; i++) 
   cin >> Na[i];
for(int i = 0; i < N; i++) 
   cin >> Ke[i];

sort(Na.begin(),Na.end());
sort(Ke.begin(),Ke.end());

Ke2 = Ke;
Na2 = Na;


int scoreWar = 0, scoreDWar = 0;

// compute score D war
for(int i = 0; i < N; i ++) {
   if(Na[0] > Ke[0]) {
      Na.erase(Na.begin());
      Ke.erase(Ke.begin());
      scoreDWar++;
   }
   else {
      Na.erase(Na.begin());
      Ke.erase(Ke.begin()+Ke.size()-1);
   }
}

// Compute score war
int j = 0;
int i = 0;
int KenScore = 0;
while(j < N) {
   if(Na2[i] < Ke2[j]) {
      i++;
      j++;
      KenScore++;
      continue;
   }
   j++;
}
scoreWar = j-i;
if(scoreWar != N-KenScore){
   cout << "Error" << endl;
   exit(0);
}

cout << scoreDWar << " " << scoreWar;

}

int main() {

int t;
cin >> t;
for (int i = 0; i < t; i++) {
   cout << "Case #" << i+1 << ": "; 
   solve();
   cout << endl;
}


return 0;
}
