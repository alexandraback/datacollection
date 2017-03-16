// code jam c
int verbose = 0 ;

const int maxDigits=200;

#include <iostream>
#include <math.h>

using namespace std ;

// Because of the asymmetry of multiplication, there can be no carries - no digits higher than 3
// squares with no carries have an odd number of digits
// when multiplying the square, the middle digit will get the sum of all products twice, except only once for middle digit when odd number of digits to start
// Thus, the sum of all squares can be 9 at max:
// nine 1s - up to four 1s on each side, if digits are odd, can be 1 in the center
// one 2 and five 1s -- two has to be in center. thus can only be 0, 2, or 4 ones  1...2...1 or 1...1...2...1...1
// two 2s and one 1 -- two can't be in center, so must be 2...0...2 or 2...1...2 or 2......2
// one 3



int isPalindrome(char *decimal) {
  unsigned long N = strlen(decimal) ;
  int i;
  for (i = 0 ; i*2 < N-1 ; i++) {
    if (decimal[i] != decimal[N-i-1])
      return 0;
  }
  return 1 ;
}
int isPalindrome(unsigned long a) {
  char decimal[100];
  sprintf(decimal, "%ld",a);
  return isPalindrome(decimal);
}
void squareNoCarry(int N, int *digits, int *square) {
  int i,j;
  for (i = 0 ; i < N ; i++) {
    square[i] = 0 ;
    for (j = 0 ; j <= i ; j++)
      square[i] += digits[i-j]*digits[j] ;
  }
  for (i = N ; i < 2*N-1 ; i++) {
    square[i] = 0 ;
    for (j = i-N+1 ; j < N ; j++)
      square[i] += digits[i-j]*digits[j] ;
  }
 
}
void coutDigits(int N, int *digits) {
  int i;
  for (i = 0 ; i < N ; i++)
    cout << digits[i] ;
}
void digitsToChar(int N, int *digits, char *out) {
  int i;
  for (i = 0 ; i < N ; i++)
    out[i] = '0' + (char) digits[i] ;
  out[N] = 0 ;
}

int isInRange(char *min, char *max, char *v) {
  return (strcmp(v,min)>=0) && (strcmp(max,v)>=0);
}

