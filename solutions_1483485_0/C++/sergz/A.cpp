#include <iostream>
#include <stdio.h>

using namespace std;

void
learn(const char* f, const char* t, char* m) {
  while((*f) != '\0') {
    if((*f) != ' ') {
      m[(*f)-'a'] = (*t);
    }
    f++;
    t++;
  }
}

int
main() {
  char map[26];
  const char* t0 = "yeq";
  const char* t1 = "our language is impossible to understand";
  const char* t2 = "there are twenty six factorial possibilities";
  const char* t3 = "so it is okay if you want to just give up";
  const char* f0 = "aoz";
  const char* f1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
  const char* f2 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
  const char* f3 = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
  
  for(int i = 0; i < sizeof(map)/sizeof(map[0]); i++) {
    map[i] = '-';
  }
  
  learn(f0, t0, map);
  learn(f1, t1, map);
  learn(f2, t2, map);
  learn(f3, t3, map);
  
  int n = 0;
  int idx = 0;
  int summ = 0;
  for(int i = 0; i < sizeof(map)/sizeof(map[0]); i++) {
    if(map[i] == '-') {
      idx = i;
      n++;
    } else {
      summ += map[i];
    }
  }

  if(n == 1) {
    map[idx] = 2847 - summ;
    
    int N;
    char c;
    cin >> N;
    cin.ignore(1000, '\n');
    
    for(int i = 0; i < N; i++) {
      char s[101];
      
      cin.getline(s, 101);
      
      cout << "Case #" << i+1 << ": ";
      for(int j = 0; s[j] != '\0'; j++) {
        if(s[j] != ' ') { 
          s[j] = map[s[j]-'a'];
        }
        cout << s[j];
        
        c++;
      }
      cout << endl;
    }    
  } 
  
  return 0;
}
