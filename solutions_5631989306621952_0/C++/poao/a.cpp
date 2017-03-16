#include <cstdio>
#include <deque>

using namespace std;

std::deque<char> ans;
int T;
char in[1010];

int main() {
	scanf("%d", &T);
	for(int tc=1; tc<=T; ++tc) {
		ans = deque<char>();
		scanf("%s", in);
		for(int i=0; in[i]; ++i) {
			if(ans.empty() || in[i] >= ans.front()) {
				ans.push_front(in[i]);
			}
			else {
				ans.push_back(in[i]);
			}
		}
		printf("Case #%d: ", tc);
		for(auto i=ans.begin(); i!=ans.end(); ++i) {
			printf("%c", *i);
		}
		printf("\n");
	}
	return 0;
}