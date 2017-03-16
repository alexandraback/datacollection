//
//  main.cpp
//  Omino
//
//  Created by Liubing Yu on 4/11/15.
//  Copyright (c) 2015 Liubing Yu. All rights reserved.
//


#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;
ifstream ifs ("/Users/yuliubing/Desktop/input.txt", std::ifstream::in);
ofstream ofs ("/Users/yuliubing/Desktop/output.txt", std::ofstream::out);

void go(int x, int r, int c){
    cout << x << r << c <<endl;
    if( (r*c)%x) //filling in condition
    {
        cout << "NO1";
        ofs << "RICHARD";
        return;
    }
    if(r <x && c <x) //stright line condition
    {
        cout << "NO2";
        ofs << "RICHARD";
        return;
    }
    if(r< (x+1)/2 || c<(x+1)/2) //triangle condition
    {
        cout << "NO3";
        ofs << "RICHARD";
        return;
    }
    if(x >= 7) //7 means die
    {
        cout << "NO4";
        ofs << "RICHARD";
        return;
    }
    if(x == 1) //1 will survive
    {
        cout << "YES1";
        ofs << "GABRIEL";
        return;
    }
    
    //get the long and short edge
    int l = max(r, c);
    int s = min(r, c);
    
    if(x == 6 && s == 3) //7 means die
    {
        cout << "NO5";
        ofs << "RICHARD";
        return;
    }
    //the hard one now will be how to fit the short edge
    //It will always fit the long edge
    int l1 = (x + 2)/2;
    int s1 = x + 1 -l1;
    
    if(s1 <s) //it means the it will give both edge space
    {
        cout << "YES2";
        ofs << "GABRIEL";
        return;
    }
    else if(s1 > s)
    {
        cout << "ERROR \n\n\n\n\n";
        ofs << "GABRIEL";
        return;
    }
    
    //since it will hold the width, it will divide into two separate area
    // with some hole in each side to be filled in, it value could be varied
    int tspace = l1 * s1 - x;
    int lspace = 1;
    int rspace = tspace - lspace;
    
    int emore = 0; //need more edge to add
    int maxEmore = 0;
    for(; lspace <= rspace; lspace++, rspace--)
    {
        for(emore =0; emore < x; emore ++)
        {
            if((emore *s + lspace) %x ==0)
            {
                break;
            }
        }
        if(emore == x)
        {
            cout << "NO6";
            ofs << "RICHARD";
            return;
        }
        maxEmore = max(maxEmore, emore);
    }
    
    if(maxEmore + l1 > l)
    {
        cout << "NO7";
        ofs << "RICHARD";
        return;
    }
    else
    {
        cout << "YES3";
        ofs << "GABRIEL";
        return;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n,l, x ,c;
    
    ifs >> n;
    cout << n <<" a"<<endl;
    for (int i = 0; i < n; i++){
        ifs >> l >> x >> c;
        cout << "Case #" << i + 1 << ": ";
        ofs << "Case #" << i + 1 << ": ";
        go(l, x, c);
        cout << endl;
        ofs << endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
