#include<iostream>
#include<cstdlib>
#include<cstring>
#include<map>
using namespace std;

int main(){
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int T;
    string s;
    int ct[10];
    map<char, int> x;
    cin>>T;
    int cs;
    for(cs=1;cs<=T;cs++){
        cout<<"Case #"<<cs<<": ";
        cin>>s;
        x.clear();
        for(int i=0;i<=9;i++){
            ct[i]=0;
        }
        for(int i=0;i<=s.length()-1;i++){
            if(x.count(s[i])==0){
                x[s[i]]=1;
            }
            else{
                x[s[i]]++;
            }
        }
        ct[6]=(x.count('X')==0)? 0 : x['X'];
        ct[0]=(x.count('Z')==0)? 0 : x['Z'];
        ct[8]=(x.count('G')==0)? 0 : x['G'];
        ct[4]=(x.count('U')==0)? 0 : x['U'];
        ct[2]=(x.count('W')==0)? 0 : x['W'];
        ct[3]=(x.count('T')==0)? 0 : (x['T']-ct[2]-ct[8]);
        ct[7]=(x.count('S')==0)? 0 : (x['S']-ct[6]);
        ct[5]=(x.count('V')==0)? 0 : (x['V']-ct[7]);
        ct[9]=(x.count('I')==0)? 0 : (x['I']-ct[5]-ct[6]-ct[8]);
        ct[1]=(x.count('O')==0)? 0 : (x['O']-ct[0]-ct[2]-ct[4]);
        for(int i=0;i<=9;i++){
            
            while(ct[i]--){
                cout<<i;
            }
        }
        cout<<endl;
    }
    return 0;
}
