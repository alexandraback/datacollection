#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int T=0,k=1;
    cin >> T;
    while(T--){
        int ans=0;
        char S[110];
        memset(S,0,sizeof(S));
        cin >> S;
        int last=0;
        if(S[0]=='-'){
            last=0;
        }
        else{
            last=1;
        }
        for(int a=1;a<(int)strlen(S);a++){        
            if(S[a]=='-'){
                if(last==0){
                    continue;
                }
                else{
                    ans++;
                }
                last=0;
            }
            else{
                if(last==1){
                    continue;
                }
                else{
                    ans++;
                }
                last=1;
            }
        }
        if(last==0){
            ans++;
        }
        cout << "CASE #" << k << ": "<< ans << endl;
        k++;
    }
    return 0;
}
