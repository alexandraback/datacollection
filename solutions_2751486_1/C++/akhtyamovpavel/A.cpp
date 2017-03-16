#include<cstdio>
#include<ctime>
#include<cmath>
#include<cctype>

#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
#include<utility>
#include<stack>
#include<queue>
using namespace std;
#define pb push_back
#define mp make_pair
#define FILEIN "A.in"
#define FILEOUT "A.txt"
int main(){
    freopen(FILEIN,"r",stdin);
    freopen(FILEOUT,"w",stdout);
    int t;
    cin>>t;
    string obr="aeiou";
    for(int u=1;u<=t;++u){
        long long N;
        string s;
        cin>>s>>N;
        long long res=0;
        int ls;
        long long curvalue=0;
        bool issogl=false;
        long long l=0;
        int bsogl;
        for(int i=0;i<s.length();++i){
            if(s[i]!=obr[0]&&s[i]!=obr[1]&&s[i]!=obr[2]&&s[i]!=obr[3]&&s[i]!=obr[4]){
                    if(!issogl)
                    {
                        issogl=true;
                        curvalue=1;
                        bsogl=i;
                    }
                    else{
                        curvalue++;
                    }
            }
            else{
                issogl=false;
                curvalue=0;

            }
            if (curvalue>=N){
                res+=(bsogl-l+1)*((long long)s.length()-i);
                bsogl++;
                l=bsogl;
            }
            //cout<<i<<" "<<res<<endl;
        }
        cout<<"Case #"<<u<<": ";
        cout<<res<<endl;
    }


    return 0;
}
