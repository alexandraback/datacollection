#include<iostream>
#include<algorithm>
#include<cstring>
#include<set>
#include<cstdio>
#include<iomanip>
using namespace std;
const int MX=2000;
double hussain[MX] , alex[MX];
set<double>S1,S2;
set<double>::iterator it;
int n , T , Tn=0 , fair , unfair;
int main(){
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    cin>>T;
    while(T--){
        Tn++;
        S1.clear();
        S2.clear();
        cin>>n;
        for(int j=1;j<=n;j++){
            cin>>hussain[j];
            S1.insert(hussain[j]);
        }
        for(int j=1;j<=n;j++){
            cin>>alex[j];
            S2.insert(alex[j]);
        }
        fair=0; unfair=0;
        while(!S1.empty()){
            it=S1.begin();
            if(S2.lower_bound(*it)==S2.end()){
                fair=S1.size();
                break;
            }
            S2.erase(S2.lower_bound(*it));
            S1.erase(it);
        }
        sort(hussain+1,hussain+1+n);
        sort(alex+1,alex+1+n);
        /*for(int j=1;j<=n;j++) cout<<hussain[j]<<' ';
        cout<<endl;
        for(int j=1;j<=n;j++) cout<<alex[j]<<' ';
        cout<<endl;*/
        S1.clear();
        S2.clear();
        for(int j=1;j<=n;j++){
            S2.insert(alex[j]);
        }
        for(int j=1;j<=n;j++){
            if(hussain[j]>*S2.begin()){
                S2.erase(S2.begin());
                unfair++;
            }
            else S2.erase(--S2.end());
        }
        printf("Case #%d: %d %d\n",Tn,unfair,fair);
    }
}