int listFairAndSquare(int N, char *min, char *max) {
  if (N<1)
    return 0 ;
  if (N==1) {
    char one[] = "1";
    char four[] = "4";
    char nine[] = "9";
    return isInRange(min, max, one)+isInRange(min, max, four)+isInRange(min, max, nine);
  }
  int count = 0 ;
  int digits[N];
  int digits2[2*N-1];
  int i;
  for (i = 0 ; i < N ; i++) {
    digits[i] = 0 ;
  }
  for (i = 0 ; i < 2*N+1 ; i++) {
    digits2[i] = 0 ;
  }
  digits[0] = 1 ;
  digits[N-1] = 1 ;
  int numOnes = 1 ;
  char fairandsquare[200];

  int onesPosition[3]={0,0,0};
  while ((numOnes <= 4)&&(numOnes <=N/2)) {
    squareNoCarry(N, digits, digits2);
    digitsToChar(2*N-1, digits2, fairandsquare);
    count += isInRange(min,max,fairandsquare);
    if (verbose) {
      coutDigits(N,digits);
      cout << " " ;
      cout << fairandsquare << endl ;
    }
    
    // if odd digits
    if (N&1) {
      int mid = ++digits[N/2] ;
      if (mid*mid+numOnes*2<=9) {
        continue ;
      }
      digits[N/2]=0 ;
    }
    for (i = 1 ; i < N-1 ; i++) {
      digits[i] = 0 ;
    }
    if (numOnes == 1) {
      numOnes++;
      onesPosition[0] = 1 ;
      digits[onesPosition[0]]=1;
      digits[N-1-onesPosition[0]]=1;
      continue ;
    }
    if (numOnes==2) {
      onesPosition[0]++;
      if (onesPosition[0] >= N/2) {
        numOnes++ ;
        onesPosition[0] = 1 ;
        onesPosition[1] = 2 ;
        digits[onesPosition[1]]=1;
        digits[N-1-onesPosition[1]]=1;
      }
      digits[onesPosition[0]]=1;
      digits[N-1-onesPosition[0]]=1;
      continue ;
    }
    if (numOnes==3) {
      onesPosition[1]++;
      if (onesPosition[1] >= N/2) {
        onesPosition[0]++ ;
        if (onesPosition[0] >= N/2-1) {
          numOnes++ ;
          onesPosition[0] = 1 ;
          onesPosition[1] = 2 ;
          onesPosition[2] = 3 ;
          digits[onesPosition[0]]=1;
          digits[N-1-onesPosition[0]]=1;
          digits[onesPosition[1]]=1;
          digits[N-1-onesPosition[1]]=1;
          digits[onesPosition[2]]=1;
          digits[N-1-onesPosition[2]]=1;
          continue;
        }
        onesPosition[1] = onesPosition[0]+1 ;
      }
      digits[onesPosition[0]]=1;
      digits[N-1-onesPosition[0]]=1;
      digits[onesPosition[1]]=1;
      digits[N-1-onesPosition[1]]=1;
      continue ;
    }
    if (numOnes==4) {
      onesPosition[2]++;
      if (onesPosition[2] >= N/2) {
        onesPosition[1]++ ;
        if (onesPosition[1] >= N/2-1) {
          onesPosition[0]++ ;
          if (onesPosition[0] >= N/2-2)
            break ;
          onesPosition[1] = onesPosition[0]+1 ;
          onesPosition[2] = onesPosition[1]+1 ;
          digits[onesPosition[0]]=1;
          digits[N-1-onesPosition[0]]=1;
          digits[onesPosition[1]]=1;
          digits[N-1-onesPosition[1]]=1;
          digits[onesPosition[2]]=1;
          digits[N-1-onesPosition[2]]=1;
          continue;
        }
        onesPosition[2] = onesPosition[1]+1 ;
      }
      digits[onesPosition[0]]=1;
      digits[N-1-onesPosition[0]]=1;
      digits[onesPosition[1]]=1;
      digits[N-1-onesPosition[1]]=1;
      digits[onesPosition[2]]=1;
      digits[N-1-onesPosition[2]]=1;
      continue ;
    }
  }
  digits[0] = 2 ;
  digits[N-1] = 2 ;
  for (i = 1 ; i < N-1 ; i++) {
    digits[i] = 0 ;
  }
  squareNoCarry(N, digits, digits2);
  digitsToChar(2*N-1, digits2, fairandsquare);
  count += isInRange(min,max,fairandsquare);
  if (verbose) {
    coutDigits(N,digits);
    cout << " " ;
    cout << fairandsquare << endl ;
  }
  if (N&1) {
    digits[N/2] = 1 ;
    squareNoCarry(N, digits, digits2);
    digitsToChar(2*N-1, digits2, fairandsquare);
    count += isInRange(min,max,fairandsquare);
    if (verbose) {
      coutDigits(N,digits);
      cout << " " ;
      cout << fairandsquare << endl ;
    }
  }
  return count ;
}


int runTest() {
  char A[101] ;
  char B[101] ;
  cin >> A ;
  cin >> B ;
  if (verbose)
    cout << "// A=" << A << " B=" << B << endl ;
  int i;
  int minDigits = (strlen(A)+2)/2 ;
  int maxDigits = (strlen(B)+1)/2 ;
  int count=0 ;
  for (i = minDigits; i <= maxDigits ; i++) {
    char minChar[2] = "0" ;
    char maxChar[2] = ":" ;

    char *minc = minChar ;
    char *maxc = maxChar ;
    if ((minDigits == i)&& strlen(A)&1)
      minc = A ;
    if ((maxDigits == i)&& strlen(B)&1)
      maxc = B ;
    if (verbose)
      cout << "Min max " << minc << " " << maxc << endl ;
    count+=listFairAndSquare(i,minc,maxc);
  }
  /*
  for (i = sqrt(A) ; i <= sqrt(B) ; i++) {
    if (i*i < A)
      continue ;
    char decimal[100];
    sprintf(decimal, "%ld",i);
    unsigned long numDigits = strlen(decimal) ;
    if ((numDigits > 1)&& (decimal[0]>='3')) {
      i = pow(10,numDigits) ;
      continue ;
    }
   
    if (isPalindrome(decimal) && isPalindrome(i*i)) {
      count ++;
      if (verbose)
        cout << " Pair " << count << '\t' << i << '\t' << i*i << endl ;
    }
  }*/
  cout << count << endl ;
  return 1;
}

int main (int argc, const char * argv[])
{
  int testCases ;
  cin >> testCases ;
  if (verbose) {
    cerr << "Verbose is on!" << endl ;
    cout << "// Test cases: " << testCases << endl ;
  }
  int i;
  for (i=0 ; i < testCases ; i++) {
    if (verbose)
      cout << "// Running case #" << i+1 << endl ;
    cout << "Case #" << i + 1 << ": " ;
    int r = runTest();
    if (!r) {
      cerr << "test failed!" << endl ;
    }
  }
  
  return 0;
}

