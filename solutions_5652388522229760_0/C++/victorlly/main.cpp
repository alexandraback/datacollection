//
//  main.cpp
//  CodeJam
//
//  Created by Victor Young on 4/9/16.
//  Copyright © 2016 Victor Young. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
    if(freopen("/Users/Victor/Desktop/output.txt", "w", stdout) == NULL)
        fprintf(stderr,"error redirecting stdout\n");
    if(freopen("/Users/Victor/Desktop/A-small-attempt0.in", "r", stdin) == NULL)
        fprintf(stderr,"error redirecting stdin\n");
    
    int n;
    cin >> n;
    int temp;
    
    for (int i = 0; i<n; i++) {
        cin >> temp;
        int digit[11];
        memset(digit, 0, 11*4);
        int iter = 0;
        int final;
        while (temp) {
            iter ++;
//            temp *= iter;
            final = temp*iter;
            int temp2 = final;
            while (temp2) {
                digit[temp2%10] = 1;
                temp2 = temp2/10;
            }
            int flag = 0;
            for (int k = 0; k<10; k++) {
                if (digit[k]==0) {
                    flag = 1;
                }
            }
            if (flag==0) {
                break;
            }

        }
        if (temp == 0) {
            cout << "Case #"<<i+1<<": INSOMNIA";
        }
        else{
            cout<<"Case #"<<i+1<<": "<<final
            ;
        }
        if (i!=n-1) {
            cout << endl;
        }
    }
    return 0;
}
