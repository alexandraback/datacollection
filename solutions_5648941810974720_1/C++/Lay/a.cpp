#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <functional>
#include <set>
#include <sstream>
#include <map>
#include <queue>
#include <stack>

using namespace std;




int main()
{
    string d[]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
    int T;
    cin>>T;
	

    
    for(int t=1;t<=T;t++){
        string s;
        cin>>s;
        vector<int> cnt(26);
        for(int i=0;i<s.size();i++) cnt[s[i]-'A']++;
        
        double a[10][10]={
            {-0.5,-1.5,0.5,0.5,0,0.5,1,-0.5,-0.5,1.5},
            {1.25,1.25,-0.75,-0.25,-0.5,0.25,-1.5,0.25,-0.25,-2.25},
            {0,0,-1,0,0,0,0,0,1,0},
            {1.25,1.25,-1.75,-0.25,-0.5,-0.75,-0.5,0.25,0.75,-2.25},
            {-0.75,0.25,1.25,-0.25,0.5,0.25,0.5,0.25,-0.25,0.75},
            {0.75,0.75,-1.25,0.25,-0.5,-0.25,-0.5,-0.25,0.25,-0.75},
            {0.75,0.75,-1.25,0.25,-0.5,-0.25,-0.5,0.75,0.25,-1.75},
            {-0.75,-0.75,1.25,-0.25,0.5,0.25,0.5,0.25,-0.25,1.75},
            {-1.25,-1.25,2.75,0.25,0.5,0.75,0.5,-0.25,-0.75,2.25},
            {-0.25,-0.25,-0.25,0.25,0.5,-0.25,0.5,-0.25,0.25,0.25}
        };
        
        double b[10]={cnt['E'-'A'],cnt['F'-'A'],cnt['H'-'A'],cnt['I'-'A'],cnt['N'-'A'],cnt['O'-'A'],cnt['R'-'A'],cnt['S'-'A'],cnt['T'-'A'],cnt['V'-'A']};
        double use[10]={};
        
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                use[i]+=a[i][j]*b[j];
            }
            use[i]=round(use[i]);
            //cout<<use[i]<<" ";
        }
        //cout<<endl;

        string ans;
        for(int i=0;i<10;i++){
            for(int j=0;j<use[i];j++) ans+=(char)('0'+i);
        }
        printf("Case #%d: %s\n",t,ans.c_str());
    }
    
    
    
    return 0;
}