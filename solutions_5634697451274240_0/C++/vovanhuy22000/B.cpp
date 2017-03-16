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
    
	ofstream fout("B.out");
    
    int t; cin>>t;
    for(int test = 0; test < t; test++){
    	string s; cin>>s;
        int curr = s.length()-1;
        int count = 0;
        while(curr >= 0){
            int pos = -1;
            for(int i = 0;i <= curr; i++){
                if(s[i] == '-') pos = i;
            }
            if(pos == -1){
                //fout<<"Case #"<<test+1<<": "<<count<<endl;
                break;
            }
            for(int i = 0; i <= pos; i++){
                if(s[i] == '-') s[i] ='+';
                else s[i] = '-';
            }
            curr = pos - 1;
            count++;
        }
        fout<<"Case #"<<test+1<<": "<<count<<endl;

    }
    // printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);


	
}
