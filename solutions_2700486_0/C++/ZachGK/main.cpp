/*
ID: zachary11
PROG: calfflac
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stdio.h>

using namespace std;
int minSolve;

template <typename Type>
string toString(Type t){
	stringstream ss;
        string s;
	ss << t;
        ss >> s;
        return s;
}

template <typename Type>
char toChar(Type t){
	stringstream ss;
        char s;
	ss << t;
        ss >> s;
        return s;
}

long long searchCost(int dimension){
    return dimension*(1+dimension)/2;
}

int search(long long n){
    int min=1,max=499;
    while(true){
        int middle = round((max+min)/2);
        long long cost = searchCost(middle);
        if(cost == n){
            return n;
        } else if(cost > n){
            max = middle;
        } else{
            min = middle;
        }
        if(max-min <= 5) break;
    }
    for(long long i=min+1; i<max; i++){
        if( searchCost(i) > n) return i-1;
    }
}

int countSolutions(int onSide, int offside, int n, int needed){
    if(n == 0){
        if(onSide >= needed) return 1;
        return 0;
    }
    //cout << onSide << " " << offside << " " << n << endl;
    //cout << countSolutions(onSide+1, offside, n-1, needed) + countSolutions(onSide,offside+1, n-1, needed) << endl;
    return countSolutions(onSide+1, offside, n-1, needed) + countSolutions(onSide,offside+1, n-1, needed);
    
}

float solve(long long n, int x, int y){
    int stackD = search(n);
    if(stackD%2 == 0) stackD--;
    /*if( abs(x) <= (stackD-1)/2 && abs(y) <= (stackD-1)/2 ) return 1;
    if( abs(x) >= (stackD+1)/2 && abs(y) >= (stackD+1)/2 ) return 0;*/
    if(abs(x) + y <= stackD-1) return 1;
    if(abs(x) + y > stackD+1) return 0;
    long long usable = n - searchCost(stackD);
    if(y+1 > usable) return 0;
    if(x == 0) return 0;
    //cout << usable << " " << countSolutions(0,usable,y) << " " << pow(2,usable) << endl;
    return (float)countSolutions(0,0,usable,y+1)/(pow(2,usable));
}

int main() {
    ofstream fout("codeJam.out");
    ifstream fin("codeJam.in");
    long caseNumber=0;
    fin >> caseNumber;
    for(long i=1; i<=caseNumber; i++){
        
        long long n;
        int myX, myY;
        fin >> n >> myX >> myY;
        
        string solution = toString(solve(n, myX, myY));
        fout << "Case #" << i << ": " << solution << endl;
        cout << "Case #" << i << ": " << solution << endl;
    }
    
    return 0;
}
