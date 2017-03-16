#include <cstdio>
#include <cstring>

char buffer[2001];
int map[256];
int count[10];

int main(void) {
	int cases;
	scanf("%d", &cases);
	for (int c = 1; c <= cases; c++) {
		memset(map, 0, sizeof(map));
		memset(count, 0, sizeof(count));

		scanf("%s", buffer);
		for (char* c = buffer; *c; c++) {
			map[(unsigned char)*c]++;
		}

		// Z => E O R Z
		// E N O
		// W => O T W
		// E E H R T
		// F O R U
		// E F I V
		// X => I S X
		// E E N S V
		// G => E G H I T
		// E I N N

		count[0] = map['Z'];
		map['Z'] -= count[0];
		map['E'] -= count[0];
		map['R'] -= count[0];
		map['O'] -= count[0];

		count[6] = map['X'];
		map['S'] -= count[6];
		map['I'] -= count[6];
		map['X'] -= count[6];

		count[2] = map['W'];
		map['T'] -= count[2];
		map['W'] -= count[2];
		map['O'] -= count[2];

		count[8] = map['G'];
		map['E'] -= count[8];
		map['I'] -= count[8];
		map['G'] -= count[8];
		map['H'] -= count[8];
		map['T'] -= count[8];

		// E N O
		// E E H R T
		// F O R U
		// E F I V
		// S => E E N S V
		// E I N N
		count[7] = map['S'];
		map['S'] -= count[7];
		map['E'] -= count[7];
		map['V'] -= count[7];
		map['E'] -= count[7];
		map['N'] -= count[7];

		// E N O
		// E E H R T
		// F O R U
		// V => E F I V
		// E I N N
		count[5] = map['V'];
		map['F'] -= count[5];
		map['I'] -= count[5];
		map['V'] -= count[5];
		map['E'] -= count[5];

		// E N O
		// E E H R T
		// F => F O R U
		// E I N N
		count[4] = map['F'];
		map['F'] -= count[4];
		map['O'] -= count[4];
		map['U'] -= count[4];
		map['R'] -= count[4];

		// E N O
		// R => E E H R T
		// E I N N
		count[3] = map['R'];
		map['T'] -= count[3];
		map['H'] -= count[3];
		map['R'] -= count[3];
		map['E'] -= count[3];
		map['E'] -= count[3];

		count[1] = map['O'];
		map['O'] -= count[1];
		map['N'] -= count[1];
		map['E'] -= count[1];

		count[9] = map['I'];

		printf("Case #%d: ", c);
		for (int i = 0; i <= 9; i++) {
			for (int j = 0; j < count[i]; j++) {
				putchar('0' + i);
			}
		}
		printf("\n");
	}
	return 0;
}