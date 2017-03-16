////GCJ Qualification 2014-04-12 A --- AC
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<algorithm>
//using namespace std;
//
//FILE* fw;
//
//int main() {
////	freopen("B-small-attempt0.in", "r", stdin);
//	freopen("A-small-attempt0.in", "r", stdin);
//	fw = fopen("A-s.txt", "w");
//	int i, j, cse, r1, r2, map1[4][4], map2[4][4], cnt, res, g = 1;
//	scanf("%d", &cse);
//	while(cse--) {
//		scanf("%d", &r1);
//		for(i = 0; i < 4; ++i) {
//			for(j = 0; j < 4; ++j) {
//				scanf("%d", &map1[i][j]);
//			}
//		}
//		scanf("%d", &r2);
//		for(i = 0; i < 4; ++i) {
//			for(j = 0; j < 4; ++j) {
//				scanf("%d", &map2[i][j]);
//			}
//		}
//		cnt = 0;
//		for(i = 0; i < 4; ++i) {
//			for(j = 0; j < 4; ++j) {
//				if(map1[r1 - 1][i] == map2[r2 - 1][j]) {
//					cnt++;
//					res = map1[r1 - 1][i];
//					break;
//				}
//			}
//		}
//		if(!cnt) fprintf(fw, "Case #%d: Volunteer cheated!\n", g++);
//		else if(cnt == 1) fprintf(fw, "Case #%d: %d\n", g++, res);
//		else
//			fprintf(fw, "Case #%d: Bad magician!\n", g++);
//	}
//	fclose(fw);
//	return 0;
//}



////GCJ Qualification 2014-04-12 B
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<algorithm>
//using namespace std;
//
//FILE* fw;
//
//int main() {
////	freopen("B-small-attempt0.in", "r", stdin);
//	freopen("B-large.in", "r", stdin);
//	fw = fopen("B-l.txt", "w");
//	int cse, g = 1;
//	double tp, t1, T1, T2, c, f, x, curp, curt;
//	scanf("%d", &cse);
//	while(cse--) {
//		scanf("%lf %lf %lf", &c, &f, &x);
//		tp = 0;
//		curp = 2.0;
//		curt = 0;
//		while(tp < x) {
//			t1 = (c - tp) / (curp); // time to get next farm
//			T1 = t1 + (x - tp) / (curp + f); // time to exit
//			T2 = (x - tp) / curp;
//			if(T1 < T2) {
//				curt += t1;
//				curp += f;
//			}
//			else {
//				curt += T2;
//				break;
//			}
//		}
//		fprintf(fw, "Case #%d: %.7lf\n", g++, curt);
//	}
//	return 0;
//}










//GCJ Qualification 2014-04-12 C
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

FILE* fw;

