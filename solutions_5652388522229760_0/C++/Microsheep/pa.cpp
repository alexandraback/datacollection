#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int T=0,k=1;
    cin >> T;
    while(T--){
        int N=0,check[15],ans=0;
        memset(check,0,sizeof(check));
        cin >> N;
        if(N!=0){
            for(int a=1;a<1000;a++){
                ans=a*N;
                int x=a*N;
                while(x>0){
                    check[x%10]=1;
                    x=x/10;
                }
                if(check[0]&&check[1]&&check[2]&&check[3]&&check[4]&&check[5]&&check[6]&&check[7]&&check[8]&&check[9]){
                    break;
                }
            }
        }
        if(ans==0){
            cout << "CASE #" << k << ": INSOMNIA" << endl;
        }
        else{
            cout << "CASE #" << k << ": "<< ans << endl;
        }
        k++;
    }
    return 0;
}
