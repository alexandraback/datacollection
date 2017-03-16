#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    int T=0,k=1;
    cin >> T;
    while(T--){
        string input,ans;
        cin >> input;
        for(int a=0;a<(int)input.length();a++){
            if(input[a]>=ans[0]){
                ans = input[a] + ans;
            }
            else{
                ans = ans + input[a]; 
            }
        }

        cout << "Case #" << k << ": " << ans << endl;
        k++;
    }
    return 0;
}
