#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define PB push_back
#define MP make_pair
#define SL size()
#define LE length()
#define INFI 2000000000
#define X first
#define Y second
#define MIN(a,b) ((a)<(b)?(a):(b))
char A[4][4];

bool checkH(char c){
     for(int i = 0; i < 4;i++){
         int cont = 0;
         for(int j=0;j<4;j++){
             if(A[i][j] == c || A[i][j] == 'T'){
                cont++;
             }
         }  
         if(cont == 4) return true;      
     }     
     return false;
}

bool checkV(char c){
     for(int i = 0; i < 4;i++){
         int cont = 0;
         for(int j=0;j<4;j++){
             if(A[j][i] == c || A[j][i] == 'T'){
                cont++;
             }
         }  
         if(cont == 4) return true;      
     }     
     return false;
}

bool checkD(char c){
     int cont1 = 0, cont2 = 0;
     for(int i = 0; i < 4;i++){
         if(A[i][i] == c || A[i][i] == 'T'){
                cont1++;
         }
         if(A[i][3-i] == c || A[i][3-i] == 'T'){
                cont2++;
         }
     }  
     if(cont1 == 4 || cont2 == 4) return true;         
     return false;
}

int main(){
    int T; cin>>T;
    for(int kases = 1; kases <= T;kases++){
        bool xWin = false, oWin = false, isCompleted = true;
        for(int i=0;i<4;i++){ for(int j=0;j<4;j++){ 
                cin>>A[i][j]; 
                if(A[i][j] == '.') isCompleted = false; 
        }}
        xWin = checkH('X');  xWin |= checkV('X'); xWin |= checkD('X');
        oWin = checkH('O');  oWin |= checkV('O'); oWin |= checkD('O');
        if(xWin) cout<<"Case #"<<kases<<": X won"<<endl;
        else if(oWin) cout<<"Case #"<<kases<<": O won"<<endl;
        else if(isCompleted) cout<<"Case #"<<kases<<": Draw"<<endl;
        else cout<<"Case #"<<kases<<": Game has not completed"<<endl;
    }
}
