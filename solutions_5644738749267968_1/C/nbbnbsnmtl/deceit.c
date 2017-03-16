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
    //"D-small-attempt0.in",
    "D-large.in",
    "sample.in" };
  char outFile[STR_SIZE];
  FILE * fin, * fout;
  int set, numCases, c;
  
  // vars
  char line[STR_SIZE], token[STR_SIZE];
  int i, j, k, i2, j2, n;
  long long llsum;
  int numBlocks;
  float nBlock[1000];
  float kBlock[1000];
  int nUsed[1000];
  int kUsed[1000];
  
  for (set = 0; set < sizeof(inFile)/sizeof(char *); set++) {
    if (fin = fopen(inFile[set], "r")) {
      sprintf(outFile, "%s.out", inFile[set]);
      if (fout = fopen(outFile, "w")) {
      
        // input header
        fscanf(fin, "%d", &numCases);
        //numCases = readInt(fin);
        for (c = 0; c < numCases; c++) {
          
          // read each case
          //readLine(fin, line);
          fscanf(fin, "%d", &numBlocks);
          for (i = 0; i < numBlocks; i++)
            fscanf(fin, "%f", &nBlock[i]);
          for (i = 0; i < numBlocks; i++)
            fscanf(fin, "%f", &kBlock[i]);
          
          // process
          int nptCheat = 0;
          int nptFair = 0;
          int trials;
          for (i = 0; i < numBlocks; i++)
            kUsed[i] = nUsed[i] = 0;
            
            
          for (trials = 0; trials < numBlocks; trials++) {
          float limf;
          int limi;
          limi = -1;
          for (i = 0; i < numBlocks; i++) {
            if (nUsed[i] == 0) {
              if ((limi == -1) || (nBlock[i] < limf)) {
                limf = nBlock[i];
                limi = i;
              }
            }
          }
          float nPick = nBlock[limi];
          float nTold = nPick;
          nUsed[limi] = 1;
          
          //
          float pimf;
          int pimi;
          limi = -1;
          pimi = -1;
          for (i = 0; i < numBlocks; i++) {
            if (kUsed[i] == 0) {
              if ((limi == -1) || (kBlock[i] < limf)) {
                limf = kBlock[i];
                limi = i;
              }
              if (kBlock[i] > nTold) {
                if ((pimi == -1) || (kBlock[i] < pimf)) {
                  pimf = kBlock[i];
                  pimi = i;
                }
              }
            }
          }
          float kPick;
          if (pimi >= 0) {
            kPick = kBlock[pimi];
            kUsed[pimi] = 1;
          } else {
            kPick = kBlock[limi];
            kUsed[limi] = 1;
          }
          if (nPick > kPick)
            nptFair++;
          
          }
          
          
          
          for (trials = 0; trials < numBlocks; trials++) {
          
          
          float nTold;
          float nPick;
          float limf;
          int limi;
          limi = -1;
          float kensMin;
          for (i = 0; i < numBlocks; i++) {
            if (kUsed[i] == 1) {
              if ((limi == -1) || (kBlock[i] < kensMin)) {
                kensMin = kBlock[i];
              }
              if ((limi == -1) || (kBlock[i] > limf)) {
                limf = kBlock[i];
                limi = i;
              }
            }
          }
          float kMax = limf;
          //printf("Ken's best is %f\n", kMax);
          
          
          //
          float pimf;
          int pimi;
          limi = -1;
          pimi = -1;
          float mimf;
          int mimi;
          mimi = -1;
          for (i = 0; i < numBlocks; i++) {
            if (nUsed[i] == 1) {
              if ((limi == -1) || (nBlock[i] < limf)) {
                limf = nBlock[i];
                limi = i;
              }
              if ((mimi == -1) || (nBlock[i] > mimf)) {
                mimf = nBlock[i];
                mimi = i;
              }
              if (nBlock[i] > kMax) {
                if ((pimi == -1) || (nBlock[i] < pimf)) {
                  pimf = nBlock[i];
                  pimi = i;
                }
              }
            }
          }
          
          if (1) {
            if (limf < kensMin) {
              nPick = nBlock[limi];
              nUsed[limi] = 2;
              nTold = kMax - 0.000005;
              //printf("Useless, so play %f, say %f\n", nPick, nTold);
            } else {
              nPick = nBlock[limi];
              nUsed[limi] = 2;
              /*
              limi = -1;
              for (i = 0; i < numBlocks; i++) {
                if (kUsed[i] == 1) {
                  if (nPick > kBlock[i]) {
                    if ((limi == -1) || (kBlock[i] > limf)) {
                      limi = i;
                      limf = kBlock[i];
                    }
                  }
                }
              }
              nTold = limf + 0.00005; //nPick;//kensMin + 0.000005;
              */
              nTold = 9.99999;
              //printf("OK, so play %f, say %f\n", nPick, nTold);
            }
          } else
          if (nBlock[limi] < kensMin) {
            nPick = nBlock[limi];
            nUsed[limi] = 2;
            nTold = kMax - 0.000005;
            //printf("Naomi kills Ken's best\n");
          } else
          if (pimi >= 0) {
            nPick = nBlock[mimi];//nBlock[pimi];
            nUsed[mimi] = 2;//nUsed[pimi] = 2;
            nTold = nPick;
            //printf("Naomi can beat so %f\n", nPick);
          } else {
            nPick = nBlock[limi];
            nUsed[limi] = 2;
            nTold = kMax - 0.000005;
            //printf("Naomi can't beat so %f, really %f\n", nTold, nPick);
          }
          
          
          
          
          //
          float pimf;
          int pimi;
          limi = -1;
          pimi = -1;
          for (i = 0; i < numBlocks; i++) {
            if (kUsed[i] == 1) {
              if ((limi == -1) || (kBlock[i] < limf)) {
                limf = kBlock[i];
                limi = i;
              }
              if (kBlock[i] > nTold) {
                if ((pimi == -1) || (kBlock[i] < pimf)) {
                  pimf = kBlock[i];
                  pimi = i;
                }
              }
            }
          }
          float kPick;
          if (pimi >= 0) {
            kPick = kBlock[pimi];
            kUsed[pimi] = 2;
          } else {
            kPick = kBlock[limi];
            kUsed[limi] = 2;
          }
          //printf("Ken plays %f\n", kPick);
          if (nPick > kPick) {
            nptCheat++;
            //printf(" > NAOMI POINT\n");
          } else {
            //printf(" > Ken\n");
          }
          //if ((nPick > kPick) != (nTold > kPick))
            //printf(">> CAUGHT LYING\n");
          
          
          
          
          
          }
          //printf("\n");
          
          
          
          
          
          
          
          
          
          
          
          
          
          // output
          fprintf(fout, "Case #%d: ", (c + 1));
          {
            fprintf(fout, "%d %d", nptCheat, nptFair);
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
