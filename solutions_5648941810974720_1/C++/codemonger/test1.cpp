#include <iostream>
#include <stdio.h>
#include <cstring>
#include <sstream>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;
#define sc(x) scanf("%d",&(x))
#define fori(n) for(int i=0;i<n;i++)




int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w",stdout);
	
	int t;
	sc(t);
	for(int z=1;z<=t;z++){
		string s;
		cin>>s;
		int a[10];
		fori(10)a[i]=0;
		int b[26];
		fori(26)b[i]=0;
		fori(s.length()){
			b[s[i]-65]++;
		}	
		//fori(26)cout<<b[i]<<" ";cout<<endl;
		int t1=b['Z'-65];
		a[0]=t1;
		string s1="ZERO";
		fori(s1.length()){
			b[s1[i]-65]-=t1;
		} 

		t1=b['W'-65];
		a[2]=t1;
		s1="TWO";
		fori(s1.length()){
			b[s1[i]-65]-=t1;
		} 

		t1=b['U'-65];
		a[4]=t1;
		s1="FOUR";
		fori(s1.length()){
			b[s1[i]-65]-=t1;
		} 

		t1=b['X'-65];
		a[6]=t1;
		s1="SIX";
		fori(s1.length()){
			b[s1[i]-65]-=t1;
		}

		t1=b['G'-65];
		a[8]=t1;
		s1="EIGHT";
		fori(s1.length()){
			b[s1[i]-65]-=t1;
		} 

		t1=b['F'-65];
		a[5]=t1;
		s1="FIVE";
		fori(s1.length()){
			b[s1[i]-65]-=t1;
		}  

		t1=b['V'-65];
		a[7]=t1;
		s1="SEVEN";
		fori(s1.length()){
			b[s1[i]-65]-=t1;
		}  

		t1=b['O'-65];
		a[1]=t1;
		s1="ONE";
		fori(s1.length()){
			b[s1[i]-65]-=t1;
		}  

		t1=b['T'-65];
		a[3]=t1;
		s1="THREE";
		fori(s1.length()){
			b[s1[i]-65]-=t1;
		} 

		t1=b['I'-65];
		a[9]=t1;
		s1="NINE";
		fori(s1.length()){
			b[s1[i]-65]-=t1;
		}  

		printf("Case #%d: ",z);
		fori(10){
			for(int j=0;j<a[i];j++){
				cout<<i;
			}
		}
		cout<<endl;


	}

		
	

}