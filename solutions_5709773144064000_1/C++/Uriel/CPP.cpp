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



//GCJ Qualification 2014-04-12 B
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

FILE* fw;

int main() {
//	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-large.in", "r", stdin);
	fw = fopen("B-l.txt", "w");
	int cse, g = 1;
	double tp, t1, T1, T2, c, f, x, curp, curt;
	scanf("%d", &cse);
	while(cse--) {
		scanf("%lf %lf %lf", &c, &f, &x);
		tp = 0;
		curp = 2.0;
		curt = 0;
		while(tp < x) {
			t1 = (c - tp) / (curp); // time to get next farm
			T1 = t1 + (x - tp) / (curp + f); // time to exit
			T2 = (x - tp) / curp;
			if(T1 < T2) {
				curt += t1;
				curp += f;
			}
			else {
				curt += T2;
				break;
			}
		}
		fprintf(fw, "Case #%d: %.7lf\n", g++, curt);
	}
	return 0;
}










////GCJ Qualification 2014-04-12 C
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<algorithm>
//using namespace std;
//
//FILE* fw;
//
//int main() {
//	freopen("C-small-attempt0.in", "r", stdin);
////	freopen("B.in", "r", stdin);
//	fw = fopen("C-s.txt", "w");
//	int cse, g = 1, ok, i, j;
//	int r, c, m, cnt;
//	scanf("%d", &cse);
//	while(cse--) {
//		scanf("%d %d %d", &r, &c, &m);
//		cnt = 0;
//		ok = 1;
//		for(i = 0; i < r; ++i) {
//			if(cnt == m) break;
//			if(i >= r - 2) {
//				for(j = 0; j < c - 2; ++j) {
//					if(cnt == m) break;
//					cnt++;
//				}
//			}
//			else {
//				for(j = 0; j < c; ++j) {
//					if(cnt == m) break;
//					cnt++;
//				}
//			}
//		}
//		if(cnt < m) {
//			ok = 0;
//			fprintf(fw, "Case #%d:\nImpossible\n", g++);
//		}
//		else {
//			fprintf(fw, "Case #%d:\n", g++);
//			cnt = 0;
//			for(i = 0; i < r; ++i) {
//				for(j = 0; j < c; ++j) {
//					if(i == r - 1 && j == c - 1) {
//						fprintf(fw, "C");
//					}
//					else {
//						if(cnt == m) {
//							fprintf(fw, ".");
//						}
//						else {
//							if(i >= r - 2 && j >= c - 2) fprintf(fw, ".");
//							else {
//								fprintf(fw, "*");
//								cnt++;
//							}
//						}
//					}
//					if(j == c - 1) fprintf(fw, "\n");
//				}
//			}
//		}
//	}
//	return 0;
//}
