#include <iostream>
#include <set>
#include <time.h>
#include <stdio.h>
#include <fstream>

using namespace std;

int trace[10];

int main(){
	// clock_t tStart = clock();
    /* Do your stuff here */
    
	ofstream fout("A.out");
    
    int t; cin>>t;
    for(int test = 0; test < t; test++){
    	int n; cin>>n;
    	if(n == 0){
    		fout<<"Case #"<<test+1<<": INSOMNIA"<<endl;
    		continue;	
    	} 

    	for(int i = 0; i < 10; i++) trace[i] = 0;
    	int count = 0;

    	for(int i = 1; ;i++){
    		int curr = n*i;
    		while(curr > 0){
    			if(trace[curr%10] == 0){
    				trace[curr%10] = 1;
    				count++;
    			}
    			curr = curr/10;
    		}
    		if(count == 10){
    			fout<<"Case #"<<test+1<<": "<<n*i<<endl;
    			break;
    		}
    	}

    }
    // printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);


	
}
