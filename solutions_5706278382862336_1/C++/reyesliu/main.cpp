//
//  main.cpp
//  part elf
//
//  Created by Minghui Liu on 5/11/14.
//  Copyright (c) 2014 Minghui Liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

long helper(long a, long b){
    if(a>b){
        long tmp = b;
        b=a;
        a=tmp;
    }
    if(a==0){
        return b;
    }else{
        long tmp = b%a;
        b = a;
        a = tmp;
        return helper(a,b);
    }
}


void solve(int i, long numerator, long denominator){
    if(numerator > denominator){
        cout<<"Case #"<<i+1<<": impossible"<<endl;
    }else{
        int j;
        long gcd = helper(numerator,denominator);
        //cout<<gcd;
        numerator = numerator/gcd;
        denominator = denominator/gcd;
        long tmp = denominator;
        //cout<<numerator<<endl;
        //cout<<tmp<<endl;
        bool flag = false;
        for(j=1;j<=40;j++){
            if(denominator==1){
                flag = true;
                break;
            }
            else if(denominator%2==1){
                break;
            }else{
                denominator/=2;
            }
        }
        int counter=0;
        if(flag==true){
            for(j=1;j<=40;j++){
                counter++;
                numerator*=2;
                if(numerator>=tmp){
                    break;
                }
            }
            cout<<"Case #"<<i+1<<": "<<counter<<endl;
        }else{
        cout<<"Case #"<<i+1<<": impossible"<<endl;
        }
    }
}



int main(int argc, const char * argv[])
{
    freopen("/Users/minghui/Documents/C++/A-large.in.txt", "r", stdin);
    freopen("/Users/minghui/Documents/C++/A-large.out.txt", "w", stdout);
    int T;
    cin>>T;
    int i;
    for(i=0;i<T;i++){
        string tmp1,tmp2;
        long numerator, denominator;
        getline(cin,tmp1,'/');
        getline(cin,tmp2);
        //cout<<tmp2;
        stringstream ss,ss1;
        ss<<tmp1;
        ss>>numerator;
        ss1<<tmp2;
        ss1>>denominator;
        //cout<<numerator<<" "<<denominator<<endl;
        solve(i,numerator,denominator);
    }
    return 0;
}
/*
int main(){
    string numerator, denominator;
    int numeratorN;
    getline(cin,numerator,'/');
    getline(cin,denominator);
    stringstream ss;
    ss<<numerator;
    ss>>numeratorN;
    cout << numeratorN<<" "<<denominator<<endl;
}
*/