//
//  main.cpp
//  C
//
//  Created by 珏吉 杨 on 12-5-6.
//  Copyright (c) 2012年 zju. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{
    freopen("C-small-attempt0.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
    int t,i,n,j,k,l,flag;
    int array[20];
    int set[1<<20];
    cin >> t;
    for (i = 0; i<t; i++) {
        memset(set, 0, sizeof(set));
        cin >> n;
        for (j = 0; j<20; j++) {
            cin >> array[j];
        }
        for (j = 0; j<(1<<20);j++){
            for (k = 0; k < 20; k++) {
                if(j&(1<<k)){
                    set[j]+=array[k];
                }
            }
        }
        flag = 0;
        for (j = 1; j<(1<<20);j++) {
            for (k = j+1; k<(1<<20); k++) {
                if (set[j]==set[k]&&(j&k)==0) {
                    cout << "Case #"<< i+1 <<":" << endl;
                    for (l = 0; l<20; l++) {
                        if (j&(1<<l)) {
                            if (flag == 0) {
                                flag = 1;
                                cout << array[l];
                            }
                            else {
                                cout << " " << array[l];
                            }
                        }
                    }
                    cout << endl;
                    flag = 0;
                    for (l = 0; l<20; l++) {
                        if (k&(1<<l)) {
                            if (flag == 0) {
                                flag = 1;
                                cout << array[l];
                            }
                            else {
                                cout << " " << array[l];
                            }
                        }
                    }
                    cout << endl;
                    goto END;
                }
            }
        }
    END:;
    }
    return 0;
}

