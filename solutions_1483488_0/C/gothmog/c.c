#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int back_to_front(int n, int digits)
{
   char number[20];
   char copy[20];
   int length = 0;
   int ret = 0;

   sprintf(number, "%d", n);

   length = strlen(number);

   strncpy(copy, number + (length-digits), digits);
   copy[digits] = '\0';

   number[length-digits] = '\0';
   strcat(copy, number);

   ret = atoi(copy);

   return ret;
}

#define MAX_DIGITS 10

int count_pairs(int A, int B, int n, int digits)
{
   int i=0;
   int count = 0;
   int history[MAX_DIGITS];

   if(digits <= 1) return 0;
   if(n < A) return 0;
   if(n > B) return 0;

   for(i=1; i<=(digits-1); i++)
   {
      int m = back_to_front(n, i);

      if( (m>n) && (m<=B))
      {
         int g=0;
         int found=0;

         for(g=0; g<count; g++)  /* Check for dupes */
         {
            if(history[g] == m)
            {
//					printf("Rejected dupe %d <= %d < %d <= %d\r\n", A, n, m, B);
               found = 1;
               break;
            }
         }
         if(found == 0)
         {
//				printf("Added  %d <= %d < %d <= %d\r\n", A, n, m, B);
            history[count++] = m;
         }
      }
		else
		{

			if( (A<=n) && (n<m) && (m<=B) )
			{
				printf("************** Rejected a good one! ************************\r\n");
			}
			
//			printf("Reject %d <= %d < %d <= %d\r\n", A, n, m, B);
		}

   }

   return count;
}

int do_it(int A, int B)
{
   int i=0;
   int count=0;

   char strA[20];
   int lenA=0;
   char strB[20];
   char lenB=0;

   sprintf(strA, "%d", A);
   sprintf(strB, "%d", B);

   lenA = strlen(strA);
   lenB = strlen(strB);

   if(lenA != lenB)
   {
      printf("Error %d and %d have different number of digits!", A, B);

      return 0;
   }


   for(i=A; i<=B; i++)
   {
      count += count_pairs(A, B, i, lenA);
   }

   return count;
}

int main(int argc, char *argv[])
{
   FILE *fp = NULL;


   if(argc == 2)
   {
      fp = fopen(argv[1], "rt");

      if(fp)
      {
         int n_tests = 0;
         int i = 0;

         fscanf(fp, "%d", &n_tests);

         for(i=1; i<=n_tests; i++)
         {
            int A=0, B=0;
            fscanf(fp, "%d %d", &A, &B);
//				printf("A=%d B=%d\n", A, B);

            printf("Case #%d: %d\r\n", i, do_it(A, B));
         }
      }
   }

   return 0;
}
