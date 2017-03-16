#include <bits/stdc++.h>

#define PI 3.14159265358979323846
#define N 20

using namespace std;

typedef unsigned long long ull;
typedef unsigned int ui;
typedef long long ll;

char c[N];
char j[N];
char resC[N];
char resJ[N];
int n;
int pot[9];

vector <int> pc;
vector <int> pj;

/*int solve(int i){
	if (c[i] == '?' and j[i] == '?'){

	}
	else if (c[i] == '?'){

	}
	else if (j[i] == '?'){

	}
	else{

	}
}*/

void solveC(int i, int x){
	int k;

	if (i >= n){
		pc.push_back(x);
		return;
	}

	if (c[i] == '?'){
		for (k = 0; k < 10; k++){
			x += k * pot[n - 1 - i];

			solveC(i + 1, x);

			x -= k * pot[n - 1 - i];
		}
	}
	else{
		x += (c[i] - '0') * pot[n - 1 - i];
		solveC(i + 1, x);
	}
}

void solveJ(int i, int x){
	int k;

	if (i >= n){
		pj.push_back(x);
		return;
	}

	if (j[i] == '?'){
		for (k = 0; k < 10; k++){
			x += k * pot[n - 1 - i];

			solveJ(i + 1, x);

			x -= k * pot[n - 1 - i];
		}
	}
	else{
		x += (j[i] - '0') * pot[n - 1 - i];
		solveJ(i + 1, x);
	}
}

int main(void){
	int i, k, l, t, x, y, diff;

	pot[0] = 1;
	for (i = 1; i < 9; i++){
		pot[i] = pot[i - 1] * 10;
	}

	scanf("%d%*c", &t);

	for (i = 0; i < t; i++){
		scanf("%s", c);
		scanf("%*c");
		scanf("%s", j);
		scanf("%*c");

		n = strlen(c);


		solveC(0, 0);
		solveJ(0, 0);

		/*printf("PC:\n");
		for (k = 0; k < pc.size(); k++){
			printf("%d\n", pc[k]);
		}

		printf("\nPJ:\n");
		for (k = 0; k < pj.size(); k++){
			printf("%d\n", pj[k]);
		}*/

		sort(pc.begin(), pc.end());
		sort(pj.begin(), pj.end());

		// 1 5 7 8
		// 3 4 7

		x = 0;
		y = INT_MAX;
		diff = INT_MAX;

		for (k = 0, l = 0; k < pc.size() and l < pj.size();){
			if (pc[k] > pj[l]){
				if (pc[k] - pj[l] < diff){
					diff = pc[k] - pj[l];
					x = pc[k];
					y = pj[l];
				}

				l++;
			}
			else if (pc[k] < pj[l]){
				if (pj[l] - pc[k] < diff){
					diff = pj[l] - pc[k];
					x = pc[k];
					y = pj[l];
				}

				k++;
			}
			else{
				x = pc[k];
				y = pj[l];

				break;
			}
		}

		sprintf(resC, "%d", x);
		sprintf(resJ, "%d", y);

		printf("Case #%d: ", i + 1);
		for (k = 0; k < n - strlen(resC); k++){
			printf("0");
		}
		printf("%s ", resC);
		for (k = 0; k < n - strlen(resJ); k++){
			printf("0");
		}
		printf("%s\n", resJ);

		pc.clear();
		pj.clear();
	}

	return 0;
}