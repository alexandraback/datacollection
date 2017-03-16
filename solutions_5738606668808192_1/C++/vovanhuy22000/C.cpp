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


int main(){
	// clock_t tStart = clock();
    /* Do your stuff here */
    
	ofstream fout("C.out");
    
    int t; cin>>t;
    for(int test = 0; test < t; test++){
    	int N, J;
        cin>>N>>J;
        fout<<"Case #"<<test+1<<":"<<endl;
        int a[N/2-1];
        for(int i = 0; i < J; i++){
            factor(a, 2, i, N/2-1);
            char s[N];
            s[0] = '1';
            for(int k = 1; k <= N/2-1; k++){
                s[2*k-1] = s[2*k] = (char)(a[k-1]+48);
            }
            s[N-1] = '1';
            for(int k = 0; k < N; k++){
                fout<<s[k];
            }
            fout<<" "<<3<<" "<<4<<" "<<5<<" "<<6<<" "<<7
                    <<" "<<8<<" "<<9<<" "<<10<<" "<<11<<endl;
        }


    }
    // printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);


	
}
