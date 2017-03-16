using namespace std;
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<set>
#include<map>
#include<utility>
#include<climits>
#include<sstream>
#define S(a) scanf("%d",&(a))

int main(){
    int tc,cs=1,ans,n,c;
    string s;
    freopen("C:\\input.txt","r",stdin);
    freopen("C:\\output.txt","w",stdout);
    S(tc);
    while(tc--){
        ans=0;
        cin>>s;
        S(n);
        for(int i=0;i<s.length();i++)
            for(int j=i+n;j<=s.length();j++){
                c=0;
                for(int k=i;k<j;k++){
                    
                    if(s[k]=='a' || s[k]=='e' || s[k]=='i'|| s[k]=='o' || s[k]=='u')
                        c=0;
                    else
                        c++;
                    if(c>=n){
                        ans++;
                        break;
                    }
                }
                //cout<<endl;
            }
 
        printf("Case #%d: %d\n",cs++,ans);
    }
}
 