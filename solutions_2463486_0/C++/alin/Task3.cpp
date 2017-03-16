#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include <math.h>

char A[100][10000][100];
unsigned int AN[100], GN = 5;
char Good[100000][102] = {"1","2","3","11","22"};
char Good2[100000][204] = {"1","4","9","121","484"};

char s1[] = "1024", s2[] = "997", s3[1000];

void inc(char a[]){
  int i, lena, f;

  lena = (int)strlen(a);
  f = 1;
  for( i = lena - 1; i >=0; i --){
    if( a[i] == '9' ){
      a[i] ='0';
    }
    else{
      a[i] = a[i] + 1;
      break;
    }
  }
  if( i == -1 ){
    for( i = lena; i >=0; i --){
      a[i+1] = a[i];
    }
    a[0] = '1';
  }
}

int mul(char a[], char b[], char c[]){
  int i, j, lena, lenb, lenc, f = 0;
  int C[1000];
  lena = (int)strlen(a);
  lenb = (int)strlen(b);
  for( i = 0; i < 1000; i ++ )
    C[i] = 0;
  for( i = 0; i < lena; i ++ )
    for( j = 0; j < lenb; j ++ )
      C[lena+lenb-i-j-2] += (a[i]-'0')*(b[j]-'0');
  lenc = 0;
  for( i = 0; i < 1000; i ++ ){
    if( C[i] >= 10 )
      f = 1;
    C[i+1] += C[i] / 10;
    C[i] = C[i] % 10;
    if( C[i] != 0 ){
      lenc = i + 1;
    }
  }
  for( i = 0; i < lenc; i ++ ){
    c[i] = '0' + C[lenc - i - 1];
  }
  c[lenc] = '\0';
  return f;
}

int Cmp(char a[], char b[]){
  int i, lena, lenb;

  lena = (int)strlen(a);
  lenb = (int)strlen(b);
  if( lena > lenb )
    return 1;
  if( lena < lenb )
    return -1;
  for( i = 0; i < lena; i ++ ){
    if( a[i] > b[i] )
      return 1;
    if( a[i] < b[i] )
      return -1;
  }
  return 0;
}

void Prefixes(unsigned int N){
  unsigned int i, j, k, l, an, f, len, q;
  char s1[100], s2[100], s3[200], s4[200], s5[200], s6[100], s7[100], s8[100], s9[102], ss[203];

  GN = 5;
  AN[0] = 3;
  A[0][0][0] = '1';
  A[0][0][1] = '\0';
  A[0][1][0] = '2';
  A[0][1][1] = '\0';
  A[0][2][0] = '3';
  A[0][2][1] = '\0';

  i = 1;
  for( j = 0; j < AN[i-1]; j ++ ){
    for( q = 0; q <= 2; q ++ ){
      for( l = 0; l < i; l ++ ){
        s9[l] = A[i-1][j][i-1-l];
        s9[2*i+1-l-1] = A[i-1][j][i-1-l];
      }
      s9[i] = '0' + q;
      s9[2*i+1] = '\0';
      mul(s9,s9,ss);
      f = 1;
      for( l = 0; l < strlen(ss)/2; l ++ ){
        if( ss[l] != ss[strlen(ss)-1-l] )
          f = 0;
      }
      if( f == 1 ){
        for( l = 0; l <= strlen(s9); l ++ ){
          Good[GN][l] = s9[l];
        }
        for( l = 0; l <= strlen(ss); l ++ ){
          Good2[GN][l] = ss[l];
        }
//        printf("%s %s %s\n", A[i-1][j], Good[GN], Good2[GN]);
        GN ++;
      }
    }
  }

  for( i = 2; i <= N/2; i ++ ){
    an = 0;
    for( j = 0; j < AN[i-2]; j ++ ){
      for( k = 0; k < 3; k ++){
        s1[0] = '0' + k;
        for( l = 0; l < i - 1; l ++){
          s1[l+1] = A[i-2][j][l];
          s2[l] = A[i-2][j][i-2-l];
        }
        s2[i-1] = '0' + k;
        s1[i] = '\0';
        s2[i] = '\0';
        if(mul(s1,s1,s3))
          continue;
        while( strlen(s3) < i ){
          len = (int)strlen(s3);
          for( l = len + 1; l > 0; l -- ){
            s3[l] = s3[l-1];
          }
          s3[0] = '0';
        }
        if(mul(s2,s2,s4))
          continue;
        if(mul(s1,s2,s5))
          continue;
        if(mul(s5,"2",s5))
          continue;
//        inc(s2);
//        mul(s2,s2,s5);
        for( l = 0; l < i; l ++){
          s6[l] = s3[strlen(s3)-l-1];
          s7[l] = s4[l];
//          s8[l] = s5[l];
//          if( strlen(s5) > strlen(s4) ){
//            s8[l] = '9';
//          }
        }
        s6[i] = s7[i] = 0;
//        s6[i] = s7[i] = s8[i] = 0;
//        if( (Cmp(s6, s7) >= 0) &&(Cmp(s6,s8) <= 0) ){
        if( Cmp(s6, s7) == 0 ){
          for( l = 0; l < i; l ++){
            A[i-1][an][l] = s1[l];
//            printf("%c",s1[l]);
          }
//          printf(" %s %s\n", s3, s4);
          A[i-1][an][i] = 0;
          an ++;
        }
      }
    }
    AN[i-1] = an;
    for( j = 0; j < AN[i-1]; j ++ ){
      for( l = 0; l < i; l ++ ){
        s9[l] = A[i-1][j][i-1-l];
        s9[2*i-1-l] = A[i-1][j][i-1-l];
      }
      s9[2*i] = '\0';
      mul(s9,s9,ss);
      f = 1;
      for( l = 0; l < strlen(ss)/2; l ++ ){
        if( ss[l] != ss[strlen(ss)-1-l] )
          f = 0;
      }
      if( f == 1 ){
        for( l = 0; l <= strlen(s9); l ++ ){
          Good[GN][l] = s9[l];
        }
        for( l = 0; l <= strlen(ss); l ++ ){
          Good2[GN][l] = ss[l];
        }
//        printf("%s %s %s\n", A[i-1][j], Good[GN], Good2[GN]);
        GN ++;
      }
    }
    for( j = 0; j < AN[i-1]; j ++ ){
      for( q = 0; q <= 2; q ++ ){
        for( l = 0; l < i; l ++ ){
          s9[l] = A[i-1][j][i-1-l];
          s9[2*i+1-l-1] = A[i-1][j][i-1-l];
        }
        s9[i] = '0' + q;
        s9[2*i+1] = '\0';
        mul(s9,s9,ss);
        f = 1;
        for( l = 0; l < strlen(ss)/2; l ++ ){
          if( ss[l] != ss[strlen(ss)-1-l] )
            f = 0;
        }
        if( f == 1 ){
          for( l = 0; l <= strlen(s9); l ++ ){
            Good[GN][l] = s9[l];
          }
          for( l = 0; l <= strlen(ss); l ++ ){
            Good2[GN][l] = ss[l];
          }
//          printf("%s %s %s\n", A[i-1][j], Good[GN], Good2[GN]);
          GN ++;
        }
      }
    }
  }
}

