#include <bits/stdc++.h>

#define digits(num) (num == 0 ? 0 : (int)((log(abs(num))/log(10))+1))
#define first_bit_index(num) (num == 0 ? 0 : __builtin_ctz(abs(num))) // count trailing zeros (e.g: 8 1000, so ans: 4)
#define last_bit_index(num) (num == 0 ? 0 : __builtin_clz(abs(num))) // count leading zeros (e.g: 8 0x27 1000, so ans: 28)
#define check_bit(num, bit) ((num & 1 << bit) != 0)
#define num_bits(num) __builtin_popcount(num) //count 1 bits
#define get_low_bit(x) ((x)&((x)^((x)-1))) //get the lowest bit of x
#define set_bit(num, bit) num |= (1 << bit);
#define reset_bit(num, bit) num &= ~(1 << bit);
#define flip_bit(num, bit) num ^= (1 << bit);
#define fi first
#define se second
#define IOS ios_base::sync_with_stdio(0); 
#define therms(type, func) type, vector<type>, func //usefull with priority queues
#define in(a,b) ( (b).find(a) != (b).end())
#define EPS 1e-9
#define is_pow2(num) (int)(num && !(num & (num - 1)))

using namespace std;

typedef long long int ll;
typedef struct t { int a; bool operator<(const t &cpy) const { return a < cpy.a; } } t; //usefull with sort and sets
typedef struct cmp { bool operator()(const int& a, const int& b) const { return a > b; } } cmp; //usefull with priority queues

template<typename F,typename S> ostream& operator<<(ostream &s, pair<F,S> t) { return s<<"("<<t.fi<<","<<t.se<<")"; } //print pair
template<typename T> ostream& operator<<(ostream &s, vector<T> t){ //print vector
	for(int i = 0, sz = t.size(); i < sz; i++) s << t[i] <<" ";return s; }

ll pow(ll b, int e);
void diffstring(string ss, int end1, int end2);
ll stringtonumber(string s, int size);

int main()
{
	IOS
	int T;
	string s1, s2;
	cin >> T;

	for(int i = 0; i < T; i++) {
		cin >> s1 >> s2;
		cout << "Case #" << i+1 << ": ";
		string st = s1+s2;
		//cout << st << " " <<  s1.size() << " " << st.size() << endl;
		diffstring(st, s1.size(), st.size());
	}
	

	return 0;
}


void diffstring(string s, int end1, int size)
{
	int pos[1000];
	for(int i = 0; i < 1000; i++) pos[i] = -1;
	int t = 0;

	for(int i = 0; i < size; i++) if(s[i] == '?') pos[t++] = i;
	
	int i_cpy, t_cpy;
	int pow_10t = pow(10, t);
	ll diff, lower_diff = 9999999999;
	string lower_diff_str;
	for(int i = 0; i < pow_10t; i++){
		i_cpy = i;
		for(t_cpy = t-1; t_cpy >= 0; t_cpy--) {
			s[pos[t_cpy]] = i_cpy%10 + '0';
			i_cpy /= 10;
		}

		string s1 = s.substr(0, end1);
		string s2 = s.substr(end1, size-end1);
		diff = abs(stringtonumber(s1, s1.size()) - stringtonumber(s2, s2.size()));
		if(diff < lower_diff) {
			lower_diff = diff;
			lower_diff_str = s;
		}
		if(diff == 0) break;
	}

	cout << lower_diff_str.substr(0, end1) << " " << lower_diff_str.substr(end1, size-end1) << endl;
}

ll pow(ll b, int e) 
{
	ll bcpy = 1;
	for(int i = 0; i < e; i++)
		bcpy*=b;
	return bcpy;
	//return e == 0 ? 1 : b *= pow(b, e-1);
}

ll stringtonumber(string s, int size)
{
	ll n = 0, pot10 = 1;
	for(int i = size-1; i >= 0; i--) {
		n += (s[i]-'0')*pot10;
		pot10*=10;
	}

	return n;
}