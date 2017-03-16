#pragma comment(linker, "/STACK:268435456")

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>
#include <bitset>
#include <math.h>
#include <stdio.h>
#include <limits.h>
#include <stack>

using namespace std;

char* itoa1(int a,int pow){
	char *pom = new char[pow];
	for(int i=1 ; i <= pow ; i++){
		pom[pow-i] = a%10;
		a/=10;
	}
	return pom;
}

int atoi1(char *numb,int pow){
	int res=0,k=1;
	for(int i=pow-1 ; i >= 0 ; i--){
		res+=numb[i]*k;
		k*=10;
	}
	return res;
}

int shiftLeft(char *temp,int k,int pow){
	int l;
//	char *temp = itoa1(a,pow);
	//itoa(a,temp,10);
	l = pow;
	char *pom = new char[l];
	for(int i = 0 ; i < k ; i++){
		pom[l-k+i] = temp[i];
	}
	for(int i = k ; i < l ; i++){
		pom[i-k] = temp [i];
	}
//	int res = atoi(pom);
	int res = atoi1(pom,pow);
	delete pom;
	//delete temp;
	return res;
}

int getPow(int a){
	int res=0;
	while(a){
		a/=10;
		res++;
	}
	return res;
}

int main(){
	ofstream myout("C-small-attempt0.out");
	ifstream myin("C-small-attempt0.in");
	int t,a,b;
	myin >> t;
	char *temp = new char[10];
	for(int i=0 ; i<t ; i++){
		myout << "Case #" << i+1 << ": ";
		myin >> a >> b;
		int stepen = getPow(a),resoult=0;
		for(int j = a ; j < b ; j++){
			int buffer[10];
			temp = itoa1(j,stepen);
			for(int l = 1 ; l < stepen ; l++){
				int pom = shiftLeft(temp,l,stepen);
				if(j < pom && pom <= b ){
					bool ok = true;
					for(int i = 0 ; i < l-1 ; i++){
						if(buffer[i] == pom) ok = false;
					}
					if(ok)
					resoult++;
				}
				buffer[l-1]=pom;
			}
			
		}
		myout << resoult;
		myout << endl;
	}

//	cout << shiftLeft(1234,1,4);
}