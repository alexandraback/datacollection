#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;

int n, s1, s2;
set<double> no, ke, ke2;

double most(set<double> ss){
    set<double>::iterator it = ss.end();
    return *(--it);
}
int main(){

    int t, ca=1;
    double a;
    scanf("%d", &t);

    for(; t>0; t--){
        printf("Case #%d: ", ca++);
        s1 = s2 = 0;
        scanf("%d", &n);
        for(int i=0; i<n; i++){
            scanf("%lf", &a);
            no.insert(a);
        }
        for(int i=0; i<n; i++){
            scanf("%lf", &a);
            ke.insert(a);
        }ke2 = ke;
        set<double>::iterator it, it2;
        for(it = no.begin(); it!=no.end(); it++){
            if(most(ke)<*it){
                s2 += ke.size();
                ke.clear();
                break;
            }
            for(it2 = ke.begin(); it2 != ke.end(); it2++){
                if(*it2>*it){
                    ke.erase(it2);
                    break;
                }
            }
        }
        if(most(no)>*(ke2.begin())){
            while(!no.empty()){
                double no1 = *(no.begin()), ke1 = *(ke2.begin());
                no.erase(no1);
                if(no1>ke1){
                    s1 ++;
                    ke2.erase(ke1);
                }else
                    ke2.erase(most(ke2));
            }
        }
        no.clear();
        printf("%d %d\n", s1, s2);
    }

    return 0;
}


