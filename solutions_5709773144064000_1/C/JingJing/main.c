#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
  double C,F,X;
  double farm_cnt_tmp;
  double time;
  long int farm_cnt;
  long int i_0;
  for (test_case_cnt=1; test_case_cnt<=TEST_CASE_NB; test_case_cnt++) {
    fprintf(fd_out,"Case #%d: ",test_case_cnt);
    r = fscanf(fd_in,"%lf %lf %lf",&C,&F,&X);
    if (r==0) {
      fprintf(stderr,"> ERROR : Wrong input format\n");
      exit(EXIT_FAILURE);
    }
    
#ifdef DEBUG
  fprintf(stdout,"> Case #%d: C=%lf F=%lf X=%lf \n",test_case_cnt,C,F,X);
#endif

    farm_cnt_tmp = ((((X*F)/C)-2)/F)-1;
    if (farm_cnt_tmp<0) farm_cnt = 0;
    else farm_cnt = (long)farm_cnt_tmp + 1;
 
#ifdef DEBUG
  fprintf(stdout,"farm_cnt=%ld\n",farm_cnt);
#endif

    time=0;
    for (i_0=0; i_0<farm_cnt; i_0=i_0+1) {
      time = time + (C/(2+i_0*F));
    }
    time = time + X/(2+farm_cnt*F);

    fprintf(fd_out,"%0.7lf\n",time);
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
