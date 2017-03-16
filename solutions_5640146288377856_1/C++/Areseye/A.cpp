#include"cstdio"
#include"iostream"
#include"map"
#include"string"
#include"cstring"
#include"vector"
#include"utility"
#include"algorithm"
#include"cmath"
#include"queue"
#include"stack"
#include"set"

using namespace std;

int compute(int C,int W){
    if(C==W){return W;}
    int c=C;
    int ans=0;
    while(1){
        if(c-W<=W){
            ans+=W+1;
            break;
        }
        c-=W;
        ans++;
    }
    return ans;
}
int main(){
    freopen("d:A-large.in","r",stdin);
    freopen("d:A.out","w",stdout);
	int T;
	int casenum=0;
	cin>>T;
	while(casenum++<T){
        int R,C,W;
        cin>>R>>C>>W;
        int ans=0;

        if(R==1){
            ans=compute(C,W);
            printf("Case #%d: %d\n",casenum,ans);

        }else{
            ans+=(R-1)*(C/W);
            ans+=compute(C,W);
            printf("Case #%d: %d\n",casenum,ans);
        }
	}


return 0;}
