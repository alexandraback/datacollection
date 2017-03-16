#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;


int main() {_;
  int T;
  cin >> T;
  
  for (int t=1; t<=T; t++) {
    int ans[10];
    int cnt[256];
    string input;
    cin >> input;
    for (int i=0;i<10;i++) ans[i]=0;
    for (int i=0;i<256;i++) cnt[i]=0;
    for (unsigned int i=0; i<input.size(); i++) {
      cnt[(int)input[i]]++;
    }
    while (cnt['Z']>0) {
      cnt['Z']--;
      cnt['E']--;
      cnt['R']--;
      cnt['O']--;
      ans[0]++;
    }
    while (cnt['W']>0) {
      cnt['T']--;
      cnt['W']--;
      cnt['O']--;
      ans[2]++;
    }
    while (cnt['U']>0) {
      cnt['F']--;
      cnt['O']--;
      cnt['U']--;
      cnt['R']--;
      ans[4]++;
    }
    while (cnt['X']>0) {
      cnt['S']--;
      cnt['I']--;
      cnt['X']--;
      //      cnt['R']--;
      ans[6]++;
    }
    while (cnt['O']>0) {
      cnt['O']--;
      cnt['N']--;
      cnt['E']--;
      //      cnt['R']--;
      ans[1]++;
    }
    while (cnt['S']>0) {
      cnt['S']--;
      cnt['E']--;
      cnt['V']--;
      cnt['E']--;
      cnt['N']--;
      ans[7]++;
    }
    while (cnt['F']>0) {
      cnt['F']--;
      cnt['I']--;
      cnt['V']--;
      cnt['E']--;
      ans[5]++;
    }
    while (cnt['N']>0) {
      cnt['N']--;
      cnt['I']--;
      cnt['N']--;
      cnt['E']--;
      ans[9]++;
    }
    while (cnt['I']>0) {
      cnt['E']--;
      cnt['I']--;
      cnt['G']--;
      cnt['H']--;
      cnt['T']--;
      ans[8]++;
    }
    while (cnt['T']>0) {
      cnt['T']--;
      cnt['H']--;
      cnt['R']--;
      cnt['E']--;
      cnt['E']--;
      ans[3]++;
    }
    printf("Case #%d: ", t);
    for (int i=0; i<10; i++) {
      while(ans[i]>0) {
	printf("%d", i);
	ans[i]--;
      }
    }
    printf("\n");
  }
  return 0;
}
