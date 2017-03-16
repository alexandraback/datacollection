#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;
  static const unsigned int table[] = {1, 1, 2, 6, 24, 120, 720,
    5040, 40320, 362880, 3628800, 39916800, 479001600};
bool check(string a[],int m){
	char c[27];
	for(int i=1;i<27;i++)c[i]=96+i;
	char d;
	for(int i=0;i<m;i++){
		for(int u=0;u<a[i].length();u++){
			if(i==0 && u==0){d=(a[0])[0];c[(int)d-96]=NULL;}
			else if(a[i][u]!=d){d=a[i][u];if(c[(int)d-96]==NULL)return false;c[(int)d-96]=NULL;continue;}
		}
	}
	return true;
}

int count(string a[],int m){
	long int count1=0;
	for(int i=table[m];i>0;i--){
		if(check(a,m))count1++;
		next_permutation(a,a+m);
	}
	return count1;	
	}
int main(){
	long int k;
	cin>>k;
	for(long int i=0;i<k;i++){
	cout<<"Case #"<<i+1<<":";
	int m;
	cin>>m;
	string a[m];
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	long int haha=count(a,m);
	if(haha==0){cout<<" 0 "<<endl;}
	else {cout<<" "<<haha<<endl;}
	}
	return 0;
	
	}
