//
//  main.cpp
//  tictactomac
//
//  Created by Nolan Miller on 4/12/13.
//  Copyright (c) 2013 Nolan Miller. All rights reserved.
//

#include <iostream>
#include <sstream>	//string manipulation
#include <vector>	//dynamic arrays
#include <algorithm>//useful algorithms (sort) etc
#include <climits>	//data type cap info
#include <cmath>    //mathematical operations
#define min(A,B) (((A)>(B))?(B):(A))
#define max(A,B) (((A)<(B))?(B):(A))

using namespace std;


void print2d(int** array,int w,int h){
    for(int i =0;i<h;i++){
	    for(int ii =0;ii<w;ii++){
	        cout<<array[i][ii]<<" ";
		}
	    cout<<endl;
    }
    cout<<endl;
}

string arrayComp(int **in1,int**in2,int n,int m){

    for (int i = 0; i<n; i++) {
        for(int ii = 0;ii<m;ii++){
            if(in1[i][ii]!=in2[i][ii]){
                return "NO";
            }
        }
    }
    return "YES";
}


string testBoard(int **b,int n,int m){
    string ret;
    int **t;
    t = new int*[n];
    for(int i = 0;i<n;i++){
        t[i] = new int[m];
        for (int ii = 0; ii<m; ii++) {
            t[i][ii] = 100000;
        }
    }
    
    for (int i = 0; i<n; i++) {
        //find max of row
        int rmax =0;
        for (int ii = 0; ii<m; ii++) {
            rmax = max(rmax,b[i][ii]);
        }
        for (int ii = 0;ii<m; ii++) {
            t[i][ii] = min(rmax,t[i][ii]);
        }
    }
    for (int i = 0; i<m; i++) {
        //find max of row
        int rmax =0;
        for (int ii = 0; ii<n; ii++) {
            rmax = max(rmax,b[ii][i]);
        }
        for (int ii = 0;ii<n; ii++) {
            t[ii][i] = min(rmax,t[ii][i]);
        }
    }
    ret = arrayComp(t, b, n, m);
    
    for (int i = 0; i<n; i++) {
        delete[] t[i];
    }
    delete t;
    return ret;
}


int main(int argc, const char * argv[])
{
    int length;
    cin>>length;
    int **lawn;
    int M,N;
    for (int it=0; it<length; it++) {
        cin>>N;
        cin>>M;
        lawn = new int*[N];
        for(int i = 0;i<N;i++){
            lawn[i] = new int[M];
        }
        for (int i=0; i<N; i++) {
            for (int ii =0; ii<M; ii++) {
                cin>>lawn[i][ii];
            }
        }
        cout<<"Case #"<<it+1<<": "<< testBoard(lawn,N,M) <<endl;
        for (int i = 0; i<N; i++) {
            delete[] lawn[i];
        }
        delete lawn;
    }
    return 0;
}


