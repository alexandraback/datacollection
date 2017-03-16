#include <iostream>

using namespace std;
char tablero[4][5];
char tmp[5];

int vertical(int pos, char c){
    for(int i=0;i<4;i++){
        if(tablero[pos][i]!=c && tablero[pos][i]!='T')
        {
            return 0;
        }
    }
    return 1;
}

int horizontal(int pos, char c){
    for(int i=0;i<4;i++){
        if(tablero[i][pos]!=c && tablero[i][pos]!='T')
        {
            return 0;
        }
    }
    return 1;
}

int diagonal1(char c){
    if(tablero[0][0]!=c && tablero[0][0]!='T')
    {
        return 0;
    }
    if(tablero[1][1]!=c && tablero[1][1]!='T')
    {
        return 0;
    }
    if(tablero[2][2]!=c && tablero[2][2]!='T')
    {
        return 0;
    }
    if(tablero[3][3]!=c && tablero[3][3]!='T')
    {
        return 0;
    }
    return 1;
}

int diagonal2(char c){
    if(tablero[0][3]!=c && tablero[0][3]!='T')
    {
        return 0;
    }
    if(tablero[1][2]!=c && tablero[1][2]!='T')
    {
        return 0;
    }
    if(tablero[2][1]!=c && tablero[2][1]!='T')
    {
        return 0;
    }
    if(tablero[3][0]!=c && tablero[3][0]!='T')
    {
        return 0;
    }
    return 1;
}

int haGanado(char c)
{
    if(vertical(0,c) ||vertical(1,c) || vertical(2,c) || vertical(3,c))
    {
        return 1;
    }
    if(horizontal(0,c) || horizontal(1,c) || horizontal (2,c) || horizontal(3,c))
    {
        return 1;
    }
    if(diagonal1(c) || diagonal2(c))
    {
        return 1;
    }
    return 0;
}


int todosMovimientos()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(tablero[i][j]=='.')
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int i,j,k;
    int T;
    cin >> T;
    
    for(i=0;i<T;i++)
    {
        // Leeemos el tablero
        cin.getline(tmp,5);
        
        cin.getline(tablero[0],5);
        cin.getline(tablero[1],5);
        cin.getline(tablero[2],5);
        cin.getline(tablero[3],5);
        /*
        cout << "TABLERO" << endl;
        cout << tablero[0]<<endl;
        cout << tablero[1]<<endl;
        cout << tablero[2]<<endl;
        cout << tablero[3]<<endl;
        */
        if(haGanado('X')){
            cout << "Case #"<<(i+1)<<": X won"<<endl;
        }
        else if(haGanado('O')){
            cout << "Case #"<<(i+1)<<": O won"<<endl;
        }
        else if(todosMovimientos()){
            cout << "Case #"<<(i+1)<<": Draw"<<endl;
        }
        else{
            cout << "Case #"<<(i+1)<<": Game has not completed"<<endl;
        }
    }
    return 0;
}
