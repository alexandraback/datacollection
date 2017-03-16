#include"iostream"
#include"string"
#include"math.h"
#include"vector"


using namespace std;

int main(){

    freopen("d:A-small-attempt0.in","r",stdin);
    freopen("d:outputA.txt","w",stdout);

    int T;
    cin>>T;
    int casenum=0;
    while(casenum++<T){
        int Smax=0;
        string shyness;
        cin>>Smax;
        cin>>shyness;
        vector<int> shynum;
        for(int i=0;i<Smax+1;i++){shynum.push_back(shyness[i]-'0');}

        int cur=shynum[0];
        int ans=0;

        for(int i=1;i<=Smax;i++){
            if(shynum[i]>0&&cur<i){
                ans+=i-cur;
                cur=i+shynum[i];
            }else {
                cur+=shynum[i];
            }
        }

        printf("Case #%d: %d\n",casenum,ans);

    }

return 0;}
