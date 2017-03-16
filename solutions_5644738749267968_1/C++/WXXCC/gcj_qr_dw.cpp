#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<fstream>
#include<algorithm>
#include<map>
#include<stdlib.h>
#include <iomanip>
#include<vector>
#include<stack>
#include<queue>
#include<set>
using namespace std;
const double eps = 1e-12;
const double dinf = 99999999999.99;

int main()
{
//    freopen("D1.in","r",stdin);
//    freopen("D1.txt","w",stdout);
    int T;
    cin>>T;
    int cas = 1;
    while(T--){
        int n;
        double inpt;
        cin>>n;
        vector<double> nmc;
        vector<double> knc;
        vector<bool> nvis;
        vector<bool> mvis;
        for(int i = 0; i < n; i ++){
            cin>>inpt;
            nmc.push_back(inpt);
            nvis.push_back(false);
        }
        for(int i = 0; i < n; i ++){
            cin>>inpt;
            knc.push_back(inpt);
            mvis.push_back(false);
        }
        sort(nmc.begin(),nmc.end());
        sort(knc.begin(),knc.end());

        int dwp = 0, wp = 0;
        int nid = 0;
        bool isend = false;

        for(int i = nmc.size() - 1; i >= 0; i --){
            if(nvis[i] == true)
                break;
            for(int j = knc.size() - 1; j >= 0; j --){
                if(mvis[j] == false){
                    if(nmc[i] > knc[j]){
                        nvis[i] = true;
                        dwp ++;
                    }else{
                        nvis[nid] = true;
                        nid ++;
                        i ++;
                    }
                    mvis[j] = true;
                    break;
                }
            }
        }

        for(int i = 0; i < n; i ++)
            mvis[i] = false;
        for(int i = 0; i < nmc.size(); i ++){
            bool isfound = false;
            for(int j = 0; j < knc.size(); j ++){
                if(mvis[j] == false){
                    if(knc[j] > nmc[i]){
                        isfound = true;
                        mvis[j] = true;
                        break;
                    }
                }
            }
            if(!isfound){
                wp = nmc.size() - i;
                break;
            }
        }
        cout<<"Case #"<<cas<<": ";
        cout<<dwp<<" "<<wp<<endl;
        cas ++;
    }
    return 0;
}
