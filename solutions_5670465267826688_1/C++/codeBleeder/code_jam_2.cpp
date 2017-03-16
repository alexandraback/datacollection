#include <bits/stdc++.h>

typedef long long int li;

#define min(a,b) a<=b?a:b
#define max(a,b) a>=b?a:b
#define Fi(i, st, ft) for(i = st;i <= ft; ++i)
#define Fd(i, st, ft) for(i = st;i >= ft; --i)
#define pb(a, b) a.push_back(b)
#define mod 1000000007
#define MAXN 1500000
#define MX 1450000
#define inf 1000000000000000000ll
const int maxBufSize = (10000000);

using namespace std;

li t , l , x;
string str , s;
map< pair<char , char> , pair<li , char> > M;

int main()
{
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	li i , j , k , a , b , c , chk1 , chk2 , chk3 , cnt , sz , rem;
	pair<char , char> p , pf;
	pair<li , char> q , qf , q1 , q2 , q3 , qf1 , qf2 , qf3 , r;
	
	p.first = '1' , p.second = '1' , M[p].first = 1 , M[p].second = '1';
	p.first = '1' , p.second = 'i' , M[p].first = 1 , M[p].second = 'i';
	p.first = '1' , p.second = 'j' , M[p].first = 1 , M[p].second = 'j';
	p.first = '1' , p.second = 'k' , M[p].first = 1 , M[p].second = 'k';
	
	p.first = 'i' , p.second = '1' , M[p].first = 1 , M[p].second = 'i';
	p.first = 'i' , p.second = 'i' , M[p].first = -1 , M[p].second = '1';
	p.first = 'i' , p.second = 'j' , M[p].first = 1 , M[p].second = 'k';
	p.first = 'i' , p.second = 'k' , M[p].first = -1 , M[p].second = 'j';
	
	p.first = 'j' , p.second = '1' , M[p].first = 1 , M[p].second = 'j';
	p.first = 'j' , p.second = 'i' , M[p].first = -1 , M[p].second = 'k';
	p.first = 'j' , p.second = 'j' , M[p].first = -1 , M[p].second = '1';
	p.first = 'j' , p.second = 'k' , M[p].first = 1 , M[p].second = 'i';
	
	p.first = 'k' , p.second = '1' , M[p].first = 1 , M[p].second = 'k';
	p.first = 'k' , p.second = 'i' , M[p].first = 1 , M[p].second = 'j';
	p.first = 'k' , p.second = 'j' , M[p].first = -1 , M[p].second = 'i';
	p.first = 'k' , p.second = 'k' , M[p].first = -1 , M[p].second = '1';
	
	cin >> t;
	Fi(k , 1 , t) {
		cin >> l >> x;
		cin >> s;
		str = "";
		sz = 0;
		Fi(i , 1 , x) {
			str += s;
			sz += l;
			if(sz > 1000000ll) {
				break;
			}
		}
		cnt = sz/l;
		rem = x-cnt;
		li len = str.length();
		if(len >= 3) {
			chk1 = chk2 = chk3 = 0;
			qf1.first = 1 , qf1.second = '0';
			qf2.first = 1 , qf2.second = '0';
			qf3.first = 1 , qf3.second = '0';
			Fi(i , 0 , len-1) {
				if(qf1.second == 'i') {
					chk1 = 1;
				}
				if(qf2.second == 'j') {
					chk2 = 1;
				}
				if(chk1 == 0) {
					if(qf1.second == '0') {
						qf1.first = 1 , qf1.second = str[i];
						q1 = qf1;
					} else {
						p.first = q1.second , p.second = str[i];
						qf1 = M[p];
						qf1.first = qf1.first*q1.first;
						q1 = qf1;
					}
				}
				if(chk2 == 0 && chk1 == 1) {
					if(qf2.second == '0') {
						qf2.first = 1 , qf2.second = str[i];
						q2 = qf2;
					//	cout << i << " " << qf1.first << " " << qf1.second << "\n";
					} else {
						p.first = q2.second , p.second = str[i];
						qf2 = M[p];
						qf2.first = qf2.first*q2.first;
						q2 = qf2;
					}
				}
				if(chk3 == 0 && chk1 == 1 && chk2 == 1) {
					if(qf3.second == '0') {
						qf3.first = 1 , qf3.second = str[i];
						q3 = qf3;
					//	cout << i << " " << qf2.first << " " << qf2.second << "\n";
					} else {
						p.first = q3.second , p.second = str[i];
						qf3 = M[p];
						qf3.first = qf3.first*q3.first;
						q3 = qf3;
					}
				}
				//cout << qf1.first << " " << qf2.first << " " << qf3.first << "\n";
				
			}
			//cout << qf1.first << " " << qf2.first << " " << qf3.first << "\n";
			//cout << qf1.second << " " << qf2.second << " " << qf3.second << "\n";
			
			if(rem > 0) {
				q.first = 1 , q.second = s[0];
				qf = q;
				Fi(i , 1 , l-1) {
					p.first = q.second , p.second = s[i];
					qf = M[p];
					qf.first = qf.first*q.first;
					q = qf;
				}
				if(rem%4 == 0) {
					qf.first = 1 , qf.second = '1';
				} else if(rem%4 == 2) {
					qf.first = -1 , qf.second = '1';
				} else if(rem%4 == 3) {
					qf.first = -1*qf.first;
				}
				p.first = qf3.second , p.second = qf.second;
				r = M[p];
				qf3.first = qf3.first*r.first*qf.first;
				qf3.second = r.second;
				
			}
			
			a = qf1.first * qf2.first * qf3.first;
			
			if((qf1.second == 'i') && (qf2.second == 'j') && (qf3.second == 'k') && (a == 1)) {
				printf("Case #%lld: YES\n" , k);
			} else {
				printf("Case #%lld: NO\n" , k);
			}
		} else {
			printf("Case #%lld: NO\n" , k);
		}
	}
	return 0;	
}
