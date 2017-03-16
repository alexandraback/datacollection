#include <iostream>
#include <map>
#include <set>
using namespace std;
long long prods[12];
int R,N,M,K;    
int digs[12];
int ct = 0;
long long reps[20000];
long long ways[20000][6000];
long long facts[13];
set<long long> possprods;
map<long long,int> prodrep;
long long realprods[10000];
int prodct = 0;
void genprods(int len, int upto, int themin, long long prod) {
    if (upto<len) {
        for (int i=themin; i<=M; i++) {
            genprods(len,upto+1,i,prod*i);
        }
    } else {
        possprods.insert(prod);
    }
}
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
            ways[ct][prodrep[prod]]++;
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
        for (int i=0; i<=N; i++) {
            genprods(i,0,2,1);
        }        

        for (set<long long>::iterator it = possprods.begin(); it!=possprods.end(); it++) {
            prodrep[*it] = prodct++;
        }
        fprintf(stderr,"%d\n",prodct);        
        gen(0,2,0);
        printf("Case #%d:\n",t);
        for (int i=0; i<R; i++) {
            if (i%100==0) fprintf(stderr,"i = %d\n",i);
            for (int j=0; j<K; j++) {
                scanf("%I64d",&prods[j]);
                prods[j] = prodrep[prods[j]];
            }
            int best = -1;
            double bestprob;
            
            double denom = 1;
            for (int j=0; j<K; j++) denom *= 1./(1<<N);
            
            for (int j=0; j<ct; j++) {
                double prob = denom;
                // lets suppose the string was 'rep'
                // what's the probability of getting each of those products
                for (int k=0; k<K; k++) {
                    prob *= ways[j][prods[k]];
                    if (prob==0) break;
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
