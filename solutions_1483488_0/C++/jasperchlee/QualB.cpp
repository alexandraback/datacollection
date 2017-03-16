#include<cstdio>
using namespace std;

long long choose2(long count){
   if(count == 1) return 0;
   long long c = count;
   long long d = c * (c-1);
   return d/((long long) 2);
}

long rotate(long digt, long num, long val){
   long val2 = val;
   long tens = 1;
   for(long c = 0; c < num; c++){
      val2 = val2/10;
      tens *= 10;
   }
   long val3 = val%tens;
   for(long c = 0; c < digt-num; c++){
      val3 *= 10;
   }
   return val3+val2;
}

long digits(long d){
   long result = 1, temp = 10;
   while(d/temp != 0){
      result++;
      temp*= 10;
   }
   return result;
}

int main(){
   long long result = 0;
   long n, a, b;

   scanf("%ld", &n); 
   for(long c = 0; c < n; c++){
      scanf("%ld %ld", &a, &b);
      bool visited[2000010];
      for(long d = 0; d < 2000010; d++){
         visited[d] = false;
      }
      for(long d = a; d <= b; d++){
         if(!visited[d]){
	    visited[d] = true;
	    long digt = digits(d);
	    long count = 1;
	    for(long e = 1; e < digt; e++){
	       long temp = rotate(digt, e, d);
	       if(a <= temp && temp <= b && !visited[temp]){
	          count++;
		  visited[temp] = true;
	       }
	    }
	    result += choose2(count);
	 }
      }
      printf("Case #%ld: %lld\n", c+1, result);
      result = 0;
   }
   return 0;
}
