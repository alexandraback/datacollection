#pragma comment(linker, "/STACK:66777216")

#include <cstdio>
#pragma warning(disable : 4996)
#include <algorithm>
#include <array>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <utility>
#include <functional>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cassert>
#include <queue>
#include <cmath>
#include <random>
#include <sstream>
#include <numeric>
#include <limits>
#include <chrono>
#include <type_traits>
#pragma hdrstop

#ifdef _MSC_VER
#include <intrin.h>


#define popcount(a) __popcnt(a)


#else
#define LLD "%lld"
#define LLU "%llu"
#define popcount(a) __builtin_popcount(a)
#define clz(a) __builtin_clz(a)
#define ctz(a) __builtin_ctz(a)
#endif


template<class T> 
inline bool umax(T& a, const T& b) {
	return (a < b ? a = b, true : false);
}


#ifdef _MSC_VER


#endif


inline uint32_t abs(const uint32_t x) {
	return x;
}


inline bool is_digit(const char ch) {
	return (ch >= '0' && ch <= '9');
}


class IO {
public:
	
	constexpr static const std::size_t kBufferSize = 1 << 18;

	IO() : read_bytes_count_(0), read_buffer_offset_(0), current_char_(0), eof_(false) {
		static_assert(kBufferSize > 32, "Size of a buffer must be greater than 32 due to comparison in IO::flush() method.");
	}

	~IO() {
		flush();
	}

	IO(const IO&) = delete;
	IO& operator=(const IO&) = delete;
	IO(const IO&&) = delete;
	IO& operator=(const IO&&) = delete;

	
	inline void shift_char();
	
	
	inline int32_t next_int();
	
	
	IO& operator >>(int32_t& x);
	
	
	inline void flush();
	inline void new_line();

	inline void print_int(const int32_t x);
	inline void print_uint(const uint32_t x);
	
	
	inline void print_string(const char* s);
	//inline void print_string(const std::string& s);
	
	//inline void print_line(const std::string& s);

	IO& operator <<(const int32_t x);
	IO& operator <<(const uint32_t x);
	
	
	IO& operator <<(const char* s);
	

	// Intended to use with std::endl.
	IO& operator <<(std::ostream& (*)(std::ostream&));

	
	static void assign_files_input_txt();

private:
	using Buffer = std::array<char, kBufferSize>;
	Buffer read_buffer_;
	Buffer write_buffer_;
	std::size_t read_bytes_count_;
	std::size_t read_buffer_offset_;
	std::size_t write_buffer_offset_;
	bool eof_;
	char current_char_;

	inline void update_buffer();

	template<typename T>
	T read_number();

	template<typename T>
	void print_number(const T& value);

};

extern bool useFastIO;
extern std::istream * pin;
extern std::ostream * pout;
extern IO io;

inline int32_t next_int();


inline void new_line();

inline void print_int(const int32_t x);
inline void print_uint(const uint32_t x);


inline void print_string(const char* s);
//inline void print_string(const std::string& s);

//inline void print_line(const std::string& s);


using namespace std;

int __;
IO io;


struct Outfit {
	int jacket, pants, shirt;

	
	Outfit(int j, int p, int s) : jacket(j), pants(p), shirt(s) {}

	bool operator < (const Outfit& rhs) const {
		return	jacket < rhs.jacket
			|| (jacket == rhs.jacket && pants < rhs.pants)
			|| (jacket == rhs.jacket && pants == rhs.pants && shirt < rhs.shirt);
	}

};

bool not_full(std::map<Outfit, int>& cnt, const int j, const int p, const int s, const int K) {
	int& x = cnt[{j, p, 0}];
	int& y = cnt[{j, 0, s}];
	int& z = cnt[{0, p, s}];
	if (x >= K || y >= K || z >= K) {
		return false;
	}
	++x;
	++y;
	++z;
	return true;
}

void gen_stupid(std::vector<Outfit>& a, const int J, const int P, const int S, const int K) {
	map<Outfit, int> cnt;
	for (int j = 1; j <= J; ++j) {
		for (int p = 1; p <= P; ++p) {
			for (int s = 1; s <= S; ++s) {
				if (j == p && j == s) {
					continue;
				}
				if (not_full(cnt, j, p, s, K)) {
					a.emplace_back(j, p, s);
				}
			}
		}
	}
	for (int i = 1; i <= J; ++i) {
		if (not_full(cnt, i, i, i, K)) {
			a.emplace_back(i, i, i);
		}
	}
}

void gen_all(std::vector<Outfit>& a, int J, int P, int S) {
	for (int i = 1; i <= J; ++i) {
		for (int j = 1; j <= P; ++j) {
			for (int k = 1; k <= S; ++k) {
				a.emplace_back(i, j, k);
			}
		}
	}
}

