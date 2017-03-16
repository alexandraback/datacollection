// cat input.in | ./a.out > output
#include <iostream>
#include <vector>
#include <unordered_map>

typedef long long myint;

template <typename T>
std::vector<T> read_vector(int length, std::istream& in = std::cin) {
	std::vector<T> vector;
	for(; length>0; length--) {
		T item;
		in >> item;
		vector.push_back(item);
	}
	return vector;
}


class outfit {
public:
	int j,p,s;
	outfit(int j, int p, int s) {
		this->j = j; this->p = p; this->s = s;
	}
	bool operator==(const outfit &other) const {
		return (j == other.j && p == other.p && s == other.s);
	}
};

class combination {
public:
	int a, b;
	
	combination(int a, int b) {
		this->a = a;
		this->b = b;
	}
	
	bool operator==(const combination &other) const {
		return (a == other.a && b == other.b);
	}
};

class myHasher {
public:
	std::size_t operator()(const outfit &o) const {
		return 100*o.j + 10*o.p + o.s;
	}
	std::size_t operator()(const combination &o) const {
		return 100*o.a + o.b;
	}
};





// has to print everything except "Case #n: " and eol \n
// read from std::cin
void handle_case() {
	int j,p,s,k;
	std::cin >> j >> p >> s >> k;
	
	std::unordered_map<combination, int, myHasher> combojp;
	std::unordered_map<combination, int, myHasher> combojs;
	std::unordered_map<combination, int, myHasher> combops;
	
	std::vector<outfit> all;
	
	for(int ij=1; ij<=j; ij++) {
		for(int ip=1; ip<=p; ip++) {
			for(int is=1; is<=s; is++) {
				if(combojp[combination(ij, ip)] < k && combojs[combination(ij, is)] < k && combops[combination(ip, is)] < k) {
					combojp[combination(ij, ip)]++;
					combojs[combination(ij, is)]++;
					combops[combination(ip, is)]++;
					all.push_back(outfit(ij, ip, is));
				}
			}
		}
	}
	
	std::cout << (all.size()) << std::endl;
	for(outfit o: all) {
		std::cout << o.j << " " << o.p << " " << o.s << std::endl;
	}
}


int main() {
	int num_cases;
	std::cin >> num_cases;
	for(int tcase = 1; tcase <= num_cases; tcase++) {
		std::cout << "Case #" << tcase << ": ";
		handle_case();
	}
}
