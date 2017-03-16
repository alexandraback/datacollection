#include <stdio.h>
#include <string.h>
#include <malloc.h>

char *substring(char *slovo, int position, int length)
{
   char *pointer;
   int c;

   pointer = (char *) malloc(length+1);

   if (pointer == NULL)
   {
      printf("Unable to allocate memory.\n");
      exit(EXIT_FAILURE);
   }

   for (c = 0 ; c < position -1 ; c++)
      slovo++;

   for (c = 0 ; c < length ; c++)
   {
      *(pointer+c) = *slovo;
      slovo++;
   }

   *(pointer+c) = '\0';

   return pointer;
}

int over(char* slovo, int n)
{
    int i, string_length = strlen(slovo);
    int pocet = 0;

    for(i = 0; i < string_length; i++)
    {
        if(slovo[i] != 'a' &&
           slovo[i] != 'e' &&
           slovo[i] != 'i' &&
           slovo[i] != 'o' &&
           slovo[i] != 'u'
          )
            pocet++;
        else
            pocet = 0;

        if(pocet == n)
            return 1;
    }

    return 0;
}


 int main() {

    int t, tt = 1, x, y;

    scanf("%d", &t);

    while(t--)
    {
        scanf("%d %d", &x, &y);


        printf("Case #%d: ", tt++);

            while(x != 0)
                if (x > 0) { printf("WE"); x--; } else { printf("EW"); x++; }
            while(y != 0)
                if (y > 0) { printf("SN"); y--; } else { printf("NS"); y++; }


        printf("\n");
    }

    return 0;
 }
