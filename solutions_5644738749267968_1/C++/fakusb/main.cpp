#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <iomanip>

#define epsilon 0.000000001

using namespace std;

int T;
vector<int> resWar;
vector<int> resDWar;

int main(){
    cin>>T;
    for(int t=1;t<=T;t++){
        int N;
        cin>>N;
        set<double> naomi1,ken1;
        for(int i=0;i<N;i++){
            double temp;
            cin>>temp;
            naomi1.insert(temp);
        }
        for(int i=0;i<N;i++){
            double temp;
            cin>>temp;
            ken1.insert(temp);
        }
        set<double> naomi=naomi1;
        set<double> ken=ken1;
        //normal war
        {
            int scoreNaomi=0;
            //naomi plays one by one, small to large, ken uses the smallest weight that beats naomi
            //or his smallest at all if he can't beat her
            for(auto n : naomi){
                auto k = ken.upper_bound(n);
                if(k==ken.end()){
                    k=ken.begin();
                }
                if(n>*k)
                    scoreNaomi++;
                ken.erase(k);
            }
            resWar.push_back(scoreNaomi);
        }
        naomi=naomi1;
        ken=ken1;
        //delWar:
        {
            int scoreNaomi=0;
            //naomi plays her smallest weigths telling ken it's just
            //infinitesimal smaller then kens one if her largest one could not beat kens largest one
            //otherwise she chooses her smallest one beating ken (she could also choose her largest one at all, but wayne...)
            //note: this is somehow the same as normal war, but with switched roles and inverted compare function.
            //for the sake of debugging the code is still is writen out 2 times!
            for(auto k = ken.rbegin();k!=ken.rend();k++){
                auto n = naomi.upper_bound(*k);
                if(n==naomi.end()){
                    n=naomi.begin();
                }
                if(*n>*k){
                    scoreNaomi++;
                }
                naomi.erase(n);
            }
            resDWar.push_back(scoreNaomi);

        }

    }
    for(int t=1;t<=T;t++){
        cout<<"Case #"<<t<<": "<<resDWar[t-1]<<" "<<resWar[t-1]<<endl;
    }
    return 0;
}