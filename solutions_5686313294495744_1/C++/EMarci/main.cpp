#include <cstdio>
//#include <iostream>
#include <vector>

using namespace std;

FILE *in,*out;
vector<int> h[1001];

int Q;
int n;

char c[2][1001][21];
int N,M;
char s[21];

bool cstrequal(char *s, char *t) {
    if((*s)!=(*t)) return 0;
    if((*s)=='\0') return 1;
    s++; t++;
    return cstrequal(s,t);
}

int pa[2][1001];
bool eler[1001];

bool bpm(int p) {
    eler[p] = 1;
    for(int q:h[p]) {
        if(pa[1][q] < 0) {
            pa[0][p] = q;
            pa[1][q] = p;
            return 1;
        }
        if(eler[pa[1][q]]) continue;
        if(bpm(pa[1][q])) {
            pa[0][p] = q;
            pa[1][q] = p;
            return 1;
        }
    }
    return 0;
}

int main()
{
    in = fopen("C-large.in","r");
    out = fopen("C-large.out","w");

    fscanf(in,"%d",&Q);
    for(int q=1; q<=Q; q++) {
        fscanf(in,"%d",&n);
        N=M=0;
        for(int i=0; i<n; i++) {
            fscanf(in,"%s",s);
            int x(0);
            while((x<N) && (!cstrequal(&s[0],&c[0][x][0]))) x++;
            if(x==N) {
                h[x].clear();
                int j;
                for(j=0; s[j]!='\0'; j++) c[0][x][j] = s[j];
                c[0][x][j] = '\0';
                N++;
            }

            fscanf(in,"%s",s);
            int y(0);
            while((y<M) && (!cstrequal(&s[0],&c[1][y][0]))) y++;
            if(y==M) {
                int j;
                for(j=0; s[j]!='\0'; j++) c[1][y][j] = s[j];
                c[1][y][j] = '\0';
                M++;
            }

            //cerr << x << ' ' << y << endl;
            h[x].push_back(y);
        }

        int sol(0);
        for(int i=0; i<N; i++) pa[0][i] = -1;
        for(int i=0; i<M; i++) pa[1][i] = -1;
        for(int p=0; p<N; p++) {
            if(pa[0][p] >= 0) continue;
            for(int i=0; i<N; i++) eler[i] = 0;
            sol += bpm(p);
        }

        sol = sol + (N-sol) + (M-sol); //Min number of edges to cover all vertices
        //solution to the original problem: the rest of the edges
        sol = n-sol;

        fprintf(out,"Case #%d: %d\n",q,sol);
    }

    return 0;
}
