#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
using namespace std;  
struct swing{
	long long p,l;
    bool operator<(const swing ext) const{
    return (p<ext.p);
    }
};
bool empty;
string s[4],temp;
bool check(char d){
     int i,j;
     bool ok;
     for (i=0; i<4; ++i){
         ok=true;
         for (j=0; j<4; ++j){
             if (s[i][j]!=d && s[i][j]!='T'){
                ok=false;
                break;
             }
         }    
         if (ok)
            return true;
     }
     for (i=0; i<4; ++i){
         ok=true;
         for (j=0; j<4; ++j){
             if (s[j][i]!=d && s[j][i]!='T'){
                ok=false;
                break;
             }
         }    
         if (ok)
            return true;
     }     
     ok=true;
     for (i=0; i<4; ++i){
             if (s[i][i]!=d && s[i][i]!='T'){
                ok=false;
                break;
             }
     }
         if (ok)
            return true;
     ok=true;
     for (i=0; i<4; ++i){
             if (s[i][3-i]!=d && s[i][3-i]!='T'){
                ok=false;
                break;
             }
     }
         if (ok)
            return true;
     return false;
}
int main(){
    int i,j,k,n,t,z;
    cin>>t;
    for (z=1; z<=t; ++z){
        for (i=0; i<4; ++i)
            cin>>s[i];
        //cin>>temp;
        cout<<"Case #"<<z<<": ";
        empty=false;
        for (i=0; i<4; ++i)
        for (j=0; j<4; ++j){
            if (s[i][j]=='.')
               empty=true;
        }
       // for (i=0; i<4; ++i)
        //cout<<s[i]<<endl;
        bool xwin=false;
        bool owin=false;
        xwin=check('X');
        if (xwin){
           cout<<"X won"<<endl;
        }
        else{
             owin=check('O');
             if (owin)
               cout<<"O won"<<endl;
             else if (empty)
               cout<<"Game has not completed"<<endl; 
              else
              cout<<"Draw"<<endl;   
        }
    }
    return 0;
}
