#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;

string s,ans;
int a[30];

int main()
{
    freopen("gcj_16_r1_b_1_in.txt","r",stdin);
    freopen("gcj_16_r1_b_1_out.txt","w",stdout);
    int t;
    cin>>t;
    char num[][20]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
    int num_len[10]={4,3,3,5,4,4,3,5,5,4};
    for(int qq=1;qq<=t;qq++) {
        cout<<"Case #"<<qq<<": ";
        int i,j,n,m,temp,prev=-1;
        cin>>s;
        memset(a,0,sizeof(a)); ans="";
        n=s.length();
        for(i=0;i<n;i++) {
            a[s[i]-'A']++;
        }
        while(1) {
            for(i=0;i<26;i++) if(a[i]>0) break;
            if(i>=26) break;
            if(a['Z'-'A']>0) { for(i=0;i<4;i++) a[num[0][i]-'A']--; ans+='0'; }
            else if(a['W'-'A']>0) { for(i=0;i<3;i++) a[num[2][i]-'A']--; ans+='2'; }
            else if(a['G'-'A']>0) { for(i=0;i<5;i++) a[num[8][i]-'A']--; ans+='8'; }
            else if(a['U'-'A']>0) { for(i=0;i<4;i++) a[num[4][i]-'A']--; ans+='4'; }
            else if(a['X'-'A']>0) { for(i=0;i<3;i++) a[num[6][i]-'A']--; ans+='6'; }
            else if(a['R'-'A']>0) { for(i=0;i<5;i++) a[num[3][i]-'A']--; ans+='3'; }
            else if(a['S'-'A']>0) { for(i=0;i<5;i++) a[num[7][i]-'A']--; ans+='7'; }
            else if(a['I'-'A']>0 && a['V'-'A']>0) { for(i=0;i<4;i++) a[num[5][i]-'A']--; ans+='5'; }
            else if(a['I'-'A']>0 && a['N'-'A']>0) { for(i=0;i<4;i++) a[num[9][i]-'A']--; ans+='9'; }
            else if(a['N'-'A']>0 && a['O'-'A']>0) { for(i=0;i<3;i++) a[num[1][i]-'A']--; ans+='1'; }
        }
        sort(ans.begin(),ans.end());
        cout<<ans<<"\n";
    }
    return 0;
}
