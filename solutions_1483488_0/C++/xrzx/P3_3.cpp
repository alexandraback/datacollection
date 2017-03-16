#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;


int shift1(int x){return x = (x % 10) *      10 + (x / 10); }
int shift2(int x){return x = (x % 10) *     100 + (x / 10); }
int shift3(int x){return x = (x % 10) *    1000 + (x / 10); }
int shift4(int x){return x = (x % 10) *   10000 + (x / 10); }
int shift5(int x){return x = (x % 10) *  100000 + (x / 10); }
int shift6(int x){return x = (x % 10) * 1000000 + (x / 10); }

int temp[7];
int ind;

int main(){
	int n, i, j,k,l ;
	int a, b;
	int x,y;
	scanf("%d",&n);
	
	for (i = 0 ; i < n ; i++){
		scanf("%d %d",&a,&b);
		y = 0;	
		if (a >= 10) for (j = a ; j <= b ; j++){
				x = j;
				if (x < 100){
					x = shift1(x);
					if ( ( x > 10 ) && ( x > j) && (x <= b) && (x >= a))
						y++;
				} else if (x < 1000){
					for (k = 0 ; k < 2; k ++){
						x = shift2(x);
						temp[k] = x;
						ind = 1;
						for (l = 0 ; (l < k) && (x == temp[l]); l++) ind = 0;
						if ( ind && ( x > 100 ) && ( x > j ) && (x <= b) && (x >= a)) y++;
					}
				}
				else if (x < 10000){
					for (k = 0 ; k < 3; k ++){
						x = shift3(x);
						temp[k] = x;
						ind = 1;
						for (l = 0 ; (l < k) && (x == temp[l]); l++) ind = 0;
						if ( ind && ( x > 1000 ) && ( x > j ) && (x <= b) && (x >= a)) y++;
					}
				}
				else if (x < 100000){
					for (k = 0 ; k < 4; k ++){
						x = shift4(x);
						temp[k] = x;
						ind = 1;
						for (l = 0 ; (l < k) && (x == temp[l]); l++) ind = 0;
						if ( ind && ( x > 10000 ) && ( x > j ) && (x <= b) && (x >= a)) y++;
					}
				}
				else if (x < 1000000){
					for (k = 0 ; k < 5; k ++){
						x = shift5(x);
						temp[k] = x;
						ind = 1;
						for (l = 0 ; (l < k) && (x == temp[l]); l++) ind = 0;
						if ( ind && ( x > 100000 ) && ( x > j ) && (x <= b) && (x >= a) ) y++;
					}
				}
				else if (x < 10000000){
					for (k = 0 ; k < 6; k ++){
						x = shift6(x);
						temp[k] = x;
						ind = 1;
						for (l = 0 ; (l < k) && (x == temp[l]); l++) ind = 0;
						if ( ind && ( x > 1000000 ) && ( x > j ) && (x <= b) && (x >= a)) y++;
					}
				}
		}
		printf("Case #%d: %d\n",i+1, y);
	}
	return 0;
}