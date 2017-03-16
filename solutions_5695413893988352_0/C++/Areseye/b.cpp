#include"cstdio"
#include"iostream"
#include"map"
#include"cmath"
#include"string"
#include"cstring"
#include"stdlib.h"
#include"vector"
#include"algorithm"
#include"utility"
#include"set"
#include"unordered_set"
#include"unordered_map"
#include"ctime"

using namespace std;
class solution{
    public:
        string fcoder,fjammer;
        string coder,jammer;
        int N_s;
        int min_abs_diff;
        int min_na;
        int min_nb;
        solution(const string&coder_in,const string&jammer_in):coder(coder_in),jammer(jammer_in){
            N_s = coder.size();
            min_abs_diff = 1000;
            min_na = 1000;
            min_nb = 1000;
        }
        void dfs(){
            int N_num = 1;
            for(int i = 0;i<N_s;i++)N_num*=10;

            for(int i = 0;i<N_num;i++){
                for(int j = 0;j<N_num;j++){
                    int na = i;
                    int nb = j;
                    int na_val = 0;
                    int nb_val = 0;
                    int base = 1;
                    for(int k = 0;k<N_s;k++){
                        na_val*=10;
                        nb_val*=10;
                        if(coder[k]!='?'){
                            na_val+=coder[k]-'0';
                        }else{
                            na_val+=na%10;
                        }
                        if(jammer[k]!='?'){
                            nb_val+=jammer[k]-'0';
                        }else{
                            nb_val+=nb%10;
                        }
                        na/=10;
                        nb/=10;
                    }
                    //got val
                    if(abs(na_val-nb_val)<min_abs_diff){
                        min_abs_diff = abs(na_val - nb_val);
                        min_na = na_val;
                        min_nb = nb_val;
                    }else if(abs(na_val-nb_val)==min_abs_diff){
                        if(min_na>na_val){
                            min_abs_diff = abs(na_val - nb_val);
                            min_na = na_val;
                            min_nb = nb_val;
                        }else if(min_na==na_val){
                            if(min_nb>nb_val){
                                min_abs_diff = abs(na_val - nb_val);
                                min_na = na_val;
                                min_nb = nb_val;
                            } 
                        }
                    }else{}

                }
            }
        }
        void solve(){
             dfs();
             // get coder and jammer
             int na = min_na;
             int nb = min_nb;
             for(int i = 0;i<N_s;i++){
                fcoder.push_back('0'+na%10);
                na/=10;
                fjammer.push_back('0'+nb%10);
                nb/=10;
             }
             reverse(fcoder.begin(),fcoder.end());
             reverse(fjammer.begin(),fjammer.end());
        }

};
int main(){
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    int T;
    cin>>T;
    int casenum(0);
    while(++casenum<=T){
        string coder,jammer;
        cin>>coder>>jammer;
        //solution
        solution sol(coder,jammer);
        sol.solve();
        printf("Case #%d: ",casenum);
        cout<<sol.fcoder<<" "<<sol.fjammer<<endl;
    }

return 0;}
