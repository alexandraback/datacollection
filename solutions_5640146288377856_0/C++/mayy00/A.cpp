#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;
    for(int i=1;i<=T;++i){
        int r,c,w,res;
        cin >> r >> c >> w;
        
        res = r * c/w;
        if(c%w!=0)
            res++;
        res+=w-1;
        
        cout << "Case #" << i << ": " << res << endl;
    }
    return 0;
}