#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int T;
int N;
vector<double> Naomi, Ken;

int War(int N, vector<double> _Naomi, vector<double> _Ken){
    int res = 0;

    vector<double> Naomi = _Naomi;
    vector<double> Ken = _Ken;

    sort(Naomi.begin(), Naomi.end());
    sort(Ken.begin(), Ken.end());

    for(int i = 0; i<N; i++){
        double naomi = Naomi[i];
        vector<double>::iterator up = upper_bound(Ken.begin(), Ken.end(), naomi);
        if (up == Ken.end()){
            up = Ken.begin();
            res++;
            //cout <<" up here "<<*up<<endl;
        };
        //cout <<naomi<<" "<<*up<<endl;
        Ken.erase(up);
    }
    return res;
}

int DeceitfulWar(int N, vector<double> _Naomi, vector<double> _Ken){
    int res = 0;
    vector<double> Naomi = _Naomi;
    vector<double> Ken = _Ken;

    sort(Naomi.begin(), Naomi.end());
    sort(Ken.begin(), Ken.end());

    for(int i = 0; i<N; i++){
        double ken = Ken[i]; // Ken minimum
        //cout <<ken<<" ";
        vector<double>::iterator up = upper_bound(Naomi.begin(), Naomi.end(), ken);
        if (up == Naomi.end()){
            up = Naomi.begin();
            //cout <<*up<<endl;
            //res++;
            Naomi.erase(up);
        }
        else{
           // cout<<*up<<endl;
            Naomi.erase(up);
            res++;
        };
    }

    return res;
}


void solve(int i){
   int w = War(N, Naomi, Ken);
   int dw = DeceitfulWar(N, Naomi, Ken);
   cout <<"Case #"<< (i+1) <<": "<<dw<<" "<<w<<endl;
}

void readInput(){
    cin >>T;
    for(int i = 0; i<T; i++){
        cin >>N;
        Naomi.clear();
        for(int j = 0; j<N; j++){
            double x;
            cin >>x;
            Naomi.push_back(x);
        };
        Ken.clear();
        for(int j = 0; j<N; j++){
            double x;
            cin >>x;
            Ken.push_back(x);
        };
        //solve:
        solve(i);
    };
};



int main()
{
    readInput();
    return 0;
}
