#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <string>

using namespace std;

bool compatible(int *num1, int *num2, int len){
	int i;
	for(i = 0 ; i < len ; i++)
	{
		if(num1[i] == -1)
			continue;
		if(num1[i] != num2[i])
			return false;
	}
	return true;
}

int *getDigits(int number, int length){
	int *digits = new int[length];
	int i = 0;
	for(i = 0 ; i < length ; i++)
		digits[i] = 0;
	i = length - 1;
	while(number > 0)
	{
		digits[i--] = number%10;
		number = number/10;
	}
	return digits;
}

int main(){
	int i,j,k,l;
	int N, T;
	cin>>T;
	string oce, eur;	
	for(l = 0 ; l < T ; l++)
	{
		cin>>oce>>eur;
		int *a,*b;
		a = new int[oce.length()];
		b = new int[eur.length()];
		for(i = 0 ; i < oce.length() ; i++)
		{
			if(oce[i] == '?')
				a[i] = -1;
			else
				a[i] = oce[i] - '0';
			if(eur[i] == '?')
				b[i] = -1;
			else
				b[i] = eur[i] - '0';
		}			
		int maxi = pow(10, oce.length());
		int mini = pow(10, oce.length());
		int *val1, *val2;
		//val1 = val2 = -1;
		for(i = 0 ; i < maxi ; i++){
			int *temp1 = getDigits(i, oce.length());
			if(compatible(b, temp1, oce.length())){
				for(j = 0 ; j < maxi ; j++){
					int *temp2 = getDigits(j, oce.length());
					if(!compatible(a, temp2, oce.length()))
						continue;
					int diff = abs(i - j);
					if(mini > diff){
						mini = diff;
						val1 = temp2;
						val2 = temp1;
					}
					/*else{
						delete[] temp1;
						delete[] temp2;
					}*/
				}
			} 
		}
		cout<<"Case #"<<l+1<<": ";
		for(i = 0 ; i < oce.length() ; i++)
			cout<<val1[i];
		cout<<" ";
		for(i = 0 ; i < oce.length() ; i++)
			cout<<val2[i];
		cout<<"\n";
	}
}
