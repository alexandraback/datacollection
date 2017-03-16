#include<cstdio>
#include<iostream>
#include<string>
#include<climits>
using namespace std;
int firstOcc[26];
int main()
{
  int T, test, i, j, value, firstBigger, firstSmaller;
  string str, ans;
  cin >> T;
  for (test=1; test<=T; test++) {
    cin >> str;
    for (i=0;i<26;i++) {
      firstOcc[i] = -1;
    }
    ans = str[0];
    value = (int)str[0]-(int)'A';
    firstOcc[value] = 0;
    for (i=1; i<str.length(); i++) {
      value = (int)str[i] - (int)'A';
      firstBigger = firstSmaller = INT_MAX;
      for (j = value+1; j<26; j++) {
	if (firstOcc[j] >= 0 && firstOcc[j] < firstBigger) {
	  firstBigger = firstOcc[j];
	}
      }
      for (j=0; j<value; j++) {
	if (firstOcc[j] >= 0 && firstOcc[j] < firstSmaller) {
	  firstSmaller = firstOcc[j];
	}
      }
      //cout << firstBigger << " " << firstSmaller << endl;
      if (firstBigger <= firstSmaller) {
	ans = ans+str[i];
	if (firstOcc[value]==-1) {
	  firstOcc[value] = i;
	}
      } else {
	ans = str[i]+ans;
	firstOcc[value] = 0;
	for (j=0; j<26; j++) {
	  if (j!=value && firstOcc[j]>=0)firstOcc[j]++;
	}
      }
    }
    cout << "Case #" << test << ": " << ans << endl;
  }
  return 0;
}
