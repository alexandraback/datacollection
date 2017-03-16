/*************************************************************************
    > Fil:		2s.cpp
    > Author:quietsmile
    > Mail:	debingzhangchina@gmail.com
    > Created Time: Sun 12 May 2013 05:15:24 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

int T;
int main(){
	cin >> T; int idx = 0;
    while(T--){
        string ret="";
        int x,y; cin >> x >> y;
        idx++;

        if(x>=0){
            while(x--){
                ret+="WE";
            }
        }else{
            while(x++){
                ret+="EW";
            }
        }

        if(y>=0){
            while(y--){
                ret+="SN";
            }
        }else {
            while(y++){
                ret+="NS";
            }
        }
        cout << "Case #" << idx<<": " << ret << endl;
    }
	return 0;
}
