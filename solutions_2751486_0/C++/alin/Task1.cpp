#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char Name[1000001];
int n;

__int64 Solver(void){
	int i, j, len, prev, size;
	int before, after;
	__int64 res = 0;

	len = strlen(Name);
	printf("length = %d\n", len);

	for( i = 0; i <= len - n;  ){
		prev = i;
		size = 0;
		for( j = i; j < len; j ++ ){
			if( (Name[j] != '\0')&&(Name[j] != 'a')&&(Name[j] != 'e')&&(Name[j] != 'i')&&(Name[j] != 'o')&&(Name[j] != 'u') ){
				if( size == 0 )
					prev = j;
				size ++;
			}
			else{
				printf("i=%d,prev=%d, size=%d\n", i, prev, size);
				if( size >= n )
					break;
				else
					size = 0;
			}
		}
		if( size >= n ){
//			res += (j-prev+1)*(len-(prev+size)+1);
			before = prev - i;
			after = len - (prev + size);
			res += (size-n+1)*(size-n+2)/2 + before * (size - n + 1) + after * (size - n + 1) + before*after;
//			res += (prev+size-n+1-i)*(len-(prev+size)+1);
			i = prev+size-n+1;
		}
		else{
			break;
		}
	}

	return (int)res;
}

int main(int argc, char *argv[]){
  FILE* filein;
  FILE* fileout;
  int T;
  int t, i;
  __int64 res;

  if( argc < 3 ){
    printf("Usage is: task1 filein fileout\n");
    return 0;
  }

  // Input 

  filein = fopen(argv[1], "r");
  if( filein == NULL ){
    printf("Error open(); filein\n");
    return 0;
  }
  fileout = fopen(argv[2], "w");
  if( fileout == NULL ){
    printf("Error open(); fileout\n");
    return 0;
  }

  fscanf(filein, "%d\n", &T);
  printf("%d\n", T);
  for( t = 0; t < T; t ++ ){
    printf("-------------\t=%d\n", t);
    fscanf(filein, "%s %d\n", Name, &n);
    printf("%s %d\n", Name, n);

    // Solve & Output
    res = Solver();
    fprintf(fileout, "Case #%d: %I64u\n", t + 1, res);
  }

  fclose(fileout);
  fclose(filein);

  return 0;
}
