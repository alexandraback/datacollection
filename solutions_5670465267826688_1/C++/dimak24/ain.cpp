#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std; 
long long mult(long long a, long long b) {
    if(a==1 && b==1) return 1;
    else if(a<0 && b<0) return mult(-a, -b);
    else if(a*b<0) return -mult(-a, b);
    else if(a==b) return -1;
    else if(a==1) return b;
    else if(b==1) return a;
    else if(a==105 && b==106) return 107;
    else if(a==106 && b==105) return -107;
    else if(a==105 && b==107) return -106;
    else if(a==107 && b==105) return 106;
    else if(a==107 && b==106) return -105;
    else if(a==106 && b==107) return 105;
}
int main() {
    ofstream fout("qqq.txt");
    ifstream fin("C-large.in");
    long long t, s, x;
    string str;
    fin >> t;
    for(int j=0; j<t; j++) {
            bool p=false;
            fin >> s >> x;
            fin >> str;
            long long q=(long long)str[0];
            for(long long i=1; i<str.size(); i++) q=mult(q, (long long)str[i]);
            if((q==-1 && x%2==1) || (x%4==2 && q!=1 && q!=-1)) {
                    q=1;
                 string str1="";
                 while(str1.size()<25) str1=str1+str;
                 for(long long i=0; i<str1.size() && !p; i++) {
                         q=mult(q, (long long)str1[i]);
                         if(q==105) {
                                    int w=1;
                                    for(long long z=i+1; z<str1.size(); z++) {
                                            w=mult(w, (long long)str1[z]);
                                            if(w==106 && z<s*x) {
                                                      p=true;
                                                      break;
                                                      }
                                                      }
                                                      }
                                                      }
                         }
    fout << "Case #" << j+1 << ": " << (p ? "YES" : "NO") << "\n";
    }
    return 0;
}
                    
