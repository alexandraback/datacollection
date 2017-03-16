#include<iostream>
#include<string>
#include<cstdio>

using namespace std;

int multi[]= 
  {0,1,2,3,4,5,6,7,
   1,4,3,6,5,0,7,2,
   2,7,4,1,6,3,0,5,
   3,2,5,4,7,6,1,0,
   4,5,6,7,0,1,2,3,
   5,0,7,2,1,4,3,6,
   6,3,0,5,2,7,4,1,
   7,6,1,0,3,2,5,4};

int toInt(char a) {
  if (a=='i')
    return 1;
  if (a=='j')
    return 2;
  if (a=='k')
    return 3;
  return 0;
}

int mult(int a, int b) {
  return multi[8*a+b];
}
  

int main() {
  int T;
  cin>>T;
  for (int t=1;t<=T;t++) {
    long long L,X;
    string str;
    cin>>L>>X>>str;
    if (X > 16) {
      X = 16 + X%16;
    }
    int cur = 0;   
    int pos1 = 0;
    int pos2 = 0;
    int target = 1;
    while (pos1<X) {
      cur = mult(cur,toInt(str[pos2]));
      //      printf("%d %d %d %d\n", pos1, pos2, cur, target);
      pos2++;
      if (pos2>= L) {
	pos2 = 0;
	pos1++;
      }
      if (cur == target) {
	cur = 0;
	if (target < 3) {
	  target++;
	} else {
	  target = -1;
	}
      }
    }
    if (target != -1 || cur != 0) {
      printf("Case #%d: NO\n", t);
    } else {
      printf("Case #%d: YES\n", t);
    }
  }
}
