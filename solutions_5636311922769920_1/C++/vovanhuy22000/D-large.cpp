#include <iostream>
#include <set>
#include <time.h>
#include <stdio.h>
#include <fstream>

using namespace std;

void factor(int a[], int base, int num, int n){
    for(int i = n - 1; i >= 0; i--){
        a[i] = num % base;
        num = num/base;
    }
}

template<typename T>
void display(T a[], int n){
    for(int i = 0; i < n; i++){
        cout<<a[i];
    }
}

long long power(int base, int n){
    long long res = 1;
    for(int i = 0; i < n; i++){
        res *= base;
    }
    return res;
}


int main(){
	// clock_t tStart = clock();
    /* Do your stuff here */
    
	ofstream fout("D-large.out");
    
    int t; cin>>t;
    for(int test = 0; test < t; test++){
    	int k, c, s;
        cin>>k>>c>>s;
        if((k-1)/c+1 > s){
            fout<<"Case #"<<test+1<<": IMPOSSIBLE"<<endl;
            continue;
        }
        else{
            fout<<"Case #"<<test+1<<": ";
            for(int i = 1; i <= (k-1)/c+1; i++){
                long long pos = 0;
                for(int j = 1; j <= c; j++){
                    if((i-1)*c+j <= k){
                        pos += ((i-1)*c+j-1)*power(k, c-j);
                    }
                    //else pos += (k-1)*power(k,c-j);
                }
                pos++;
                if(i < (k-1)/c+1) fout<<pos<<" ";
                else fout<<pos<<endl;
            }
        }


    }
    // printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);


	
}
