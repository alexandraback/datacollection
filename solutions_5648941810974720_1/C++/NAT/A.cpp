#include <cstdio>

char in[2005];
int num[10];
int ct[30];
int T;

int main(){
	int i;

	scanf("%d", &T);
	for(int tt = 1; tt <= T; tt++){
		for(int i = 0; i < 26; i++)
			ct[i] = 0;
		for(int i = 0; i < 10; i++)
			num[i] = 0;

		scanf("%s", in);
		for(int i = 0; in[i] != '\0'; i++){
			ct[in[i] - 'A']++;
		}

		//ZERO
		num[0] = ct['Z' - 'A'];
		ct['E' - 'A'] -= ct['Z' - 'A'];
		ct['R' - 'A'] -= ct['Z' - 'A'];
		ct['O' - 'A'] -= ct['Z' - 'A'];
		ct['Z' - 'A'] = 0;

		//SIX
		num[6] = ct['X' - 'A'];
		ct['S' - 'A'] -= ct['X' - 'A'];
		ct['I' - 'A'] -= ct['X' - 'A'];
		ct['X' - 'A'] = 0;

		//FOUR
		num[4] = ct['U' - 'A'];
		ct['F' - 'A'] -= ct['U' - 'A'];
		ct['O' - 'A'] -= ct['U' - 'A'];
		ct['R' - 'A'] -= ct['U' - 'A'];
		ct['U' - 'A'] = 0;

		//FIVE
		num[5] = ct['F' - 'A'];
		ct['I' - 'A'] -= ct['F' - 'A'];
		ct['V' - 'A'] -= ct['F' - 'A'];
		ct['E' - 'A'] -= ct['F' - 'A'];
		ct['F' - 'A'] = 0;

		//SEVEN
		num[7] = ct['V' - 'A'];
		ct['S' - 'A'] -= ct['V' - 'A'];
		ct['E' - 'A'] -= 2*ct['V' - 'A'];
		ct['N' - 'A'] -= ct['V' - 'A'];
		ct['V' - 'A'] = 0;

		//TWO
		num[2] = ct['W' - 'A'];
		ct['T' - 'A'] -= ct['W' - 'A'];
		ct['O' - 'A'] -= ct['W' - 'A'];
		ct['W' - 'A'] = 0;

		//THREE
		num[3] = ct['R' - 'A'];
		ct['T' - 'A'] -= ct['R' - 'A'];
		ct['H' - 'A'] -= ct['R' - 'A'];
		ct['E' - 'A'] -= 2*ct['R' - 'A'];

		//EIGHT
		num[8] = ct['G' - 'A'];
		ct['I' - 'A'] -= ct['G' - 'A'];

		//NINE
		num[9] = ct['I' - 'A'];

		//ONE
		num[1] = ct['O' - 'A'];

		printf("Case #%d: ", tt);


		for(int i = 0; i < 10; i++){
		//printf("%d ", num[i]);
			for(int j = 0; j < num[i]; j++)
				printf("%d", i);
		}
		printf("\n");
	}
}