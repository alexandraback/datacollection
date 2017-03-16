#include <iostream>
using namespace std;
int main(){
    long long cases = 0;
    cin >> cases;
    for(long long c=0;c<cases;c++){
        long long level = 0;
        cin >> level;
        long long need = 0;
        long long up = 0;
        string s = "";
        cin >> s;
        for(long long i=0;i<level+1;i++){
            if(up < i){
                need += i-up;
                up += i-up;
            }
            up += (s[i]-'0');
            
        }
        cout << "Case #" << c+1 << ": " << need << endl;
    }
}