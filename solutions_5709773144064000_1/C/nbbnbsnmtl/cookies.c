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

float quickest(float cost, float rateStep, float goal, float have, float rate)
{
  float ttWait = 0.0;
  float ttBuy = 0.0;
  while (1) {
    if (have >= goal)
      break;
    printf("Have %f, want %f, rate: %f\n", have, goal, rate);
    ttWait = ttBuy + (goal - have) / rate;
    ttBuy += (cost - have) / rate;
    printf("Wait until %f or buy at %f\n", ttWait, ttBuy);
    if (ttWait <= ttBuy)
      break;
    have = 0;
    rate += rateStep;
  }
  return min(ttWait, ttBuy);
}

void main(void)
{
  char * inFile[]  = {
    "A-small-practice.in", "A-large-practice.in", 
    "B-small-practice.in", "B-large-practice.in",
    "C-small-practice.in", "C-large-practice.in",
    "D-small-practice.in", "D-large-practice.in",
    //"B-small-attempt0.in",
    "B-large.in",
    "sample.in" };
  char outFile[STR_SIZE];
  FILE * fin, * fout;
  int set, numCases, c;
  
  // vars
  char line[STR_SIZE], token[STR_SIZE];
  int i, j, k, i2, j2, n;
  long long llsum;
  
  for (set = 0; set < sizeof(inFile)/sizeof(char *); set++) {
    if (fin = fopen(inFile[set], "r")) {
      sprintf(outFile, "%s.out", inFile[set]);
      if (fout = fopen(outFile, "w")) {
      
        // input header
        numCases = readInt(fin);
        for (c = 0; c < numCases; c++) {
          
          // read each case
          readLine(fin, line);
          float fCost, fStep, fGoal;
          sscanf(line, "%f %f %f", &fCost, &fStep, &fGoal);
          
          // process
          long double cost = fCost;
          long double rateStep = fStep;
          long double goal = fGoal;
          long double baseRate = 2.0;
          long double rate;
          long double endTime;
          long double time;
          long double startTime = 0.0;
          #define MX    8192
          for (i = 0; i < MX; i++) {
            rate = baseRate + rateStep * i;
            endTime = startTime + goal / rate;
            //printf("%d :  %f\n", i, endTime);
            if (i == 0) {
              time = endTime;
            } else {
              if (endTime > time)
                break;
              time = endTime;
            }
            startTime += (cost / rate);
          }
          
          // output
          fprintf(fout, "Case #%d: ", (c + 1));
          {
            fprintf(fout, "%.7f", (float)time);
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
