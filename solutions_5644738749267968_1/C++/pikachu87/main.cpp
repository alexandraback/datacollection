//
//  main.cpp
//  TaskD
//
//  Created by Quoc-Huy Tran on 13/04/2014.
//  Copyright (c) 2014 *. All rights reserved.
//

#include <iostream>

using namespace std;

void swap(double& a, double& b) {
    double t = a;
    a = b;
    b = t;
}

void sort(double A[], int N) {
    for(int i=0; i<N-1; i++)
        for (int j=i+1; j<N; j++)
            if (A[i]>A[j])
                swap(A[i],A[j]);
}

int checkBest(double nao[], double ken[], int N) {
    int i = 0;
    int j = 0;
    int nmark = 0;
    while (i<N && j<N) {
        if (nao[i]<=ken[j]) {
            if (j<N-1) {
                double t = ken[N-1];
                for (int k=N-1; k>j; k--)
                    ken[k] = ken[k-1];
                ken[j] = t;
            }
        } else {
            nmark++;
        }
        i++;
        j++;
    }
    
    return nmark;
}

int checkWorst(double nao[], double ken[], int N) {
    int i = 0;
    int j = 0;
    int kmark = 0;
    while (i<N && j<N) {
        while (ken[j]<=nao[i] && j<N-1)
            j++;
        if (ken[j]>nao[i])
            kmark++;
        i++;
        j++;
    }
    
    return N-kmark;
}

int main()
{
    int T;
    cin>>T;
    
    for (int k=0; k<T; k++) {
        int N;
        cin>>N;
        
        double nao[N],ken[N];
        for (int i=0; i<N; i++)
            cin>>nao[i];
        for (int i=0; i<N; i++)
            cin>>ken[i];
        
        sort(nao,N);
        sort(ken,N);
        
        int worst = checkWorst(nao,ken,N);
        int best = checkBest(nao,ken,N);

        cout<<"Case #"<<k+1<<": "<<best<<" "<<worst<<endl;
    }
    
    return 0;
}

