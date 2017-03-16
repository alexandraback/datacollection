//
//  main.cpp
//  D
//
//  Created by Zhou Sun on 4/12/14.
//  Copyright (c) 2014 Zhou Sun. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int main(int argc, const char * argv[])
{
    freopen("myfile1.txt","r",stdin);
    
    freopen("myfile.txt","w",stdout);
    
    int ts;
    cin>>ts;
    for (int tt=0; tt<ts; ++tt) {
        cout<<"Case #"<<tt+1<<": ";
        int n;
        cin>>n;
        vector<double>a(n,0);
        vector<double>b(n,0);
        for (int i=0; i<n; i++) {
            cin>>a[i];
        }
        for (int i=0; i<n; i++) {
            cin>>b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int i=0;
        int j=0;
        int c=0;
        for (i=0; i<n && j<=n; i++) {
            while (j<n&& a[j]<b[i] ) {
                j++;
            }
            if (j==n) {
                break;
            }
            if (a[j]>b[i]) {
                c++;
            }
            j++;
        }
        cout<<c<<' ';
        i=0;
        j=0;
        c=0;
        for (i=0; i<n && j<=n; i++) {
            while (j<n&& b[j]<a[i] ) {
                j++;
            }
            if (j==n) {
                break;
            }
            if (a[i]<b[j]) {
                c++;
            }
            j++;
        }
        cout<<n-c<<endl;
        }

    
    return 0;
}

