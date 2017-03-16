/******************************************************************************
 * RECYCLED NUMBERS 
 * ***************************************************************************/
#include<iostream>
#include<stdio.h>
#include<bitset>
using namespace std;

void rotate_r(char src[]);
int get_exact_count(long int i, long int A, long int B);
int get_num_of_digits(long int A);
int get_max_digit(long int A);
int combination(int n, int r);

int num_of_digits;
static int fact[8] = {0};

/* Track the pairs */
bitset<2000000> mytrack_bits;

int main()
{
  int T;
  scanf("%d",&T);
  /*Factorial of a number */
  fact[0] = 1;
  for(int i=1;i<=7;i++) {
    fact[i] = i*fact[i-1];
  }
  int test_count = 1;
  while(T--) {
    printf("Case #%d: ", test_count++);
    long int A, B;
    scanf("%ld%ld",&A, &B);
    num_of_digits = get_num_of_digits(A);
    long int i;
    long int count =0;
    mytrack_bits.reset();
    for(i=A; i<= B; i++) {
      if(!mytrack_bits.test(i)) {
        count += get_exact_count(i, A, B);
      }
    } 
    printf("%ld\n", count);
  }
}

int get_max_digit(long int A)
{
  int max=0;
  long int quot;
  int rem;
  quot = A;
  do
  {
    A=quot;
    rem = A%10;
    if(rem > max) {
      max = rem;
    }
    quot = A/10;
  } while(quot !=0);
  return(max);
}

int get_num_of_digits(long int A)
{
  int count=0;
  long int quot;
  int rem;
  quot = A;
  do
  {
    A=quot;
    rem = A%10;
    quot = A/10;
    count++;
  } while(quot !=0);
  return(count);
}

int get_exact_count(long int i, long int A, long int B)
{
  int count = 0;
  long int temp = i;
  do
  {
    char str1[8] = {'\0'};
    char str2[5] = {'\0'};
    sprintf(str2, "%s", "%0");
    sprintf(&str2[2],"%dd", num_of_digits);
    str2[4] = '\0';
    /*Start rotating now */
    sprintf(str1,str2, temp);
    rotate_r(str1);
    temp = atol(str1);
    if((temp != i) && (temp >=A && temp <= B)) {
      mytrack_bits[temp] = 1;
      count++;
    }
  } while(temp != i);
  return(combination(count+1, 2));
}

void rotate_r(char src[])
{
  char last_char = '\0';
  int i;
  int last_index = 0;
  for(i=7; i >=0 ; i--) {
    if((src[i] != '\0') && (last_char == '\0')) {
      last_char = src[i];
      last_index = i;
    }
    src[i+1] = src[i];
  }
  src[0]= last_char;
  src[last_index+1] = '\0';
}

int combination(int n, int r)
{
  if(n<r) {
    return(0);
  } else {
    int x;
    x = fact[n]/(fact[n-r]*fact[r]);
    return(x);
  }
}
