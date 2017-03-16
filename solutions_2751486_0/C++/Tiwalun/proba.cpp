#include<cstdio>
#include<iostream>

using namespace std;

bool isCon(char c) {
  if (c == 'a') return false;
  if (c == 'e') return false;
  if (c == 'i') return false;
  if (c == 'o') return false;
  if (c == 'u') return false;

  return true;
}

bool hasCons(string sub, int n) {
  int c = 0;

//cout << "Checking string " << sub << endl;

  for (int i = 0; i < sub.length(); i++) {
    if (isCon(sub[i])) c++;
    else c = 0;

    if (c >= n) return true;
  } 

  return false;
}

int solve(string name, int n) {
  int count = 0;

  for (int i = n; i <= name.length(); i++) {
    for (int j = 0; j+i <= name.length(); j++) {
      if (hasCons(name.substr(j,i), n)) count++;
    }
  } 
  return count;
}

int main() {
  int probs;
  scanf("%i", &probs);
  
  for (int p = 1; p <= probs; p++) {
    string name;
    int n;
    cin >> name >> n;

    printf("Case #%i: ",  p);
    printf("%i", solve(name, n));
    printf("\n");
  }
  return 0;
}
