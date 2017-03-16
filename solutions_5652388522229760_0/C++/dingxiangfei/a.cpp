//
//  a.cpp
//  
//
//  Created by Xiang Fei Ding on 4/9/16.
//
//

#include <iostream>
#include <bitset>
using std::cin;
using std::cout;
using std::endl;
using std::bitset;

int main() {
    int t;
    cin>>t;
    for (int i=0;i<t;++i) {
        cout<<"Case #"<<i+1<<": ";
        unsigned long long int n, m, c;
        unsigned int s = 0;
        cin>>n;
        if (n) {
            c = n;
            while (s != 0x3ff) {
                m = c;
                while (m) {
                    s |= 1 << (m % 10);
                    m /= 10;
                }
                if (s == 0x3ff)
                    cout<<c<<endl;
                c += n;
            }
        } else {
            cout<<"INSOMNIA"<<endl;
        }
    }
    return 0;
}
