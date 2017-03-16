#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

int t,n;
int a[15];
map<char,int> mp;
string s[110];
vector<char> v,b[11];

int main(){
    freopen("B-small-attempt1.in","r",stdin);
    freopen("1.out","w",stdout);
    cin >> t;
    for (int ti=1;ti<=t;ti++){
        scanf("%d",&n);
        mp.clear();
        int tot=0;
        for (int i=1;i<=n;i++){
            cin>>s[i];
            b[i].clear();
            b[i].push_back(s[i][0]);
            for (int j=0;j<s[i].size();j++){
                if (mp[s[i][j]]==0) tot++;
                mp[s[i][j]]++;
                if (s[i][j]!=b[i][b[i].size()-1]) b[i].push_back(s[i][j]);
            }
            //for (int j=0;j<b[i].size();j++) cout<<b[i][j];cout<<endl;
        }
        
        int ans=0;
        //cout<<tot<<endl;
        for (int i=0;i<n;i++) a[i]=i+1;
        do{
           //string st="";
           //for (int i=0;i<n;i++) st+=s[a[i]];
           int bo=1;
           v.clear();
           //v.push_back(b[a[0]][0]);
           
           for (int i=0;i<n;i++){
               for (int j=0;j<b[a[i]].size();j++){
                   if (bo){v.push_back(b[a[i]][j]);bo=0;}
                      else
                      if (b[a[i]][j]!=v[v.size()-1]) v.push_back(b[a[i]][j]);
               }
               if (v.size()>tot) break;
           }
           if (v.size()==tot){
              ans++;
              //for (int j=0;j<v.size();j++) cout<<v[j];cout<<endl;
              //cout<<st<<endl;                
           } 
           
           /*
           for (int i=0;i<st.length();i++){
               int x1=i-1;
               int x2=i+1;
               int flag=0;
               if (x1>=0 && st[x1]==st[i]) flag=1;
               if (x2<st.length() && st[x2]==st[i]) flag=1;
               if (mp[st[i]]>1 && flag==0) {bo=0;break;}
           }
           
           if (bo){
              ans++;
              cout<<st<<endl;
           }
           */
        }while (next_permutation(a,a+n));
        cout << "Case #"<<ti<<": "<<ans<<endl;
    }
    //system("pause");
    return 0;
}
