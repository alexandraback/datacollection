#include<iostream>
#include<string>

using namespace std;


int a[26];
int n[10];
void f(int y,char c,string s){
    int x = a[c-'A'];
    n[y]=x;
    for(int i=0;i<s.size();i++)
        a[s[i]-'A']-=x;
}
int main(){
    int T;
    string s;
    cin>>T;
    int case_n =1;
    while(T--){
        cin>>s;
        for(int i=0;i<26;i++)
            a[i]=0;
        for(int i=0;i<10;i++)
            n[i]=0;
        for(int i=0;i<s.size();i++)
            a[s[i]-'A']++;
        f(0,'Z',"ZERO");
        f(8,'G',"EIGHT");
        f(4,'U',"FOUR");
        f(3,'R',"THREE");
        f(2,'W',"TWO");
        f(6,'X',"SIX");
        f(7,'S',"SEVEN");
        f(1,'O',"ONE");
        f(5,'V',"FIVE");
        f(9,'E',"NINE");
        cout<<"Case #"<<case_n++<<": ";
        for(int i=0;i<10;i++){
            for(int j=0;j<n[i];j++)
                cout<<i;
        }
        cout<<endl;
    }
}
