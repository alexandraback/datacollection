#include <set>
#include <iostream>
#include <string>

inline char rev(char s) {
	if (s == '-')
		return '+';
	else
		return '-';
}

std::string transform(std::string& old, int k) {
	std::string res = old;
	for (int i = 0; i < k; ++i)
		res[i] = rev(old[k - i - 1]);

	//std::cout << "in: " << old << "; out: " << res << std::endl;

	return res;
}

int main() {
	int n;
	std::cin >> n;

	for (int ind = 1; ind <= n; ++ind) {
		
		std::string in;
		std::cin >> in;

		int len = in.size();

		int licznik = 0;

		while (true) {
			bool ok = true;
			int flag = 0;
			for (int i = len - 1; i >= 0; --i) {
				if (in[i] == '-') {
					flag = i;
					ok = false;
					break;
				}
			}
			
			if (ok)
				break;

			if (in[0] == '+') {
				for (int i = 0; i < len; ++i) {
					if (in[i] == '-') {
						licznik += 1;
						in = transform(in, i);
						break;
					}
				}
			}

			licznik += 1;
			in = transform(in, flag + 1);
		}

		std::cout << "Case #" << ind << ": " << licznik << std::endl;
	}
}