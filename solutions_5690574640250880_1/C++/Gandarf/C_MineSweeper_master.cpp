#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int test, caseNum;
int map[55][55];
int r,c,m;

FILE *in = fopen("C-large.in", "r");
//FILE *in = fopen("input.txt", "r");
FILE *out = fopen("output.txt", "w");

void one();
void print();

void ppp()
{
	for (int i = 0; i < r; i++) {
							for (int j = 0; j < c; j++) {
								if (map[i][j] == 2) printf("c");
								else if (map[i][j] == 0) printf("*");
								else printf(".");
							}
							printf("\n");
						}
	printf("=========================\n");
}

int main()
{
	caseNum = 1;
	fscanf(in, "%d", &test);
	while(caseNum <= test)
	{
		fscanf(in, "%d %d %d", &r, &c, &m);

		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				map[i][j] = 0;
		
		int s = r*c-m;
		if (r == 1 || c == 1) {
			one();
			print();
		}
		else if (s == 1) {
			map[0][0] = 2;
			print();
		}
		else if (s == 2 || s == 3 || s == 5 || s == 7)
			fprintf(out, "Case #%d:\nImpossible\n", caseNum++);
		else if (s % 2 == 1 && (r == 2 || c == 2))
			fprintf(out, "Case #%d:\nImpossible\n", caseNum++);
		else {
				int x = 0, y = 0;
				int cnt = 0;
				bool d = true; // true == 세로, false == 가로

				if ((r*c-m) % 2 == 0) { // 짝수
					while (cnt < r*c-m) { // 세로 채우기
						//if (d) {
							map[x][y] = 1;
							map[x+1][y++] = 1;
							cnt += 2;
						//}
						if (y >= c) {
							y = 0;
							x += 2;
							break;
						}
					}
					///ppp();
					while (cnt < r*c-m) { // 가로 채우기
						//else {
							map[x][y] = 1;
							map[x][y+1] = 1;
							cnt += 2;
							y += 2;
						//}
						if (y >= c || y+1 >= c) {
							y = 0;
							x++;
							if (x >= r) {
								y = c-1;
								x = 2;
								break;
							}
						}
					}
					//ppp();
					while (cnt < r*c-m) { // 마저 채우기 (세로)
						map[x][y] = 1;
						map[x+1][y] = 1;
						x += 2;
						cnt += 2;
					}
				}

				//else if (r*c-m >= 9 && (r*c-m) % 3 == 0) { // 홀수 (3의배수)	
				else {
					while (cnt < r*c-m) { // 세로 채우기
						map[x][y] = map[x+1][y] = map[x+2][y] = 1;
						y++;
						cnt += 3;
						if (y >= c) {
							y = 0;
							x += 3;
							break;
						}
					}
					//ppp();
					while (cnt < r*c-m) {  // 가로 채우기
						map[x][y] = map[x][y+1] = map[x][y+2] = 1;
						y += 3;
						cnt += 3;
						if (y >= c || y+1 >= c || y+2 >= c) {
							y = 0;
							x++;
							if (x >= r) {
								y = c-1;
								x = 3;
								if (map[x][y-1] == 0) y--;
								break;
							}
						}
					}
					//ppp();
					int ori = y;
					while (cnt < r*c-m) { // 마저 (세로)
						if (x+1 >= r || x+2 >= r)
							break;
						map[x][y] = map[x+1][y] = map[x+2][y] = 1;
						y++;
						cnt += 3;
						if (y >= c) {
							x += 3;
							y = ori;
						}
					}

					if (cnt < r*c-m) {
						for (int i = 0; i < r; i++) {
							for (int j = 0; j < c; j++) {
								if (cnt < r*c-m && map[i][j] == 0) {
									cnt++;
									map[i][j] = 1;
								}
							}
						}
					}

					if (cnt > r*c-m) {
						int px, py;
						int k = cnt - (r*c-m);
						
						//printf("%d\n", k);
						//ppp();
						
						while(k-- > 0) {
							int temp = 0;
							for (int i = 0; i < r; i++) {
								for (int j = 0; j < c; j++) {
									if (i == 1 || j == 1) continue;
									if (i+j > temp && map[i][j] == 1) {
										temp = i+j;
										px = i;
										py = j;
									}
								}
							}
							map[px][py] = 0;
						}
					}
				}
				/*else if (r*c-m >= 9 && (r*c-m) % 3 > 0) { // 홀수 (3의배수아님)  // && (r*c-m) % 2 == 1) { */
				map[0][0] = 2;
			//}
			print();
		}
	}

	fcloseall();
	return 0;
}

void one()
{ 
	int cnt = 0;
	if (r == 1) {
		for (int j = 0; j < c-m; j++)
			map[0][j] = 1;
		/*
		for (int j = c-1; j >= 0; j--) {
			if (cnt == m) break;
			map[0][j] = 0;
			cnt++;
		}
		*/
	}
	else {
		for (int i = 0; i < r-m; i++)
			map[i][0] = 1;
		/*
		for (int i = r-1; i >= 0; i--) {
			if (cnt == m) break;
			map[i][0] = 0;
			cnt++;
		}
		*/
	}
	map[0][0] = 2;
}

void print()
{
	fprintf(out, "Case #%d:\n", caseNum++);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 2) fprintf(out, "c");
			else if (map[i][j] == 0) fprintf(out, "*");
			else fprintf(out, ".");
		}
		fprintf(out, "\n");
	}
}