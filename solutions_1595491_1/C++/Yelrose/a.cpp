#include <iostream>
using namespace std;

void go(){
    int num,sup,p;
    cin >> num >> sup >> p;
    int sum = 0;
    for(int i = 0;i < num;i ++){
        int k;
        cin >> k;
        bool can = true;
        for(int j = p;j <= 10;j ++){
            if(k - j < 0)break;
            int z = k - j;
            z /= 2;
            if(j - z <= 1){
                sum ++;
                //cout << k << endl;
                can = false;
                break;
            }


        }
        //cout  << sup << endl;
        if(can && sup > 0){
            //sup --;
            for(int j = p;j <= 10;j ++){
                if(k - j < 0)break;
            int z = k - j;
            z /= 2;
            if(j - z <= 2){
                sum ++;
                sup -- ;
                //cout << k << endl;
                //can = false;
                break;
            }


        }

        }
    }
    cout << sum << endl;



}


int main(){
        int T;
        cin >> T;
        for(int i = 1;i <= T;i ++){
            cout << "Case #" << i << ": ";
            go();
        }



}
