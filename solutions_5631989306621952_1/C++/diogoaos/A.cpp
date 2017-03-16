#include <cstdio>
#include <deque>

using namespace std;

int main() {
	int T;
	char str[1010];
	
	scanf("%d", &T);
	
	for (int test = 1; test <= T; test++) {
		printf("Case #%d: ", test);
		
		scanf("%s", str);
		
		deque<char> out;
		
		for (int i = 0; str[i]; i++) {
			if (out.empty() || out.front() > str[i]) {
				out.push_back(str[i]);
			} else {
				out.push_front(str[i]);
			}
		}
		
		while (!out.empty()) {
			putchar(out.front());
			out.pop_front();
		}
		
		printf("\n");
	}
	return 0;
}