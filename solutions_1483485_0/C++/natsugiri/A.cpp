#include<iostream>
#include<string>
#include<cctype>
#include<cstdio>

using namespace std;


int T;
string G;

char d[]="yhesocvxduiglbkrztnwjpfmaq";
int x[255];

int main(){
  scanf("%d\n", &T);
  
  for(int t=1; t<=T; t++){
    getline(cin, G);
    for(int i=0; i<G.size(); i++)G[i]=islower(G[i])?d[G[i]-'a']:G[i];
    printf("Case #%d: %s\n", t, G.c_str());
  }
  return 0;
}