int main() {
	freopen("C-large.in", "r", stdin);
//	freopen("B.in", "r", stdin);
	fw = fopen("C-l.txt", "w");
	int cse, g = 1, ok, i, j, total;
	int r, c, m, cnt, tp, rcnt;
	scanf("%d", &cse);
	while(cse--) {
		scanf("%d %d %d", &r, &c, &m);
		fprintf(fw, "Case #%d:\n", g++);
		total = r * c;
		if(m == total - 1) {
			for(i = 0; i < r; ++i) {
				for(j = 0; j < c; ++j) {
					if(i == r - 1 && j == c - 1) fprintf(fw, "c");
					else
						fprintf(fw, "*");
					if(j == c - 1) fprintf(fw, "\n");
				}
			}
		}
		else if(m >= total) {
			fprintf(fw, "Impossible\n");
		}
		else if(r < 3 || c < 3) {
			if(r == 1) {
				for(j = 0; j < m; ++j) {
					fprintf(fw, "*");
				}
				for(j = m; j < c - 1; ++j) {
					fprintf(fw, ".");
				}
				fprintf(fw, "c\n");
			}
			else if(c == 1) {
				for(j = 0; j < m; ++j) {
					fprintf(fw, "*\n");
				}
				for(j = m; j < r - 1; ++j) {
					fprintf(fw, ".\n");
				}
				fprintf(fw, "c\n");
			}
			else if(r == 2) {
				if((m & 1) || (m + 2 == total)) fprintf(fw, "Impossible\n");
				else {
					for(j = 0; j < (m / 2); ++j) fprintf(fw, "*");
					for(j = m / 2; j < c; ++j) fprintf(fw, ".");
					fprintf(fw, "\n");
					for(j = 0; j < (m / 2); ++j) fprintf(fw, "*");
					for(j = m / 2; j < c - 1; ++j) fprintf(fw, ".");
					fprintf(fw, "c\n");
				}
			}
			else if(c == 2) {
				if((m & 1) || (m + 2 == total)) fprintf(fw, "Impossible\n");
				else {
					for(j = 0; j < (m / 2); ++j) fprintf(fw, "**\n");
					for(j = m / 2; j < r - 1; ++j) fprintf(fw, "..\n");
					fprintf(fw, ".c\n");
				}
			}
		}
		else {
			if(m <= (r - 2) * (c - 2)) {
				cnt = 0;
				for(i = 0; i < r; ++i) {
					for(j = 0; j < c; ++j) {
						if(j < c - 2 && cnt < m) {
							fprintf(fw, "*");
							cnt++;
						}
						else if(i == r - 1 && j == c - 1) fprintf(fw, "c");
						else
							fprintf(fw, ".");
					}
					fprintf(fw, "\n");
				}
			}
			else if(m == total - 2) {
				fprintf(fw, "Impossible\n");
			}
			else if((m - (r - 2) * ( c - 2)) & 1) {
				if(m <= total - 9){
					tp = (m + 1 - (r - 2) * ( c - 2)) / 2;
					cnt = 0;
					rcnt = 0;
					for(i = 0; i < r - 2; ++i) {
						for(j = 0; j < c; ++j) {
							if(i == r - 3 && j == c - 3) {
								fprintf(fw, ".");
							}
							else if(j < c - 2) {
								fprintf(fw, "*");
								cnt++;
							}
							else {
								if(rcnt < tp && i != r - 3) {
									rcnt++;
									fprintf(fw, "**\n");
								}
								else {
									fprintf(fw, "..\n");
								}
								break;
							}
						}
					}
					for(i = r - 2; i < r; ++i) {
						for(j = 0; j < c; ++j) {
							if(i == r - 1 && j == c - 1) fprintf(fw, "c");
							else if(j < tp - rcnt) fprintf(fw, "*");
							else
								fprintf(fw, ".");
						}
						fprintf(fw, "\n");
					}
				}
				else {
					fprintf(fw, "Impossible\n");
				}
			}
			else if(!((m - (r - 2) * ( c - 2)) & 1)) {
				tp = (m - (r - 2) * ( c - 2)) / 2;
				cnt = 0;
				rcnt = 0;
				for(i = 0; i < r - 2; ++i) {
					for(j = 0; j < c; ++j) {
						if(j < c - 2) {
							fprintf(fw, "*");
							cnt++;
						}
						else {
							if(rcnt < tp) {
								rcnt++;
								fprintf(fw, "**\n");
							}
							else {
								fprintf(fw, "..\n");
							}
							break;
						}
					}
				}
				for(i = r - 2; i < r; ++i) {
					for(j = 0; j < c; ++j) {
						if(i == r - 1 && j == c - 1) fprintf(fw, "c");
						else if(j < tp - rcnt) fprintf(fw, "*");
						else
							fprintf(fw, ".");
					}
					fprintf(fw, "\n");
				}
			}
		}
	}
	return 0;
}






//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//int a[1010], fg[1010][1010];
//char str[1010];
//
//int main() {
//	int i, tp, k, j, res, a1, a2;
//	memset(str, 0x00, sizeof(str));
//	while(gets(str) != NULL) {
//		i = 0;
//		tp = 0;
//		k = 1;
//		while(i < strlen(str)) {
//			if(str[i] <= '9' && str[i] >= '0') {
//				tp = tp * 10 + str[i] - '0';
//				++i;
//			}
//			else if(str[i] == ',') {
//				a[k] = tp;
//				tp = 0;
//				++k;
//				++i;
//			}
//		}
//		a[k] = tp;
////		for(i = 1; i <= k; ++i) {
////			printf("~%d\n", a[i]);
////		}
//		for(i = 1; i <= k; ++i) {
//			fg[i][0] = 0;
//			for(j = 1; j <= k; ++j) {
//				if(a[j] > a[i]) fg[i][j] = fg[i][j - 1] + 1;
//				else
//					fg[i][j] = fg[i][j - 1];
//			}
//		}
//		for(i = 1; i <= k; ++i) {
//			for(j = 1; j <= k; ++j) {
//				printf("%d ", fg[i][j]);
//			}
//			puts("");
//		}
//		res = 0;
//		for(i = 1; i<= k; ++i) {
//			for(j = i + 1; j <= k; ++j) {
//				 if(a[i] < a[j]) continue;
//				 else {
//					 a1 = fg[i][j] - fg[i][i - 1];
//					 a2 = fg[j][j] - fg[j][i - 1];
//					 if(a2 - a1 > res) res = a2 - a1;
//					 printf("~~%d %d %d %d %d %d %d %d\n", i, j, a1, a2, fg[i][i], fg[i][j], fg[j][j], fg[j][i]);
//				 }
//			}
//		}
//		printf("%d\n", res);
//	}
//	return 0;
//}
