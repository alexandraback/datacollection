#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <math.h>
#include <stack>
#include <bitset>

using namespace std;


#define ii pair<int,int>
#define iii pair<int,ii>
typedef long long ll;
typedef unsigned long long ull;


int main (){

	//freopen("A-small-attempt0.in","r",stdin);	freopen("output.txt","w",stdout);

	int ta;

	scanf("%d",&ta);

	int r,t;
	int hitung;
	int butuh;

	int sekarang,past;

	for(int kasus=1;kasus<=ta;kasus++){

		hitung=0;

		scanf("%d %d",&r,&t);

		while(t>=0){

			sekarang=r+1;
			past=r;

			butuh=sekarang*sekarang-past*past;

			t-=butuh;

			if(t>=0)hitung++;

			r+=2;
		}

		printf("Case #%d: ",kasus);

		printf("%d\n",hitung);

	}


}





