#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

char C[20];
char J[20];
int64_t res = 1000000000000000000LL;
int64_t mejorA = 0;
int64_t mejorB = 0;

void iguales(int i, int64_t A, int64_t B) {
    if (C[i] == '\0') {
        res = 0;
        mejorA=A;
        mejorB=B;
        return;
    }
    char auxC = C[i];
    char auxJ = J[i];
    if (C[i]=='?')
        C[i]=J[i];
    if (J[i]=='?')
        J[i]=C[i];
    if (C[i]==J[i]) {
        if (C[i]=='?'){
            C[i]=J[i]='0';
        }
        A*=10;
        A+=C[i]-'0';
        B*=10;
        B+=J[i]-'0';
        iguales(i+1,A,B);
    }
    C[i]=auxC;
    J[i]=auxJ;
}

void ganaC(int i, int64_t A, int64_t B) {
    if (C[i] == '\0') {
        int64_t actual=A-B;
        if (actual<res) {
            res = actual;
            mejorA=A;
            mejorB=B;
        } else if (actual==res) {
            if (A<mejorA) {
                mejorA=A;
                mejorB=B;
            } else if (A==mejorA) {
                if (B<mejorB) {
                    mejorB=B;
                }
            }
        }
        return;
    }
    char auxC = C[i];
    char auxJ = J[i];
    if ((C[i]=='?') && (J[i]=='?')){
        if (A>B) {
            C[i]='0';
            J[i]='9';
            int64_t newA=(A*10)+(C[i]-'0');
            int64_t newB=(B*10)+(J[i]-'0');
            ganaC(i+1,newA,newB);
        }
        else {
            C[i]='0';
            J[i]='0';
            int64_t newA=(A*10)+(C[i]-'0');
            int64_t newB=(B*10)+(J[i]-'0');
            ganaC(i+1,newA,newB);
            C[i]='1';
            newA=(A*10)+(C[i]-'0');
            ganaC(i+1,newA,newB);
        }
    }
    if ((C[i]=='?') && (J[i]!='?')){
        if (A>B) {
            C[i]='0';
            int64_t newA=(A*10)+(C[i]-'0');
            int64_t newB=(B*10)+(J[i]-'0');
            ganaC(i+1,newA,newB);
        }
        else {
            C[i]=J[i];
            int64_t newA=(A*10)+(C[i]-'0');
            int64_t newB=(B*10)+(J[i]-'0');
            ganaC(i+1,newA,newB);
            if (J[i]!='9')
            {
                C[i]=J[i]+1;
                newA=(A*10)+(C[i]-'0');
                ganaC(i+1,newA,newB);
            }
        }
    }
    if ((C[i]!='?') && (J[i]=='?')){
        if (A>B) {
            J[i]='9';
            int64_t newA=(A*10)+(C[i]-'0');
            int64_t newB=(B*10)+(J[i]-'0');
            ganaC(i+1,newA,newB);
        }
        else {
            J[i]=C[i];
            int64_t newA=(A*10)+(C[i]-'0');
            int64_t newB=(B*10)+(J[i]-'0');
            ganaC(i+1,newA,newB);
            if (C[i]!='0') {
                J[i]=C[i]-1;
                newB=(B*10)+(J[i]-'0');
                ganaC(i+1,newA,newB);
            }
        }
    }
    if ((C[i]!='?') && (J[i]!='?')){
        int64_t newA=(A*10)+(C[i]-'0');
        int64_t newB=(B*10)+(J[i]-'0');
        if (newA>=newB) {
            ganaC(i+1,newA,newB);
        }
    }
    C[i]=auxC;
    J[i]=auxJ;
}

void ganaJ(int i, int64_t A, int64_t B) {
    if (C[i] == '\0') {
        int64_t actual=B-A;
        if (actual<res) {
            res = actual;
            mejorA=A;
            mejorB=B;
        } else if (actual==res) {
            if (A<mejorA) {
                mejorA=A;
                mejorB=B;
            } else if (A==mejorA) {
                if (B<mejorB) {
                    mejorB=B;
                }
            }
        }
        return;
    }
    char auxC = C[i];
    char auxJ = J[i];
    if ((C[i]=='?') && (J[i]=='?')){
        if (A<B) {
            J[i]='0';
            C[i]='9';
            int64_t newA=(A*10)+(C[i]-'0');
            int64_t newB=(B*10)+(J[i]-'0');
            ganaJ(i+1,newA,newB);
        }
        else {
            C[i]='0';
            J[i]='0';
            int64_t newA=(A*10)+(C[i]-'0');
            int64_t newB=(B*10)+(J[i]-'0');
            ganaJ(i+1,newA,newB);
            J[i]='1';
            newB=(B*10)+(J[i]-'0');
            ganaJ(i+1,newA,newB);
        }
    }
    if ((J[i]=='?') && (C[i]!='?')){
        if (A<B) {
            J[i]='0';
            int64_t newA=(A*10)+(C[i]-'0');
            int64_t newB=(B*10)+(J[i]-'0');
            ganaJ(i+1,newA,newB);
        }
        else {
            J[i]=C[i];
            int64_t newA=(A*10)+(C[i]-'0');
            int64_t newB=(B*10)+(J[i]-'0');
            ganaJ(i+1,newA,newB);
            if (C[i]!='9')
            {
                J[i]=C[i]+1;
                newB=(B*10)+(J[i]-'0');
                ganaJ(i+1,newA,newB);
            }
        }
    }
    if ((J[i]!='?') && (C[i]=='?')){
        if (A<B) {
            C[i]='9';
            int64_t newA=(A*10)+(C[i]-'0');
            int64_t newB=(B*10)+(J[i]-'0');
            ganaJ(i+1,newA,newB);
        }
        else {
            C[i]=J[i];
            int64_t newA=(A*10)+(C[i]-'0');
            int64_t newB=(B*10)+(J[i]-'0');
            ganaJ(i+1,newA,newB);
            if (J[i]!='0') {
                C[i]=J[i]-1;
                newA=(A*10)+(C[i]-'0');
                ganaJ(i+1,newA,newB);
            }
        }
    }
    if ((C[i]!='?') && (J[i]!='?')){
        int64_t newA=(A*10)+(C[i]-'0');
        int64_t newB=(B*10)+(J[i]-'0');
        if (newA<=newB) {
            ganaJ(i+1,newA,newB);
        }
    }
    C[i]=auxC;
    J[i]=auxJ;
}

int main()
{
    int T;
    cin >> T;
    cerr << "T:" << T << '\n';
    for (int t=1;t<=T;t++) {
        cin >> C;
        cin >> J;
        res = 1000000000000000000LL;
        mejorA = 0;
        mejorB = 0;
        iguales(0,0,0);
        ganaC(0,0,0);
        ganaJ(0,0,0);
        cerr << t << ": " << C << " " << J << " " << res << " " << mejorA << " " << mejorB << "\n";
        int lon = strlen(C);
        char aux[100];
        sprintf(aux, " %%0%dd", lon);
        cerr << aux << '\n';
        cout << "Case #" << t << ":";
        printf(aux, mejorA);
        printf(aux, mejorB);
        cout << '\n';
    }
    return 0;
}
