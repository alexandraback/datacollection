#include <iostream> 
#include <fstream> 
#include <math.h> 
#include <stdlib.h> 
#include <stdio.h> 
#include <vector> 
#include <string> 
#include <iterator> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <map> 
#include <queue> 
#include <set> 
#include <stack> 
#include <sstream> 
#include <cctype> 
#include <assert.h> 
#include <list> 
#include <ext/hash_set> 
#include <ext/hash_map> 

using namespace __gnu_cxx; 
using namespace std; 

#define MP(a,b) make_pair(a,b) 
#define i64 long long 
#define pb push_back 
#define For(i,a,b) for(typeof(a) i=(a);i<(b);i++) 
#define Rev(i,a,b) for(typeof(a) i=(a);i>=(b);i--) 
#define FOREACH(V,it) for(typeof(V.begin()) it=V.begin();it!=V.end();it++) 
#define CLR(a,x) memset(a,x,sizeof(a)) 
#define ALL(x) x.begin(),x.end() 

/**********************************************************************************/ 

int s[10001];
void p1(FILE *f,int cas){
        int n;
	scanf("%d",&n);
        int S = 0;
	For(i,0,n){
                scanf("%d",&s[i]);
                S+=s[i];
	}
        vector<double> ret;
        double TS = 0;
        For(i,0,n){
                double lo=0,high=1.00,best=1010;
                while ((high-lo)>1e-8){
                        double mid = (high+lo)/2;
                        double cur = s[i]+mid*S;
                        double ret=0;
                        For(j,0,n){
                                if (i==j) continue;
                                ret += max(0.0,cur-s[j]);
                        }
                        //printf("%.4lf %.4lf\n",mid,ret);
                        if (ret>=(1-mid)*S){
                                high = mid;
                                best = mid;
                        } else{
                                lo = mid;
                        }
                }
                if (best>1) best=1;
                best = best*100;
                TS += best;
                printf("%.4lf ",best);
                ret.pb(best);
        }
        printf("TOTAL %.4lf",TS);
        printf("\n");
	fprintf(f,"Case #%d:",cas);
        For(i,0,ret.size())
                fprintf(f," %.6lf",ret[i]);
        fprintf(f,"\n");
}

int main(){
	int test,cas=1;
	scanf("%d",&test);
        FILE *f = fopen("output.txt","w");
	For(cas,1,test+1){
		p1(f,cas);				
	}
        fclose(f);
	return 0;
}
