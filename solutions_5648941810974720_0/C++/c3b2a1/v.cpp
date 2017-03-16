#include<iostream>

using namespace std;

inline int cocc(string s, char c){
  int cnt = 0;
  //cout << s << " with " << c << endl;
  for(int k=0; k<s.length(); k++)
    if(s[k] == c) cnt++;
  return cnt;
}

int main(int agrc, char *argv[]){
  int T; cin>>T;
  for(int tc=1; tc<=T; tc++){
    cout<<"Case #"<<tc << ": ";
    int alp[256];
    for(int i=0; i<256; i++)
     alp[i] = 0;
    string s; cin>>s;
    for(int i=0; i<s.length(); i++){
      alp[s[i]]++;
    }
    int sol[10];
    for(int i=0; i<10; i++) sol[i] = 0;
    string number[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
    int nr[10] = {  8,  6 ,  4 , 2  , 5  ,  3 , 0  , 9  , 7,    1};
    char ch[10] = {'G','X', 'U', 'W', 'F', 'T', 'Z', 'I', 'V', 'N'};
    for(int i=0; i<10; i++){
      int id = nr[i];
      int cnt = cocc(number[id], ch[i]);
     
      sol[id] = alp[ch[i]]/cnt;
      for(int k=0; k<number[id].length(); k++)
        alp[number[id][k]] -= sol[id];
    }
    for(int i=0; i<10; i++)
      for(int a=0; a<sol[i]; a++)
        cout<<i;
    cout<<endl;
  }
  return 0;
}
