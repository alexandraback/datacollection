#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>
using namespace std;

vector<int> T;
string alphabet;
int s;
int ile(string napis,string wzorzec){
   int res=0;
   for(int i=0;i<napis.size();i++){
        bool flaga=true;
        for(int j=0;j<wzorzec.size();j++){
            if(i+j>napis.size() || wzorzec[j]!=napis[i+j])
                flaga=false;
        }
        if(flaga)
            res++;
   }
   return res;
}
void gen(string & target,int licz,string word){
    if(licz==s)
        T.push_back(ile(word,target));
    else{
        for(auto &i:alphabet){
            gen(target,licz+1,word+i);
        }
    }
}
main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    int licznik=1;
    while(t--){
        T.clear();
        int k,l;
        cin >> k >> l >> s;
        cin >> alphabet;
        string target;
        cin >> target;
        gen(target,0,"");
        double res=0.0;
        double maax=-1;
        for(auto &i:T){
            res+=i;
            maax=max(maax,(double)i);
        }
        res/=(double)T.size();
        cout <<fixed << setprecision(10)<< "Case #" << licznik++ << ": " <<maax-res << endl;
    }
    return 0;
}
