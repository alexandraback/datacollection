#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;

ofstream ofs("2.out");
ifstream ifs("2.in");

#define INT64 long long

char train[100][105];
int anal[100];
int lenarr[100];
bool used[100];
int n;
INT64 res;
char temp[10000];

bool check() {
	int i;
	int arr[100];
	for (i=0; i<100; i++)
		arr[i] = 0;
	char b = temp[0];
	for (i=0; i<strlen(temp); i++) {
		int ind = temp[i]-'a';
		if (b != temp[i]) {
			if (arr[ind] > 0) return false;
		}

		arr[ind]++;
		b = temp[i];
	}
	
	return true;
}

void process2(char *pt, int lv, char c) {
	if (lv == n) {
		if (check()) res++;
		return;
	}
	
	int arr[100];
	for (int i=0; i<n; i++) {
		if (used[i]) continue;
		int len = lenarr[i];
//		int len = strlen(train[i]);

/*
		// analyze string
		int j;
		bool go = true;
		for (j=0; j<100; j++)
			arr[j] = 0;
		int len = strlen(train[i]);
		char c2 = c;
		if (c2==0) c2 = train[i][0];
		for (int j=0; j<len; j++) {
			if (train[i][j] != c2) {
				if (arr[ train[i][j] - 'a'] > 0) {
					go = false;
					break;
				}
				c2 = train[i][j];
				arr[c2-'a']++;
			}
		}
		if (!go) continue;

		// check suitablility
		for (j=0; j<='z'-'a'; j++) {
			if (c-'a' == j || 
		}
*/
		strcpy(pt, train[i]);
		used[i] = true;
		process2(pt+len, lv+1, c);
		used[i] = false;
	}
}

void opti(char *str) {
	char c = str[0];
	char *npt = str;
	for (int i=0; i<strlen(str); i++) {
		if (c != str[i]) {
			*(++npt) = c = str[i];
		}
	}
	*(++npt) = 0;
}

void process() {
	int i,j,k,l;
	ifs >> n;
	for (i=0; i<n; i++) {
		ifs >> train[i];
		opti(train[i]);
		lenarr[i] = strlen(train[i]);
	}

	// create various array
	res = 0;
	for (i=0; i<100; i++) used[i] = false;
	process2(temp, 0, 0);
}

int main() {
	int cnt;
	ifs >> cnt;
	for (int i=0; i<cnt; i++) {
		process();
		cout << "Case" << (i+1) << endl;
		ofs << "Case #" << (i+1) << ": " << (res % 1000000007) << endl;
	}

	return 0;
}
