#include <bits/stdc++.h>
using namespace std;


#define DBG 0
#define debug(x) if (DBG) {cerr << "\n" << #x << " : " << x << endl;}
#define debug2(x, y) if (DBG) {cerr << #x << " : " << x << " :: " << #y << " : " << y << endl;}
#define debug3(x, y, z) if (DBG) {cerr << #x << " : " << x << " :: " << #y << " : " << y << " :: " << #z << " : " << z << endl;}
#define rep(i,n) for(int i=0; i<(n); i++)

char str[10010];
int val[10010];
int prefixProd[10010];

int rules[5][5];

int product(int a, int b){
	if (a < 0 and b < 0){
		a *= -1;
		b *= -1;
	}
	if (a < 0){
		return -1*rules[-a][b];
	}
	if (b < 0){
		return -1*rules[a][-b];
	}
	return rules[a][b];
}

int main(){
	int t;
	scanf("%i", &t);
	rep(i, 4) rules[i+1][1] = i+1;
	rep(i, 4) rules[1][i+1] = i+1;
	rep(i, 3) rules[i+2][i+2] = -1;
	rules[2][3] = 4; 
	rules[3][2] = -4;
	rules[2][4] = -3;
	rules[4][2] = 3;
	rules[3][4] = 2;
	rules[4][3] = -2;

	// debug(product(3,2));

	for (int test_case = 1; test_case <= t; test_case++){
		int l;
		long long x;
		scanf("%i %lli", &l, &x);
		scanf("%s", str);

		/*
		rep(i, l){
			if (str[i] == 'i') val[i] = 1;
			if (str[i] == 'j') val[i] = 2;
			if (str[i] == 'k') val[i] = 3;
		}
		*/
		int fullProduct = 1;

		rep(i, l){
			fullProduct = product(fullProduct, str[i] - 'i' + 2);
		}
		
		// debug(fullProduct);

		bool separable = true;

		long long blockNum = 0, currentIndex = 0;
		long long iPlace = -1, jPlace = -1, kPlace = -1;
		int prod = 1;

		
		while(currentIndex <= 4*l and currentIndex < x*l)
		{
			long long index = currentIndex % l;
			prod = product(prod, str[index] - 'i' + 2);

			currentIndex++;

			if (prod == 2)
			{
				iPlace = currentIndex - 1;
				break;
			}
		}
		
		if (iPlace == -1){
			// debug2(iPlace, currentIndex);

			printf("Case #%i: %s\n", test_case, "NO");
			continue;
		}

		prod = 1;
		while(currentIndex - iPlace <= 4*l and currentIndex < x*l){
			long long index = currentIndex % l;
			prod = product(prod, str[index] - 'i' + 2);

			currentIndex++;
			
			if (prod == 3){
				jPlace = currentIndex - 1;
				break;
			}

		}

		if (jPlace == -1){
			// debug2(jPlace, currentIndex);
			printf("Case #%i: %s\n", test_case, "NO");
			continue;
		}
		
		prod = 1;


		while(currentIndex - jPlace <= 4*l and currentIndex < x*l){
			long long index = currentIndex % l;
			prod = product(prod, str[index] - 'i' + 2);

			currentIndex++;			


			if (prod == 4){
				kPlace = currentIndex - 1;
				break;
			}

		}

		if (kPlace == -1){
			// debug2(kPlace, currentIndex);
			printf("Case #%i: %s\n", test_case, "NO");
			continue;
		}


		if (currentIndex % l == 0){
			long long leftOver = x - (currentIndex/l);
			leftOver = leftOver%4;
			bool x = false;
			if (fullProduct == 1) x = true;
			if (leftOver == 2) if (fullProduct == -1) x = true;
			if (leftOver == 0) x = true;
			if (x){
				printf("Case #%i: %s\n", test_case, "YES");
			}
			else{
				printf("Case #%i: %s\n", test_case, "NO");
			}
			
		}
		else{
			prod = 1;
			long long index = currentIndex%l;
			for(; index < l; index++){
				prod = product(prod, str[index] - 'i' + 2);
				currentIndex++;
			}
			long long leftOver = x - (currentIndex/l);
			leftOver = leftOver%4;
			bool x = false;

			if (leftOver == 0){
				if (prod == 1) x = true;
			}
			else if (leftOver == 1){
				if (product(prod, fullProduct) == 1) x = true;
			}

			else if (leftOver == 2){
				int temp = product(prod, fullProduct);
				temp = product(temp, fullProduct);
				if (temp == 1) x = true;
			}
			else {
				int temp = product(prod, fullProduct);
				temp = product(temp, fullProduct);
				temp = product(temp, fullProduct);
				if (temp == 1) x = true;
			}
			if (x){
				printf("Case #%i: %s\n", test_case, "YES");
			}
			else{
				printf("Case #%i: %s\n", test_case, "NO");
			}


		}
		

	}
}