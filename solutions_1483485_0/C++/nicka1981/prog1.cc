#include <string>
#include <vector>
#include <memory>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

vector<string> a;
vector<string> b;

char mp[26];
char imp[26];

char buf[150];

int main(int argc, char **argv) {
    a.push_back("ejp mysljylc kd kxveddknmc re jsicpdrysi");
    a.push_back("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd");
    a.push_back("de kr kd eoya kw aej tysr re ujdr lkgc jv");

    b.push_back("our language is impossible to understand");
	b.push_back("there are twenty six factorial possibilities");
	b.push_back("so it is okay if you want to just give up");

    memset(mp,0,sizeof(mp));

	mp['z'-'a'] = 'q';
	mp['q'-'a'] = 'z';
	imp['q'-'a'] = 'z';
	imp['z'-'a'] = 'q';

    for (int i = 0; i < a.size(); i++)
    {
      for (int j = 0; j < a[i].size(); j++) 
      {
        if (a[i][j] != ' ') {
          mp[a[i][j]-'a'] = b[i][j];
          imp[b[i][j]-'a'] = a[i][j]; 
        }
      }
    }

    for (int i = 0; i < 26; i++) {
      if (mp[i] == 0) {
        printf("Missing %c\n", (char)(i+'a')); 
      }
      if (imp[i] == 0) {
        printf("IMissing %c\n", (char)(i+'a')); 
      }

    }
	int nC;
	gets(buf);
    sscanf(buf,"%i", &nC);
	for (int cs = 0; cs < nC; cs++) 
    {
      gets(buf);
      for (int i = 0; i < strlen(buf); i++) {
        if ((buf[i] >= 'a') && (buf[i] <= 'z')) {
          buf[i] = mp[buf[i]-'a'];
        }
      } 
      printf("Case #%i: %s\n", cs + 1, buf);     
    }
}
