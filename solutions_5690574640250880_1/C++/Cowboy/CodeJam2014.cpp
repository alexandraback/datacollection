/*
 *ID:   Cowboy
 *TASK:
 *Judge:
 */
#include <bits/stdc++.h>
#define INF 0x7fffffff
#define PI 2*acos(0.0)
#define EPS 10E-9
using namespace std;

#define PB(t) push_back(t)
#define ALL(t) t.begin(),t.end()
#define MP(x, y) make_pair((x), (y))
#define Fill(a,c) memset(&a, c, sizeof(a))

vector<string>grid;
int R, C;

void imprimir(){
    cout<<"_______________________\n";
    for (int i=0; i<R; i++)
        cout<<grid[i]<<endl;
    cout<<"_______________________\n";
}

bool isValid( int x, int y){
    return x>=0 && x<R && y>=0 && y<C;
}

bool llenar( int nV ){
    //cout<<nV<<endl;
    if( nV==1 )
        return true;

    if( R==1 ) {
        for(int i=0; i<nV; i++){
            grid[0][i]='.';
        }
        return (grid[0][1]=='.');
    } else if( C==1 ){
        for(int i=0; i<nV; i++){
            grid[i][0]='.';
        }
        return grid[1][0]=='.';
    }

    grid[0][0]=grid[0][1]=grid[1][0]=grid[1][1]='.';
    nV-=4;
    if( nV<0 )
        return false;

    if( nV&1 ){
        if(nV<=3 || C<3 || R<3){
            return false;
        }
        grid[2][2]=grid[0][2]=grid[1][2]=grid[2][0]=grid[2][1]='.';
        nV-=5;
    }
//    cout<<"Antes de filas por 2 "<<nV<<endl;
//    imprimir();
    //Llenar fila 0 y 1
    for( int i= 0; nV>0 && i<C; i++ ){
        if( grid[0][i]=='*' && grid[1][i]=='*' ){
            grid[0][i]='.';
            grid[1][i]='.';
            nV-=2;
        }
    }

//    cout<<"Antes de Col< por 2 "<<nV<<endl;
//    imprimir();
    //Llenar Col 0 y 1
    for( int i= 0; nV>0 && i<R; i++ ){
        if( grid[i][0]=='*' && grid[i][1]=='*' ){
            grid[i][0]='.';
            grid[i][1]='.';
            nV-=2;
        }
    }

//    cout<<"Antes de Terminado "<<nV<<endl;
//    imprimir();
    for( int i=0; nV>0 && i<R; i++){
        for (int j=0 ; nV>0 && j<C; j++){
            if( grid[i][j]=='*' ){
                grid[i][j]='.';
                nV--;
            }
        }
    }
//    cout<<"Despues "<<nV<<endl;
//    imprimir();
    return true;
}

int main( ){
    freopen("C-large.in","r",stdin);
    freopen("solution.out","w",stdout);
    int T, k = 0;
    for( cin>>T; k<T; k++){
        int M;
        cin>>R>>C>>M;
        grid= vector<string>(R, string(C, '*') );

        //llenar( R*C-M );


        printf("Case #%d:\n", k+1);
        if( !llenar( R*C-M ) ){
            printf("Impossible\n");
//            cout<<R<<" "<<C<<" "<<M<<endl;
//            imprimir();
        } else {
            grid[0][0]='c';
            for (int i=0; i<R; i++){
                cout<<grid[i]<<endl;
            }
        }

    }

return 0;
}
