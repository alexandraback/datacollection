#include <stdio.h>
#include <string.h>

int T;
long long int A,B,K, resp;
long long int pd[70][2][2][2];

long long int f(int dig, int eqa, int eqb, int eqk){
  if(dig < 0) return 1;
  if(pd[dig][eqa][eqb][eqk] >= 0) return pd[dig][eqa][eqb][eqk];
  
  long long int ret = 0;
  
  long long int pot = (1LL << dig);
  
  for(int diga=0; diga <=1; diga++){
    for(int digb = 0; digb<=1; digb++){
      int digk = diga & digb;
      if ((eqa && diga && !(pot&A)) ||
          (eqb && digb && !(pot&B)) ||
          (eqk && digk && !(pot&K)))
        continue;
                       
      bool temp_eqa = eqa && (diga == !(!(pot&A)));
      bool temp_eqb = eqb && (digb == !(!(pot&B)));
      bool temp_eqk = eqk && (digk == !(!(pot&K)));
 
      ret += f(dig-1, temp_eqa, temp_eqb, temp_eqk);
    }
  }
  
  pd[dig][eqa][eqb][eqk] = ret;
  return pd[dig][eqa][eqb][eqk];
}

int main(){
  scanf(" %d", &T);
  for(int u=1; u<=T; u++){
    scanf(" %lld %lld %lld", &A, &B, &K);
    A--;
    B--;
    K--;
    memset(pd, -1, sizeof(pd));
    resp = f(60,1,1,1);
    printf("Case #%d: %lld\n", u, resp);
  }
  return 0;
}
