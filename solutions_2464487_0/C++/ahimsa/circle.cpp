#include<iostream>
#include<vector>

using namespace std;

int main(){
    int T;
    cin>>T;
    for(int test = 0; test < T;test++){
        int r, t;
        cin>>r>>t;
        int count = 0;
        int sum = 0;
        int coef = 1;
        sum = 2 * r + coef;
        while(sum <= t){
            coef += 4;
            sum += (2 * r + coef);
            count++;
        }
        cout<<"Case #"<<(test + 1)<<": "<<count<<endl;

    }
}
