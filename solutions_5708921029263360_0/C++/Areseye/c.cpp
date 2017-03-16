#include"iostream"
#include"map"
#include"vector"
#include"string"
#include"cstring"
#include"cstdio"
#include"set"
#include"algorithm"


using namespace std;


int main(){
    freopen("c1.in","r",stdin);
    freopen("c.out","w",stdout);
    int T;
    cin>>T;
    int casenum(0);
    while(casenum++<T){
    
        int J,P,S;
        cin>>J>>P>>S;
        int K;
        cin>>K;
        //solution
        int ans(0);
        map<pair<int,int>,int>JP,JS,PS;
        vector<vector<int> > sol;
         
        for(int i = 1;i<=J;i++){
            for(int j = 1;j<=P;j++){
                for(int k = 1;k<=min(S,K);k++){
                    if(JP.count(make_pair(i,j))>0){
                        if(JP[make_pair(i,j)]>=K){
                            continue;
                        }else{
                            JP[make_pair(i,j)]++;
                        }
                    }
                    else{
                        JP[make_pair(i,j)] = 1;
                    }
                    if(JS.count(make_pair(i,k))>0){
                        if(JS[make_pair(i,k)]>=K){
                            continue;
                        }else{
                            JS[make_pair(i,k)]++;
                        }
                    }
                    else{
                        JS[make_pair(i,k)] = 1;
                    }
                    if(PS.count(make_pair(j,k))>0){
                        if(PS[make_pair(j,k)]>=K){
                            continue;
                        }else{
                            PS[make_pair(j,k)]++;
                        }
                    }
                    else{
                        PS[make_pair(j,k)] = 1;
                    }

                    ans++;
                    vector<int>curvec;
                    curvec.push_back(i);
                    curvec.push_back(j);
                    curvec.push_back(k);
                    sol.push_back(curvec);

                } 
            } 
        }
        printf("Case #%d: %d\n",casenum,ans);
        for(auto it:sol){
            printf("%d %d %d\n",it[0],it[1],it[2]);
        }
    
    }


return 0;}
