#include <cstdio>
#include <vector>
#include <string>
std::vector<std::string> alpha[26];
std::vector<std::string> data = {
	"ZERO",
	"ONE",
	"TWO",
	"THREE",
	"FOUR",
	"FIVE",
	"SIX",
	"SEVEN",
	"EIGHT",
	"NINE"
};
int main(void){
	int n;
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	std::vector<std::pair<int, char>> order = 
	{	{ 0, 'Z' }, { 6, 'X' }, { 2, 'W' }, { 4, 'U' }, 
		{ 8, 'G' }, { 7, 'S' }, { 3, 'H' }, { 1, 'O' }, 
		{ 5, 'V' }, { 9, 'I' } 
	};
	for (int t = 1; t <= n; t++){
		char tmp[2010];
		int ans[10] = { 0 };
		scanf("%s", tmp);
		printf("Case #%d: ", t);
		int alcount[26] = { 0 };
		for (int i = 0; tmp[i] != 0; i++){
			alcount[tmp[i] - 'A']++;
		}
		for (auto p : order){
			ans[p.first] = alcount[p.second - 'A'];
			for (auto c : data[p.first]){
				alcount[c - 'A'] -= ans[p.first];
			}
		}
		for (int i = 0; i < 10; i++){
			if (ans[i] != 0){
				for (int j = 0; j < ans[i]; j++){
					printf("%d", i);
				}
			}
		}
		printf("\n");

	}
}