#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;
int p[100][100];
int main() {
	int x,c=1;
	cin>>x;
	while(x--) {
        long long b, m, maxNo = 1;
        cin>>b>>m;
        
        for(int i = 2; i < b; i++) {
           maxNo = maxNo * 2;
        }   
        printf("Case #%d: ",c++);     
        
        if(m > maxNo) {
        	printf("IMPOSSIBLE\n"); 
        } else {
        	printf("POSSIBLE\n"); 
        	
        	for(int i = 0; i < b; i++) {
        		for(int j = 0; j < b; j++) {
        			if(j > i) p[i][j] = 1;
        			else p[i][j] = 0;
        	    }	
        	}	

        	maxNo = maxNo - m;
        	int index = 0;
        	while(maxNo > 0) {
        		if(maxNo%2 == 1) {
        			p[0][b-2-index] = 0;
        		}			
        		maxNo = maxNo/2;
        		index++;
        	}		
        	
        	for(int i = 0; i < b; i++) {
        		for(int j = 0; j < b; j++) {
        			cout<<p[i][j]; 
        	    }	
        	    cout<<"\n";
        	}	
		}	
	}
	return 0;
}
