#include<fstream>
#include<iostream>
#include<cstdlib>
#include<cmath> 
#include<algorithm>
#include<vector>
#include<list>
#include<cstring>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<queue>
#include<deque>
#include<ctime>
#include<complex>
#include<bitset>

using namespace std;
#define PB push_back
#define LL long long
#define MP make_pair

//ifstream fin("D-small-attempt4.in");
//ofstream fout("Omino-small4.out");
ifstream fin("D-large.in");
ofstream fout("Omino-large.out");

int T,X,R,C;
int counter = 1;

void win(void){
    fout << "Case #" << counter << ": RICHARD" << endl;
    counter++;
}
void lose(void){
    fout << "Case #" << counter << ": GABRIEL" << endl;
    counter++;
}
int main(void){
    fin >> T;
    while(counter<=T){
        cout <<  "counter " << counter << endl;
        fin >> X >> R >> C;
        if (X==2 && R*C%X==0){
            lose();
            cout << "0" << endl;
            continue;
        }
        else if(R*C%X!=0){
            win();
            cout << "1" << endl;
            continue;
        }
        else if (X==2 && R*C ==2){
            win();
            cout << "2" << endl;                        
            continue;
        }
        else if(X>R && X>C){
            win();
            cout << "3" << endl;            
            continue;
        }
        else if (R >= C && 2*C+1<=X){
            win();
            cout << "4" << endl;            
            continue;
        }
        else if (R >= C && 2*C == X && C!=1){
            win();
            cout << "5" << endl;                        
            continue;
        }
        else if (C >= R && 2*R+1<=X){
            win();
            cout << "6" << endl;            
            continue;
        }
        else if (C >= R && 2*R == X && R!=1){
            win();
            cout << "7" << endl;                        
            continue;
        }
        else if (X<=R && X<=C && X>=7){
            win();
            cout << "8" << endl;            
            continue;
        }
        else{
            lose();
            cout << "9" << endl;            
            continue;
        }

            

        
    }
    
    return 0;
}

