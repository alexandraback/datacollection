#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

int T;
char map[5][5],tmp;

void check(){
     int empty=0,cntx=0,cnto=0;
     //row
     for (int i=0;i<4;i++){
         cntx=0,cnto=0;
         for (int j=0;j<4;j++){
             if (map[i][j]=='X') cntx++;else
             if (map[i][j]=='O') cnto++;else
             if (map[i][j]=='T'){cntx++;cnto++;}else
             empty++; 
         }
         if (cntx==4){cout<<"X won"<<endl;return;}
         if (cnto==4){cout<<"O won"<<endl;return;}
     }
     //col
     for (int i=0;i<4;i++){
         cntx=0,cnto=0;
         for (int j=0;j<4;j++){
             if (map[j][i]=='X') cntx++;else
             if (map[j][i]=='O') cnto++;else
             if (map[j][i]=='T'){cntx++;cnto++;}
         }
         if (cntx==4){cout<<"X won"<<endl;return;}
         if (cnto==4){cout<<"O won"<<endl;return;}
     }
     // dia1
     cntx=0,cnto=0;
     for (int i=0;i<4;i++){
         if (map[i][i]=='X') cntx++;else
         if (map[i][i]=='O') cnto++;else
         if (map[i][i]=='T'){cntx++;cnto++;}
     }
     if (cntx==4){cout<<"X won"<<endl;return;}
     if (cnto==4){cout<<"O won"<<endl;return;}
     //dia2
     cntx=0,cnto=0;
     for (int i=0;i<4;i++){
         if (map[i][3-i]=='X') cntx++;else
         if (map[i][3-i]=='O') cnto++;else
         if (map[i][3-i]=='T'){cntx++;cnto++;}
     }
     if (cntx==4){cout<<"X won"<<endl;return;}
     if (cnto==4){cout<<"O won"<<endl;return;}
     //not complete
     if (empty!=0){cout<<"Game has not completed"<<endl;return;}
     //Draw
     cout<<"Draw"<<endl;
     return;
}

int main()
{
    freopen("1.in","r",stdin);    
    freopen("1.out","w",stdout);
    cin>>T;
    for (int Case=1;Case<=T;Case++){
        for (int i=0;i<4;i++) cin>>map[i]; 
        //cout<<"-----------------------------------"<<endl;
        //for (int i=0;i<4;i++) cout<<map[i]<<endl;
        //cout<<"-----------------------------------"<<endl;
        cout<<"Case #"<<Case<<": "; 
        check();
    } 
} 
