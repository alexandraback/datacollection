//
//  main.cpp
//  pb
//
//  Created by Mac on 13/5/12.
//  Copyright (c) 2013年 Mac. All rights reserved.
//
#include <math.h>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    ofstream cout("/Users/macintosh/Downloads/000GCJ/B-small.out");
    ifstream cin("/Users/macintosh/Downloads/000GCJ/B-small.in");
    int t;
    cin>>t;
    for (int cnt=0; cnt<t; cnt++) {
        int x,y,a=0,b=0,i;
        cin>>x>>y;
        cout<<"Case #"<<cnt+1<<": ";
        if(x>0){
            i=-1;
        }else{
            i=1;
        }
        while(a!=x){
            a+=i;
            cout<<(i<0?"W":"E");
            i=-i+(i>0?-1:1);
        }
        if(y>0){
            if(i>0)
                i=-i;
        }else{
            if(i<0)
                i=-i;
        }
        while (b!=y) {
            b+=i;
            cout<<(i<0?"S":"N");
            i=-i+(i>0?-1:1);
        }
        cout<<endl;
    }
    return 0;
}

