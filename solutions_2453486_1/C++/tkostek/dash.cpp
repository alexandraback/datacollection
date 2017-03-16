#include<iostream>
using namespace std;
char t[4][4];
int f(int c){
bool kr=0;
for(int i=0;i<4;i++){
for(int x=0;x<4;x++){cin>>t[i][x];if(t[i][x]=='.')kr=1;}        
}
int l=0;
for(int i=0;i<4;i++){
l=0;
for(int x=0;x<4;x++)l+=(t[i][x]=='X'||t[i][x]=='T');
if(l==4){cout<<"Case #"<<c<<": X won\n";return 0;}
l=0;
for(int x=0;x<4;x++)l+=(t[x][i]=='X'||t[x][i]=='T');
if(l==4){cout<<"Case #"<<c<<": X won\n";return 0;}        
}
l=0;
for(int x=0;x<4;x++)l+=(t[x][x]=='X'||t[x][x]=='T');
if(l==4){cout<<"Case #"<<c<<": X won\n";return 0;}  
l=0;
for(int x=0;x<4;x++)l+=(t[4-x-1][x]=='X'||t[4-x-1][x]=='T');
if(l==4){cout<<"Case #"<<c<<": X won\n";return 0;}  

for(int i=0;i<4;i++){
l=0;
for(int x=0;x<4;x++)l+=(t[i][x]=='O'||t[i][x]=='T');
if(l==4){cout<<"Case #"<<c<<": O won\n";return 0;}
l=0;
for(int x=0;x<4;x++)l+=(t[x][i]=='O'||t[x][i]=='T');
if(l==4){cout<<"Case #"<<c<<": O won\n";return 0;}        
}
l=0;
for(int x=0;x<4;x++)l+=(t[x][x]=='O'||t[x][x]=='T');
if(l==4){cout<<"Case #"<<c<<": O won\n";return 0;}  
l=0;
for(int x=0;x<4;x++)l+=(t[4-x-1][x]=='O'||t[4-x-1][x]=='T');
if(l==4){cout<<"Case #"<<c<<": O won\n";return 0;}  
if(kr)cout<<"Case #"<<c<<": Game has not completed\n";
else cout<<"Case #"<<c<<": Draw\n";
}
main(){
int t;
cin>>t;
for(int i=1;i<=t;i++)f(i);       
}
