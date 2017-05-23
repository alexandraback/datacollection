#include<cstdio>

unsigned long long cache[]={
  0,
  1,
  4,
  9,
  121,
  484,
  10201,
  12321,
  14641,
  40804,
  44944,
  1002001,
  1234321,
  4008004,
  100020001,
  102030201,
  104060401,
  121242121,
  123454321,
  125686521,
  400080004,
  404090404,
  10000200001,
  10221412201,
  12102420121,
  12345654321,
  40000800004,
  1000002000001,
  1002003002001,
  1004006004001,
  1020304030201,
  1022325232201,
  1024348434201,
  1210024200121,
  1212225222121,
  1214428244121,
  1232346432321,
  1234567654321,
  4000008000004,
  4004009004004,
  100000020000001,
  100220141022001,
  102012040210201,
  102234363432201,
  121000242000121,
  121242363242121,
  123212464212321,
  123456787654321,
  400000080000004
};

int main(){
  int T;
  scanf("%d", &T);
  int l = sizeof(cache)/sizeof(unsigned long long);
  for(int j = 1; j <= T; j++){
    unsigned long long a, b;
    scanf("%llu %llu", &a, &b);
    int sum = 0;
    for(int i = 0; i < l; i++)
      if(cache[i] >= a && cache[i] <= b)
        sum++;
    printf("Case #%d: %d\n", j, sum);
  }
}