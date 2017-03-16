#include<bits/stdc++.h>

using namespace std;

long long calc( string a ) {
	long long ret = 0;
	for( int i = 0 ; i < a.length() ; i++ )
		ret = ret*10+a[i]-'0';
	return ret;
}

long long sub( string a , string b ) {
	return abs( calc( a )-calc( b ) );
}

vector < pair < long long , string > > ans;
string c , j;
int test;

int main() {
	cin >> test;
	for( int ca = 1 ; ca <= test ; ca++ ) {
		ans.clear();
		cin >> c >> j;
		string cc = c , jj = j;
		cout << "Case #" << ca << ": ";
		int len = c.length() , pos = -1;
		for( int i = 0 ; i < len ; i++ )
			if( c[i] != '?' && j[i] != '?' && c[i] != j[i] ) {
				pos = i;
				break;
			}
		if( pos == -1 ) {
			for( int i = 0 ; i < len ; i++ )
				if( c[i] == '?' ) {
					if( j[i] == '?' )
						c[i] = '0';
					else
						c[i] = j[i];
				}
			cout << c << " " << c << endl;
			continue;
		}
		else {
			if( c[pos] > j[pos] ) {
				for( int i = 0 ; i < pos ; i++ ) {
					if( c[i] == '?' ) {
						if( j[i] == '?' )
							c[i] = '0';
						else
							c[i] = j[i];
					}
					j[i] = c[i];
				}
				for( int i = pos+1 ; i < len ; i++ )
					if( c[i] == '?' )
						c[i] = '0';
				for( int i = pos+1 ; i < len ; i++ )
					if( j[i] == '?' )
						j[i] = '9';
				ans.push_back( make_pair( sub( c , j ) , c+" "+j ) );
			}
			else {
				int temp = pos;
				temp--;
				while( temp >= 0 ) {
					if( c[temp] == '?' && j[temp] == '?' ) {
						break;
					}
					if( c[temp] == '?' ) {
						if( j[temp] != '9' ) {
							break;
						}
					}
					else if( j[temp] == '?' ) {
						if( c[temp] != '0' ) {
							break;
						}
					}
					temp--;
				}
				while( temp >= 0 ) {
					c = cc;
					j = jj;
					for( int i = 0 ; i < temp ; i++ ) {
						if( c[i] == '?' ) {
							if( j[i] == '?' )
								c[i] = j[i] = '0';
							else
								c[i] = j[i];
						}
						j[i] = c[i];
					}
					if( c[temp] == '?' && j[temp] == '?' ) {
						c[temp] = '1';
						j[temp] = '0';
					}
					else if( c[temp] == '?' ) {
						if( j[temp] != '9' ) {
							c[temp] = j[temp]+1;
						}
						else {
							temp--;
							continue;
						}
					}
					else if( j[temp] == '?' ) {
						if( c[temp] != '0' ) {
							j[temp] = c[temp]-1;
						}
						else {
							temp--;
							continue;
						}
					}
					for( int i = temp+1 ; i < len ; i++ ) {
						if( c[i] == '?' )
							c[i] = '0';
						if( j[i] == '?' )
							j[i] = '9';
					}
					ans.push_back( make_pair( sub( c , j ) , c+" "+j ) );
					temp--;
				}
			}
			c = cc;
			j = jj;
			if( c[pos] < j[pos] ) {
				for( int i = 0 ; i < pos ; i++ ) {
					if( c[i] == '?' ) {
						if( j[i] == '?' )
							c[i] = '0';
						else
							c[i] = j[i];
					}
					j[i] = c[i];
				}
				for( int i = pos+1 ; i < len ; i++ )
					if( c[i] == '?' )
						c[i] = '9';
				for( int i = pos+1 ; i < len ; i++ )
					if( j[i] == '?' )
						j[i] = '0';
				ans.push_back( make_pair( sub( c , j ) , c+" "+j ) );
			}
			else {
				int temp = pos;
				temp--;
				while( temp >= 0 ) {
					if( c[temp] == '?' && j[temp] == '?' ) {
						break;
					}
					if( c[temp] == '?' ) {
						if( j[temp] != '0' ) {
							break;
						}
					}
					else if( j[temp] == '?' ) {
						if( c[temp] != '9' ) {
							break;
						}
					}
					temp--;
				}
				while( temp >= 0 ) {
					c = cc;
					j = jj;
					for( int i = 0 ; i < temp ; i++ ) {
						if( c[i] == '?' ) {
							if( j[i] == '?' )
								c[i] = j[i] = '0';
							else
								c[i] = j[i];
						}
						j[i] = c[i];
					}
					if( c[temp] == '?' && j[temp] == '?' ) {
						c[temp] = '0';
						j[temp] = '1';
					}
					else if( c[temp] == '?' ) {
						if( j[temp] != '0' ) {
							c[temp] = j[temp]-1;
						}
						else {
							temp--;
							continue;
						}
					}
					else if( j[temp] == '?' ) {
						if( c[temp] != '9' ) {
							j[temp] = c[temp]+1;
						}
						else {
							temp--;
							continue;
						}
					}
					for( int i = temp+1 ; i < len ; i++ ) {
						if( c[i] == '?' )
							c[i] = '9';
						if( j[i] == '?' )
							j[i] = '0';
					}
					ans.push_back( make_pair( sub( c , j ) , c+" "+j ) );
					temp--;
				}
			}
		}
		sort( ans.begin() , ans.end() );
		cout << ans.begin()->second << endl;
	}
	return 0;
}
