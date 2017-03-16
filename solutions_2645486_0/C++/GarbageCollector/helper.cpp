#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void rchar(char *c)
{
  fscanf(stdin, "%c", c);
}


void r1int(unsigned *i0)
{
  char a;
  fscanf(stdin, "%d", i0);
  fscanf(stdin, "%c", &a);
  assert(a == '\n');
}


void r2int(unsigned *i0, unsigned *i1)
{
  char a;
  fscanf(stdin, "%d", i0);
  fscanf(stdin, "%d", i1);
  fscanf(stdin, "%c", &a);
  assert(a == '\n');
}

void r3int(unsigned *i0, unsigned *i1, unsigned *i2)
{
  char a;
  fscanf(stdin, "%d", i0);
  fscanf(stdin, "%d", i1);
  fscanf(stdin, "%d", i2);
  fscanf(stdin, "%c", &a);
  assert(a == '\n');
}


void r1double(double *d0)
{
  char a;
  fscanf(stdin, "%lf", d0);
  fscanf(stdin, "%c", &a);
  assert(a == '\n');
}


void r2double(double *d0, double *d1)
{
  char a;
  fscanf(stdin, "%lf", d0);
  fscanf(stdin, "%lf", d1);
  fscanf(stdin, "%c", &a);
  assert(a == '\n');
}


void newtabint(unsigned **tab, unsigned nb_line, unsigned nb_col)
{
  char a;
  *tab = (unsigned *)malloc(nb_line * nb_col * sizeof(unsigned));
  for (unsigned i = 0; i < nb_line; i++) {
    for (unsigned j = 0; j < nb_col; j++) {
      fscanf(stdin, "%d", *tab + nb_col * i + j);
    }
    fscanf(stdin, "%c", &a);
    assert(a == '\n');
  }
}


void newtabdouble(double **tab, unsigned nb_line, unsigned nb_col)
{
  char a;
  *tab = (double *)malloc(nb_line * nb_col * sizeof(double));
  for (unsigned i = 0; i < nb_line; i++) {
    for (unsigned j = 0; j < nb_col; j++) {
      fscanf(stdin, "%lf", *tab + nb_col * i + j);
    }
    fscanf(stdin, "%c", &a);
    assert(a == '\n');
  }
}


void dchar(char c)
{
  printf("%c\n", c);
}


void d1int(unsigned i0)
{
  printf("%d\n", i0);
}


void d2int(unsigned i0, unsigned i1)
{
  printf("%d %d\n", i0, i1);
}


void d1double(double d0)
{
  printf("%lf\n", d0);
}


void d2double(double d0, double d1)
{
  printf("%lf, %lf\n", d0, d1);
}


void dtabint(unsigned *tab, unsigned nb_line, unsigned nb_col)
{
  for (unsigned i = 0; i < nb_line; i++) {
    for (unsigned j = 0; j < nb_col; j++) {
      printf("%d ", tab[nb_col * i + j]);
    }
    printf("\n");
  }
}


void dtabdouble(double *tab, unsigned nb_line, unsigned nb_col)
{
  for (unsigned i = 0; i < nb_line; i++) {
    for (unsigned j = 0; j < nb_col; j++) {
      printf("%lf ", tab[nb_col * i + j]);
    }
    printf("\n");
  }
}
