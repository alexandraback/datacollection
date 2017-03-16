#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
using namespace std;

//ifstream fin (".in");
ifstream fin ("C-small.in");
//ifstream fin ("C-large.in");
ofstream fout (".out");

const int INF = 0x3f3f3f3f;
set<string> dic;
int dist[64][64], maxlen, d[64];

int get_dist(string s) {
   if( dic.find(s)!=dic.end() ) return 0;
   for(int i=0; i<s.size(); i++) {
      char init = s[i];
      for(char c='a'; c<='z';c++) {
         s[i] = c;
         if( dic.find(s)!=dic.end() ) return 1;
      }
      s[i] = init;
   }

   if( s.size() > 5 ) {
      for(int i=0; i<s.size(); i++) {
         char init = s[i];
         for(char c='a'; c<='z';c++) {
            s[i] = c;
            for(int j=i+5; j<s.size(); j++) {
               char init2 = s[j];
               for(char c2='a'; c2<='z';c2++) {
                  s[j] = c;
                  if( dic.find(s)!=dic.end() ) return 2;
               }
               s[j] = init2;
            }
         }
         s[i] = init;
      }
   }

   return INF;
}

void solve() {
   string s;
   fin >> s;
   memset(dist, INF, sizeof(dist));

   for(int i=0; i<s.size()-1; i++)
   for(int j=1; j<=maxlen && i+j<=s.size(); j++) {
      dist[i][i+j-1] = get_dist(s.substr(i, j));
   }

   //for(int i=0; i<s.size(); i++) {
   //   cout << endl;
   //   for(int j=i+1; j<s.size(); j++)
   //      cout << dist[i][j] << " ";
   //}cout << endl;

   memset(d, INF, sizeof(d));
   for(int i=0; i<s.size(); i++)
      if( dist[0][i]!=INF ) 
         d[i] = dist[0][i];

   for(int i=1; i<s.size(); i++)
      if( d[i]!=INF )
      for(int j=i+2; j<s.size(); j++)
         if( dist[i+1][j]!=INF )
            d[j] = min(d[j], d[i] + dist[i+1][j]);

   //for(int i=0; i<s.size(); i++)
   //   cout << d[i] << " ";
   //cout << endl;
   fout << d[s.size()-1] << endl;
}

int main() {
   ifstream indic("garbled_email_dictionary.txt");
   string word;
   while( indic>>word ) {
      dic.insert(word);
      maxlen = max(maxlen, (int)word.size());
   }
   int N, N2 = 1;
	fin >> N;
	while( N2<=N ) {
      cout << N2;
      fout << "Case #" << N2++ << ": ";
      solve();
   }

	return 0;
}