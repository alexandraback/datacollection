#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define For(i, a, b) for (int i = (a); i != b; i++)
#define Rep(i,n) For(i,0,n)
#define debug(x) cout<<#x<<": "<<x<<endl
#define Pb push_back
#define Mp make_pair

template<class T>void show(T a,int n) {Rep(i,n)cout<<a[i]<<' ';cout<<endl;}
template<class T>void show(T a,int n,int m) {Rep(i,n){Rep(j,m)cout<<a[i][j]<<' ';cout<<endl;}}

char g2n[] = "yhesocvxduiglbkrztnwjpfmaq";

int main() {
	int N;
	scanf("%d\n", &N);

	Rep(iN, N) {
		printf("Case #%d: ", iN+1);
		char ch;
		while((ch=getchar()) != EOF) {
			if (ch >= 'a' && ch <= 'z') {
				putchar(g2n[ch-'a']);
			} else {
				putchar(ch);
			}
			if (ch == '\n') break;
		}
	}
	//system("pause");
	return 0;
}
