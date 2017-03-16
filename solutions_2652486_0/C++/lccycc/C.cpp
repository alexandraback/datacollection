#include <set>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int main() {
	freopen("C.in","r", stdin);
	freopen("C.out","w", stdout);
	int T;
	int N, M, R, K;
	cin>>T>>R>>N>>M>>K;
	int k[K];

	cout<<"Case #1:"<<endl;
  int a,b,c;
  while (R--){
	  for (int i = 0; i<K; i++){
	  	  		cin>>k[i];
	  	  }
	  int score = -1, besta, bestb, bestc;
	  for (a = 2; a<=5; a++){
		  for (b = 2; b<=5; b++){
			  for (c = 2; c<=5; c++){
				   int s[8];
				   s[0] = a;
				   s[1] = b;
				   s[2] = c;
				   s[3] = a*b;
				   s[4] = a*c;
				   s[5] = b*c;
				   s[6] = a*b*c;
				   s[7] = 1;
				   int as = 0;
				   for (int i = 0; i<K; i++){
					   bool fd = 0;
					   for (int j = 0; j<8; j++){
						   if (k[i] == s[j]){
							   as ++;
							   fd = true;
						   }
					   }
					   if (!fd){
						   as = -1;
						   break;
					   }
				   }
				  // cout<<as<<endl;
				   if (as > score){
					   besta = a;
					   bestb = b;
					   bestc = c;
					   score = as;
				   }

			  }
		  }
	  }
	  cout<<besta<<bestb<<bestc<<endl;
  }
  return 0;

}
