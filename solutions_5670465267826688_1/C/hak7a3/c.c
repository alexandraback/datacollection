#include <stdio.h>
#include <stdlib.h>

#define MAX_L 10000

typedef struct {int sign; int value;} qual;
#define ONE 0
#define I 1
#define J 2
#define K 3

int mul_sign[4][4] ={{1,1,1,1},{1,-1,1,-1},{1,-1,-1,1},{1,1,-1,-1}};
int mul_val[4][4] = {{ONE, I, J, K},{I, ONE, K, J},{J, K, ONE, I},{K, J, I, ONE}};


qual mul(qual a, qual b)
{
  qual ret;
  ret.sign = a.sign * b.sign * mul_sign[a.value][b.value];
  ret.value = mul_val[a.value][b.value];
  return ret;
}

qual char2qual(char c)
{
  switch(c) {
  case 'i':
    return (qual){1, I};
  case 'j':
    return (qual){1, J};
  case 'k':
    return (qual){1, K};
  }
  exit(-1); /* never comes */
}


void calc(int L, int64_t X, char *s)
{
  qual left_mul[MAX_L];
  qual right_mul[MAX_L];
  /* init */
  qual tmp = {1, ONE};
  int i;
  for(i=0; i<L; i++) {
    tmp = mul(tmp, char2qual(s[i]));
    left_mul[i] = tmp;
  }
  tmp = (qual){1, ONE};
  for(i=L-1; i>=0; i--) {
    tmp = mul(char2qual(s[i]), tmp);
    right_mul[i] = tmp;
  }
  /* cut one -- final reduction is not -1 */
  qual check_final_reduction = {1, ONE};
  for(i=0; i< (X % 4); i++) {
    check_final_reduction = mul(check_final_reduction, right_mul[0]);
  }
  
  if(check_final_reduction.sign != -1 || check_final_reduction.value != ONE) {
    printf("NO");
    return;
  }
  int j, k, l;
  qual tmp_mulk, tmp_mull;
  for(i=0; i<L; i++) {
    for(j=L-1; j>=0; j--) {
      for(k=0, tmp_mulk = (qual){1, ONE};
          k<=3;
          k++, tmp_mulk = mul(right_mul[0], tmp_mulk)) {
        for(l=0, tmp_mull = (qual){1, ONE};
            l<=3;
            l++, tmp_mull = mul(tmp_mull, right_mul[0])) {
          int tmp_consumed = ((j - i) <= 1)? 1 : 0;
          qual tmp_leftmul = mul(tmp_mulk, left_mul[i]);
          qual tmp_rightmul = mul(right_mul[j], tmp_mull);

          /* for debug */
          /* printf("\n"); */
          /* printf("i=%d, j=%d, k=%d, l=%d\n", i,j,k,l); */
          /* printf("left = (%d, %d)\n", tmp_leftmul.sign, tmp_leftmul.value); */
          /* printf("right = (%d, %d)\n", tmp_rightmul.sign, tmp_rightmul.value); */
          
          if(k+l <= X - 1 - tmp_consumed && 
             tmp_leftmul.sign == 1 && tmp_leftmul.value == I &&
             tmp_rightmul.sign == 1 && tmp_rightmul.value == K) {
            printf("YES");
            return;
          }
        }
      }
    }
  }
  printf("NO");
  return;
}


int main()
{
  int T;
  scanf("%d", &T);

  int i;
  for (i = 0; i < T; i++) {
    printf("Case #%d: ", i + 1);
    int64_t X;
    int L;
    scanf("%d %ld", &L, &X);
    char input[MAX_L + 1];
    scanf("%s", input);
    calc(L, X, input);
    
    printf("\n");
  }

  
  return 0;
}

