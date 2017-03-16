//============================================================================
// Name        : CodeJam2013.cpp
// Author      : Gaurav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<stdio.h>
#include<algorithm>

#include<vector>
#include<stack>
#include<math.h>
#include<fstream>
#include<string.h>
using namespace std;



int eval(char* str,int N){
	int len= strlen(str),i,j,k;
	int tot=0,result=0;
	for(i=0;i<len;i++)
	{
		for(j=i;j<len;j++){
			tot=0;
			for(k=i;k<=j;k++){
				if(str[k]=='a' || str[k]=='e' ||str[k]=='i' ||str[k]=='o' ||str[k]=='u' )
				{
					tot=0;
				}
				else tot++;
				if(tot==N){
					result++;
					tot=0;
					break;
				}

			}
		}
	}

	return result;


}

int main() {

	ofstream file;
	file.open("out.txt");
	int i,j,k,T,N;
	char str[101];


	scanf("%d",&T);

	for(i=0;i<T;i++){

		scanf("%s %d",str,&N);


		printf("Case #%d: %d\n",i+1,eval(str,N));}

	file<<"Case #"<<i+1<<": "<<eval(str,N)<<"\n";

}

