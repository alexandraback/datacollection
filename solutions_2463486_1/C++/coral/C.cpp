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
map < bign, bign > m;
vector < bign > v;
vector < string > num[105];
const int X = 15;
void init ( ) {
	int i, j, too_long = 0;
    string s, tmp;
	bign big, bb;
    s = "0"; num[1].push_back ( s );
    s = "1"; num[1].push_back ( s );
    s = "2"; num[1].push_back ( s );
	s = "00"; num[2].push_back ( s ); 
    s = "11"; num[2].push_back ( s );
    s = "22"; num[2].push_back ( s );
	v.push_back ( 1 ); v.push_back ( 4 ); v.push_back ( 9 ); v.push_back ( 121 ); v.push_back ( 484 );
    for ( i = 3; i < X && !too_long; ++i ) {
        for ( j = 0; j < num[i-2].size ( ) && !too_long; ++j ) {
			if( num[i-2][j].length ( ) > X ) {
				too_long = 1;
				break;
			}
            tmp = num[i-2][j];
			tmp = "0" + tmp + "0";
            num[i].push_back ( tmp );

            tmp = num[i-2][j];
			tmp = "1" + tmp + "1";
			big = tmp.c_str ( );
			bb = big * big;
			if ( bb.judge ( ) ) v.push_back ( bb );
            num[i].push_back ( tmp );

            tmp = num[i-2][j];
			tmp = "2" + tmp + "2";
			big = tmp.c_str ( );
			bb = big * big;
			if ( bb.judge ( ) ) v.push_back ( bb );
            num[i].push_back ( tmp );
			if ( bb.len > X ) {
				too_long = 1;
				break;
			}
			cout << v.back ( ) << "\t" <<v.size ( ) <<"\tbb.len=" << bb.len<< "\tj=" << j << "\n";
        }
    }
}
int main ( ) {
	init ( );
	sort ( v.begin ( ), v.end ( ) );
	for ( int i = 0; i < v.size ( ); ++i ) cout << v[i] << "\n";
	int T;
	bign a, b;
	scanf ( "%d", &T );
	for ( int i = 1; i <= T; ++i ) {
		printf ( "Case #%d: ", i );
		cin >> a >> b;
		cout<< ( "%d", upper_bound ( v.begin ( ), v.end ( ), b ) - lower_bound ( v.begin ( ), v.end ( ), a ) ) << "\n";
	}
}
