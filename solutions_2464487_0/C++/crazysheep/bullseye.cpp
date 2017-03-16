#include <cstdio>
#include <cstdlib>

int main (int argc, char **argv) {
   FILE *fin = fopen ("input.txt", "r");
   FILE *fout = fopen ("output.txt", "w");
   
   int T;
   long long startRadius, paint;
   fscanf (fin, "%d", &T);
   
   for (int i = 0; i < T; i++) {
      fscanf (fin, "%lld %lld", &startRadius, &paint);
      long long startPaint = startRadius + startRadius + 1;
      long long n;
      long long paintUsed = startPaint;
      long long curPaint = startPaint;
      for (n = 1; paintUsed <= paint; n++) {
         curPaint += 4;
         paintUsed += curPaint;
      }
      fprintf (fout, "Case #%d: %lld\n", i+1, n-1);
   }
}
