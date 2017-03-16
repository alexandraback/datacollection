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

    int t, tt = 1, n;
    char *pointer;
    int position = 1, length = 1, temp, string_length;
    char slovo[3000];
    int pocet;

    scanf("%d", &t);

    while(t--)
    {

        scanf("%s %d", slovo, &n);

        pocet = 0;
        position = 1, length = 1,
        temp = string_length = strlen(slovo);

        //printf("Substring of \"%s\" are\n", slovo);

        while (position <= string_length)
        {
          while (length <= temp)
          {
             pointer = substring(slovo, position, length);
            // printf("%s => %d\n", pointer, pocet);



             if (over(pointer, n)) pocet++;

             free(pointer);
             length++;
          }
          temp--;
          position++;
          length = 1;
        }



        printf("Case #%d: %d\n", tt++, pocet);
    }

    return 0;
 }