void solve(istream& ins, ostream& out) {
	io.assign_files_input_txt();
	io >> __;
	for (int _ = 1; _ <= __; ++_) {
		cerr << _ << endl;
		io << "Case #" << _ << ": ";
		int j, p, s, k;
		io >> j >> p >> s >> k;
		vector<Outfit> a;
		gen_stupid(a, j, p, s, k);
		io << a.size() << endl;
		for (const auto& it : a) {
			io << it.jacket << " " << it.pants << " " << it.shirt << endl;
		}
		continue;
		gen_all(a, j, p, s);
		if (j == 3) {
			io << 0 << endl;
			continue;
		}
		size_t ans = 0;
		size_t best_mask = 0;
		for (size_t mask = 0; mask < (1 << a.size()); ++mask) {
			map<Outfit, int> cnt;
			for (size_t i = 0; i < a.size(); ++i) {
				if (mask & (1 << i)) {
					const auto& cur = a[i];
					cnt[{cur.jacket, cur.pants, 0}] += 1;
					cnt[{cur.jacket, 0, cur.shirt}] += 1;
					cnt[{0, cur.pants, cur.shirt}] += 1;
				}
			}
			bool ok = true;
			for (const auto& it : cnt) {
				ok &= it.second <= k;
			}
			if (ok && umax(ans, popcount(mask))) {
				best_mask = mask;
			}
		}
		io << ans << endl;
		for (size_t i = 0; i < a.size(); ++i) {
			if (best_mask & (1 << i)) {
				const auto& cur = a[i];
				// io << cur.jacket << " " << cur.pants << " " << cur.shirt << endl;
			}
		}
	}
}


#include <fstream>


extern class IO io;
bool useFastIO = false;
istream * pin;
ostream * pout;


int main() {
    srand(time(NULL));
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    istream& in = cin;
    useFastIO = true;


    ostream& out = cout;

    out << fixed << setprecision(16);
    pin = &in; pout = &out;
    solve(in, out);
    return 0;
}


template<typename T>
T IO::read_number() {
	bool is_negative = false;
	while (!eof_ && !is_digit(current_char_) && (std::is_unsigned<T>() || current_char_ != '-')) {
		shift_char();
	}
	if (std::is_signed<T>() && current_char_ == '-') {
		is_negative = true;
		shift_char();
	}
	T result = 0;
	while (!eof_ && is_digit(current_char_)) {
		result = (result << 3) + (result << 1) + current_char_ - '0';
		shift_char();
	}
	return (is_negative ? result * -1 : result);
}

template<typename T>
void IO::print_number(const T& value) {
	T current_value = value;
	if (write_buffer_offset_ + 32 > kBufferSize) {
		flush();
	}
	if (current_value < 0) {
		write_buffer_[write_buffer_offset_++] = '-';
		current_value = abs(current_value);
	} else
	if (current_value == 0) {
		write_buffer_[write_buffer_offset_++] = '0';
		return;
	}
	std::size_t start_index = write_buffer_offset_;
	while (current_value != 0) {
		write_buffer_[write_buffer_offset_++] = current_value % 10 + '0';
		current_value /= 10;
	}
	std::reverse(write_buffer_.begin() + start_index, write_buffer_.begin() + write_buffer_offset_);
}


inline void IO::update_buffer() {
	if (read_buffer_offset_ == read_bytes_count_) {
		read_bytes_count_ = fread(&read_buffer_[0], sizeof(read_buffer_[0]), read_buffer_.size(), stdin);
		if (read_bytes_count_ == 0) {
			eof_ = true;
			return;
		}
		read_buffer_offset_ = 0;
	}
}

inline void IO::shift_char() {
	update_buffer();
	current_char_ = read_buffer_[read_buffer_offset_++];
}

inline int32_t IO::next_int() {
	return read_number<int32_t>();
}


IO& IO::operator >>(int32_t& x) {
	x = ::next_int();
	return *this;
}


void IO::assign_files_input_txt() {
	if (useFastIO) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
}

inline void IO::flush() {
	fwrite(&write_buffer_[0], sizeof(write_buffer_[0]), write_buffer_offset_, stdout);
	write_buffer_offset_ = 0;
}

inline void IO::new_line() {
	if (write_buffer_offset_ == kBufferSize) {
		flush();
	}
	write_buffer_[write_buffer_offset_++] = '\n';
}

inline void IO::print_int(const int32_t x) {
	print_number(x);
}

inline void IO::print_uint(const uint32_t x) {
	print_number(x);
}


inline void IO::print_string(const char* s) {
	for (std::size_t i = 0; s[i] != '\0'; ++i) {
		if (write_buffer_offset_ == kBufferSize) {
			flush();
		}
		write_buffer_[write_buffer_offset_++] = s[i];
	}
}


IO& IO::operator <<(const int32_t x) {
	::print_int(x);
	return *this;
}

IO& IO::operator <<(const uint32_t x) {
	::print_uint(x);
	return *this;
}


IO& IO::operator <<(const char* s) {
	::print_string(s);
	return *this;
}


IO& IO::operator <<(std::ostream& (*)(std::ostream&)) {
	::new_line();
	return *this;
}

inline int32_t next_int() {
	if (useFastIO) {
		return io.next_int();
	}
	int32_t ret;
	*pin >> ret;
	return ret;
}


inline void new_line() {
	if (useFastIO) {
		io.new_line();
		return;
	}
	*pout << std::endl;
}

inline void print_int(const int32_t x) {
	if (useFastIO) {
		io.print_int(x);
		return;
	}
	*pout << x;
}

inline void print_uint(const uint32_t x) {
	if (useFastIO) {
		io.print_uint(x);
		return;
	}
	*pout << x;
}


inline void print_string(const char* s) {
	if (useFastIO) {
		io.print_string(s);
		return;
	}
	*pout << s;
}


