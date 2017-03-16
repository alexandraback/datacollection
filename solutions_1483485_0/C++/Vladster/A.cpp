#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <set>
#include <map>
#include <cmath>

using namespace std;

#define INP_FILE "A-small-attempt1.in"
#define OUT_FILE "output.txt"

#define rp(i,n) for(int (i)=0;(i)<(n);++(i))
#define pb push_back
#define L(s) (int)s.size()
#define mp make_pair
#define pii pair<int,int>
#define x first 
#define y second
#define inf 1000000000
#define VI vector<int>
#define ll long long
#define all(s) (s).begin(),(s).end()
#define C(u) memset((u),0,sizeof((u)))
#define ull unsigned ll
#define uint unsigned int

char decode[300];

void precalc() {
  string eng_text[] = {
    "our language is impossible to understand",
    "there are twenty six factorial possibilities",
    "so it is okay if you want to just give up"
  };
  string ggl_text[] = {
    "ejp mysljylc kd kxveddknmc re jsicpdrysi",
    "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
    "de kr kd eoya kw aej tysr re ujdr lkgc jv"
  };

  for(int i = 0; i < 3; ++i) {
    for(int j = 0; j < L(ggl_text[i]); ++j) {
      decode[ggl_text[i][j]] = eng_text[i][j];
    }
  }
  decode['q']='z';
  decode['z']='q';
}

int main()
{
	freopen( INP_FILE , "r" , stdin );
	freopen( OUT_FILE , "w" , stdout );
	int tstCnt;
	cin>>tstCnt;
  string line;
  getline(cin,line);

  precalc();

	for(int tst=1;tst<=tstCnt;tst++)
	{
    getline(cin,line);
    for(int i = 0; i < L(line); ++i) {
        line[i] = decode[line[i]];
    }
    printf("Case #%d: %s\n",tst,line.c_str());
	}
	
	return 0;
}