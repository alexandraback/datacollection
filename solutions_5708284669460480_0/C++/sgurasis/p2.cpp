#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<stdio.h>
using namespace std;
int counter;
int summ,s,l;
char key[20],l1[20];
int max1;
int count(char a[],char l2[]){
	int c=0;
	for(int i=0;i<s;i++){
		if(a[i]==l2[0])	{
			int i1=i;
			int j=0;
			while(j<l){
				if(i1==s) break;
				if(a[i1]==l2[j]){i1++;j++; }
				else break;
			}	
			if(j==l) c++;
		
		}
	
	
	}

	return c;
}
float  func(int in,char a[],int ar[]){
	int sm=0;
	//cout<<in<<" "<<s<<endl;
	if(in == s){
		a[in]='\0';
		counter++;
		int c= count(a,l1);
		if(c>max1) max1= c;
//		cout<<counter<<endl;
		return c;
				
	
	}
	//cout<<strlen(key)<<endl;
	for(int i=0;i<strlen(key);i++){
		a[in]=key[i];
		sm+=func(in+1,a,ar);
	
	
	}
	if(in==0) {setprecision(6);return sm*1.0/counter;}
	return sm;
}


int main(){
	
	long int t,i1,k;
	s=5;
	l=3;

	cin>>t;
	char ar[20];

	int arr[20];

		
	for (i1=1;i1<=t;i1++){
		cin>>k;
		max1=0;
		for(int i=0;i<20;i++) arr[i]=0;
		cin>>l;
		cin>>s;
		cin>>key;
		cin>>l1;
		counter = 0;
		summ =0;
		float v = func(0,ar,arr);
		
		cout<<"Case #"<<i1<<": ";
		printf("%.6f\n",1.0*max1-v);
		

	}
	


}

