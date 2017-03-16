#include <cstdio>
#include <cstring>
#include <algorithm>
#include<iostream>
#include<fstream.h>
using namespace std;
//Define Global Variables Here
long long e,r,n;
long long v[12];
long long maximum;

long long recurse(long long c,long long i,long long g)
{
    if (i>=n) {
        return g;
    }
    if (e<0) {
        return g;
    }
    for (int j=0; j<=c; j++) {
        if ((c-j+r)>e) {
        long long newmax1 = recurse(e,i+1,g+(v[i]*j));
            maximum = newmax1>maximum?newmax1:maximum;
        }
        else{
            long long newmax = recurse(c-j+r,i+1,g+(v[i]*j));
            maximum = newmax>maximum?newmax:maximum;
            }
        
        }
    return maximum;
}
int main() {
   ofstream myfile;
    myfile.open ("2small.txt");
    int tc; scanf("%d\n", &tc);
    for(int g = 0; g < tc; g++) {
        cin>>e>>r>>n;
        for (int i = 0; i<n; i++) {
            cin>>v[i];
        }
        maximum = -1;
       long long ans =  recurse(e,0,0);
        myfile<<"Case #"<<g+1<<": "<<ans<<endl;
    }
    

    
    return 0;
}

