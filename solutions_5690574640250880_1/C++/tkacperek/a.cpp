#include <iostream>
using namespace std;

void showme(char ** tab, int R, int C) {
    int j,k;
    for (j=0; j<R; j++) {
        for (k=0; k<C; k++) {
            cout << tab[j][k];
        }
        cout << endl;
    }
}

void revshowme(char ** tab, int R, int C) {
    int j,k;
    for (j=0; j<C; j++) {
        for (k=0; k<R; k++) {
            cout << tab[R-1-k][j];
        }
        cout << endl;
    }
}

void size1(char ** tab, int R, int C, int M) {
    int i;
    if (R==1 && M+2<=C) {
        tab[0][0]='c';
        for (i=1; i<C-M; i++) {
            tab[0][i]='.';
        }
        showme(tab,R,C);
    }
    else if (C==1 && M+2<=R) {
        tab[0][0]='c';
        for (i=1; i<R-M; i++) {
            tab[i][0]='.';
        }
        showme(tab,R,C);
    } else
        cout << "Impossible\n";
}

void even(char ** tab, int R, int C, int D) {
    int j,k;
    // 2x2 in upper left corner
    tab[0][0]='c';
    tab[0][1]=tab[1][0]=tab[1][1]='.';
    D-=4;
    // add 2x1 to the right
    k=2;
    while (D>0 && k<C) {
        tab[0][k]=tab[1][k]='.';
        k++;
        D-=2;
    }
    // add 1x2 below from left to right
    j=2;
    k=0;
    while (D>0) {
        // add pair
        tab[j][k]=tab[j][k+1]='.';
        D-=2;
        if (k+3>=C) {
            if (D>0 && k+3==C && tab[j-1][k+2]=='*') {
                // fill holes
                tab[j-1][k+2]=tab[j][k+2]='.';
                D-=2;
            }
            // next row
            j+=1;
            k=0;
        } else {
            // next pair
            k+=2;
        }
    }
}

void odd(char ** tab, int R, int C, int D) {
    int j,k;
    bool found;
    // fill with D-1 dots
    even(tab,R,C,D-1);
//showme(tab,R,C);
    // if less or exactly 2 lines are filled
    if (tab[2][0]=='*') {
        // find last 2x1
        k=0;
        while (tab[0][k+1]=='.')
            k++;
        // if 3. row exists and there is enought space
        if (2<R && k>2) {
            tab[0][k]=tab[1][k]='*';
            tab[2][0]=tab[2][1]=tab[2][2]='.';
            showme(tab,R,C);
        }
        else {
            cout << "Impossible\n";
        }
    }
    else {
        // find first *
        j=1;
        found=false;
        while (!found) {
            j++;
            k=-1;
            while (!found && k+1<C) {
                k++;
                found=(tab[j][k]=='*');
            }
        }
//cout << j << endl << k << endl;
        if (k==0) {
            tab[j-1][C-1]='*';
            tab[j][0]=tab[j][1]='.';
            showme(tab,R,C);
        }
        else {
            tab[j][k]='.';
            showme(tab,R,C);
        }
        
    }
}

void revodd(char ** tab, int R, int C, int D) {
    int j,k;
    bool found;
    // fill with D-1 dots
    even(tab,R,C,D-1);
    // if less or exactly 2 lines are filled
    if (tab[2][0]=='*') {
        // find last 2x1
        k=0;
        while (tab[0][k+1]=='.')
            k++;
        // if 3. row exists and there is enought space
        if (2<R && k>2) {
            tab[0][k]=tab[1][k]='*';
            tab[2][0]=tab[2][1]=tab[2][2]='.';
            revshowme(tab,R,C);
        }
        else {
            cout << "Impossible\n";
        }
    }
    else {
        // find first *
        j=1;
        found=false;
        while (!found) {
            j++;
            k=-1;
            while (!found && k+1<C) {
                k++;
                found=(tab[j][k]=='*');
            }
        }
        
        if (k==0) {
            tab[j-1][C-1]='*';
            tab[j][0]=tab[j][1]='.';
            showme(tab,R,C);
        }
        else {
            tab[j][k]='.';
            revshowme(tab,R,C);
        }
        
    }
}

int main() {
    int i,j,k,T,R,C,M,D;
    char ** tab, **rottab;
    cin >> T;
    for (i=0; i<T; i++) {
        // out start
        cout << "Case #" << i+1 << ":\n";
        // rows ,columns, mines, dots
        cin >> R >> C >> M;
        D = R*C-M;
        // start tab
        tab = new char * [R];
        for (j=0; j<R; j++) {
            tab[j]=new char [C];
            for (k=0; k<C; k++) {
                tab[j][k]='*';
            }
        }
        
        if (M==0) {
            for (j=0; j<R; j++) {
                for (k=0; k<C; k++) {
                    tab[j][k]='.';
                }
            }
            tab[0][0]='c';
            showme(tab,R,C);
        }
        else if (D==1) {
            for (j=0; j<R; j++) {
                for (k=0; k<C; k++) {
                    tab[j][k]='*';
                }
            }
            tab[0][0]='c';
            showme(tab,R,C);
        }
        else if (R==1 || C==1) {
            size1(tab,R,C,M);
        }
        else if (D < 4 || D==5 || D==7) {
            cout << "Impossible\n";
        }
        else if (D % 2 == 0) {
            if (R>C) {
                rottab = new char * [C];
                for (j=0; j<C; j++) {
                    rottab[j]=new char[R];
                    for (k=0; k<R; k++) {
                        rottab[j][k]='*';
                    }
                }
                even(rottab,C,R,D);
                for (j=0; j<R; j++) {
                    for (k=0; k<C; k++) {
                        tab[j][k]=rottab[C-1-k][j];
                    }
                }
                for (j=0; j<C; j++) {
                    delete [] rottab[j];
                }
                delete [] rottab;

                showme(tab,R,C);
            } else {
                even(tab,R,C,D);
                showme(tab,R,C);
            }
        }
        else if (D % 2 == 1 && (R==2 || C==2)) {
            cout << "Impossible\n";
        }
        else { // other odds
            if (R>C) {
                rottab = new char * [C];
                for (j=0; j<C; j++) {
                    rottab[j]=new char[R];
                    for (k=0; k<R; k++) {
                        rottab[j][k]='*';
                    }
                }
                revodd(rottab,C,R,D);
            } else {
                odd(tab,R,C,D);
            }
        }
        
        // delete tab
        for (j=0; j<R; j++) {
            delete [] tab[j];
        }
        delete [] tab;
    }
    return 0;
}