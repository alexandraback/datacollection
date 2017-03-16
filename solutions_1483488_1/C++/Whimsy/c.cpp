/*
 * c.cpp
 *
 *  Created on: 2012-4-14
 *      Author: whimsy
 */
#include<iostream>
#include<cstdio>

using namespace std;

int a,b,Test;
int tmp,tot,base,ans = 0;
int num = 0,arr[10],flag;
void work(){

	cin >> a >> b;
	//cout << a << b << endl;

	ans = 0;
	for (int i = a;i<=b;++i){
		tmp = i;
		tot = 0;
		base = 1;
		while (tmp>=10){
			++tot;
			tmp /= 10;
			base *= 10;
		}
//		cout << i << endl;
		tmp = i;
		num = 0;
		for (int k = 0;k<tot;++k){
			tmp = tmp % 10 * base + tmp / 10;
//			cout << tmp << " ";
			if (tmp>i && tmp<= b) {
				flag = 1;
				for (int kk = 0;kk<num;++kk) {
					if (arr[kk] == tmp) flag = 0;
				}
				if (!flag) continue;
				++ ans;
				arr[num++] = tmp;
//				cout << ans <<":"<< i <<"->"<< tmp << endl;
				//				cout << "*           ";
		//		break;
			}
		}
		//cout << endl;
	}
	cout << ans << endl;
}

int main(){
	freopen("in.txt","r",stdin);
	freopen("c.txt","w",stdout);
	cin >> Test;
	for (int ii = 1;ii<=Test;++ii){
		printf("Case #%d: ",ii);
		work();
//		if (ii==2) break;
	}
}
