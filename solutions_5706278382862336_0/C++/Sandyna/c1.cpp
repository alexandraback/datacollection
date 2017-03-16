#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<cmath>
using namespace std;

int main(){
  long long t, a, b, c=1, i, j=0, gcd=0, citatel, menovatel, tymtonasobim=1;
  char nacitanie;
  cin >> t;
  for(i=0; i<t; i++){
    j=0;
    tymtonasobim=1;
    cin >> a >> nacitanie >> b;
    citatel=a;
    menovatel=b;
//     cout << a << " " << b << endl;
    while(b!=0){
      c=a%b;
      a=b;
      b=c;
    }
//     cout << a << endl;
//     cout << citatel/a << "/" << menovatel/a << endl;
    citatel=citatel/a;
    menovatel=menovatel/a;
//     cout << int(log2(menovatel)) << endl;
//     cout << pow(2, int(log2(menovatel))) << endl;
    if(pow(2, int(log2(menovatel))) == menovatel){
      tymtonasobim=1;
      while((citatel*tymtonasobim) < menovatel){
// 	cout << ": "<< citatel << " " << tymtonasobim << " " << menovatel << endl;
	tymtonasobim=tymtonasobim*2;
	j++;
      }
      cout << "Case #" << i+1 << ": " << j << endl;
    }
    else{
      cout << "Case #" << i+1 << ": impossible\n";
    }
  }
  return 0;
}