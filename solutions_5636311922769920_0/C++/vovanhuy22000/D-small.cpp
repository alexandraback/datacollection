#include <iostream>
#include <set>
#include <time.h>
#include <stdio.h>
#include <fstream>

using namespace std;



int main(){
	// clock_t tStart = clock();
    /* Do your stuff here */
    
	ofstream fout("D-small.out");
    
    int t; cin>>t;
    
    for(int test = 0; test < t; test++){
        int k; cin>>k>>k>>k;
        fout<<"Case #"<<test+1<<": ";
        for(int i = 1; i < k; i++){
            fout<<i<<" ";
        }
        fout<<k<<endl;
    }
    // printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);


	
}
