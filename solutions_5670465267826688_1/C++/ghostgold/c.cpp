#include<iostream>
#include<cstdio>
int mul(int x, int y){
  int sign;
  if(x *y < 0)
    sign = -1;
  else sign = 1;
  x = abs(x);
  y = abs(y);
  switch (x){
  case 1:
    return sign*y;

  case 2:
    switch(y){
    case 1:return sign*2;
    case 2:return sign*(-1);
    case 3:return sign*4;
    case 4: return sign*(-3);
    }
  case 3:
    switch(y){
    case 1: return sign *3;
    case 2: return sign *(-4);
    case 3: return sign *(-1);
    case 4: return sign*(2);
    }

  case 4:
    switch(y){
    case 1: return sign *4;
    case 2: return sign *3;
    case 3: return sign *(-2);
    case 4: return sign*(-1);
    }
  }
}
char s[20000];
int ss[20000];
void work()
{
  int l;
  long long x;
  scanf("%d%lld",&l,&x);
  scanf("%s",s);
  for(int i = 0; i < l; i++){
    if(s[i]=='i')ss[i] = 2;
    if(s[i]=='j')ss[i]=3;
    if(s[i]=='k')ss[i]=4;
  }
  int p = 0, round = 0;
  int thisr = 0;
  int cur = 1;
  while(round < x){
    cur = mul(cur, ss[p++]);
    // printf("%d",cur);
    if (p == l){
      p= 0;
      round++;
      thisr++;
    }
    if(cur ==2)
      break;
     if(thisr > 6){
      printf("NO\n");
      return;
      }

  }

  if (cur !=2){
    printf("NO\n");
    return;
  }
  cur = 1;
  thisr = 0;
  while(round < x){
    cur = mul(cur, ss[p++]);
    if (p == l){
      p= 0;
      round++;
      thisr++;
    }
    if(cur ==3)
      break;
    if(thisr > 6){
      printf("NO\n");
      return;
      }
  }
   if (cur !=3){
    printf("NO\n");
    return;
  }
    
  cur = 1;
  thisr = 0;
  while(round < x){
    cur = mul(cur, ss[p++]);
    if (p == l){
      p= 0;
      round++;
      thisr++;
    }
    if(cur ==4)
      break;
     if(thisr > 6){
      printf("NO\n");
      return;
      }
  }
   if (cur !=4){
    printf("NO\n");
    return;
  }
   // printf("%d\n",x);
   long long  totr = (x - round -1)/4;
   if(totr >=0) x -= totr*4;
     //printf("%d %d\n", round, x);
  cur = 1;
  while(round < x){
    cur = mul(cur, ss[p++]);
    if (p == l){
      p= 0;
      round++;
    }
  }
   if (cur !=1){
    printf("NO\n");
    return;
  }
   printf("YES\n");
}
int main()
{
  int T;
  scanf("%d",&T);
  for(int i =1; i <=T; i++){
    printf("Case #%d: ", i);
    work();
  }
}
