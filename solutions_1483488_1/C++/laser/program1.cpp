#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string.h>
#include <iostream>

using namespace std;

char dict[100];

char word1[] = {"zyeqejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv"};
char word2[] = {"qaozour language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up"};

char inp1[256];

int main() 
{
   int i; 
   int n = strlen(word2);
   for( i=0; i<n; i++)
   {
      if( word1[i]>='a' && word1[i]<='z')
      dict[word1[i]-'a'] = word2[i];
   }

   int t=0;
   cin >> t; cin.getline(inp1, 200);
   for(int j=1; j<=t; j++ )
   {
      cout << "Case #" << j << ": ";

      cin.getline(inp1,256);
      
      for( i=0; i<strlen(inp1); i++)
      {
         if( inp1[i]>='a' && inp1[i]<='z') 
            cout << dict[inp1[i]-'a'];
         else
            cout << inp1[i];
      }
      cout << endl;
   }

	return 0;
}

