/*************************************************************************
    > Fil:		1s.cpp
    > Author:quietsmile
    > Mail:	debingzhangchina@gmail.com
    > Created Time: Sun 12 May 2013 05:04:22 PM CST
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
        int ret = 0;
        idx++;
        string name; cin >> name;
        int n; cin >> n;
        int len = name.size();
        for(int i = 0; i< len; i++){
            int f = 0;
            for(int j = i; j < len ;j ++){
                if(name[j]!='a' && name[j]!='e' && name[j]!='i' && name[j]!='o' && name[j]!='u'){
                    f ++;
                    if(f>=n){
                        ret+=(len-j);
                        break;
                    }
                }
                else {
                f=0;
            }
            } 
        }
        cout << "Case #" << idx<<": " << ret << endl;
    }
	return 0;
}
