//
//  main.cpp
//  mine master
//
//  Created by Zulkarnine on 4/12/14.
//  Copyright (c) 2014 Zulkarnine Mahmud. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <deque>
#include <list>

using namespace std;

#define nl cout<<endl
#define CLICK 2
#define MINE 0
#define BLANK 1

void printImpossible(){
    cout<<"Impossible\n";
}

void printMatrix(vector< vector<int> > mat){
    
    vector< vector<int> >printMat=mat;
    
    int row=mat.size();
    int column=mat[0].size();
    for (int i=0; i<row; i++) {
        for (int j=0; j<column; j++) {
            switch (mat[i][j]) {
                case MINE: //means mine
                    cout<<"*";
                    break;
                case BLANK:  //means no mine
                    cout<<".";
                    break;
                case CLICK:  //means click
                    cout<<"c";
                    break;
                    
                default:
                    break;
            }
            
        }
        cout<<"\n";
    }
}


void printNoMine(int row,int column){
    vector< vector<int> >mat;
    vector<int> temp(column,BLANK);
    for (int i=0; i<row; i++) {
        mat.push_back(temp);
    }
    
    mat[0][0]=CLICK;
    printMatrix(mat);
    
}

void printOneRemaining(int row, int column){
    for (int i=0; i<row-1; i++) {
        for (int j=0; j<column; j++) {
            cout<<"*";
        }
        cout<<"\n";
    }
    for (int j=0; j<column-1; j++) {
        cout<<"*";
    }
    cout<<"c\n";
    
    
    //    vector< vector<int> >mat;
    //    vector<int> temp(column,BLANK);
    //    for (int i=0; i<row; i++) {
    //        mat.push_back(temp);
    //    }
    //
    //    mat[0][0]=CLICK;
    //    mat[row-1][column-1]=MINE;
    //    printMatrix(mat, row, column);
}

void print1D(int row, int column,int mines){
    if (row==1) {
        int i=0;
        for ( i=0; i<mines; i++) {
            cout<<"*";
        }
        
        while (i<column-1) {
            cout<<".";
            i++;
        }
        cout<<"c\n";
    }else{
        //column==1
        
        int i=0;
        for ( i=0; i<mines; i++) {
            cout<<"*\n";
        }
        
        while (i<row-1) {
            cout<<".\n";
            i++;
        }
        cout<<"c\n";
    }
    
    
    
}

void print2D(int row, int column,int mines){
    if (row==2) {
        int perRow=mines/2;
        int i;
        for ( i=0; i<perRow; i++) {
            cout<<"*";
        }
        while (i<column) {
            cout<<".";
            i++;
        }
        cout<<"\n";
        
        for ( i=0; i<perRow; i++) {
            cout<<"*";
        }
        while (i<column-1) {
            cout<<".";
            i++;
        }
        cout<<"c\n";
    }else{
        //column==2
        int perColumn=mines/2;
        int i;
        for ( i=0; i<perColumn; i++) {
            cout<<"**\n";
        }
        while (i<row-1) {
            cout<<"..\n";
            i++;
        }
        cout<<".c\n";
    }
    
    
    
}


vector< vector<int> > printDoublePaired(int row, int column,int mines,int remaining){
    //0 means mines
    //1 means no mines
    
    int dotCount=0;
    vector< vector<int>> mat;
    for (int i=0; i<row; i++) {
        vector<int> rows(column,0);
        mat.push_back(rows);
    }
    
    for (int i=0; i<row-1; i+=2) {
        for (int j=0; j<column; j++) {
            
            if (j==0&&(remaining-dotCount==2)) {
                mat[i][j]=BLANK;
                mat[i][j+1]=BLANK;
                dotCount+=2;
                break;
            }
            
            
            if (dotCount<remaining) {
                mat[i][j]=BLANK;
                mat[i+1][j]=BLANK;
                dotCount+=2;
            }else break;
        }
    }
    
    mat[0][0]=CLICK;
    
    if (dotCount<remaining) {
        for (int j=0; j<column; j++) {
            if (dotCount<remaining) {
                mat[row-1][j]=1;
                dotCount++;
            }else break;
        }
    }
    
    
    
    return mat;
    
}

vector< vector<int> >flipMat(vector< vector<int> > mat){
    vector< vector<int> > flipMat;
    
    
    vector<int> temp(mat.size(),MINE);
    for (int i=0; i<mat[0].size(); i++) {
        flipMat.push_back(temp);
    }
    
    for (int i=0; i<flipMat.size(); i++) {
        for (int j=0; j<flipMat[i].size(); j++) {
            flipMat[i][j]=mat[j][i];
        }
    }
    
    return flipMat;
    
}

