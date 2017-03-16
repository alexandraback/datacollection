#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

long T, xx, yy;

int main(){
	freopen("B1.in","r",stdin);freopen("b1.out","w",stdout);
	cin>>T;
	for (int h=1; h<=T; h++){
		cin >> xx >> yy;
		cout << "Case #" << h << ": ";
		while (xx> 0){
			cout <<"WE"; xx--;
		}
		while (xx < 0){
			cout <<"EW"; xx++;
		}
		while (yy > 0){
			cout <<"SN"; yy--;
		}
		while (yy<0){
			cout << "NS"; yy++;
		}
		cout << endl;
	}
	return 0;
} 
