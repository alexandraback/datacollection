#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>

#define EPS 1e-12

using namespace std;

//typedef pair<long double,long double> ii;

typedef struct {
    long double first, second;
    int third;
} ii;

int T, C=1, n;
long double vel, pos;
char aux[4], s[1024];
ii p[2][64];
int P[2];

inline int cmpf(long double a, long double b) {
    if (fabs(a-b) < EPS) return 0;
    return a < b ? -1 : 1;
}

bool cmpii(ii a, ii b) {
    if (cmpf(a.first,b.first)!=0) return a.first < b.first;
    if (cmpf(a.second,b.second)!=0) return a.second < b.second;
    return a.third < b.third;
}

int main() {

    for(scanf("%d",&T);T--;) {
        printf("Case #%d: ",C++);
        scanf("%d",&n);
        P[0] = P[1] = 0;
        for (int i=0;i<n;i++) {
            scanf("%s",aux);
            scanf("%Lf %Lf",&vel,&pos);
            if (aux[0] == 'L')
                p[0][P[0]++] = (ii){pos,vel,i};
            else
                p[1][P[1]++] = (ii){pos,vel,i};
        }
        sort(p[0],p[0]+P[0],cmpii);
        sort(p[1],p[1]+P[1],cmpii);
        long double tempo = 0.0;
        bool deupau = false;
        for (int tt=0;tt<5000000;tt++) {

            long double dabostaem = 1e100;
            //pra cada pista
            for (int k=0;k<2;k++) {
                for (int i=0;i<P[k]-1;i++) {
                    long double x1 = p[k][i].first+5.0, x2 = p[k][i+1].first;
                    long double v1 = p[k][i].second, v2 = p[k][i+1].second;
                    if (cmpf(v2,v1)>=0) continue; //nunca colide
                    long double x = (x1*v2 - v1*x2)/(v2-v1);
                    long double t = (x-x1)/v1;
                    if (cmpf(t,0.0)<0) {
                        printf("t deu %Lf, x deu %Lf x1=%Lf x2=%Lf hm\n",t, x, x1, x2);
                        continue; // coline no passado, lol
                    }
                    dabostaem = min(dabostaem,t);
                }
            }
            if (dabostaem > 1e90) {
                break; //nunca da pau
            }

            //simula os proximos dabostaem segundos
            tempo += dabostaem;

            for (int k=0;k<2;k++)
                for (int i=0;i<P[k];i++)
                    p[k][i].first += p[k][i].second*dabostaem;

            //axa qm vai dar bosta
            set<int> S;
            S.clear();
            axapau:;
            for (int k=0;k<2;k++)
                for (int i=0;i<P[k]-1;i++)
                    if (cmpf(p[k][i].first+5.0,p[k][i+1].first)==0 and cmpf(p[k][i].second,p[k][i+1].second)>0) {
                        // da pra trocar?
                        for (int j=0;j<P[k^1];j++)
                            if (cmpf(p[k][i].first-5.0,p[k^1][j].first)<0 and cmpf(p[k^1][j].first,p[k][i].first+5.0)<0) {
                                deupau = true;
                                goto fodeu;
                            }
                        // da =)
                        int id = p[k][i].third;
                        if (S.find(id) != S.end()) {
                            // esse ja foi
                            deupau = true;
                            goto fodeu;
                        }
                        S.insert(id);
                        p[k^1][P[k^1]++] = p[k][i];
                        p[k][i] = p[k][P[k]-1]; P[k]--;
                        sort(p[k],p[k]+P[k],cmpii);
                        sort(p[k^1],p[k^1]+P[k^1],cmpii);
                        goto axapau;
                    }
        }
        fodeu:;
        if (!deupau) printf("Possible\n");
        else {
            sprintf(s,"%.12Lf",tempo);
            int x = strlen(s);
            while (x > 0 and s[x-1]=='0') x--;
            if (s[x-1] == '.') x--;
            s[x]='\0';
            printf("%s\n",s);
        }
    }

    return 0;
}
