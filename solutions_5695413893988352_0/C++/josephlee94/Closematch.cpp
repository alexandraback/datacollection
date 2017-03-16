#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int T, len;
char num1[20], num2[20];
char num1i[20], num2i[20];
char currabs[20], maxabs[20], bestnum1[20], bestnum2[20];
int maxdiff, small1, small2;

int abs(int x){
	if (x<0) return -x;
	else return x;
}
/*
int check(){
	for(int j=0; j<len; j++){
		currabs[j]=(int)num1i[j]-(int)num2i[j];
	}
	for(int j=0; j<len; j++){
		if(currabs[j]<maxabs[j]){
			
		}
	}
	
	
}*/
int pwof(int x){
	int c = 1;
	for(int k = 0; k<x; k++) c*=10;
	return c;
}

int check(){
	int currdiv = 0, curr1 = 0, curr2 = 0;
	//cout << "Check " << num1i << " " << num2i << endl;
	for(int j=0; j<len; j++){
	//	cout << "sigh: " << (int)num1i[j] << " " << pwof(len-j-1) << " " << curr1 << endl; 
		curr1+=((int)num1i[j]-'0')*pwof(len-j-1);
		curr2+=((int)num2i[j]-'0')*pwof(len-j-1);
		
	//	cout << j << ": " << curr1 << " " << num1i[j] << " " <<curr2 << " "<< num2i[j] << endl;
	}
	currdiv=curr1 - curr2;
	//cout << "currdiv is "<< currdiv << " " << curr1 << " " << curr2 << " " << endl;
	if(abs(currdiv)<maxdiff){
		maxdiff = abs(currdiv);
		small1 = curr1;
		small2 = curr2;
		//cout << maxdiff << " max here " << endl;
		for(int j=0; j<len; j++){
			bestnum1[j]=num1i[j];
			bestnum2[j]=num2i[j];
		}
	}
	
	else if (abs(currdiv)==maxdiff){
	//	cout << small1 << " " << curr1 << " " << small2 << " " << curr2 << endl;
		if(curr1 < small1){
			small1 = curr1;
			for(int j=0; j<len; j++){
			bestnum1[j]=num1i[j];
			bestnum2[j]=num2i[j];
			}	
		}
		else if(small1 == curr1){
			if(curr2 < small2){
				small2 = curr2;
				for(int j=0; j<len; j++){
					bestnum1[j]=num1i[j];
					bestnum2[j]=num2i[j];
				}
			}
		}
	}
}

int bfs(int pos){
//	cout << "pos is " << pos << endl;
	if(pos == len){
		check();
	}
	else if(num1[pos]=='?' && num2[pos]=='?'){
		for(int k = '0'; k<='9'; k++){
				for(int l = '0'; l<='9'; l++){
				num1i[pos]=k;
				num2i[pos]=l;
				bfs(pos+1);
			}
		}
	}
	
	else if(num1[pos]=='?'){
		num2i[pos]=num2[pos];
		
		for(int k = '0'; k<='9'; k++){
				num1i[pos]=k;
				bfs(pos+1);
		}
	}
	
	else if(num2[pos]=='?'){
		num1i[pos]=num1[pos];
		
		
		for(int k = '0'; k<='9'; k++){
				num2i[pos]=k;
				bfs(pos+1);
		}
	}	
	
	else{
		
		num1i[pos]=num1[pos];
		
		num2i[pos]=num2[pos];
		
		bfs(pos+1);
	}
		
}

int main(){
	
	cin >> T;
	
	for (int i=1; i<=T; i++){
		cin >> num1 >> num2;
		cout << "Case #" << i << ": ";
		len = strlen(num1);
	//	for(int j=0; j<20; j++) maxabs[j]=9;
		maxdiff = 100000;
		bfs(0);
		for(int j=0; j<len; j++) cout << bestnum1[j];
		cout << " ";
		for(int j=0; j<len; j++) cout << bestnum2[j];
		cout << endl;
	}
}
