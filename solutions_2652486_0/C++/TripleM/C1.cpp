#include <iostream>
#include <map>
using namespace std;
long long prods[7];
int R,N,M,K;    
int digs[12];
int ct = 0;
long long reps[20000];
map<long long,int> ways[20000];
long long numways[20000];
long long facts[13];
void gen(int upto, int themin, long long rep) {
    if (upto<N) {
        for (int i=themin; i<=M; i++) {
            digs[upto] = i;
            gen(upto+1,i,rep*10+i);
        }
    } else {
        reps[ct] = rep;
        // rep shows a possible substr
        // what is the probability of each subset
        for (int i=0; i<(1<<N); i++) {
            long long prod = 1;
            for (int j=0; j<N; j++) if (i&(1<<j)) {
                prod *= digs[j];
            }
            ways[ct][prod]++;
//            printf("%I64d\n",prod);
        }
        /*
        numways[ct] = facts[N];
        int run = 0;
        for (int i=0; i<N; i++) {
            run++;
            if (i==N-1 || digs[i]!=digs[i+1]) {
                numways[ct] /= facts[run];
                run = 0;
            }
        }
        */
        // what is probability of getting this string?
        ct++;
//        system("PAUSE");
    }
}
int main() {
    facts[0] = 1; for (int i=1; i<=12; i++) facts[i] = facts[i-1]*i;
    int T; scanf("%d",&T); for (int t=1; t<=T; t++) {
        scanf("%d %d %d %d",&R,&N,&M,&K);
        gen(0,2,0);
        printf("Case #%d:\n",t);
        for (int i=0; i<R; i++) {
            for (int i=0; i<K; i++) scanf("%I64d",&prods[i]);
            int best = -1;
            double bestprob;
            
            for (int j=0; j<ct; j++) {
                double prob = 1;
                // lets suppose the string was 'rep'
                // what's the probability of getting each of those products
                for (int k=0; k<K; k++) {
                    prob *= 1.*ways[j][prods[k]] / (1<<N);
                }
                
                //double here = prob * numways[j];
                double here = prob;
                
                if (best==-1 || here>bestprob) {
                    bestprob = here;
                    best = j;
                }
            }
            printf("%I64d\n",reps[best]);
        }
    
    }
   // system("PAUSE");
}