vector< vector<int> > printUnevenPaired(int row, int column, int mines, int ActRemaining){
    
    vector< vector<int> > mat;
    
    
    int remaining=ActRemaining-3;
    
    if (column>=row) {
        vector<int> temp(column,MINE);
        for (int i=0; i<row; i++) {
            mat.push_back(temp);
        }
        
        int dotCount=0;
        
        bool filledFlag=false;
        int lastFilli=0;
        int lastFillj=0;
        
        for (int i=0; i<row-1; i+=2) {
            for (int j=0; j<column; j++) {
                
                if (j==0&&(remaining-dotCount==2)) {
                    mat[i][j]=BLANK;
                    mat[i][j+1]=BLANK;
                    dotCount+=2;
                    filledFlag=true;
                    if (i!=row-1) {
                        mat[i][2]=BLANK;
                        mat[i+1][0]=BLANK;
                        mat[i+1][1]=BLANK;
                    }else{
                        mat[i][2]=BLANK;
                        mat[i][3]=BLANK;
                        mat[i][4]=BLANK;
                    }
                    
                    break;
                }
                
                
                if (dotCount<remaining) {
                    mat[i][j]=BLANK;
                    mat[i+1][j]=BLANK;
                    lastFilli=i+1;
                    lastFillj=j;
                    dotCount+=2;
                }else break;
            }
        }
        
        mat[0][0]=CLICK;
        
        if (dotCount==remaining&&(filledFlag==false)) {
            if (lastFilli!=row-1) {
                mat[lastFilli+1][0]=BLANK;
                mat[lastFilli+1][1]=BLANK;
                if (lastFillj==column-1) {
                    mat[lastFilli+1][2]=BLANK;
                }else if(lastFilli-1==0){
                    mat[lastFilli+1][2]=BLANK;
                }else{
                    mat[lastFilli-1][lastFillj+1]=BLANK;
                }
            }else{
                mat[lastFilli-1][lastFillj+1]=BLANK;
                mat[lastFilli][lastFillj+1]=BLANK;
                mat[lastFilli-1][lastFillj+2]=BLANK;
                
            }
        }
        
        if (dotCount<remaining) {
            for (int j=0; j<column; j++) {
                if (dotCount<ActRemaining) {
                    dotCount++;
                    mat[row-1][j]=1;
                }else break;
            }
        }
        
        return mat;
    }else{
        int tm=row;
        row=column;
        column=tm;
        
        mat.clear();
        vector<int> temp(column,MINE);
        for (int i=0; i<row; i++) {
            mat.push_back(temp);
        }
        
        int dotCount=0;
        
        bool filledFlag=false;
        int lastFilli=0;
        int lastFillj=0;
        
        for (int i=0; i<row-1; i+=2) {
            for (int j=0; j<column; j++) {
                
                if (j==0&&(remaining-dotCount==2)) {
                    mat[i][j]=BLANK;
                    mat[i][j+1]=BLANK;
                    dotCount+=2;
                    filledFlag=true;
                    if (i!=row-1) {
                        mat[i][2]=BLANK;
                        mat[i+1][0]=BLANK;
                        mat[i+1][1]=BLANK;
                    }else{
                        mat[i][2]=BLANK;
                        mat[i][3]=BLANK;
                        mat[i][4]=BLANK;
                    }
                    
                    break;
                }
                
                
                if (dotCount<remaining) {
                    mat[i][j]=BLANK;
                    mat[i+1][j]=BLANK;
                    lastFilli=i+1;
                    lastFillj=j;
                    dotCount+=2;
                }else break;
            }
        }
        
        mat[0][0]=CLICK;
        
        if (dotCount==remaining&&(filledFlag==false)) {
            if (lastFilli!=row-1) {
                mat[lastFilli+1][0]=BLANK;
                mat[lastFilli+1][1]=BLANK;
                if (lastFillj==column-1) {
                    mat[lastFilli+1][2]=BLANK;
                }else if(lastFilli-1==0){
                    mat[lastFilli+1][2]=BLANK;
                }else{
                    mat[lastFilli-1][lastFillj+1]=BLANK;
                }
            }else{
                mat[lastFilli-1][lastFillj+1]=BLANK;
                mat[lastFilli][lastFillj+1]=BLANK;
                mat[lastFilli-1][lastFillj+2]=BLANK;
                
            }
        }
        
        if (dotCount<remaining) {
            for (int j=0; j<column; j++) {
                if (dotCount<ActRemaining) {
                    dotCount++;
                    mat[row-1][j]=1;
                }else break;
            }
        }
        vector< vector<int> >flippedMatrix=flipMat(mat);
        
        return flippedMatrix;
        
    }
    
}

void solveCase(int row, int column, int mines){
    int total=row*column;
    int remaining=total-mines;
    //    vector< vector<int> >mat;
    //    vector<int> temp(column,MINE);
    //    for (int i=0; i<row; i++) {
    //        mat.push_back(temp);
    //    }
    
    
    //for 1 mine
    if (mines==0) {
        printNoMine(row, column);
        return;
    }
    
    if (remaining==1) {
        printOneRemaining(row,column);
        return;
    }
    
    //for 1d
    if (min(row, column)==1) {
        int bigger,smaller;
        if (row>column) {
            bigger=row;
            smaller=column;
        }else{
            bigger=column;
            smaller=row;
        }
        
        if (mines<bigger) {
            print1D(row,column,mines);
        }else{
            printImpossible();
        }
        
        return;
    }else if(min(row, column)==2){
        //for 2d
        if (remaining%2==1||remaining==2) {
            printImpossible();
        }else{
            print2D(row, column, mines);
        }
        
        return;
        
    }else{
        
        //for greater d
        if (remaining==2||remaining==3||remaining==5||remaining==7) {
            printImpossible();
        }else{
            if (remaining%2==0) {
                vector< vector<int> >ansMat=printDoublePaired(row, column, mines, remaining);
                
                printMatrix(ansMat);
            }else{
                vector< vector<int> >ansMat=printUnevenPaired(row, column, mines, remaining);
                
                printMatrix(ansMat);
            }
        }
        return;
    }
}


int main(int argc, const char * argv[])
{
    int T,cas=0;
    
    
    freopen("C-small-attempt5.in", "r", stdin);
    freopen("C-small-attempt5.out", "w", stdout);
    
    
    //    freopen("/Users/rezan_mahmud/Desktop/Codejam/t.inp", "r", stdin);
    //    freopen("/Users/rezan_mahmud/Desktop/Codejam/t.out", "w", stdout);
    
    
    cin>>T;
    while (T--) {
        int row,column,mines;
        cin>>row>>column>>mines;
        printf("Case #%d:\n",++cas);
        //        printf("%d %d %d\n",row,column,mines);
        solveCase(row,column,mines);
        
    }
    
    
    return 0;
}
