#include<iostream>
#include<stdio.h>
#include<fstream>
#include<cmath>
using namespace std;
/*
int main(){
	int CaseNum;
	ifstream in;
	ofstream out;
	in.open("test.txt");
	out.open("out.txt");
	in>>CaseNum;
	for(int Case=0;Case<CaseNum;Case++){


	out<<"Case #"<<Case+1<<": "<<endl;
	}
	out.clear();
	out.close();
	return 0;
}
*/
int power[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int main(){
	int CaseNum;
	ifstream in;
	ofstream out;
	in.open("C-large.in");
	out.open("out.txt");
	in>>CaseNum;
	int A,B,n,num,temp,used[10];
	for(int Case=0;Case<CaseNum;Case++){
		in>>A>>B;
		n=int(floor(log10(double(A))))+1;
		num=0;
		for(int i=A;i<B;i++){
			temp=i;
			for(int j=1;j<n;j++){
				temp=(temp%10)*power[n-1]+(temp/10);
				if(int(log10(double(temp)))+1<n)continue;
				used[j]=-1;
				if(temp>i&&temp<=B){
					int k;
					for(k=1;k<j;k++)
						if(used[k]==temp){
							break;
						}
				    if(k>=j){
						num++;
						used[j]=temp;
					}
				}

			}

		}

	out<<"Case #"<<Case+1<<": "<<num<<endl;
	}
	out.clear();
	out.close();
	return 0;
}