#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct String
{
  char *str;
  String() { str=new char[1002]; }
  String& operator= (const String &S) { str=S.str; return *this; }
} S[10];

bool operator<(const String &a, const String &b)
{
  return strcmp(a.str+1, b.str+1) < 0;
}

bool perm_comp(const String &a, const String &b)
{
  return strcmp(a.str, b.str) < 0;
}

int main()
{
  int T;
  scanf("%d", &T);
  bool occur[26];
  for ( int t=1; t<=T; ++t ) {
    int N;
    scanf("%d", &N);
    for ( int i=0; i<N; ++i ) {
      char buf[1002];
      scanf("%s", buf);
      S[i].str[0] = char(i+1);
      char *ptr = S[i].str+1;
      char *ptr2 = buf;
      while ( *ptr2 ) {
	if ( ptr==S[i].str+1 || ptr[-1]!=*ptr2 ) {
	  *ptr++ = *ptr2;
	}
	++ptr2;
      }
      *ptr = '\0';
      //printf(">> %s\n", S[i].str+1);
    }

    sort(S, S+N, perm_comp);

    /*
    puts("--");
    for ( int i=0; i<N; ++i ) {
      printf(">> %s\n", S[i].str+1);
    }
    puts("==");
    */

    int valid_count = 0;
    do {
      char buf[1002], *ptr=buf, *ptr2;
      for ( int i=0; i<N; ++i ) {
	//printf("%s ", S[i].str+1);
	ptr2  = S[i].str+1;
	while ( *ptr++ = *ptr2++ );
	--ptr;
      }
      *ptr = '\0';
      //printf("==> %s\n", buf);

      char tmp[1002];
      ptr  = tmp;
      ptr2 = buf;
      while ( *ptr2 ) {
	if ( ptr==tmp || ptr[-1]!=*ptr2 ) {
	  *ptr++ = *ptr2;
	}
	++ptr2;
      }
      *ptr = '\0';
      //printf("### %s\n", buf);

      memset(occur, 0, sizeof(occur));
      ptr = tmp;
      bool valid = true;
      while ( *ptr ) {
	int ch = *ptr-'a';
	if ( occur[ch] ) { valid=false; break; }
	else occur[ch] = true;
	++ptr;
      }
      if ( valid ) {
	//printf("==> %s is valid.\n", tmp);
	++valid_count;
      }

    } while ( next_permutation(S, S+N, perm_comp));

    printf("Case #%d: %d\n", t, valid_count);
  }
}
