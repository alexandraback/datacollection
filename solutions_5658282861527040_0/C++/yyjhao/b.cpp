#include <iostream>

using namespace std;

int main() {
    int t;
    cin>>t;
    for (int ca = 0; ca < t; ca++) {
        int a, b, k;
        cin>>a>>b>>k;
        int c = 0;
        for (int i = 0; i < a; i++)for(int j = 0; j < b; j++) {
            if ((i & j) < k) {
                c++;
            }
        }
        cout<<"Case #"<<(ca+1)<<": "<<c<<endl;
    }
    return 0;
}