#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

bool mask_bit(char*,int);

bool compare_func (pair<char,int>A,pair<char,int>B){  return ( A.second > B.second );  }

int main(int argc,char *argv[]){

    fstream fs(argv[1],fstream::in);

    int N;
    fs >> N;

    for(int in_index=0; in_index<N; in_index++){
        long int B,M;
        fs >> B >> M;

        long int max_bound = pow(2,B-2);
        if( M <= max_bound){
            cout<<"Case #"<< in_index+1<<": POSSIBLE\n";
        }
        else {
            cout<<"Case #"<< in_index+1<<": IMPOSSIBLE\n";
            continue;
        }


        if( M == max_bound){
            for(int i=0; i<(B-1); i++){
                int add_len = i+1;
                string add_str = string(add_len, '0');
                add_len = B-add_len;
                add_str = add_str + string(add_len, '1');

                cout << add_str << endl;
            }
            string last_row = string(B, '0');
            cout<< last_row<<endl; 

            continue;
        }

        string row1;
        while(M != 0){
            long int mod_num = M%2;
            if(mod_num == 0){
                row1 = "0" + row1;
            }   
            else if(mod_num == 1){
                row1 = "1" + row1;
            }
            M /= 2;
        }   
        row1 = row1 + "0";
        if (row1.length() < B){
            int add_len = B-row1.length();
            string add_str = string(add_len,'0');
            row1 = add_str + row1;
        }
        cout << row1<<endl;
        for(int i=1; i<(B-1); i++){
            int add_len = i+1;
            string add_str = string(add_len, '0');
            add_len = B-add_len;
            add_str = add_str + string(add_len, '1');

            cout << add_str << endl;
        }
        string last_row = string(B, '0');
        cout<< last_row<<endl; 
    }

    fs.close();
    return 0;
}

bool mask_bit(char* array,int N){
   bool pass = false; 

   while(N != 0){
      int mod_num = N%10;
      array[mod_num] = 1;
      N /= 10;
   }
    int cnt=0;
    for(cnt=0;cnt<10;cnt++){
        if(array[cnt] == 0){
            break;
        }
    }
    if(cnt == 10){
        pass = true;
    }
    return pass;
}
