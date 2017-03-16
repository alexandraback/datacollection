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

ifstream fin("C-small-attempt1.in");
//ifstream fin("Dijkstra.in");
ofstream fout("Dijkstra.out");

int T,L,X;
char input[20000];
char realstr[900000];

int mult(int a, int b){
    int result = 1;
    if(a>0 && b>0){
        if(a=='i'&&b=='i'){
            result = -1;
        }
        else if(a=='i'&&b=='j'){
            result = 'k';
        }
        else if(a=='i'&&b=='k'){
            result = 'j';
            result *=-1;
        }
        else if(a=='j'&&b=='i'){
            result = 'k';
            result *=-1;
        }
        else if(a=='j'&&b=='j'){
            result = -1;
        }
        else if(a=='j'&&b=='k'){
            result = 'i';
        }
        else if(a=='k'&&b=='i'){
            result = 'j';
        }
        else if(a=='k'&&b=='j'){
            result = 'i';
            result *=-1;
        }
        else if(a=='k'&&b=='k'){
            result = -1;
        }
        else{
            result = a*b;
        }
    }
    else if (a<0&&b>0){
        int _a = 0-a;
        result = mult(_a,b);
        result*=-1;
    }
    else if (a>0&&b<0){
        int _b = 0-b;
        result = mult(a,_b);
        result*=-1;
    }
    else{
        int _a = 0-a;
        int _b = 0-b;
        result = mult(_a,_b);
    }
    //cout << "result " << result <<endl;
    return result;
}
    
        
bool preprocess(void){
    //return false if impossible
    //else concatenate all string to input
    int l = strlen(input);
    //cout << "input " << input << " length " << l<< endl;
    //each char needs <=4 blocks
    
    if (X>=12){
        X %= 4;
        X +=12;
    }
    
    int product_1 = input[0];
    for(int i=1;i<l;i++){
        product_1 = mult(product_1,input[i]);
        //cout << "i is " << i << " and p1 is " << product_1 << endl;
    }
    //cout << "prod_1 " << product_1 << endl;
    int product = 1;
    for(int i=0;i<X;i++){
        product =mult(product,product_1);
    }
    if (product!=-1){
        return false;
    }
    else{
        for(int i=0;i<X;i++){
            strcpy(realstr+i*l,input);
            //cout << realstr << endl;
        }
    }
    return true;
}

int mult_seg(int start,int end){
    //multiply realstr[start] to realstr[end] inclusive.
    if(start ==end){
        return realstr[start];
    }
    else{
        int prod = realstr[start];
        for(int i=start+1;i<=end;i++){
            prod = mult(prod,realstr[i]);
        }
        return prod;
    }
}

bool completesearch(void){
    int l = strlen(realstr); 
    for(int i=0;i<l-2&&i<=L*4;i++){
        if(mult_seg(0,i)=='i'){
            for(int j=i+1;j<l-1;j++){
                if(mult_seg(i+1,j)=='j'){
                    return true;
                }
            }
        }
    }
    return false;
}
int main(void){
    fin >> T;
    int counter = 1;
    while(counter<=T){
        memset(input,0,20000);
        memset(realstr,0,900000);
        fin >> L >> X;
        fin >> ws;
        fin.getline(input,20000);
        //cout << "L " << L << " X " << X << " input " << input <<endl;
        bool poss=preprocess();
        if(!poss){
            fout << "Case #" << counter << ": NO" << endl;
        }
        else{
            bool result = completesearch();
            if (result){
                fout << "Case #" << counter << ": YES" << endl;
            }
            else{
                fout << "Case #" << counter << ": NO" << endl;
            }
        }
        counter++;
    }
    return 0;
}

