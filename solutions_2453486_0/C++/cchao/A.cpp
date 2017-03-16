#include <cstdio>
int T;
char s[10][10];
char res[4][50] = {"X won", "O won", "Draw", "Game has not completed"};
void judge(){
	int o, x, t;
	for(int i = 0; i < 4; ++i){
		o = x = t = 0;
		for(int j = 0; j < 4; ++j)
			switch(s[i][j]){
				case 'O':++o;break;
				case 'X':++x;break;
				case 'T':++t;break;
				case '.':break;
			}
		if(x+t==4){puts(res[0]); return;}
		if(o+t==4){puts(res[1]); return;}
		o = x = t = 0;
		for(int j = 0; j < 4; ++j)
			switch(s[j][i]){
				case 'O':++o;break;
				case 'X':++x;break;
				case 'T':++t;break;
				case '.':break;
			}
		if(x+t==4){puts(res[0]); return;}
		if(o+t==4){puts(res[1]); return;}
	}
	int px, py;
	o = x = t = 0;
	for(px = py = 0; px < 4; ++px, ++py){
		switch(s[px][py]){
			case 'O':++o;break;
			case 'X':++x;break;
			case 'T':++t;break;
			case '.':break;
		}
	}
	if(x+t==4){puts(res[0]); return;}
	if(o+t==4){puts(res[1]); return;}

	o = x = t = 0;
	for(px=0, py = 3; px < 4; ++px, --py){
		switch(s[px][py]){
			case 'O':++o;break;
			case 'X':++x;break;
			case 'T':++t;break;
			case '.':break;
		}
	}
	if(x+t==4){puts(res[0]); return;}
	if(o+t==4){puts(res[1]); return;}

	for(int i = 0; i < 4; ++i)
		for(int j = 0; j < 4; ++j)
			if(s[i][j] == '.'){ puts(res[3]); return;}
	puts(res[2]);

}
int main(){
	scanf("%d", &T);
	for(int kase = 1; kase <= T; ++kase){
		scanf("%s%s%s%s", s[0], s[1], s[2], s[3]);
		printf("Case #%d: ", kase);
		judge();
	}
}
