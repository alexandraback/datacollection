#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
#include<cstring>
#include<algorithm>
#include<string>

using namespace std;

char input[1000];
vector<string> cString;
vector<string> jString;
set<string> cAllSet,jAllSet;
vector<string> cTry,jTry;
string oneString;
int minCnt;
int N;

void solve(int pos, int cnt){
//    cout<<pos<<"  "<<cnt<<endl;
    if(pos==N){
        set<string> cSet,jSet;
        for(int i=0;i<cTry.size();i++){
            cSet.insert(cTry[i]);
        }
        for(int i=0;i<jTry.size();i++){
            jSet.insert(jTry[i]);
        }
        if(cAllSet.size()==cSet.size() && jAllSet.size()==jSet.size()){
            if(minCnt>cnt)minCnt=cnt;
        }
//        cout<<cAllSet.size()<<" "<<cSet.size()<<" "<<jAllSet.size()<<" "<<jSet.size()<<endl;
//        cout<<"minCnt : "<<minCnt<<endl;
    }
    else{
        solve(pos+1,cnt);
        cTry.push_back(cString[pos]);
        jTry.push_back(jString[pos]);
        solve(pos+1,cnt+1);
        cTry.pop_back();
        jTry.pop_back();
    }

}

int main(){

    FILE *inf, *outf;
    inf=fopen("C-small-attempt0.in","r");
    outf=fopen("C-small-attempt0-result.in","w");
    
    int T;
    
    fscanf(inf,"%d",&T);
    for(int i=0;i<T;i++){
        fscanf(inf,"%d",&N);
        cString.clear();
        jString.clear();
        cAllSet.clear();
        jAllSet.clear();
        cTry.clear();
        jTry.clear();
        minCnt = 1000;
        for(int k=0;k<N;k++){
            oneString.clear();
            fscanf(inf,"%s",input);
            for(int j=0;j<strlen(input);j++){
                oneString+=input[j];
            }
            cString.push_back(oneString);
            cAllSet.insert(oneString);
            oneString.clear();
            fscanf(inf,"%s",input);
            for(int j=0;j<strlen(input);j++){
                oneString+=input[j];
            }

            jString.push_back(oneString);
            jAllSet.insert(oneString);
        }
        solve(0,0);

        fprintf(outf,"Case #%d: %d\n",i+1,N-minCnt);
            
    }
//    getchar();
}