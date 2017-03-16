#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	freopen("bullseye.in", "r", stdin);
	freopen("bullseye.out", "w", stdout);
	int run, rad, count; long long vol, used;
	cin >> run;
	for (int a = 1; a <= run; ++a){
		cin >> rad >> vol;
		used = 0;
		used -= rad * rad; ++rad;
		used += rad * rad; ++rad;
		for (count = 0; used <= vol; ++count){
			used -= rad * rad; ++rad;
			used += rad * rad; ++rad;
		}
		cout << "Case #" << a << ": " << count << endl;
	}
	return 0;
}
