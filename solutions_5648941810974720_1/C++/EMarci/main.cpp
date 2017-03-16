#include <cstdio>
#include <algorithm>

using namespace std;

FILE *in, *out;
int Q;
char s[2001];
int db[26];
int sol[10];

char dig[10][6] {
    "ZERO",
    "ONE",
    "TWO",
    "THREE",
    "FOUR",
    "FIVE",
    "SIX",
    "SEVEN",
    "EIGHT",
    "NINE"
};

void minusz(int d) {
    for(int i=0; dig[d][i]!='\0'; i++) db[dig[d][i]-'A']-=sol[d];
}

int main()
{
    in = fopen("A-large.in","r");
    out = fopen("A-large.out","w");

    fscanf(in,"%d",&Q);
    for(int q=1; q<=Q; q++) {
        fscanf(in,"%s",s);
        fill(db,db+26,0);
        fill(sol,sol+10,0);
        for(int i=0; s[i]!='\0'; i++) db[s[i]-'A']++;

        //ZERO
        sol[0] = db['Z'-'A'];
        minusz(0);
        //TWO
        sol[2] = db['W'-'A'];
        minusz(2);
        //FOUR
        sol[4] = db['U'-'A'];
        minusz(4);
        //SIX
        sol[6] = db['X'-'A'];
        minusz(6);
        //EIGHT
        sol[8] = db['G'-'A'];
        minusz(8);


        //ONE
        sol[1] = db['O'-'A'];
        minusz(1);
        //THREE
        sol[3] = db['R'-'A'];
        minusz(3);
        //SEVEN
        sol[7] = db['S'-'A'];
        minusz(7);


        //FIVE
        sol[5] = db['V'-'A'];
        minusz(5);
        //NINE
        sol[9] = db['N'-'A']/2;
        minusz(9);


        fprintf(out,"Case #%d: ",q);
        for(int i=0; i<10; i++) {
            while(sol[i]--) fprintf(out,"%d",i);
        }
        fprintf(out,"\n");
    }

    return 0;
}
