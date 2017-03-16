
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int t;
	char word[2010];
	int freq[255];
	int ans[10];

	scanf("%d", &t);
	for(int c = 1; c <= t; ++c){
		scanf("%s", word);
		memset(freq, 0, sizeof(freq));
		memset(ans, 0, sizeof(ans));
		int i = 0;
		while(word[i])
            freq[word[i++]]++;
        ans[0] = freq['Z'];
        freq['E']-=freq['Z'];
        freq['R']-=freq['Z'];
        freq['O']-=freq['Z'];
        freq['Z'] = 0;
        ans[2] = freq['W'];
        freq['T']-=freq['W'];
        freq['O']-=freq['W'];
        freq['W'] = 0;
        ans[4] = freq['U'];
        freq['F']-=freq['U'];
        freq['O']-=freq['U'];
        freq['R']-=freq['U'];
        freq['U'] = 0;
        ans[6] = freq['X'];
        freq['S']-=freq['X'];
        freq['I']-=freq['X'];
        freq['X'] = 0;
        ans[8] = freq['G'];
        freq['E']-=freq['G'];
        freq['I']-=freq['G'];
        freq['H']-=freq['G'];
        freq['T']-=freq['G'];
        freq['G'] = 0;

        ans[1] = freq['O'];
        freq['N'] -=freq['O'];
        freq['E'] -=freq['O'];
        freq['O'] = 0;
        ans[3] = freq['T'];
        freq['H'] -=freq['T'];
        freq['R'] -=freq['T'];
        freq['E'] -=2*freq['T'];
        freq['T'] = 0;
        ans[5] = freq['F'];
        freq['I'] -=freq['F'];
        freq['V'] -=freq['F'];
        freq['E'] -=freq['F'];
        freq['F'] = 0;

        ans[7] = freq['V'];
        ans[9] = freq['I'];

       printf("Case #%d: ", c);
       for(int i = 0; i < 10; ++i)
        for(int j = 0; j < ans[i]; ++j)
            printf("%d", i);
       printf("\n");

	}

	return 0;
}
