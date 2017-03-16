#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream in;
    in.open("small.in");
    ofstream out;
    out.open("small.out");
    int n;
    in>>n;
    
    string dic1,dic2;getline(in,dic1);
    dic1="ejpmysljylckdkxveddknmcrejsicpdrysirbcpcypcrtcsradkhwyfrepkymveddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
    dic2="ourlanguageisimpossibletounderstandtherearetwentysixfactorialpossibilitiesso it is okay if you want to just give up";
    //for(int i=0;i<d;i++)in>>dic[i];
    for(int i=0;i<n;i++){
        string s,s1;
        getline(in,s);
        for(int j=0;j<s.length();j++)
            for(int k=0;k<dic1.length();k++)
                if (s[j]==dic1[k]){
                    s1=s1+dic2[k];
                    break;
                    }
        out<<"Case #"<<i+1<<": "<<s1<<endl;
        }
    }
