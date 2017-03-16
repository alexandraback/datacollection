#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>

#include<cmath>
#include<iostream>
#include<fstream>

#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
using namespace std;

vector<vector <int> > vvi;
vector<int> cur;
vector<int> prv;

int t,r,n,m,k;

int pd[13];

void bt(int x){
    if(x==3){
        vvi.push_back(cur);
        return;
    }
    cur.push_back(2);
    bt(x+1);
    cur.pop_back();

    cur.push_back(3);
    bt(x+1);
    cur.pop_back();

    cur.push_back(4);
    bt(x+1);
    cur.pop_back();

    cur.push_back(5);
    bt(x+1);
    cur.pop_back();

}

void bt2(int x,int tot,int row){
    if(x==3) {
        prv.push_back(tot);
        return;
    }

    bt2(x+1,tot,row);
    bt2(x+1,tot*vvi[row][x],row);


}



int main(){
    freopen("in.txt","rt",stdin);
    freopen("out.txt","wt",stdout);

    int gt,run;
    cin>>gt;
    //long long ret;
    vvi.clear();
    cur.clear();
    bt(0);

    //cout<<vvi.size();
    cin>>r>>n>>m>>k;

    cout<<"Case #1:\n";
    for(int run=1;run<=r;run++){

        for(int i=0;i<k;i++) cin>>pd[i];

        int ans=0;
        for(int i=0;i<vvi.size();i++){
            prv.clear();
            bt2(0,1,i);
            int curmatch=0;
            for(int d=0;d<k;d++){
                for(int j=0;j<prv.size();j++){
                    if(prv[j]==pd[d]) { curmatch++;break;}
                }
            }
            if(curmatch==k){
                ans=i;
            }
        }
        cout<<vvi[ans][0]<<vvi[ans][1]<<vvi[ans][2]<<endl;



    }
    return 0;
}




