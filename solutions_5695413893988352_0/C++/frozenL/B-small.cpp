#include <iostream>
using namespace std;

int lX, lY;
string x, y, sRX, sRY;
int rX, rY;

void f(int pX, int pY, int fX, int fY){
//	cout << pX << " " << fX << " " << pY << " " << fY << endl;
	if(pY == lY){
		if(rX == -1 || abs(rX - rY) > abs(fX - fY)){
			sRX = x;
			sRY = y;
			rX = fX;
			rY = fY;
			return ;
		}
		if(abs(rX - rY) < abs(fX - fY) || rX < fX || (rX == fX && rY < fY))
			return ;
		sRX = x;
		sRY = y;
		rX = fX;
		rY = fY;
		return ;
	}
	if(pX == lX){
		if(y[pY] != '?'){
			f(pX, pY + 1, fX, fY * 10 + y[pY] - '0');
		}
		else{
			for(int i = 0; i < 10; i ++){
				y[pY] = i + '0';
				f(pX, pY + 1, fX, fY * 10 + i);
			}
			y[pY] = '?';
		}
	}
	else{
		if(x[pX] != '?'){
			f(pX + 1, pY, fX * 10 + x[pX] - '0', fY);
		}
		else{
			for(int i = 0; i < 10; i ++){
				x[pX] = i + '0';
				f(pX + 1, pY, fX * 10 + i, fY);
			}
			x[pX] = '?';
		}
	}
}

int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; i ++){
		rX = rY = -1;
		cout << "Case #" << i + 1 << ": ";
		cin >> x >> y;
		lX = x.length();
		lY = y.length();
		f(0, 0, 0, 0);
		cout << sRX << " " << sRY << endl;
//		cout << rX << " " << rY << endl;
	}
	return 0;
}

