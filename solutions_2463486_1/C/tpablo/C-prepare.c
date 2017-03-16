#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <gmp.h>


void solve_for_length (int);
void increment (char *, int);
void work_with (char *);
int is_palindrome (char *);


int
main (void)
{
  int i;
  
  for (i = 1; i <= 51; ++i)
    solve_for_length (i);
  
  return 0;
}

void
solve_for_length (palindrom_length)
     int palindrom_length;
{
  char *palindrom;
  int64_t p;
  int i;
  
  if (palindrom_length == 1)
    {
      printf ("1\n4\n9\n");
      return;
    }
  
  palindrom = malloc (palindrom_length + 1);
  palindrom[0] = '1';
  for (i = 1; i < palindrom_length - 1; ++i)
    palindrom[i] = '0';
  palindrom[palindrom_length - 1] = '1';
  palindrom[palindrom_length] = '\0';
  
  p = 1;
  for (i = palindrom_length / 2 - 1; i--;)
    p *= 2;
  
  if (palindrom_length % 2 == 0)
    {
      while (p--)
        {
          work_with (palindrom);
          increment (palindrom, palindrom_length);
        }
    }
  else
    {
      while (p--)
        {
          for (i = 0; i < 3; ++i)
            {
              palindrom[palindrom_length / 2] = '0' + i;
              work_with (palindrom);
            }
          increment (palindrom, palindrom_length);
        }
    }
  
  palindrom[0] = '2';
  for (i = 1; i < palindrom_length - 1; ++i)
    palindrom[i] = '0';
  palindrom[palindrom_length - 1] = '2';
  
  if (palindrom_length % 2 == 0)
    {
        work_with (palindrom);
    }
  else
    {
        for (i = 0; i < 3; ++i)
          {
            palindrom[palindrom_length / 2] = '0' + i;
            work_with (palindrom);
          }
    }

  free (palindrom);
  
  return;
}


void
increment (p, pl)
  char *p;
  int pl;
{
  int i;
  
  for (i = pl / 2; i--;)
    {
      if (p[i] == '1')
        {
          p[i] = '0';
        }
      else
        {
          ++p[i];
          break;
        }
    }
  
  for (i = (pl + 1) / 2; i < pl; ++i)
    {
      if (p[i] == '1')
        {
          p[i] = '0';
        }
      else
        {
          ++p[i];
          break;
        }
    }
}



int
is_palindrome (p)
     char *p;
{
  int s, e;
  s = 0;
  e = strlen(p) - 1;
  while (s < e)
    {
      if (p[s] != p[e])
        return 0;
      ++s; --e;
    }
  return 1;
}


void
work_with (p)
  char *p;
{
  static char p2[256];
  mpz_t z;
  
  mpz_init (z);
  mpz_set_str (z, p, 10);
  mpz_mul (z, z, z);
  mpz_get_str (p2, 10, z);
  
  if (is_palindrome (p2))
    printf("%s\n", p2);
  
  mpz_clear (z);
}
