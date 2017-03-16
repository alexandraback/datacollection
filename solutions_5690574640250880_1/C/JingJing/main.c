#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

//=====================================================
// Define
//=====================================================
//#define DEBUG 1

//=====================================================
// Variables
//=====================================================


//=====================================================
// Struct
//=====================================================

//=====================================================
// Utils
//=====================================================


//=====================================================
// Functions
//=====================================================
void print_array(FILE * fd_out, int R, int C, int M) {
  char array [R][C];
  bool is_even;
  int D;
  int tmp = 0;
  int i_0,i_1;
  for (i_1=0; i_1<C; i_1++) {
    for (i_0=0; i_0<R; i_0++) {
      if ((i_0 < (R-2)) && (i_1 <(C-2)) && (tmp < M)){
        array[i_0][i_1] = '*';
        tmp = tmp + 1;
      }
      else if ((i_0==(R-1)) && (i_1==(C-1)))
        array[i_0][i_1] = 'c';
      else
        array[i_0][i_1] = '.';
    }
  }

  if (M > tmp) {
    D = M - tmp;
    i_1=0;
    while ((D>1) && (i_1<(C-3))){
      array[R-2][i_1] = '*';
      array[R-1][i_1] = '*';
      D = D-2;
      i_1++;
    }
    i_0=0;
    while ((D>1) && (i_0<(R-3))){
      array[i_0][C-1] = '*';
      array[i_0][C-2] = '*';
      D = D-2;
      i_0++;
    }
    
    is_even = ((D%2)==0) ? true : false;
    if ((D > 0) && (is_even || (D==7))) {
      if (D == 6) {
        fprintf(stderr,"> ERROR : impossible case : remains 6\n");
        exit(EXIT_FAILURE);
      }
      if (D >= 2) {
        array[R-2][C-3] = '*';
        array[R-1][C-3] = '*';  
      }
      if (D >= 4) {
        array[R-3][C-2] = '*';
        array[R-3][C-1] = '*';  
      }
      if (D == 7) {
        array[R-2][C-2] = '*';
        array[R-1][C-2] = '*';
        array[R-2][C-1] = '*';  
      }
    }
    else if ((D==1) && ((i_0<(R-3)) || (i_1<(C-3)))) {
      array[R-3][C-3] = '.';
      if (i_0<(R-3)) {
	array[i_0][C-1] = '*';
	array[i_0][C-2] = '*';
      }
      else {
	array[R-2][i_1] = '*';
	array[R-1][i_1] = '*';
      }
    }
  }

  // print
  for (i_1=0; i_1<C; i_1++) {
    for (i_0=0; i_0<R; i_0++) {
      fprintf(fd_out,"%c",array[i_0][i_1]);
    }
    fprintf(fd_out,"\n");
  }
}


//=====================================================
// MAIN
//=====================================================

