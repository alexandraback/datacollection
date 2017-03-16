// C++11
#include <iostream>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <cstdlib>

using namespace std;

void test_small(){

    int T;

    cin>>T;
    string S;

    for(int c=1; c<=T; c++){

        cin>>S;

        string last_word = "";

        for(int i=0; i<S.size(); i++){

            string tmp1 = last_word + S[i];
            string tmp2 = S[i] + last_word;

            if(tmp1 >= tmp2){
                last_word = tmp1;
            } else{
                last_word = tmp2;
            }

        }


        cout<<"Case #"<<c<<": "<<last_word<<endl;
    }


}

int main()
{
    test_small();
    return 0;
}

