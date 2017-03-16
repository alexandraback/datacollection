#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<sstream>
#include<set>
#include<vector>
#include<map>
#include<cassert>
#include<queue>
using namespace std;
int cant[10];
int tengo[26];
string s;

int f(char c){
    return c-'A';
}

int main(){


    int tc;
    cin>>tc;
    for(int caso=1;caso<=tc;caso++){
        cout<<"Case #"<<caso<<": ";
        memset(cant,0,sizeof(cant));
        memset(tengo,0,sizeof(tengo));
        cin>>s;
        
        for(int i=0;i<s.size();i++)
            tengo[s[i]-'A']++;

        while(tengo[f('Z')]>0){
            cant[0]++;
            tengo[f('Z')]--;
            tengo[f('E')]--;
            tengo[f('R')]--;
            tengo[f('O')]--;
        }
        
        while(tengo[f('W')]>0){
            cant[2]++;
            tengo[f('T')]--;
            tengo[f('W')]--;
            tengo[f('O')]--;
        }
        
        while(tengo[f('X')]>0){
            cant[6]++;
            tengo[f('S')]--;
            tengo[f('I')]--;
            tengo[f('X')]--;
        }

        while(tengo[f('G')]>0){
            cant[8]++;
            tengo[f('E')]--;
            tengo[f('I')]--;
            tengo[f('G')]--;
            tengo[f('H')]--;
            tengo[f('T')]--;
        }

        while(tengo[f('H')]>0){
            cant[3]++;
            tengo[f('T')]--;
            tengo[f('H')]--;
            tengo[f('R')]--;
            tengo[f('E')]--;
            tengo[f('E')]--;
        }

        while(tengo[f('S')]>0){
            cant[7]++;
            tengo[f('S')]--;
            tengo[f('E')]--;
            tengo[f('V')]--;
            tengo[f('E')]--;
            tengo[f('N')]--;
        }

        while(tengo[f('V')]>0){
            cant[5]++;
            tengo[f('F')]--;
            tengo[f('I')]--;
            tengo[f('V')]--;
            tengo[f('E')]--;
        }
        
        while(tengo[f('F')]>0){
            cant[4]++;
            tengo[f('F')]--;
            tengo[f('O')]--;
            tengo[f('U')]--;
            tengo[f('R')]--;
        }

        while(tengo[f('O')]>0){
            cant[1]++;
            tengo[f('O')]--;
            tengo[f('N')]--;
            tengo[f('E')]--;
        }


        while(tengo[f('N')]>0){
            cant[9]++;
            tengo[f('N')]--;
            tengo[f('I')]--;
            tengo[f('N')]--;
            tengo[f('E')]--;
        }


        
        for(int i=0;i<10;i++)
            for(int j=0;j<cant[i];j++)
                cout<<i;
        cout<<endl;
    }

    
    return 0;
}





