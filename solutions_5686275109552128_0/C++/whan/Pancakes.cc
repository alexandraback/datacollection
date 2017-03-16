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

ifstream fin("B-small-attempt6.in");
ofstream fout("Pancakes-small6.out");
int T;
int D;
int pan[1010];
int op[1010];
//Operation One: substract every number by 1
//Operation Two: split a number into two.
//for # of Operation One=1:max_num
//   count the # of Operation Two in order to bring all numbers <= # of Operation One
//   calculate the total # of ops
//find the min
//
int op_two(int limit,int t){
    /*
    int result = 0;
    if (t<limit){
        return 0;
    }
    if (t>limit){
        int t1=t-t/2;
        int t2=t-t1;
        result+=1;
        result+=op_two(limit,t1);
        result+=op_two(limit,t2);
    }
    return result;
    */
    if(t%limit ==0){
        return t/limit-1;
    }
    else{
        return t/limit;
    }
    
}
int main(void){
    fin >> T;
    int counter = 1;
    while(counter <= T){
        fin >> D;
        memset(pan,0,1010);
        memset(op,0,1010);
        for(int i=0;i<D;i++){
            fin >> pan[i];
        }
        sort(pan,pan+D);
        
        for(int i=1;i<=pan[D-1];i++){
            //i is the op1 #
            int cur_num = i;
            for(int j=0;j<D;j++){
                cur_num+=op_two(i,pan[j]);
            }
            op[i]=cur_num;
                
        }
        sort(op+1,op+pan[D-1]+1);
        /*
        if(counter==5){
        for(int i = 1;i<pan[D-1]+1;i++){
            cout << op[i] <<endl;
        }
        }
        */
        int time = op[1];
        
        fout << "Case #" << counter << ": " << time << endl;
        counter++;
    }
    return 0;
}

