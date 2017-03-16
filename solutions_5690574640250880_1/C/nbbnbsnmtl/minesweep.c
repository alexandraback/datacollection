#include <stdio.h>
#include <math.h>
#include <string.h>

#define STR_SIZE          (8192)
#define intalloc(count)   (int *)(malloc((count) * sizeof(int)))
#define min(x, y)         (((x) < (y)) ? (x) : (y))
#define max(x, y)         (((x) > (y)) ? (x) : (y))

void readLine(FILE *, char *);
int readInt(FILE *);
int strField(char *, int, char, char *);
int intField(char *, int, char);
int countChar(char *, char);
void fprintllp(FILE *, long long *);
unsigned long long permute(unsigned long long, unsigned long long);
unsigned long long combine(unsigned long long, unsigned long long);
unsigned long long factorial(unsigned long long);

void main(void)
{
  char * inFile[]  = {
    "A-small-practice.in", "A-large-practice.in", 
    "B-small-practice.in", "B-large-practice.in",
    "C-small-practice.in", "C-large-practice.in",
    "D-small-practice.in", "D-large-practice.in",
    /*"C-small-attempt0.in",
    "C-small-attempt1.in",
    "C-small-attempt2.in",
    "C-small-attempt3.in",*/
    "C-large.in",
    "sample.in" };
  char outFile[STR_SIZE];
  FILE * fin, * fout;
  int set, numCases, c;
  
  // vars
  char line[STR_SIZE], token[STR_SIZE];
  int i, j, k, i2, j2, n;
  long long llsum;
  
  int grid[100][100];
  int surround[100][100];
  
  #define EMPTY 0
  #define MINE 1
  #define CLICKED 2
  
  for (set = 0; set < sizeof(inFile)/sizeof(char *); set++) {
    if (fin = fopen(inFile[set], "r")) {
      sprintf(outFile, "%s.out", inFile[set]);
      if (fout = fopen(outFile, "w")) {
      
        // input header
        numCases = readInt(fin);
        for (c = 0; c < numCases; c++) {
          
          // read each case
          readLine(fin, line);
          int approach = 1;
          tryit:
          {};
          
          // process
          int rows = intField(line, 1, ' ');
          int cols = intField(line, 2, ' ');
          int mines = intField(line, 3, ' ');
          int squares = rows * cols;
          int empties = squares - mines;
          int possible = 1;
          for (i = 0; i < 100; i++)
            for (j = 0; j < 100; j++)
              grid[i][j] = surround[i][j] = EMPTY;
          
          if (mines >= squares) {
            // too many mines, impossible
            possible = 0;
          } else if (mines == 0) {
            // no mines, instant win
            possible = 1;
            grid[0][0] = CLICKED;
          } else if (empties == 1) {
            // 1 empty, instant win
            possible = 1;
            for (i = 0; i < rows; i++) 
              for (j = 0; j < cols; j++)
                grid[i][j] = MINE;
            grid[0][0] = CLICKED;
          } else {
            if (approach == 1) {
              // approach 1
              // click top-left, fill mines from bottom-right
              int dist = max(rows, cols) - 1;
              while (mines > 0) {
                if (dist < cols) {
                  for (i = rows-1; i >= 0; i--) {
                    if (grid[i][dist] == EMPTY) {
                      grid[i][dist] = MINE;
                      if (--mines == 0)
                        goto verify;
                    }
                  }
                }
                if (dist < rows) {
                  for (j = cols-1; j >= 0; j--) {
                    if (grid[dist][j] == EMPTY) {
                      grid[dist][j] = MINE;
                      if (--mines == 0)
                        goto verify;
                    }
                  }
                }
                dist--;
              }
            } else if (approach == 2) {
              // click top-left, fill mines from bottom-right
              int transpose = (cols > rows);
              int dist = (rows-1)+(cols-1);
              while (mines > 0) {
                for (i = rows-1; i >= 0; i--) {
                  for (j = cols-1; j >= 0; j--) {
                    if (i + j == dist) {
                      if (grid[i][j] == EMPTY) {
                        grid[i][j] = MINE;
                        if (--mines == 0)
                          goto verify;
                      }
                    }
                  }
                }
                dist--;
              }
            } else if (approach == 3) {
              // approach 3?
              int trows = rows;
              int tcols = cols;
              while (1) {
                int changed = 0;
                if (trows >= tcols) {
                  if (mines >= tcols) {
                    for (j = 0; j < tcols; j++) {
                      grid[trows-1][j] = MINE;
                    }
                    mines -= tcols;
                    trows -= 1;
                    changed = 1;
                  }
                } else {
                  if (mines >= trows) {
                    for (i = 0; i < trows; i++) {
                      grid[i][tcols-1] = MINE;
                    }
                    mines -= trows;
                    tcols -= 1;
                    changed = 1;
                  }
                }
                if (!changed)
                  break;
              }
              int dist = (trows-1)+(tcols-1);
              while (mines > 0) {
                if (tcols > trows) {
                  for (i = trows-1; i >= 0; i--) {
                    for (j = tcols-1; j >= 0; j--) {
                      if (i + j == dist) {
                        if (grid[i][j] == EMPTY) {
                          grid[i][j] = MINE;
                          if (--mines == 0)
                            goto verify;
                        }
                      }
                    }
                  }
                } else {
                  for (j = tcols-1; j >= 0; j--) {
                    for (i = trows-1; i >= 0; i--) {
                      if (i + j == dist) {
                        if (grid[i][j] == EMPTY) {
                          grid[i][j] = MINE;
                          if (--mines == 0)
                            goto verify;
                        }
                      }
                    }
                  }
                }
                dist--;
              }
            }
            
            verify:
            for (i = 0; i < rows; i++) {
              for (j = 0; j < cols; j++) {
                if (grid[i][j] == MINE)
                  surround[i][j] = 9;
                else {
                  for (i2 = i - 1; i2 <= i + 1; i2++) {
                    for (j2 = j - 1; j2 <= j + 1; j2++) {
                      if ((i2 >= 0) && (i2 < rows)) {
                        if ((j2 >= 0) && (j2 < cols)) {
                          if ((i2 != i) || (j2 != j)) {
                            surround[i][j] += (grid[i2][j2] == MINE);
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            for (i = 0; i < rows; i++) {
              for (j = 0; j < cols; j++) {
                if (grid[i][j] != MINE) {
                  if (surround[i][j] > 0) {
                    possible = 0;
                    for (i2 = i - 1; i2 <= i + 1; i2++)
                      for (j2 = j - 1; j2 <= j + 1; j2++)
                        if ((i2 >= 0) && (i2 < rows))
                          if ((j2 >= 0) && (j2 < cols))
                            if ((i2 != i) || (j2 != j)) {
                              if (surround[i2][j2] == 0)
                                possible = 1;
                            }
                  }
                  if (!possible) {
                    goto exiter;
                  }
                }
              }
            }
          }
          
          exiter:
          if (possible) {
            //if (approach == 1)
              grid[0][0] = CLICKED;
          } else {
            if (approach < 3) {
              approach++;
              goto tryit;
            }
          }
          
          // output
          outputter:
          fprintf(fout, "Case #%d:", (c + 1));
          {
            //if (!possible)
              //fprintf(fout, "\nImpossible", i);
            if (possible) {
              for (i = 0; i < rows; i++) {
                fprintf(fout, "\n");
                for (j = 0; j < cols; j++) {
                  /*if (grid[i][j] == MINE)
                    fprintf(fout, "*");
                  else
                    fprintf(fout, "%c", '0' + surround[i][j]);*/
                  fprintf(fout, "%c", ".*c"[grid[i][j]]);
                }
              }
            } else {
              fprintf(fout, "\nImpossible", i);
            }
          }
          fprintf(fout, "\n");
          
          // cleanup
          //
        }
        printf("Wrote: %s\n", outFile);
        fclose(fout);
      } else {
        printf("Could not create: %s\n", inFile[set]);
      }
      fclose(fin);
    } else {
      //printf("Could not read: %s\n", inFile[set]);
    }
  }
}



void readLine(FILE * fp, char * buffer)
{
  fgets(buffer, STR_SIZE, fp);
  if (buffer[0]) {
    char * ch = buffer; while (*(ch+1)) ch++;
    while ((ch >= buffer) && ((*ch == 0x0A) || (*ch == 0x0D)))
      *(ch--) = 0x00;
  }
}

int readInt(FILE * fp)
{
  static char buffer[STR_SIZE];
  readLine(fp, buffer);
  return (atoi(buffer));
}

int strField(char * input, int index, char delimiter, char * output)
{
  *output = 0x00;
  int found = 0;
  char * st = input;
  char * ch = input;
  while (1) {
    if ((*ch == delimiter) || (*ch == 0x00)) {
      if (++found == index) {
        strncpy(output, st, ch - st);
        *(output + (ch - st)) = 0x00;
        break;
      }
      st = ch + 1;
    }
    if (*ch == 0x00)
      break;
    ch++;
  }
  return (strlen(output));
}

int intField(char * input, int index, char delimiter)
{
  int result = 0;
  int found = 0;
  char * st = input;
  char * ch = input;
  while (1) {
    if ((*ch == delimiter) || (*ch == 0x00)) {
      if (++found == index) {
        char prev = *ch;
        *ch = 0x00;
        result = atoi(st);
        *ch = prev;
        break;
      }
      st = ch + 1;
    }
    if (*ch == 0x00)
      break;
    ch++;
  }
  return (result);
}

int countChar(char * input, char delimiter)
{
  int found = 0;
  while (*(input++))
    found += (*(input-1) == delimiter);
  return found;
}

void fprintllp(FILE * fp, long long * lp)
{
  long long copy = *lp;
  char buffer[32];
  char * ch = buffer;
  char neg = (copy < 0);
  if (neg)
    copy = -copy;
  while (copy > 0) {
    *(ch++) = '0' + (copy % 10);
    copy /= 10;
  }
  if (neg)
    fprintf(fp, "-");
  if (ch == buffer)
    fprintf(fp, "%c", '0');
  while (ch > buffer) {
    fprintf(fp, "%c", *(--ch));
  }
}

unsigned long long permute(unsigned long long n, unsigned long long k)
{
  unsigned long long product = 1;
  while (k--)
    product *= (n--);
  return (product);
}

unsigned long long factorial(unsigned long long k)
{
  unsigned long long product = 1;
  while (k)
    product *= (k--);
  return (product);
}

unsigned long long combine(unsigned long long n, unsigned long long k)
{
  return (permute(n, k)/factorial(k));
}
