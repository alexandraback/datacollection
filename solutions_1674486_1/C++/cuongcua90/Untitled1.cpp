#include <iostream>
#define MAX_L 10001
using namespace std;
int T,N;
int temp1;
int a[MAX_L][MAX_L];
int b[MAX_L][MAX_L];

int dfs_1(int x, int y){
    //cout << "dfs "<< x <<" "<< y<<endl;
    for (int i =1 ; i<=N;++i){
        if (a[y][i] == 1){
            if (b[x][y]>0){
                b[x][i] = b[x][i] + 1;    
                if (b[x][i] > 1){
                    return 1;
                }
                dfs_1(x,i);
            }
            else if (x==y){
                b[x][i] = b[x][i]+1;
                if (b[x][i] > 1){
                    return 1;
                }
                //return 1;
                dfs_1(x,i);    
            }
        }    
    }
}
int print(int b[MAX_L][MAX_L]){
    for (int i=1; i<= N;++i){
        for (int j=1; j<=N;++j){
            if (b[i][j] > 1){
                return 1;    
            }
        }    
        //cout << endl;
    }    
    return 0;
}
int main(){
    cin >> T;
    
    for (int xx = 1; xx <=T ;++xx){
        cin >> N;
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        for (int i = 0; i<N;++i){
            int temp;
            cin >>   temp;
           
            for (int j = 0; j<temp;++j){
                cin >> temp1;
                a[i+1][temp1] = 1;
            } 
        } 
        for (int i = 1; i<=N;++i){
            dfs_1(i,i);
                    
                
        }
        
        if (print(b)){
            cout <<"Case #" <<xx << ": Yes"<<endl;   
        }   
        else{
            cout <<"Case #" <<xx << ": No"<<endl;   
        }
      
    }  
   
}
