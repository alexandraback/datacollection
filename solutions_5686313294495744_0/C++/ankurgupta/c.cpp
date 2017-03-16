#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
using namespace std;
int a[2501],dig[20],n;
char s[30][30],d[30][30];
vector<int> f; 

int isFake() {
	int isFake = 1;
	for(int j= 0; j < f.size()  ; j++) {
		//cout<<"2 " <<s[f[j]]<<" "<<d[f[j]]<<"\n";
   	   for(int i= 0; i < n  ; i++) {
   	   	  int index = f[j];
   	   	  int flag = 1;
   		  for(int k= 0; k < f.size()  ; k++) if(f[k] == i) flag = 0;
   		  if(flag) {
   		  	int  len1 = strlen(s[i]);
   		  	int  len2 = strlen(s[index]);
   		  	int nflag = (len1 == len2);
   		  	for(int k= 0; k < len1  ; k++) {
   		  		if(s[i][k] != s[index][k])
   		  		  nflag = 0;
   		  	}	
   		  	if(nflag) f[j] = -1;
   		  	if(nflag) {
   		  		//cout<<"0 " <<s[i]<<" "<<s[index]<<"\n";
   		  	}
   		  }
   	   }
    }
    for(int k= 0; k < f.size()  ; k++) if(f[k] != -1) isFake = 0;
    return isFake;
}

int isFake1() {
	int isFake = 1;
	for(int j= 0; j < f.size()  ; j++) {
		//cout<<"2 " <<s[f[j]]<<" "<<d[f[j]]<<"\n";
   	   for(int i= 0; i < n  ; i++) {
   	   	  int index = f[j];
   	   	  int flag = 1;
   		  for(int k= 0; k < f.size()  ; k++) if(f[k] == i) flag = 0;
   		  if(flag) {
   		  	
   		  	int len1 = strlen(d[i]);
   		  	int len2 = strlen(d[index]);
   		  	int nflag = (len1 == len2);
   		  	for(int k= 0; k < len1  ; k++) {
   		  		if(d[i][k] != d[index][k])
   		  		  nflag = 0;
   		  	}	
   		  	if(nflag) {
   		  		//cout<<"1 " <<d[i]<<" "<<d[index]<<"\n";
   		  	}
   		  	if(nflag) f[j] = -1;
   		  }
   	   }
    }
    for(int k= 0; k < f.size()  ; k++) if(f[k] != -1) isFake = 0;
    return isFake;
}

int main() {
	int x,c=1;
	cin>>x;
	while(x--) {
        cin>>n;
        
        for(int i= 0; i < n  ; i++) {
        	cin>>s[i]>>d[i];
        }
        int sum = (1<<n) - 1;
        int fakes = 0;

        while(sum > 0) {
        	int s1 = sum, q = 0, index = 0; 
        	f.clear();
        	while(s1 > 0) {
        		if(s1%2 == 1) {
        			f.push_back(index);
        			q++;
        		}		
        		s1/=2;
        		index++;
            }		
            if(q > fakes && isFake() == 1 && isFake1() == 1) fakes = q;
        	sum--;
        }
        printf("Case #%d: %d",c++, fakes);
        printf("\n");
	}
	return 0;
}
