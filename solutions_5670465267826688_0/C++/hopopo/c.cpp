#include<iostream>

using namespace std;

long long char2num[128];

inline long long times(long long a, long long b){
	long long ans = 1;
	if(a < 0){
		a = -a;
		ans *= -1;
	}
	if(b < 0){
		b = -b;
		ans *= -1;
	}

	static long long map[5][5] = {
		{0,  0,  0,  0,  0},
		{0,  1,  2,  3,  4},
		{0,  2, -1,  4, -3},
		{0,  3, -4, -1,  2},
		{0,  4,  3, -2, -1},
	};

	return ans * map[a][b];

}

bool find(const string& str, long long len, long long &i, long long &j, long long goal){
	long long start_i = i;
	long long ans = 1;


	for(; i < len; ++i){
		if(i > start_i) j = 0;
		for(; j < str.length(); ++j){
			ans = times(ans, char2num[str[j]]);
			if(ans == goal){
				++j;
				return true;
			} 
		}

		if(i - start_i > 4) return false;
	}

	return false;
}

bool is1(const string& str, long long len, long long i, long long j){
	long long ans = 1;
	for(; j < str.length(); ++j){
		ans = times(ans, char2num[str[j]]);
	}

	long long base = 1;
	for(long long j = 0; j < str.length(); ++j)
		base = times(base, char2num[str[j]]);


	long long p = len - i - 1;

	for(; p != 0; p >>= 1, base = times(base, base)){
		if(p & 1){
			ans = times(ans, base);
		}
	}

	return ans == 1;
}



int main(){
	long long cases;

	char2num['i'] = 2;
	char2num['j'] = 3;
	char2num['k'] = 4;

	cin >> cases;


	for(long long c = 1; c <= cases; ++c){
		long long t, l;
		string str;

		cin >> t >> l;
		cin >> str;
		long long i = 0, j = 0;

		bool okay = true;
		
		if(okay) okay = find(str, l, i, j, 2);
		if(okay) okay = find(str, l, i, j, 3);
		if(okay) okay = find(str, l, i, j, 4);
		if(okay) okay = is1(str, l, i, j);

		cout << "Case #" << c << ": " << (okay?"YES": "NO") << endl;
	}

	return 0;
}
