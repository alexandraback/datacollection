//
// Created by Yuxiang LI on 09/04/16.
//
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int T;
string s1, s2;
int n1,n2,mini;

void dfs(int i, int t1, int t2){
    if (i == s1.length() + s2.length()){
        if (mini == -1 || (abs(t1-t2) < mini) || (abs(t1-t2) == mini && (t1 < n1 || (t1 == n1 && t2 < n2)))){
            mini = abs(t1-t2);
            n1 = t1;
            n2 = t2;
        }
        return;
    }
    if (i < s1.length()){
        if (s1[i] == '?')
            for(int j = 0; j < 10; j++)
                dfs(i+1,t1*10+j,t2);
        else
            dfs(i+1,t1*10+(int)s1[i]-(int)'0',t2);
    }
    else{
        if (s2[i - s1.length()] == '?')
            for(int j = 0; j < 10; j++)
                dfs(i+1,t1,t2*10+j);
        else
            dfs(i+1,t1,t2*10+(int)s2[i-s1.length()]-(int)'0');

    }
}

int digit(int n){
    if (n == 0)
        return 1;
    int c = 0;
    while(n != 0){
        n = n/10;
        c++;
    }
    return c;
}

int main(){
    ifstream in("B-small.in");
    ofstream out("output.out");
    in >> T;

    for(int cases = 1; cases <= T; cases++){
        mini = -1;
        in >> s1 >> s2;
        dfs(0,0,0);
        out << "Case #" << cases << ": ";
        for(int i = 0; i < s1.length() - digit(n1); i++)
            out << 0;
        out << n1 <<' ';
        for(int i = 0; i < s1.length()-digit(n2);i++)
            out << 0;
        out << n2 << endl;
    }
    in.close();
    out.close();
    return 0;
}
