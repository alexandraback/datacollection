#include<cstdio>
#include<string>
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
#define NUM_PALINS 41551
string palinsorig[NUM_PALINS];
string palinssq[NUM_PALINS];
bool cmp(string a,string b){
    if(a.length()==b.length()) return a<b;
    else return a.length()<b.length();
}
int main(){
    freopen("QC.in","r",stdin);
    freopen("QC.out","w",stdout);
    ifstream fin("palins.txt");
    for(int i=0;i<NUM_PALINS;i++){
        fin>>palinsorig[i]>>palinssq[i];
    }
    int numcases;
    scanf("%d",&numcases);
    for(int ccase=0;ccase<numcases;ccase++){
        string start,end;
        cin>>start>>end;
        cout<<"Case #"<<ccase+1<<": "<<upper_bound(palinssq,palinssq+NUM_PALINS,end,cmp)-lower_bound(palinssq,palinssq+NUM_PALINS,start,cmp)<<endl;
    }
    return 0;
}
