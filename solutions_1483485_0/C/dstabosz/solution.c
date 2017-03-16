#include <stdio.h>
#include <assert.h>
#include <cstring>
#include <vector>

using namespace std;

int debug = 0;

int main(int argc, char *argv[])
{
  int T;
  unsigned char inBuf[256];
  unsigned char tr[26];

  memset(tr, 0, sizeof(tr));
  
tr[0] = 121;
tr[1] = 110;
tr[2] = 102;
tr[3] = 105;
tr[4] = 99;
tr[5] = 119;
tr[6] = 108;
tr[7] = 98;
tr[8] = 107;
tr[9] = 117;
tr[10] = 111;
tr[11] = 109;
tr[12] = 120;
tr[13] = 115;
tr[14] = 101;
tr[15] = 118;
tr[16] = 122;
tr[17] = 112;
tr[18] = 100;
tr[19] = 114;
tr[20] = 106;
tr[21] = 103;
tr[22] = 116;
tr[23] = 104;
tr[24] = 97;
tr[25] = 113;

tr[24] = 0;
tr[13] = 1;
tr[5] = 2;
tr[8] = 3;
tr[2] = 4;
tr[22] = 5;
tr[11] = 6;
tr[1] = 7;
tr[10] = 8;
tr[20] = 9;
tr[14] = 10;
tr[12] = 11;
tr[23] = 12;
tr[18] = 13;
tr[4] = 14;
tr[21] = 15;
tr[25] = 16;
tr[15] = 17;
tr[3] = 18;
tr[17] = 19;
tr[9] = 20;
tr[6] = 21;
tr[19] = 22;
tr[7] = 23;
tr[0] = 24;
tr[16] = 25;
  assert(scanf( "%d", &T) == 1);

  gets((char*) inBuf);

  unsigned int idxOut = 'z' - 'a';

  for (int t = 1; t <= T; t++)
  {
    printf ("Case #%d: ", t);
    gets((char*) inBuf);

    unsigned char *p = &inBuf[0];
    int i = 0;

    while (*p != 0)
    {
      unsigned char chIn = *p;
      int idxIn = chIn - 'a';


      if (chIn != ' ')
      {
        chIn = tr[idxIn] + 'a';
      }

      p++;
      putchar(chIn);
    }
    putchar('\n');
    
  }

}
