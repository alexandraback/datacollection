#include<cstdio>
#include<cstring>
#include<ext/hash_map>
using namespace std;
using namespace __gnu_cxx;

int main(){
   hash_map<char, char> trans;
   trans['a'] = 'y'; trans['b'] = 'h'; trans['c'] = 'e';
   trans['d'] = 's'; trans['e'] = 'o'; trans['f'] = 'c';
   trans['g'] = 'v'; trans['h'] = 'x'; trans['i'] = 'd';
   trans['j'] = 'u'; trans['k'] = 'i'; trans['l'] = 'g';
   trans['m'] = 'l'; trans['n'] = 'b'; trans['o'] = 'k';
   trans['p'] = 'r'; trans['q'] = 'z'; trans['r'] = 't';
   trans['s'] = 'n'; trans['t'] = 'w'; trans['u'] = 'j';
   trans['v'] = 'p'; trans['w'] = 'f'; trans['x'] = 'm';
   trans['y'] = 'a'; trans['z'] = 'q'; trans[' '] = ' ';

   long n;
   scanf("%ld\n", &n);
   for(long c = 0; c < n; c++){
     char s[200];
     gets(s);
     long l = (long) strlen(s);
     for(long d = 0; d < l; d++){
        s[d] = trans[s[d]];
     }
     printf("Case #%ld: %s\n", c+1, s);
   }
   return 0;
}
