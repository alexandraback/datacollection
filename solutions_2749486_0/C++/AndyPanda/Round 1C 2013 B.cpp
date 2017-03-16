#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

long T, x, y;

int main(){
	freopen("B-small-attempt2.in","r",stdin);freopen("stdout.txt","w",stdout);
	cin >> T;
	for (int h=1; h<=T; h++){
		cin >> x >> y;
		cout << "Case #" << h << ": ";
		while (x > 0){
			cout << "WE"; x--;
		}
		while (x < 0){
			cout << "EW"; x++;
		}
		while (y > 0){
			cout << "SN"; y--;
		}
		while (y < 0){
			cout << "NS"; y++;
		}
		cout << endl;
	}
	return 0;
} 
