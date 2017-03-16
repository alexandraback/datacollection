#include<cstdio>
using namespace std;

long min(long a, long b){
   return (a < b)?a:b;
}

int main(){
   long t;

   scanf("%ld", &t);
   for(long c = 0; c < t; c++){
      long n, s, p;
      long result = 0, pending = 0;
      scanf("%ld %ld %ld", &n, &s, &p);
      for(long d = 0; d < n; d++){
         long score;
	 scanf("%ld", &score);
	 if(score > 3*(p-1)){ result++; }
	 else if(score >= 3*(p-2)+2 && p >= 2){ pending++; }
      }
      printf("Case #%ld: %ld\n", c+1, result+min(s, pending));
   }
   return 0;
}
