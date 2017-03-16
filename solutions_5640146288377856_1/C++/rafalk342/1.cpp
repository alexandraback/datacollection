#include <iostream>
using namespace std;

main(){
    ios_base::sync_with_stdio(false);
    int licznik=1;
    int t;
    cin >> t;
    while(t--){
        int r,c,w;
        cin >> r >> c >> w;
        int suma=c/w-1;
        suma+=(r-1)*(c/w);
        if(c%w==0)
            suma+=w;
        else
            suma+=w+1;
        cout << "Case #" << licznik++ << ": "<<suma << endl;
    }
    return 0;
}
