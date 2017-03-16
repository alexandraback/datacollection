//
//  main3.cpp
//  CodeJam
//
//  Created by Victor Young on 4/9/16.
//  Copyright © 2016 Victor Young. All rights reserved.
//

#include<stdlib.h>
#include<stdio.h>
#include <iostream>
#include <math.h>
#include <sstream>      // std::stringstream
#include <vector>
using namespace std;

long long is_prime(long long num)
{
    if (num <= 2) return 1;
    if (num % 2 == 0) return 2;
    int top = (int)sqrt((double)num)+1;
    top = 100;
    for(int i = 3; i < top; i+= 2)
    {
        if (num % i == 0)
            return i;
    }
    return 1;
}

int isjamcoin(string a,vector<long long>& result){
    
    for (int index = 2; index<=10; index++) {
        long long sum = 0;
        for (int i = 0; i<a.length(); i++) {
            sum = sum + (a[i]-'0') * pow(index, a.length()-i-1);
        }
        long long temp = is_prime(sum);
        if (temp==1) {
            return 0;
        }
        result.push_back(temp);
    }
    return 1;
}

int main(){
    int n;
    
    if(freopen("/Users/Victor/Desktop/output.txt", "w", stdout) == NULL)
        fprintf(stderr,"error redirecting stdout\n");
    if(freopen("/Users/Victor/Desktop/in.txt", "r", stdin) == NULL)
        fprintf(stderr,"error redirecting stdin\n");

    cin >> n;
    for (int i = 0; i<n; i++) {
        int N,J;
        cin >> N >> J;
        int max = (int)pow(2,N-2);
        string a;
        cout << "Case #"<<i+1<<":" << endl;
        int num = 0;
        for (int j = 0; j < max; j++) {
            
//            char str[30];
            string mid = "";
//            for (int l=0; l<30; l++) {
//                str[l]='0';
//            }
            int tempj = j;
//            int tempk = 29;
            while(tempj)
            {
//                char tempa = '0'+tempj%2;
                if (tempj%2) {
                    mid = "1" + mid;
                }
                else{
                    mid = "0" + mid;
                }
//                mid =mid + '0'+tempj%2;
                tempj=tempj/2;
            }
            int len = mid.length();
            for (int l = 0; l< N-2-len; l++) {
                mid = "0" + mid;
            }
//            char str[33];
//            itoa(j, str, 2);
//            stringstream ss;
//            ss << j;
            
            a = '1' + mid + '1';
            vector<long long> result;
            if (isjamcoin(a,result)) {
                cout << a;
                for (int k =0; k<9; k++) {
                    cout << " " << result[k];
                }
                cout << endl;
                num++;
                result.clear();
            }
            if (num>=J) {
                break;
            }
        }
    }
}