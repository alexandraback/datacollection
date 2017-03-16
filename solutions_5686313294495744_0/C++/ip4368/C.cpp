#include <bits/stdc++.h>

using namespace std;

#define MAX 1013
#define WORD_LEN 23

typedef char word[WORD_LEN];
typedef word row[2];
row rows[MAX];

unordered_map<string, int> tally[2];

int main(int argc, char const *argv[]) {
  int n;
  scanf("%d\n", &n);
  for(int i=0;i<n;i++){
    int d;
    scanf("%d\n", &d);
    for(int j=0;j<d;j++){
      scanf("%s %s\n", rows[j][0], rows[j][1]);
      if(tally[0].find(string(rows[j][0]))==tally[0].end()){
        tally[0][string(rows[j][0])]=1;
      }else{
        tally[0][string(rows[j][0])]++;
      }
      if(tally[1].find(string(rows[j][1]))==tally[1].end()){
        tally[1][string(rows[j][1])]=1;
      }else{
        tally[1][string(rows[j][1])]++;
      }
    }
    int count = 0;
    for(int j=0;j<d;j++){
      if(tally[0][string(rows[j][0])]-1 && tally[1][string(rows[j][1])]-1){
        count++;
      }
    }
    printf("Case #%d: %d\n", i+1, count);
    tally[0].clear(); tally[1].clear();
  }
  return 0;
}
