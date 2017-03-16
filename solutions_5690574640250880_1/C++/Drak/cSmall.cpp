#include <bits/stdc++.h>
using namespace std;
#define msg(x) cout<<#x<<" = "<<x<<endl;
#define N 100
char mapa[N][N];
int row, col, minas;
int main() {
    int T;
    scanf("%d", &T);
    for(int caso=1 ; caso<=T ; caso++) {
    	printf("Case #%d:\n", caso);
    	scanf("%d %d %d", &row, &col, &minas);
    	if( minas == 0 ) {
    		memset(mapa, '.', sizeof(mapa));
    		mapa[row][col] = 'c';
    		for(int i=1 ; i<=row ; i++) {
    			for(int k=1 ; k<=col ; k++)
    				cout<<mapa[i][k];
    			cout<<endl;
    		}
    		continue;
    	}
    	if( row * col - 1 == minas ) {
    		memset(mapa, '*', sizeof(mapa));
    		mapa[row][col] = 'c';
    		for(int i=1 ; i<=row ; i++) {
    			for(int k=1 ; k<=col ; k++)
    				cout<<mapa[i][k];
    			cout<<endl;
    		}
    		continue;
    	}
    	if( row == 1 || col == 1 ) {
    		memset(mapa, '.', sizeof(mapa));
    		mapa[row][col] = 'c';
    		for(int i=1 ; i<=row ; i++) {
    			for(int k=1 ; k<=col ; k++)
    				if( minas ) { cout<<"*"; minas--; }
    				else cout<<mapa[i][k];
    			cout<<endl;
    		}
    		continue;
    	}
    	if( row * col - 4 < minas ) {
    		printf("Impossible\n");
    		continue;
    	}
        if( row == 2 || col == 2 ) {
            if( minas % 2 == 0 ) {
                memset(mapa, '.', sizeof(mapa));
                mapa[row][col] = 'c';
                if( row == 2 ) {
                    for(int k=1 ; k<=minas/2 ; k++) mapa[1][k] = mapa[2][k] = '*';
                } else {
                    for(int k=1 ; k<=minas/2 ; k++) mapa[k][1] = mapa[k][2] = '*';
                }
                for(int i=1 ; i<=row ; i++) {
                    for(int k=1 ; k<=col ; k++) 
                        cout<<mapa[i][k];
                    cout<<endl;
                }
            } else printf("Impossible\n");
            continue;
        }
        memset(mapa, '.', sizeof(mapa));
        bool flagSwap = false, flag = true;
        if( row > col ) {
            swap(row, col);
            flagSwap = true;
        }
        mapa[row][col] = 'c';
        int posCol = 1;
        while( flag && posCol != col-2 && minas) {
            for(int i=1 ; i<=row-2 ; i++) {
                mapa[i][posCol] = '*';
                minas--;
                if( minas == 0 ) {
                    flag = false;
                    break;
                }
            }
            if( flag == false ) break;
            if( minas == 1 ) {
                mapa[1][posCol + 1] = '*';
                minas--;
                flag = false;
                break;
            } else {
                mapa[row-1][posCol] = '*';
                mapa[row][posCol] = '*';
                minas -= 2;
                if( minas == 0 ) break;
            }
            posCol++;
        }
        int posRow = 1;
        while( flag && posRow != row-2 && minas) {
            if( minas == 1 ) {
                mapa[posRow][posCol] = '*';
                minas--;
                flag = false;
                break;
            } else {
                if( minas == 2 ) {
                    mapa[posRow][posCol] = '*';
                    mapa[posRow+1][posCol] = '*';
                    minas -= 2;
                    flag = false;
                    break;
                } else {
                    mapa[posRow][posCol] = '*';
                    mapa[posRow][posCol+1] = '*';
                    mapa[posRow][posCol+2] = '*';
                    minas -= 3;
                }
            }
            posRow++;
        }
        if( flag != false && minas != 0 ) {
            if( minas == 1 || minas == 3 || minas == 5 ) {
                if( minas == 1 ) {
                    mapa[row-2][col-2] = '*';
                }
                if( minas == 3 ) {
                    mapa[row-2][col-2] = '*';
                    mapa[row-2][col-1] = '*';
                    mapa[row-2][col] = '*';
                }
                if( minas == 5 ) {
                    mapa[row-2][col-2] = '*';
                    mapa[row-2][col-1] = '*';
                    mapa[row-2][col] = '*';
                    mapa[row-1][col-2] = '*';
                    mapa[row][col-2] = '*';
                }
            } else {
                printf("Impossible\n");
                continue;
                //cout<<"bad"<<endl;
            }
        }
        /*
        cout<<tmprow<<" "<<tmpcol<<" "<<tmpminas<<endl;
        for(int i=1 ; i<=row ; i++) {
                for(int k=1 ; k<=col ; k++) 
                    cout<<mapa[i][k];
                cout<<endl;
        }
        cout<<endl<<endl;
        */
        if( flagSwap ) {
            for(int i=1 ; i<=col ; i++) {
                for(int k=1 ; k<=row ; k++) {
                    cout<<mapa[k][i];
                }
                cout<<endl;
            }
        } else {
            for(int i=1 ; i<=row ; i++) {
                for(int k=1 ; k<=col ; k++) 
                    cout<<mapa[i][k];
                cout<<endl;
            }
        }
    }
    return 0;
}