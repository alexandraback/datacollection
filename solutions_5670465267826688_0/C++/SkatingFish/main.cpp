//
//  main.cpp
//  Dijkstra
//
//  Created by Liubing Yu on 4/10/15.
//  Copyright (c) 2015 Liubing Yu. All rights reserved.


#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;
ifstream ifs ("/Users/yuliubing/Desktop/input.txt", std::ifstream::in);
ofstream ofs ("/Users/yuliubing/Desktop/output.txt", std::ofstream::out);

int p[8][8] ={
    {0, 1, 2, 3, 4, 5, 6, 7},
    {1, 4, 3, 6, 5, 0, 7, 2},
    {2, 7, 4, 1, 6, 3, 0, 5},
    {3, 2, 5, 4, 7, 6, 1, 0},
    {4, 5, 6, 7, 0, 1, 2, 3},
    {5, 0, 7, 2, 1, 4, 3, 6},
    {6, 3, 0, 5, 2, 7, 4, 1},
    {7, 6, 1, 0, 3, 2, 5, 4}};

int t[10001],t1[10001],t2[10001];
int pr(int i, int j)
{
    return p[i][j];
}

int divBy1( int result, int m){
    int i =0;
    for(i = 0; i < 8; i++){
        if (p[m][i] == result)
            break;
    }
    return i;
}

int divBy2( int result, int m){
    int i =0;
    for(i = 0; i < 8; i++){
        if (p[i][m] == result)
            break;
    }
    return i;
}

void go(int n, long long m){
    
    int wh = 0; //the whole product
    int rh = 0; //the product from right
    char temp;
    cout << n <<"  " << m <<" ";
    for ( int i = 0; i < n; i++){
        ifs >> temp;
        t[i] = temp -'h';
        t1[i]= pr(wh, t[i]);
        wh = t1[i];
    }
    cout << wh;
    for ( int i = n-1; i >= 0; i--){
        t2[i]= pr(t[i], rh);
        rh = t2[i];
    }
    cout << rh;
    if(wh == 0){
        cout << "NO1";
        ofs << "NO";
        return;
    }
    else if(wh == 4){
        if((m % 2) == 0){
            cout << "NO2";
            ofs << "NO";
            return;
        }
    }
    else{
        if((m % 2) != 0 || (m % 4) ==0){
            cout << "NO3";
            ofs << "NO";
            return;
        }
    }
    
    int final1  = 1;
    int i1 = 0;
    int num1 = 0;
    for (num1 = 0; num1 < 4; num1 ++){
        for ( i1 = 0; i1 < n; i1++){
            if (t1[i1] == final1)
                break;
        }
        if(t1[i1] ==final1)
            break;
        final1 = divBy1(final1, wh);
    }
    if( i1 == n)
    {
        cout << "NO4";
        ofs << "NO";
        return;
    }
    
    int final2  = 3;
    int i2 = n-1;
    int num2 = 0;
    for (num2 = 0; num2 < 4; num2 ++){
        for ( i2 = n-1; i2 >= 0; i2--){
            if (t2[i2] == final2)
                break;
        }
        if(t2[i2] ==final2)
            break;
        final2 = divBy2(final2, wh);
    }
    cout << num2 << i2 <<endl;
    if( i2 == -1)
    {
        cout << "NO5";
        ofs << "NO";
        return;
    }
    cout <<num1 <<" v"<<num2<<" s"<<endl;

    int tot = num1 + num2 +1;
    if(i2 <= i1) tot++;
    if(tot <= m){
        cout << "YES";
        ofs << "YES";
    }
    else {
        cout << "NO6";
        ofs << "NO";
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n,l;
    long long x = 0;
    
    ifs >> n;
    cout << n <<" a"<<endl;
    for (int i = 0; i < n; i++){
        ifs >> l >> x;
        cout << "Case #" << i + 1 << ": ";
        ofs << "Case #" << i + 1 << ": ";
        go(l, x);
        cout << endl;
        ofs << endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
