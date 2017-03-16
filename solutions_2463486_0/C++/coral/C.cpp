#include <stdio.h>
#include <string.h>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 200;
struct bign{
  int len, s[maxn];
  bign() {
    memset(s, 0, sizeof(s));
    len = 1;
  }
  bign(int num) {
    *this = num;
  }
  bign(const char* num) {
    *this = num;
  }
  bign operator = (int num) {
    char s[maxn];
    sprintf(s, "%d", num);
    *this = s;
    return *this;
  }
  bign operator = (const char* num) {
    len = strlen(num);
    for(int i = 0; i < len; i++) s[i] = num[len-i-1] - '0';
    return *this;
  }
  string str() const {
    string res = "";
    for(int i = 0; i < len; i++) res = (char)(s[i] + '0') + res;
    if(res == "") res = "0";
    return res;
  }
  int judge () const {
	for ( int i = 0; i < len / 2; ++i ) if ( s[i] != s[len - i - 1] ) return 0;
	return 1;
  }
  bign operator + (const bign& b) const{
    bign c;
    c.len = 0;
    for(int i = 0, g = 0; g || i < max(len, b.len); i++) {
      int x = g;
      if(i < len) x += s[i];
      if(i < b.len) x += b.s[i];
      c.s[c.len++] = x % 10;
      g = x / 10;
    }
    return c;
  }
  void clean() {
    while(len > 1 && !s[len-1]) len--;
  }
  bign operator * (const bign& b) {
    bign c; c.len = len + b.len;
    for(int i = 0; i < len; i++)
      for(int j = 0; j < b.len; j++)
        c.s[i+j] += s[i] * b.s[j];
    for(int i = 0; i < c.len-1; i++){
      c.s[i+1] += c.s[i] / 10;
      c.s[i] %= 10;
    }
    c.clean();
    return c;
  }
  bign operator += (const bign& b) {
    *this = *this + b;
    return *this;
  }
	bool operator < (const bign& b) const{
		if(len != b.len) return len < b.len;
		for(int i = len-1; i >= 0; i--)
		  if(s[i] != b.s[i]) return s[i] < b.s[i];
		return false;
	}
};
istream& operator >> (istream &in, bign& x) {
  string s;
  in >> s;
  x = s.c_str();
  return in;
}
ostream& operator << (ostream &out, const bign& x) {
  out << x.str();
  return out;
}
map < bign, int > mymap;
vector < bign > v;
void init ( ) {
	bign X = 1000;
	for ( bign i = 1; i < X * X; i += 1 ) if ( i.judge ( ) ) {
		//cout << i<< " ";
		mymap[i] = 1;
	}
	for ( bign i = 1; i * i < X; i += 1 ) if ( mymap[i] && mymap[i*i] ) v.push_back ( i * i );
}
int main ( ) {
	init ( );
	//for ( int i = 0; i < v.size ( ); ++i ) cout << v[i] << " ";
	int T;
	bign a, b;
	scanf ( "%d", &T );
	for ( int i = 1; i <= T; ++i ) {
		printf ( "Case #%d: ", i );
		cin >> a >> b;
		//printf ( "%d", upper_bound ( v.begin (),v.end(),(bign)b) -v.begin());
		cout<< ( "%d", upper_bound ( v.begin ( ), v.end ( ), b ) - lower_bound ( v.begin ( ), v.end ( ), a ) ) << "\n";
	}
}
