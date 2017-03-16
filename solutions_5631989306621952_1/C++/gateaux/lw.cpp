/*The last word*/

#include<iostream>
#include<fstream>
#include<string>

#define forn(i,n) for(int i=0;i<n;i++)
using namespace std;

ifstream fin ("A-large.in");
ofstream fout ("output.out");
string answer(string s){
string t="";
forn(i,s.length()){
           if(t.length()==0)t+=s[i];
           else{
                if(t[0]>s[i])t+=s[i];
                else{
                    string temp ="";
                    temp += s[i];
                    temp +=t;
                    t=temp;
                    }
               }
                  }
return t;
}
int main(){
int testcase;
fin >> testcase;
forn(i,testcase){
    string s;
    fin >> s;
    fout << "Case #" << i+1 << ": " << answer(s) << endl;
}
return 0;
}
