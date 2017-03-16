#include <iostream>
#include <set>
using namespace std;
set<int > all;
int main(){
    int T;
    int ca = 1;
    cin >> T;
    all.insert(1);
    all.insert(4);
    all.insert(9);
    all.insert(121);
    all.insert(484);
    while(T --){
        int a,b;
        cin >> a >> b;
        int countf = 0;
        for(set<int >::iterator it= all.begin();it != all.end();it ++){
            if(a <= (*it) && (*it) <= b){

                countf ++;

            }
        }
        cout << "Case #"<<ca<<": "<<countf << endl;
        //Case #1: 2
        ca ++;

    }
}
