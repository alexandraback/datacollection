#include <stdio.h>
#include <string.h>

#include <vector>

char ap[10];
char bp[10];

char aa[20];
char bb[20];

bool isrecycled(int a, int b)
{
  sprintf(ap,"%d",a);
  sprintf(bp,"%d",b);
  sprintf(aa,"%d%d",a,a);
  sprintf(bb,"%d%d",b,b);
  
  return strstr(bb,ap) != NULL && strstr(aa,bp) != NULL;
}

int main(int argc, char** argv)
{
  if( argc != 2)
    return 1;

  int N;
  FILE* f = fopen(argv[1],"r");
  fscanf(f,"%d",&N);

  for( int i = 0; i < N; ++i)
    {
      int a, b;
      int count = 0;

      fscanf(f, "%d %d\n",&a,&b);

      for( int c = a; c < b; ++c)
	{
	  for(int d = c+1; d <= b; ++d)
	    {
	      if( isrecycled(c,d) )
		{
		  ++count;
		}
	    }
	}
      printf("Case #%d: %d\n",(i+1),count);
    }


  return 0;
};
