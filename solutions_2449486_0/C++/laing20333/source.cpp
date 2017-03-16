#include<iostream>
#include<string>
#include<sstream>
#include<cstdio>
#include<stack>
#include<vector>
#include<algorithm>
#include<map>
#include<climits>
#include<cmath>
#include<memory.h>
#include<sstream>
#include<queue>
#include<time.h>

using namespace std;



typedef long long ll;
typedef struct pos{
    int r;
    int c;
};

int lawn[101][101];
int nrow, ncol;


map<int, vector<pos> >table;


bool isok(pos cor, int value){
    int rr,cc;
    int flag = 1;
    for(cc=0;cc<ncol;cc++){
        if(lawn[cor.r][cc] > value){
            flag = 0;
            break;
        }
    }
    if(flag){
        /*
        for(cc=0;cc<ncol;cc++){
            lawn[cor.r][cc] = value;
        }
        */
        return true;
    }
    flag = 1;
    for(rr=0;rr<nrow;rr++){
        if(lawn[rr][cor.c] > value){
            flag = 0;
            break;
        }
    }
    if(flag){
        /*
        for(rr=0;rr<nrow;rr++){
            lawn[rr][cor.c] = value;
        }
        */
        return true;
    }
    return false;
}

bool isyes(){
    map<int, vector<pos> > :: reverse_iterator it;
    for(it=table.rbegin(); it!=table.rend(); it++){

        for(int i=0;i<table[it->first].size();i++){
            if(!isok(table[it->first][i], it->first)){
                return false;
            }
        }
    }
    return true;
}

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.csv", "w", stdout);
    freopen("B-small-attempt4.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int ntest;
    while(cin>>ntest){
        for(int tt=1; tt<=ntest; tt++){

            int hmax = 0;
            cin>>nrow>>ncol;
            table.clear();
            for(int r=0;r<nrow;r++){
                for(int c=0;c<ncol;c++){
                    int tmp;
                    cin>>tmp;
                    pos cor;
                    cor.r = r;
                    cor.c = c;
                    table[tmp].push_back(cor);
                    //cout<<table[tmp].back().r<<" "<<table[tmp].back().c<<endl;
                    hmax = max(hmax, tmp);
                    lawn[r][c] = tmp;
                }
            }
            /*
            for(int r=0;r<nrow;r++){
                for(int c=0; c<ncol;c++){
                    lawn[r][c] = hmax;
                }
            }
            */

/*

            map<int, vector<pos> > :: reverse_iterator it;




            for(it=table.rbegin();it!=table.rend();it++){
                    cout<<"###"<<endl;
                for(int i=0;i<table[it->first].size();i++){
                    cout<<table[it->first][i].r<<" "<<table[it->first][i].c<<endl;
                }
            }
                 return 0;
*/





            printf("Case #%d: ", tt);
            if(isyes()){
                cout<<"YES"<<endl;
            }else cout<<"NO"<<endl;

        }

    }
    return 0;
}
