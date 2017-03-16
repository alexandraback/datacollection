#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;
char KB[10],TG[10],my[10];
double prob[30];
int K,L,S;
struct XD{
    char ch;
    double p;
    XD(char _ch,double _p):ch(_ch),p(_p){
    }
    XD(){
    }
};
vector<XD> alpha;
int MAX;
double psum;
void calc(double P){
    int cnt=0;
    for(int i=0;i<S;i++){
        if(strncmp(my+i,TG,L) == 0){
            cnt++;
        }
    }
    MAX = max(cnt,MAX);
    //cout <<"P: "<< P << " cnt: " << cnt << "\n";
    psum += P*cnt;
}
void dfs(int pos,double nowP){
   // cout << "nowP : " << nowP<<"\n";
    if(pos == S){
        my[pos] = '\0';
        //cout << my<<"\n";
        calc(nowP);

        return ;
    }
    for(int i=0;i<alpha.size();i++){
        my[pos] = alpha[i].ch;
        dfs(pos+1,nowP*alpha[i].p);
    }
}
int main(){
    int T;
    cin >> T;
    for(int ca=1;ca<=T;ca++){
        cin >> K >> L >> S;
        cin >> KB >> TG;
        for(int i=0;i<26;i++)prob[i] = 0;
        for(int i=0;i<K;i++){
            prob[KB[i]-'A'] += 1.0 / K;
        }
        alpha.clear();
        for(int i=0;i<26;i++){
            if(prob[i] > 0){
                alpha.push_back(XD(i+'A', prob[i]));
                //cout << "push "  << (i+'A') << " " << prob[i]<< "\n";
            }
        }
        psum = MAX = 0;
        dfs(0,1.0);
       // cout << "MAX "<< MAX <<" psum " << psum <<"\n";
        cout << std::setprecision(9) << "Case #" << ca << ": " << MAX - psum<< "\n";
    }
    return 0;
}
