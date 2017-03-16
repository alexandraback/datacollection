#include<fstream>
#include<set>
using namespace std;

ifstream fin("lottery.in");
ofstream fout("lottery.out");

int A, B, K;
long long ans[2][2][32];
bool sen[2][2][32];

bool skipz[32];

long long cnt(long long A, long long B, bool ca, bool cb, int exp, int stp){
    if(exp < stp){
        long long op = 1LL<<stp;
        if(ca) A = op;
        if(cb) B = op;

        return min(A, op)*min(B, op);
    }

    if(sen[ca][cb][exp])
        return ans[ca][cb][exp];
    sen[ca][cb][exp] = true;
    
    ans[ca][cb][exp] = 0;
    long long op = 1LL<<exp;

    //both are on
    if(!skipz[exp] && ((ca || (op < A)) && (cb || (op < B)))){
        //fout << "BOTH ARE ON AT " << exp << "!!!" << endl;
        
        //turn on neither
        ans[ca][cb][exp] += cnt(A, B, true, true, exp-1, stp);
        //turn on A
        ans[ca][cb][exp] += cnt(A-op, B, ca, true, exp-1, stp);
        //turn on B
        ans[ca][cb][exp] += cnt(A, B-op, true, cb, exp-1, stp);
    }
    //one is on
    else if(!skipz[exp] &&  (ca || (op < A))){
        //dont turn it on
        ans[ca][cb][exp] += cnt(A, B, true, cb, exp-1, stp);
        //turn it on
        ans[ca][cb][exp] += cnt(A-op, B, ca, cb, exp-1, stp);
    }
    else if(!skipz[exp] && (cb || (op < B))){
        //dont turn it on
        ans[ca][cb][exp] += cnt(A, B, ca, true, exp-1, stp);
        //turn it on
        ans[ca][cb][exp] += cnt(A, B-op, ca, cb, exp-1, stp);
    }
    //neither is on
    else{
      //  fout << "NEITHER ARE ON AT " << exp << endl;
        ans[ca][cb][exp] = cnt(A, B, ca, cb, exp-1, stp);
    }
    
    //fout << ca << " " << cb << " " << exp << " " << ans[ca][cb][exp] << endl;
    
    return ans[ca][cb][exp];
}

int main(){
    int T;
    fin >> T;
    for(int t=0; t<T; t++){
        fin >> A >> B >> K;
//        A--;
 //       B--;
        long long anz = 0;
        memset(skipz, 0, sizeof(skipz));

        while(A>0 && B>0 && K>0){
            int log_pow = 0;
            int big_pow = 1;
            while(2*big_pow <= K){
                big_pow *= 2;
                log_pow++;
            }
            
            memset(sen, 0, sizeof(sen));
            anz += cnt(A, B, false, false, 29, log_pow);            
            
            skipz[log_pow] = true;
            
            K -= big_pow;
            A -= big_pow;
            B -= big_pow;
        }

        fout << "Case #" << t+1 << ": ";
        fout << anz << endl;
    }
}
