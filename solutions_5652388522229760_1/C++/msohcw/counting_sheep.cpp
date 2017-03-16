#include <stdio.h>
#include <cstring>

using namespace std;

int t;
int sieve[1000010];
int nmax = 0;

int terminate(int x){
    int ct = 0;
    int mem[10];
    memset(mem, 0, sizeof(mem));
    for(int i = 1; i < 100; i++){
      int n = i*x;
      while(n > 0 && ct < 10){
        if(mem[n%10] == 0){ 
            mem[n%10] = 1;
            ct++;
        }
        n/=10;
      }
      if(ct == 10) return i*x; 
    }
}

int main(){
    scanf("%d", &t);
    for(int k = 1; k <= t; k++){
        printf("Case #%d: ", k);
        
        int n;
        scanf("%d", &n);
        if(n == 0){
            printf("INSOMNIA\n");
        }else{
            printf("%d\n", terminate(n));
        }
    }
}
