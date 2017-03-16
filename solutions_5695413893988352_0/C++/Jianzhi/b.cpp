#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <set>
using namespace std;
int tc;
string a, b;
string atemp, btemp;
int arr[3];
int brr[3];

int aans[3];
int bans[3];

set<int> as, bs;

int abso(int x){
	if (x >= 0) return x;
	return -x;
}

int main(){
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("bsmallout.txt", "w", stdout);
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++){
		cin >> a >> b;
		atemp = a;
		btemp = b;
		as.clear();
		bs.clear();
		while (a.length() != 3){
			a = "0" + a;
		}
		while (b.length() != 3){
			b = "0" + b;
		}
		memset(arr, -1, sizeof(arr));
		memset(brr, -1, sizeof(brr));
		for (int j = 0; j < a.length(); j++){
			if (a[j] != '?'){
				arr[j] = (int)a[j] - 48;
			}
		}
		
		for (int j = 0; j < b.length(); j++){
			if (b[j] != '?'){
				brr[j] = (int)b[j] - 48;
			}
		}
		
		for (int j = 0; j <= 999; j++){
			int cur = j;
			if (arr[2] != -1 && arr[2] != cur%10) continue;
			cur -= cur%10;
			cur /= 10;
			if (arr[1] != -1 && arr[1] != cur%10) continue;
			cur -= cur%10;
			cur /= 10;
			if (arr[0] != -1 && arr[0] != cur%10) continue;
			as.insert(j);
		}
		
		for (int j = 0; j <= 999; j++){
			int cur = j;
			if (brr[2] != -1 && brr[2] != cur%10) continue;
			cur -= cur%10;
			cur /= 10;
			if (brr[1] != -1 && brr[1] != cur%10) continue;
			cur -= cur%10;
			cur /= 10;
			if (brr[0] != -1 && brr[0] != cur%10) continue;
			bs.insert(j);
		}
		int mindiff = 100000;
		int mina = 1000000;
		int minb = 1000000;
		for (set<int>::iterator it = as.begin(); it != as.end(); it++){
			for (set<int>::iterator itee = bs.begin(); itee != bs.end(); itee++){
				if (abso(*it - *itee) < mindiff){
					mindiff = abso(*it - *itee);
					mina = *it;
					minb = *itee;
				} else if (abso(*it - *itee) == mindiff){
					if (*it < mina){
						mina = *it;
						minb = *itee;
					} else if (*it == mina){
						if (*itee == minb){
							minb = *itee;
						}
					}
				}
			}
		}
		
		for (int j = atemp.length() - 1; j >= 0; j--){
			aans[j] = mina%10;
			mina -= (mina%10);
			mina /= 10;
		}
		
		for (int j = btemp.length() - 1; j >= 0; j--){
			bans[j] = minb%10;
			minb -= (minb%10);
			minb /= 10;
		}
		
		printf("Case #%d: ", i + 1);
		for (int j = 0; j < atemp.length(); j++){
			printf("%d", aans[j]);
		}
		printf(" ");
		for (int j = 0; j < btemp.length(); j++){
			printf("%d", bans[j]);
		}
		printf("\n");
		
	}
	
}
