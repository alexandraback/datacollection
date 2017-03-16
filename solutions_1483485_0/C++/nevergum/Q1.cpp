
#include<iostream>
#include<map>
#include<fstream>
using namespace std;


int main(){

    string o1("ejp mysljylc kd kxveddknmc re jsicpdrysi");
    string o2("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd");
    string o3("de kr kd eoya kw aej tysr re ujdr lkgc jv");

    string t1("our language is impossible to understand");
    string t2("there are twenty six factorial possibilities");
    string t3("so it is okay if you want to just give up");

    map<char,char> dic;
    
    for(int i=0;i<o1.length();i++)
        dic[o1[i]]=t1[i];
    for(int i=0;i<o2.length();i++)
        dic[o2[i]]=t2[i];
    for(int i=0;i<o3.length();i++)
        dic[o3[i]]=t3[i];

    dic['q']='z';
    dic['z']='q';
    

    ifstream infile("file.in");
    ofstream outfile("file.out");

    int t;
    infile>>t;
    string s;
    getline(infile,s);

    for(int i=0;i<t;i++){
        string t;
        getline(infile,s);
        for(int j=0;j<s.length();j++)
            t+=dic[s[j]];
        outfile<<"Case #"<<i+1<<": "<<t<<endl;
    }

}
    
