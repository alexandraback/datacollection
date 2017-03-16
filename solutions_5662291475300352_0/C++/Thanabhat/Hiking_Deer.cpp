/*
AUTHOR: THANABHAT KOOMSUBHA
LANG: C++
*/

#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<functional>
#include<vector>
#include<list>
#include<set>
#include<queue>
#include<map>
#include<cctype>
#include<cstring>
#include<string>
#include<sstream>
#include<iostream>
#include<ctime>

#define eps 1E-7

using namespace std;

int solve(int cc){
    int N;
    int D[2],H[2],M[2],_N=0;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        int _D,_H,_M;
        scanf("%d %d %d",&_D,&_H,&_M);
        D[_N]=_D;H[_N]=_H;M[_N]=_M;_N++;
        if(_H==2){
            D[_N]=_D;H[_N]=_H;M[_N]=_M+1;_N++;
        }
    }
    if(N==1){
        printf("Case #%d: 0\n",cc);
        return 1;
    }
    int iF,iB;
    if(D[0]>D[1]){iF=0;iB=1;}
    else {iF=1;iB=0;}

    double speed[2];
    speed[iF]=1.0*(360-D[iF])/M[iF];
    speed[iB]=1.0*(360-D[iB])/M[iB];

    if(speed[iF]-eps>speed[iB]){
        double _d = 360-(D[iF]-D[iB]);
        if(_d<eps){
            _d=360.0;
        }
        double _t = _d/(speed[iF]-speed[iB]);
        if(_t+eps>1.0*M[iB]){
            printf("Case #%d: 0\n",cc);
        }else{
            printf("Case #%d: 1\n",cc);
        }
    }else if(speed[iB]-eps>speed[iF]){
        double _d = (D[iF]-D[iB]);
        if(_d<eps){
            _d=360.0;
        }
        double _t = _d/(speed[iB]-speed[iF]);
        if(_t+eps>1.0*M[iF]){
            printf("Case #%d: 0\n",cc);
        }else{
            printf("Case #%d: 1\n",cc);
        }
    }else{
        printf("Case #%d: 0\n",cc);
    }

    return 1;
}

int main(){

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        solve(i);
    }

	return 0;
}
