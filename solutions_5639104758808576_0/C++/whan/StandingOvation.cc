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

ifstream fin("A-small-attempt0.in");
ofstream fout("StandingOvation_A-small.out");
int N;
int Sm;//S_max

int main(void){
    fin >> N;
    int counter = 1;
    while(counter<=N){
        fin >> Sm;
        fin >> ws;
        char input[1010];fin.getline(input,Sm+2);//the last one for '\0'?
        //cout << Sm<<' '<<input<<endl;

        int extra=0;
        int cur_num=input[0]-'0';
        for (int i=1;i<Sm+1;i++){
            if (cur_num<i){
                extra+=i-cur_num;
                cur_num=i+input[i]-'0';
            }
            else{
                cur_num+=input[i]-'0';
            }
        }
        
        fout << "Case #" << counter << ": " << extra << endl;
        counter++;
    }
    return 0;
}

