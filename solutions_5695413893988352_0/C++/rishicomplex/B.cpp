#include <iostream>
#include <string>
using namespace std;

#define LIM
#define MOD
#define INF

typedef long long int ll;

#define CLESS 0
#define EQUAL 1
#define JLESS 2


string C, J;

struct double_string {
  string c_string;
  string j_string;
  int status;
};

double_string dp[3][25];

ll convertToLong(string s) {
  //cout << "convertToLong on " << s << endl;
  ll ret = stoll(s);
  return ret;
}

void printDoubleString(double_string ds) {
  cout << ds.c_string << " " << ds.j_string << endl;
}



ll getScore(double_string ds) {
  //cout << "getScore on ";
  //printDoubleString(ds);
  ll sc, sj;
  if(ds.c_string == "")
    sc = 0;
  else
    sc = convertToLong(ds.c_string);
  if(ds.j_string == "")
    sj = 0;
  else
    sj = convertToLong(ds.j_string);
  ll ret = abs(sc - sj);
  return ret;
}

int compareDS(double_string s1, double_string s2) {
  ll score1 = getScore(s1);
  ll score2 = getScore(s2);
  if(score1 < score2) return 1;
  if(score2 < score1) return 0;
  if(convertToLong(s1.c_string) < convertToLong(s2.c_string)) return 1;
  else if (convertToLong(s1.c_string) > convertToLong(s2.c_string)) return 0;
  if(convertToLong(s1.j_string) < convertToLong(s2.j_string)) return 1;
  return 0;
}

double_string getAns(int prev_state, int index) {
  //cout << "getAns called with prev_state=" << prev_state << ", index=" << index << endl;
  double_string nothing;
  nothing.c_string = "";
  nothing.j_string = "";
  nothing.status = 1;
  if(index == (int)C.length()) return nothing;
  if(dp[prev_state][index].status != 0) return dp[prev_state][index];

  char jchar = J[index];
  char cchar = C[index];
  ll cno, jno;
  double_string temp;
  double_string ans;
  if(prev_state == CLESS) {
    if(cchar == '?') cchar = '9';
    if(jchar == '?') jchar = '0';
    temp = getAns(CLESS, index + 1);
    ans.c_string = cchar + temp.c_string;
    ans.j_string = jchar + temp.j_string;
    ans.status = 1;

    return dp[prev_state][index] = ans;
    
  }

  if(prev_state == JLESS) {
    if(cchar == '?') cchar = '0';
    if(jchar == '?') jchar = '9';
    temp = getAns(prev_state, index + 1);
    ans.c_string = cchar + temp.c_string;
    ans.j_string = jchar + temp.j_string;
    ans.status = 1;

    return dp[prev_state][index] = ans;
    
  }
  
  if(jchar != '?' && cchar != '?') {
    cno = cchar - '0';
    jno = jchar - '0';
    if(cno < jno) {
      temp = getAns(CLESS, index + 1);
    }
    else if (cno == jno) {
      temp = getAns(EQUAL, index + 1);
      
    }
    else {
      temp = getAns(JLESS, index + 1);
    }
    ans.c_string = cchar + temp.c_string;
    ans.j_string = jchar + temp.j_string;
    ans.status = 1;

    return dp[prev_state][index] = ans;
    
  }

  char cchar_0, cchar_1, cchar_2;
  char jchar_0, jchar_1, jchar_2;
  int poss_0, poss_1, poss_2;

  if(cchar == '?' && jchar != '?') {
    if(jchar == '0') {
      poss_0 = 0;
    }
    else {
      cchar_0 = jchar - 1;
      poss_0 = 1;
    }
    jchar_0 = jchar;
    

    poss_1 = 1;
    cchar_1 = jchar;
    jchar_1 = jchar;

    if(jchar == '9') {
      poss_2 = 0;
    }
    else {
      poss_2 = 1;
      cchar_2 = jchar + 1;
    }
    jchar_2 = jchar;
    
    
  }
  if(jchar == '?' && cchar != '?') {
    if(cchar == '0') {
      poss_2 = 0;
    }
    else {
      jchar_2 = cchar - 1;
      poss_2 = 1;
    }
    cchar_2 = cchar;
    

    poss_1 = 1;
    cchar_1 = cchar;
    jchar_1 = cchar;

    if(cchar == '9') {
      poss_0 = 0;
    }
    else {
      poss_0 = 1;
      jchar_0 = cchar + 1;
    }
    cchar_0 = cchar;
    
    
  }
  if(cchar == '?' && jchar == '?') {
    poss_0 = 1;
    poss_1 = 1;
    poss_2 = 1;

    cchar_0 = '0';
    cchar_1 = '0';
    cchar_2 = '1';

    jchar_0 = '1';
    jchar_1 = '0';
    jchar_2 = '0';
    
  }

  double_string large;
  large.c_string = "0000000000000000000";
  large.j_string = "1000000000000000000";

  double_string s0 = large, s1 = large, s2 = large;
  if(poss_0 == 1) {
    temp = getAns(CLESS, index + 1);
    s0.c_string = cchar_0 + temp.c_string;
    s0.j_string = jchar_0 + temp.j_string;
  }
  if(poss_1 == 1) {
    temp = getAns(EQUAL, index + 1);
    s1.c_string = cchar_1 + temp.c_string;
    s1.j_string = jchar_1 + temp.j_string;
  }
  if(poss_2 == 1) {
    temp = getAns(JLESS, index + 1);
    s2.c_string = cchar_2 + temp.c_string;
    s2.j_string = jchar_2 + temp.j_string;
  }

  
  double_string correct = s2;
  if(compareDS(s1, s2) == 1) {
    
    correct = s1;
  }

  if(compareDS(s0, s1) == 1) {
    
    correct = s0;
  }
  ans = correct;
  ans.status = 1;
  
  return dp[prev_state][index] = ans;		 
  
}

void clearDP() {
  int i, j;
  for(i = 0; i < 3; i++) {
    for(j = 0; j < 25; j++) {
      dp[i][j].c_string = "";
      dp[i][j].j_string = "";
      dp[i][j].status = 0;
    }
  }
}

void work(int index) {
  cin >> C;
  cin >> J;

  clearDP();

  double_string ans = getAns(EQUAL, 0);

  cout << "Case #" << index << ": ";
  cout << ans.c_string << " " << ans.j_string;
  cout << endl;
}

int main() {
  int T;
  cin >> T;
  int i;
  for(i = 1; i <= T; i++) work(i);
  return 0;
}
