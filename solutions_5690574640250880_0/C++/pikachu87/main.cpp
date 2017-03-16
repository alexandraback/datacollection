//
//  main.cpp
//  TaskC
//
//  Created by Quoc-Huy Tran on 12/04/2014.
//  Copyright (c) 2014 *. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;

char** fill(int R, int C, int M) {
    char** A;
    A = new char*[R];
    for (int i=0; i<R; i++)
        A[i] = new char[C];
    
    for (int i=0; i<R; i++)
        for (int j=0; j<C; j++)
            A[i][j] = '.';

    if (M==0) { // M=0
        A[R-1][C-1] = 'c';
        return A;
        
    } else if (R==1) { // R=1
        if (C-M>=1) {
            A[0][C-1] = 'c';
            for (int j=0; j<M; j++)
                A[0][j] = '*';
            return A;
        }
        
    } else if (C==1) { // C=1
        if (R-M>=1) {
            A[R-1][0] = 'c';
            for (int i=0; i<M; i++)
                A[i][0] = '*';
            return A;
        }
        
    } else if (R>1 && C>1) { // R>1, C>1
        if (R*C-M==1) {
            A[R-1][C-1] = 'c';
            for (int i=0; i<R; i++) {
                for (int j=0; j<C; j++) {
                    if (M>0) {
                        A[i][j] = '*';
                        M--;
                    }
                }
            }
            return A;
        }
        
        if (R*C-M>=4) {
            A[R-1][C-1] = 'c';
            int N = R*C-M;
            int min = R*C;
            int dR = 0;
            int dC = 0;
            for (int i=2; i<=R; i++) {
                for (int j=2; j<=C; j++) {
                    if (i*j==N) {
                        dR = i;
                        dC = j;
                        min = 0;
                        break;
                    } else {
                        if (i*j>N && i>2 && j>2 && i*j<=min) {
                            dR = i;
                            dC = j;
                            min = i*j;
                        }
                    }
                }
                if (min==0)
                    break;
            }
        
            if ((min==0) || (dR>2 && dC>2 && (dR-2)*(dC-2)>=min-N)) {
                for (int i=0; i<R; i++) {
                    for (int j=0; j<C; j++) {
                        if (i<R-dR || j<C-dC) {
                            A[i][j] = '*';
                            M--;
                        }
                    }
                }
                for (int i=R-dR; i<R-2; i++) {
                    for (int j=C-dC; j<C-2; j++) {
                        if (M>0) {
                            A[i][j] = '*';
                            M--;
                        }
                    }
                }
                return A;
            }
        }
    }

    return nullptr;
}

int main()
{
    int T;
    cin>>T;
    
    int R,C,M;
    for (int k=0; k<T; k++) {
        cin>>R>>C>>M;
        
        char** A = fill(R,C,M);
        
        cout<<"Case #"<<k+1<<":"<<endl;
        if (A==nullptr) {
            cout<<"Impossible"<<endl;
        } else {
            for (int i=0; i<R; i++) {
                for (int j=0; j<C; j++)
                    cout<<A[i][j];
                cout<<endl;
            }
        }
    }
    
    return 0;
}

