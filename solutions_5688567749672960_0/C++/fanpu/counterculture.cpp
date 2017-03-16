//#pragma comment(linker, "/STACK: 4294967296")
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000100
#define INF 2000000000
int shortest[MAX];

int reverseNum(int n){
	int reverse = 0;
	while (n != 0){
		reverse = reverse * 10;
		reverse = reverse + n%10;
		n = n/10;
   }
   return reverse;
}

void recursion(int n, int cur){
	//cout << n << "  " << cur << endl;
	shortest[n] = cur;
	if(reverseNum(n) < MAX && reverseNum(n) != n && shortest[reverseNum(n)] > cur + 1) recursion(reverseNum(n), cur + 1);
	if(n + 1 < MAX && shortest[n+1] > cur + 1) recursion(n + 1, cur + 1);
	return;
}

int main(){
	for(int i = 0; i < MAX; i++) shortest[i] = INF;
	shortest[1] = 1;
	queue<int> q; q.push(1);
	
	while(!q.empty()){
		int n = q.front(); q.pop();
		int reverse = reverseNum(n);
		if(reverse < MAX && reverse != n && shortest[reverse] > shortest[n] + 1){
			shortest[reverse] = shortest[n] + 1;
			q.push(reverse);
		}
		if(n + 1 < MAX && shortest[n+1] > shortest[n] + 1){
			shortest[n+1] = shortest[n] + 1;
			q.push(n+1);
		}
	}
	ifstream cin;
	cin.open("inputA.in");
	ofstream cout;
	cout.open("culture.txt");
	//for(int i = 1; i < MAX; i++) cout << i << " " << shortest[i] << "\n";
	int n; cin >> n;
	for(int a = 1; a <= n; a++){
		int temp; cin >> temp;
		cout << "Case #" << a << ": " << shortest[temp] << "\n";
	}
}
