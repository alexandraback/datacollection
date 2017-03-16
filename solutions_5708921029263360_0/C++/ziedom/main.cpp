#include <bits/stdc++.h>

using namespace std;
int mat[50][50];
map<pair<int,int>,int> JP , JS , PS ;
int J , P , S , K ;
vector<pair<pair<int,int>,int> >ans;
int main()
{
    ifstream cin("C-small-attempt2.in");
    ofstream cout("out.txt");
    int t ;
    cin >>t ;
    int cp = 1 ;
    while(t--){
            ans.clear();
            JP.clear();
            JS.clear();
            PS.clear();
            cout << "Case #" << cp++ << ": " ;
        cin >> J >> P >> S >> K ;
      //  cout << K ;
        for(int i = 1 ; i<=J ; i++){
            for(int j = 1 ; j<= P ; j++){
                for(int k = 1 ; k<= S ; k++){
                    //cout <<i << ' ' << j <<' ' << k << "   " <<  JP[{i,j}]<< ' '<< JS[{i,k}] << ' ' << PS[{j,k}]<< endl;
                    if(JP[{i,j}] >=K) continue ;
                    else if(JS[{i,k}] >=K || PS[{j,k}]>=K) continue;
                    else {
                        JP[{i,j}]++;
                        JS[{i,k}]++;
                        PS[{j,k}]++;
                        ans.push_back({{i,j},k});
                    }
                }
            }
        }
        cout << ans.size()<<endl;
        for(int i= 0 ; i< ans.size() ;i ++){
            cout <<  ans[i].first.first << ' ' << ans[i].first.second << ' ' << ans[i].second << endl;
        }

    }
    return 0;
}
