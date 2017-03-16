//
//  main.cpp
//  GCJR1B16
//
//  Created by Ningchen Ying on 1/5/2016.
//  Copyright © 2016 Ningchen Ying. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

string num[11] = { "ONE", "NINE"};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    freopen("/Users/yningc/Documents/code/GCJR1B16/GCJR1B16/A-small-attempt3.in","r",stdin);
    freopen("/Users/yningc/Documents/code/GCJR1B16/GCJR1B16/A-small-attempt3.out","w",stdout);
    int T;
    cin>>T;
    for(int icase = 1;icase<=T;icase++){
        string s;
        cin>>s;
        int chr[30];
        
        for(int i=0;i<=26;i++) chr[i] = 0;
        for(int i=0;i<=s.length();i++){
            chr[s[i]-'A']++;
        }
        int ans[10];
        for(int i=0;i<=9;i++) ans[i]=0;
        ans[0] = chr['Z'-'A'];
        chr['Z'-'A'] -=ans[0];
        chr['E'-'A'] -=ans[0];
        chr['R'-'A'] -=ans[0];
        chr['O'-'A'] -=ans[0];
        ans[8] = chr['G'-'A'];
        chr['E'-'A'] -=ans[8];
        chr['I'-'A'] -=ans[8];
        chr['G'-'A'] -=ans[8];
        chr['H'-'A'] -=ans[8];
        chr['T'-'A'] -=ans[8];
        ans[3] = chr['H'-'A'];
        chr['T'-'A'] -=ans[3];
        chr['H'-'A'] -=ans[3];
        chr['R'-'A'] -=ans[3];
        chr['E'-'A'] -=ans[3];
        chr['E'-'A'] -=ans[3];
        ans[2] = chr['W'-'A'];
        chr['T'-'A'] -=ans[2];
        chr['W'-'A'] -=ans[2];
        chr['O'-'A'] -=ans[2];
        ans[4] = chr['R'-'A'];
        chr['F'-'A'] -=ans[4];
        chr['O'-'A'] -=ans[4];
        chr['U'-'A'] -=ans[4];
        chr['R'-'A'] -=ans[4];
        ans[5] = chr['F'-'A'];
        chr['F'-'A'] -=ans[5];
        chr['I'-'A'] -=ans[5];
        chr['V'-'A'] -=ans[5];
        chr['E'-'A'] -=ans[5];
        ans[6] = chr['X'-'A'];
        chr['S'-'A'] -=ans[6];
        chr['I'-'A'] -=ans[6];
        chr['X'-'A'] -=ans[6];
        ans[7] = chr['S'-'A'];
        chr['S'-'A'] -=ans[7];
        chr['E'-'A'] -=ans[7];
        chr['V'-'A'] -=ans[7];
        chr['E'-'A'] -=ans[7];
        chr['N'-'A'] -=ans[7];
        ans[1] = chr['O'-'A'];
        chr['O'-'A'] -=ans[1];
        chr['N'-'A'] -=ans[1];
        chr['E'-'A'] -=ans[1];
        ans[9] = chr['I'-'A'];
        printf("Case #%d: ",icase);
        
        
        
        for(int i=0;i<=9;i++){
            for(int j=0;j<ans[i];j++){
                printf("%d",i);
            }
        }
        cout<<endl;
        
        
        
    }
    return 0;
}
