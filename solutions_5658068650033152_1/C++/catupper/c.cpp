#include<iostream>
#include<algorithm>

using namespace std;


int cnt(int n, int m, int p){
	if(n > m)swap(n, m);
	if(n <= 2)return p;
	if(p <= 3)return p;
	if(p == 4)return 5;
	if(p == 6)return 8;
	if(n == 3){
		if(p >=  (m - 2) * 2 + 2){
			return n * m - 4 + (p - ((m - 2) * 2 + 2));
		}
		else{
			return (p - 2) / 2 * 3 + 2 + (p - 2) % 2;
		}
	}
	if(n == 4){
		if(p == 7)return 10;
		if(p >= (m - 2) * 2 + 4){
			return n * m - 4 + (p - ((m - 2) * 2 + 4));
		}
		else{
			return (p - 4) * 2 + 4;
		}
	}
	if(p >= m * 2 - 2){
		int a = p - (m * 2 - 2);
		return m * n - (n - a / 2)  * (n - a / 2 + 1) / 2 - (n + a - a / 2) * (n + a - a / 2 + 1) / 2;
	}
	if(p % 4 == 0){
		return p / 2 + 1 + (p / 2) * (p / 2);
	}
	if(p % 4 == 1){
		return p / 2 + 1 + (p / 2) * (p / 2) + p / 2;
	}
	if(p % 4 == 2){
		return p / 2 + 1 + (p / 2) * (p / 2) + p / 2 + p / 2 + 1;
	}
	if(p % 4 == 3){
		return p / 2 + 1 + (p / 2) * (p / 2) + p / 2 + p / 2 + 1 + p / 2 + 2;
	}
}

int solve(){
	int n, k, m;
	cin >> n >> m >> k;
	for(int i = 1;i <= k;i++){
		if(cnt(n, m, i) >= k)return i;
	}
}

int main(){
	int t;
	cin >> t;
	for(int i = 1;i <= t;i++){
		cout << "Case #" << i << ": " << solve() << endl;
	}
	return 0;
}


/*
ooooxxooooo
oooxooxoooo
ooxooooxooo
oxooooooxoo
ooxooooxooo
oooxooxoooo
ooooxxooooo

p % 4 == 0
p / 2 + 1 + (p / 2) * (p / 2)

oooooooo
oooo*ooo
ooo*o*oo
oo*ooo*o
ooo*o*oo
oooo*ooo
oooooooo
oooooooo

p % 4 == 1

p / 2 + 1 + (p / 2) * (p / 2) + p / 2

oooooooo
ooo**ooo
oo*oo*oo
oo*ooo*o
ooo*o*oo
oooo*ooo
oooooooo

p % 4 == 2
p / 2 + 1 + (p / 2) * (p / 2) + p / 2 + p / 2 + 1

oooooooo
ooo**ooo
oo*oo*oo
o*oooo*o
oo*po*oo
ooo**ooo
oooooooo

p % 4 == 3
p / 2 + 1 + (p / 2) * (p / 2) + p / 2 + p / 2 + 1 + p / 2 + 1

oooo*ooo
ooo*o*oo
oo*ooo*o
o*oooo*o
oo*oo*oo
ooo**ooo
oooooooo
oooooooo



oooo*ooo
ooo*o*oo
oo*ooo*o
o*oooop*
oo*poo*o
ooo*o*oo
oooo*ooo
oooooooo


********
o*ooooo*
oo*****o
m +

*/