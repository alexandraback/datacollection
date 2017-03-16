#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <cmath> 

using namespace std;

int main(){
    //freopen("practice.in","r",stdin);
    freopen("C-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t, j,p,s,k;
    int arr[12][12][12];
    cin >> t;
    for(int q=0;q<t;q++){
        cout << "Case #" << q+1 << ": ";
        cin >> j >> p >> s >> k;
        int count = 0;
        int xy[12][12], yz[12][12], xz[12][12];
        for(int x=0;x<12;x++){
            for(int z=0;z<12;z++){
                xy[x][z] = 0;
                yz[x][z] = 0;
                xz[x][z] = 0;
            }
        }
        bool finish = false;
        for(int x=1;x<=j;x++){
            for(int y=1;y<=p;y++){
                for(int z=1;z<=s;z++){
                    //cout  << xy[x][y] << " " << yz[y][z] << " " << xz[x][z] <<endl;
                    while((xy[x][y]==k||yz[y][z]==k||xz[x][z]==k)&&!finish){
                    if(xy[x][y]==k){
                        if(y<p){y++;z=1;}
                        else if(x<j){x++;y=1;z=1;}
                        else finish = true;
                    }
                    else if(yz[y][z]==k){
                        if(z<s)z++;
                        else if(y<p){y++;z=1;}
                        else finish = true;
                    }
                    else if(xz[x][z]==k){
                        if(z<s)z++;
                        else if(x<j){x++;y=1;z=1;}
                        else finish = true;
                    }
                    }
                    if(xy[x][y]<k && yz[y][z]<k && xz[x][z]<k && !finish){
                        count++;
                        xy[x][y] += 1;
                        xz[x][z] += 1;
                        yz[y][z] += 1;
                    }
                }
            }
        }
        cout << count <<endl;
        finish = false;
        for(int x=0;x<12;x++){
            for(int z=0;z<12;z++){
                xy[x][z] = 0;
                yz[x][z] = 0;
                xz[x][z] = 0;
            }
        }
        for(int x=1;x<=j;x++){
            for(int y=1;y<=p;y++){
                for(int z=1;z<=s;z++){
                    //cout  << xy[x][y] << " " << yz[y][z] << " " << xz[x][z] <<endl;
                    while((xy[x][y]==k||yz[y][z]==k||xz[x][z]==k)&&!finish){
                    if(xy[x][y]==k){
                        if(y<p){y++;z=1;}
                        else if(x<j){x++;y=1;z=1;}
                        else finish = true;
                    }
                    else if(yz[y][z]==k){
                        if(z<s)z++;
                        else if(y<p){y++;z=1;}
                        else finish = true;
                    }
                    else if(xz[x][z]==k){
                        if(z<s)z++;
                        else if(x<j){x++;y=1;z=1;}
                        else finish = true;
                    }
                    }
                    if(xy[x][y]<k && yz[y][z]<k && xz[x][z]<k && !finish){
                        xy[x][y] += 1;
                        xz[x][z] += 1;
                        yz[y][z] += 1;
                        cout  << x << " " << y << " " << z <<endl;
                    }
                }
            }
        }
    }


    return 0;
}