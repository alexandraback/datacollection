#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <string>

using namespace std;

bool
   b[100][100];

bool check_cons(string s, int start, int n)
{
   for (int i = start; i < start + n; i++)
      {
      char
         c = s[i];

      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
         return (false);
      }

   return (true);
}

int count_substr(char *s, int L, int n)
{
   string
      copy = s;

   int
      count = 0;

   for (int i = n; i <= L; i++)
      {
      string
         sub = copy.substr(0, i);

      for (int j = 0; j <= i - n; j++)
         if (check_cons(sub, j, n))
            {
            count++;
            break;
            }
      }

   return (count);
}

int get_val(char *s, int L, int n)
{
   int
      count = 0;

   for (int i = 0; i < L; i++)
      count += count_substr(s + i, L - i, n);

   return (count);
}

int main(int argc, char *argv[])
{
   FILE
	   *fpi = fopen("A-small.in", "r"),
	   *fpo = fopen("A-small.out", "w");

   int
	   T,
      n;

   char
      s[100001];

	fscanf(fpi, "%d", &T);
	for (int i = 0; i < T; i++)
		{
		fscanf(fpi, "%s", &s);
		fscanf(fpi, "%d", &n);

      fprintf(fpo, "Case #%d: %lld\n", i + 1, get_val(s, strlen(s), n));
		}

	fclose(fpi);
	fclose(fpo);
	return 0;
}
