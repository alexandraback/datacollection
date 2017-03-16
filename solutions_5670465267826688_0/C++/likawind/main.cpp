//
//  main.cpp
//  a
//
//  Created by Zhou Sun on 15/4/11.
//  Copyright (c) 2015年 Zhou Sun. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
map<char , map<char,char> >m;
map<char , map<char,int> >f;
int main(int argc, const char * argv[]) {
    int ts;
    string s;
    m['1']['1']='1';
    m['1']['i']='i';
    m['1']['j']='j';
    m['1']['k']='k';
    m['i']['1']='i';
    m['i']['i']='1';
    m['i']['j']='k';
    m['i']['k']='j';
    m['j']['1']='j';
    m['j']['i']='k';
    m['j']['j']='1';
    m['j']['k']='i';
    m['k']['1']='k';
    m['k']['i']='j';
    m['k']['j']='i';
    m['k']['k']='1';
    
    f['1']['1']=1;
    f['1']['i']=1;
    f['1']['j']=1;
    f['1']['k']=1;
    f['i']['1']=1;
    f['i']['i']=-1;
    f['i']['j']=1;
    f['i']['k']=-1;
    f['j']['1']=1;
    f['j']['i']=-1;
    f['j']['j']=-1;
    f['j']['k']=1;
    f['k']['1']=1;
    f['k']['i']=1;
    f['k']['j']=-1;
    f['k']['k']=-1;

    
    ifstream in("c.txt");
    ofstream out("c_out.txt");
    in>>ts;
    int a[10000];
    for (int tt=1; tt<=ts; tt++) {
        int x,l;
        out<<"Case #"<<tt<<": ";
        in>>l>>x;
        in>>s;
        char cur='1';
        int ff=1;
        for (int i=0; i<l; i++) {
            ff*=f[cur][s[i]];
            cur=m[cur][s[i]];
        }
        if ((cur=='1'&&ff==1)||(x%4!=2&&cur!='1')||(cur=='1'&&x%2==0)) {
            out<<"NO\n";
            continue;
        }
        cur='1';
        ff=1;
        int flag=0;
        for (int j=0; j<min(x,10000)&&flag<2;j++) {
            for (int i=0; i<l&&flag<2; i++) {
                ff*=f[cur][s[i]];
                cur=m[cur][s[i]];
                if (flag) {
                    if (ff==1&&cur=='k') {
                        flag=2; 
                        out<<"YES\n";
                        continue;
                    }
                }
                else{
                    if (ff==1&&cur=='i') 
                        flag=1;

                }

            }
        }
        if(flag<2)out<<"NO\n";
    }
    return 0;
}
