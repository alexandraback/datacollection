#include <iostream>
#include <sstream> 
#include <cstdio>
#include <istream>
#include <string>
#include <cstring>
#include <complex>
#include <cstdlib>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <cmath>
 
using namespace std;

int ma[30];
bool checked[30];

string str1 = "qzejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
string str2 = "zqour language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";
 

void fillmap(){
     memset(ma, -1, sizeof(ma));
     memset(checked, false, sizeof(checked));
     
     for(int i=0; i<str1.size(); i++) if('a'<=str1[i] && str1[i]<='z'){
             ma[str1[i] - 'a'] = str2[i] - 'a';    
             checked[str2[i]-'a']=true;    
     }
     
     for(int i=0; i<='z'-'a'; i++) if(ma[i]==-1){
             for(int j=0; j<='z'-'a'; j++) if(checked[j]==false){
                     ma[i] = j;        
                     //cout << (char)(i+'a') << " -> " << (char)(j+'a');     
             }
     }
          
}
int main(){
    //freopen("input.txt", "r", stdin);
    freopen("A-small-attempt2.in", "r", stdin);
    //freopen("C-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    fillmap();
    
    int sotest;           cin>>sotest; cin.get();
    for(int run=1; run<=sotest; run++){ 
            cout << "Case #"<< run << ": ";
            string str;            getline(cin, str);
            
            for(int i=0; i<str.size(); i++){
                    char ch = str[i];
                    if('a' <= ch && ch <= 'z')   ch = (char)(ma[ch-'a'] + 'a');
                    cout << ch;
            }
            cout << endl;
    }
    
    return 0;
}
