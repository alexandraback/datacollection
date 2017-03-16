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

typedef struct t { int a; bool operator<(const t &cpy) const { return a < cpy.a; } } t; //usefull with sort and sets
typedef struct cmp { bool operator()(const int& a, const int& b) const { return a > b; } } cmp; //usefull with priority queues

template<typename F,typename S> ostream& operator<<(ostream &s, pair<F,S> t) { return s<<"("<<t.fi<<","<<t.se<<")"; } //print pair
template<typename T> ostream& operator<<(ostream &s, vector<T> t){ //print vector
	for(int i = 0, sz = t.size(); i < sz; i++) s << t[i] <<" ";return s; }


int main()
{
	IOS
	int table[200], tableO[200], vec[10];
	int T;
	string S;

	cin >> T;
	for(int c = 1; c <= T ; c++) {
		cin >> S;
		memset(tableO, 0, sizeof tableO);
		for(int i = 0; S[i] != '\0'; i++)
			tableO[S[i]]++;

		int priority[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		int minimo, finish;
		
		do {
			for(int i = 0; i < 200; i++)
				table[i] = tableO[i];

			for(int i = 0; i < 10; i++) {
				if(priority[i] == 0) {
					minimo = min(min(min(table['Z'], table['E']), table['R']), table['O']);
					table['Z'] -= minimo; table['E'] -= minimo; table['R'] -= minimo; table['O'] -= minimo;
					vec[0] = minimo;
				} else if(priority[i] == 1) {
					minimo = min(min(table['O'], table['N']), table['E']);
					table['O'] -= minimo; table['N'] -= minimo; table['E'] -= minimo;
					vec[1] = minimo;
				} else if(priority[i] == 2) {
					minimo = min(min(table['T'], table['W']), table['O']);
					table['T'] -= minimo; table['W'] -= minimo; table['O'] -= minimo;
					vec[2] = minimo;
				} else if(priority[i] == 3) {
					minimo = min(min(min(table['T'], table['H']), table['R']), table['E']/2);
					table['T'] -= minimo; table['H'] -= minimo; table['R'] -= minimo; table['E'] -= minimo*2;
					vec[3] = minimo;
				} else if(priority[i] == 4) {
					minimo = min(min(min(table['F'], table['O']), table['U']), table['R']);
					table['F'] -= minimo; table['O'] -= minimo; table['U'] -= minimo; table['R'] -= minimo;
					vec[4] = minimo;
				} else if(priority[i] == 5) {
					minimo = min(min(min(table['F'], table['I']), table['V']), table['E']);
					table['F'] -= minimo; table['I'] -= minimo; table['V'] -= minimo; table['E'] -= minimo;
					vec[5] = minimo;
				} else if(priority[i] == 6) {
					minimo = min(min(table['S'], table['I']), table['X']);
					table['S'] -= minimo; table['I'] -= minimo; table['X'] -= minimo;
					vec[6] = minimo;
				} else if(priority[i] == 7) {
					minimo = min(min(min(table['S'], table['E']/2), table['V']), table['N']);
					table['S'] -= minimo; table['E'] -= minimo*2; table['V'] -= minimo; table['N'] -= minimo;
					vec[7] = minimo;
				} else if(priority[i] == 8) {
					minimo = min(min(min(min(table['E'], table['I']), table['G']), table['H']), table['T']);
					table['E'] -= minimo; table['I'] -= minimo; table['G'] -= minimo; table['H'] -= minimo; table['T'] -= minimo;
					vec[8] = minimo;
				} else {
					minimo = min(min(table['N']/2, table['I']), table['E']);
					table['N'] -= minimo*2; table['I'] -= minimo; table['E'] -= minimo;
					vec[9] = minimo;
				}
			}

			finish = 1;
			for(int i = 0; i < 200; i++)
				if(table[i] != 0)
					finish = 0;
			if(finish) break;
			
		} while(next_permutation(priority, priority+10));

		cout << "Case #" << c << ": ";
		for(int i = 0; i < 10; i++)
			for(int j = 0; j < vec[i]; j++)
				cout << i;
		cout << endl;
	}

	return 0;
}