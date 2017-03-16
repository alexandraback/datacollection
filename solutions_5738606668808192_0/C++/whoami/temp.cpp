#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
int su[32], n,m;
void back(int k){
	if (k == n - 1){
		vector<int> temp;
		for (int b = 2; b <= 10; b++){
			int gob2 = 1, gob3 = 1, gob5 = 1, ans2 = 0, ans3 = 0, ans5 = 0, ans7=0, gob7=1;
			for (int i = n - 1; i >= 0; i--){
				ans2 += gob2*su[i];
				ans3 += gob3*su[i];
				ans5 += gob5*su[i];
				ans7 += gob7*su[i];
				gob2 *= b;
				gob3 *= b;
				gob5 *= b;
				gob7 *= b;
				gob2 %= 2;
				gob3 %= 3;
				gob5 %= 5;
				gob7 %= 7;
			}
			if (ans2 % 2 == 0)
				temp.push_back(2);
			else if (ans3 % 3 == 0)
				temp.push_back(3);
			else if (ans5 % 5 == 0)
				temp.push_back(5);
			else if (ans7 % 7 == 0)
				temp.push_back(7);
			else return;
		}
		for (int i = 0; i < n; i++)
			printf("%d", su[i]);
		printf(" ");
		for (int i = 0; i < temp.size(); i++)
			printf("%d ", temp[i]);
		printf("\n");
		m--;
		return;
	}
	su[k] = 0;
	back(k + 1);
	if (m == 0) return;
	su[k] = 1;
	back(k + 1);
}
int main(){
	int testt;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &testt);
	for (int test = 1; test <= testt; test++){
		scanf("%d %d", &n, &m);
		printf("Case #%d:\n", test);

		su[0] = 1; su[n - 1] = 1;
		back(1);
	}
	return 0;
}
