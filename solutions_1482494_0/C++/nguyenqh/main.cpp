/* 
 * File:   main.cpp
 * Author: NQH
 * Google Code Jam 2012
 * Round 1A
 * Prob B.
 * Created on April 28, 2012, 8:55 AM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

#define MAXN 1001

using namespace std;

/*
 * 
 */
typedef struct {
    int lvl;    // level
    int r;      // rating
    int req;    // required stars to complete
} Level;

int compare (const void *va, const void *vb) {
    Level *a, *b;
    a = (Level*) va;
    b = (Level*) vb;
    return (a->req - b->req);
}

int main(int argc, char** argv) {
    ifstream fin ("B-small-attempt1.in");
//    ifstream fin ("b.in");
    ofstream fout ("b.out");
    
    int test,ntest;
    fin >> ntest;
    for (test=1; test<=ntest; test++) {
        Level a[MAXN], b[MAXN];
        int n;
        int i,j,k;
        int y;
        
        
        fin >> n;
        for (i=0; i<n; i++) {
            fin >> a[i].req >> b[i].req;
            a[i].lvl = b[i].lvl = i;
            a[i].r = 1;
            b[i].r = 2;
        }
        
        qsort(a, n, sizeof(Level), compare);
        qsort(b, n, sizeof(Level), compare);
        
        int completed1[MAXN] = {};
        int completed2[MAXN] = {};
        int ncompleted = 0;
        int nstars = 0;
        int u,v,lv;
        int pa, pb, na, nb;
        na = 0; nb = 0;
        pa = 0; pb = 0;
        int fail = 0;
        while (pb<n) {
            // try 2-star lvl first
            if (b[pb].req<=nstars) {
                lv = b[pb].lvl;
                if (completed1[lv]) {
                    completed2[lv] = 1;
                    nstars += 1;
                }
                if (!completed1[lv]) {
                    completed1[lv] = 1;
                    completed2[lv] = 1;
                    nstars+=2;
                }
                pb++;
                continue;
            }
            else { // try 1-star lvl
                if (pa>=n) { // all 1-star completed
                    fail = 1;
                    break;
                }
                lv = a[pa].lvl;
                if (completed1[lv]) {
                    pa++;
                    continue;
                }
                else if (a[pa].req<=nstars) {                    
                    completed1[lv] = 1;
                    nstars +=1 ;
                    na++;
                    pa++;
                }
                else {
                    fail = 1;
                    break;
                }
            }
        }
        if (fail) 
            fout << "Case #" << test << ": " << "Too Bad\n";
        else 
            fout << "Case #" << test << ": " << pb+na << '\n';
        
    }
    return 0;
}