int Solver(char Min[], char Max[]){
  int i, res = 0;
  for( i = 0; i < GN; i ++ ){
    if( Cmp(Good2[i], Min) < 0 )
      continue;
    if( Cmp(Good2[i], Max) > 0 )
      continue;
    res ++;
  }
  return res;
}

/*
int Solver(unsigned __int64 A, unsigned __int64 B){
  unsigned int Start, End, i, j, len1, len2, f1, f2, res = 0;
  unsigned __int64 i2;
  char Ar[100],Ar2[100];

  Start = (int)floor(sqrt((double)A-1)) + 1;
  End = (int)floor(sqrt((double)B));
  printf("Start=%d, End=%d\n", Start, End);

  for( i = Start; i <= End; i ++){
    j = i;
    i2 = i * i;
    for( len1 = 0; j > 0; len1 ++ ){
      Ar[len1] = j % 10;
      j = j / 10;
    }
    i2 = (__int64)i * (__int64)i;
    for( len2 = 0; i2 > 0; len2 ++ ){
      Ar2[len2] = char(i2 % 10);
      i2 = i2 / 10;
    }
    f1 = 1;
    for( j = 0; j <= len1 / 2; j ++ )
      if( Ar[j] != Ar[len1 - 1 - j] )
        f1 = 0;
    f2 = 1;
    for( j = 0; j <= len2 / 2; j ++ )
      if( Ar2[j] != Ar2[len2 - 1 - j] )
        f2 = 0;
    if( (f1 == 1) && (f2 == 1)){
      res ++;
      printf("%d %I64d\n", i, (__int64)i*(__int64)i);
    }
  }
  return res;
}
*/

int main(int argc, char *argv[]){
  FILE* filein;
  FILE* fileout;
  int T;
  char A[101], B[101];
  int res, t;

  if( argc < 3 ){
    printf("Usage is: task1 filein fileout\n");
    return 0;
  }

  // Input 

  filein = fopen(argv[1], "r");
  if( filein == NULL ){
    printf("Error open(); filein\n");
    return 0;
  }
  fileout = fopen(argv[2], "w");
  if( fileout == NULL ){
    printf("Error open(); fileout\n");
    return 0;
  }

  Prefixes(50);
  printf("Prefixes done\n");

  fscanf(filein, "%d\n", &T);
  printf("%d\n", T);
  for( t = 0; t < T; t ++ ){
    printf("-------------\t=%d\n", t);
    fscanf(filein, "%s %s\n", A, B);
    printf("A=%s\n", A);
    printf("B=%s\n", B);

    // Solve & Output
    res = Solver(A, B);
    fprintf(fileout, "Case #%d: %d\n", t + 1, res);
  }

  fclose(fileout);
  fclose(filein);

  return 0;
}
