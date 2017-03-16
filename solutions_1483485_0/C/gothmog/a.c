#include <stdio.h>
#include <string.h>

char in_letters[27] = "abcdefghijklmnopqrstuvwxyz";
char out_letters[26];

void check_for_last()
{
   int count=0;
   int i=0;
   int last_letter_index = 0;

   for(i=0; i<sizeof(out_letters); i++)
   {
      if(out_letters[i] == '?')
      {
         count++;
         last_letter_index = i;
      }
   }

   if(count==1)
   {
      for(i=0; i<strlen(in_letters); i++)
      {
         int g=0;
         int found=0;
         for(g=0; g<sizeof(out_letters); g++)
         {
            if(out_letters[g] == in_letters[i])
            {
               found = 1;
               break;
            }
         }

         if(found == 0)
         {
            out_letters[last_letter_index] = in_letters[i];
            break;
         }
      }
   }

}




void add_mapping(char in, char out)
{
   out_letters[in-'a'] = out;
   check_for_last();
}

void translate_into(char *string)
{
   int i=0;

   printf("in : %s\nout: ", string);

   for(i=0; i<strlen(string); i++)
   {
      if((string[i] >= 'a') && (string[i] <= 'z'))
      {
         printf("%c", out_letters[string[i] - 'a']);
      }
      else if (string[i] == ' ')
      {
         printf("%c", string[i]);
      }
   }
   printf("\n");
}

void translate_from(char *string)
{
   int i=0;
   int g=0;

   for(i=0; i<strlen(string); i++)
   {
      if((string[i] >= 'a') && (string[i] <= 'z'))
      {
         for(g=0; g<sizeof(out_letters); g++)
         {
            if(out_letters[g] == string[i])
            {
               printf("%c", in_letters[g]);
               break;
            }
         }
      }
      else if (string[i] == ' ')
      {
         printf("%c", string[i]);
      }
   }
   printf("\n");
}


void consume(char *in, char *out)
{
   int i=0;

   if(strlen(in) != strlen(out))
   {
      printf("%s: Warning unmatched string lengths..\n");
      return;
   }

   for(i=0; i<strlen(in); i++)
   {
      if((in[i] >= 'a') && (in[i] <= 'z'))
      {
         add_mapping(in[i], out[i]);
      }
   }
}


int main(int argc, char* argv)
{
   int i = 0;
   FILE *fp = NULL;

   /* Init unknown mappings to '?' */
   for(i=0; i<sizeof(out_letters); i++)
   {
      out_letters[i] = '?';
   }

   add_mapping('a', 'y');
   add_mapping('o', 'e');
   add_mapping('z', 'q');

   consume("our language is impossible to understand", "ejp mysljylc kd kxveddknmc re jsicpdrysi");
   consume("there are twenty six factorial possibilities", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd");
   consume("so it is okay if you want to just give up", "de kr kd eoya kw aej tysr re ujdr lkgc jv");

   fp = fopen("A-small-attempt0.in.txt", "rt");
//   fp = fopen("sample_input.txt", "rt");

   if(fp)
   {
      int lines = 0;
      char buffer[256];

      fscanf(fp, "%d", &lines);

      fgets(buffer, 255, fp); /* Read to EOL */

      for(i=1; i<=lines; i++)
      {
         fgets(buffer, 255, fp);
//         printf("Buffer = '%s'\n", buffer);
         printf("Case #%d: ", i);
         translate_from(buffer);
      }
      fclose(fp);
   }
   else
   {
      printf("Could not open input file.. :(\n");
   }
}