int main (int argc, char **argv) {
  //=====================
  // Variables
  //=====================
  char *in_filename  = NULL;
  char *out_filename = NULL; 

  FILE * fd_in;
  FILE * fd_out;

  int TEST_CASE_NB;

  int c;
  int r;

  //======================
  // Parse input
  //======================
  opterr = 0;

  while ((c = getopt (argc, argv, "i:o:")) != -1)
    switch (c)
      {
      case 'i':
        in_filename = optarg;
        break;
      case 'o':
        out_filename = optarg;
        break;

      case '?':
        if (optopt == 'i' ||
            optopt == 'o')
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        else if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        else
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
        return 1;
      default:
        abort ();
      }


  //======================
  // Open Files
  //======================
  fd_in = fopen(in_filename,"r");
  if (fd_in == NULL) {
    fprintf(stderr, "> ERROR : cannot open %s\n", in_filename);
    exit(EXIT_FAILURE);
  }
  fd_out = fopen(out_filename,"w");
  if (fd_out == NULL) {
    fprintf(stderr, "> ERROR : cannot open %s\n", out_filename);
    exit(EXIT_FAILURE);
  }

  //======================
  // Parse TEST_CASE_CNT
  //======================
  r = fscanf(fd_in,"%d",&TEST_CASE_NB);
  if (r==0) {
    fprintf(stderr,"> ERROR : Wrong input format - TEST_CASE_NB not recognized\n");
    exit(EXIT_FAILURE);
  }

#ifdef DEBUG
  fprintf(stdout,"TEST_CASE_NB=%d\n",TEST_CASE_NB);
#endif

  //======================
  // Malloc
  //======================

  //======================
  // Process
  //======================
  int test_case_cnt;
  int R,C,M;
  int i_0, i_1;
  int tmp;
  for (test_case_cnt=1; test_case_cnt<= TEST_CASE_NB; test_case_cnt++) {
    fprintf(fd_out,"Case #%d:\n",test_case_cnt);
    r = fscanf(fd_in,"%d %d %d",&C, &R, &M);
    if (r==0) {
      fprintf(stderr,"> ERROR : Wrong input format - input line not recognized\n");
      exit(EXIT_FAILURE);
    }
#ifdef DEBUG
  fprintf(stdout," > Case=%d R=%d C=%d M=%d\n",test_case_cnt,C,R,M);
#endif
    //== (R==1) or (C==1)
    if ((R==1) || (C==1)) {
#ifdef DEBUG
  fprintf(stdout,"R==1 OR C==1\n");
#endif
      if (((R*C)-M) >= 1){
        for (i_0=1;i_0<=C; i_0=i_0+1) {
          for (i_1=1;i_1<=R; i_1=i_1+1) {
            tmp = i_0 * i_1;
            if (tmp <= M)
              fprintf(fd_out,"*");
            else if ((tmp < (R*C)) && (tmp > M))
              fprintf(fd_out,".");
            else // tmp == R*C
             fprintf(fd_out,"c");
          }
          fprintf(fd_out,"\n");
        } 
      }
      else { // impossible
        fprintf(fd_out,"Impossible\n");
      }
    }
    //== (R==2) or (C==2)
    else if ((R==2) || (C==2)) {
#ifdef DEBUG
  fprintf(stdout,"R==2 OR C==2\n");
#endif
      if ((((M % 2) == 1) && !(M==(R*C-1))) || (((R*C)-M)==2)) { // impossible
        fprintf(fd_out,"Impossible\n");
      }
      else {
        if (R==2) {
          for(i_0=0; i_0<C; i_0=i_0+1) {
            if (i_0 < (M/2)) {
              fprintf(fd_out,"**\n");
            }
            else if (i_0==(C-1)) {
              if (M==(R*C-1))
              fprintf(fd_out,"*c\n");
              else
              fprintf(fd_out,".c\n");
            }
            else
              fprintf(fd_out,"..\n");
          }
        }
        else { // C==2
          for(i_0=0; i_0<C; i_0=i_0+1) {
            for(i_1=0; i_1<R; i_1=i_1+1) {
              if (i_1 < (M/2)) {
                fprintf(fd_out,"*");
              }
              else if ((i_0==(C-1)) && (i_1==(R-1))) {
                fprintf(fd_out,"c");
              }
              else
                if (M==(R*C-1))
                  fprintf(fd_out,"*");
                else
                  fprintf(fd_out,".");
            }
            fprintf(fd_out,"\n");
          }
        }
      }
    }
    //== (R>2) and (C>2)
    else {
#ifdef DEBUG
  fprintf(stdout,"R>2 OR C>2\n");
#endif
      bool impossible = false;
      int A = M - ((R-2)*(C-2));
#ifdef DEBUG
  fprintf(stdout,"A=%d\n",A);
#endif
      if (A > 0) {
        if ((A%2)==0) {
          A = A/2;
          if (A > ((R-2)+(C-2)))
            impossible = true;
        }
        else {
          A = (A+1)/2;
          if ((A > ((R-3)+(C-3))) && !(M == ((R*C)-1)))
            impossible = true;
        }
      }


      if (impossible) {
        fprintf(fd_out,"Impossible\n");
      }
      else {
        print_array(fd_out, R, C, M);
      }
    }
  }

  //======================
  // Close Files
  //======================
  fclose(fd_in);
  fclose(fd_out); 

  //======================
  // Free
  //======================

  return 0;
}
