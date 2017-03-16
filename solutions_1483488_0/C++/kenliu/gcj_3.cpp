#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#define PI 3.141592653589793
#define DEBUG 0
#define INF 1000000007 

using namespace std;

int n;
bool used[2000001];
int pt[10];
set<int>st;
vector< pair<int, int> >seq;
int getD(int a){
    int cur=0;
    while(a>0){a/=10;cur++;}
    return cur;
}
bool getnext(int a, int &b, int digit, int &w){
    int div=pt[w], mul= pt[digit-w],div2=pt[w-1];
    int c = (a%div),dd=(a/div2)%10;;
    if(dd==0)return 0;
    b= a/div+c*mul;
    if(DEBUG)printf("getnext: %d %d %d %d\n",a,b,digit,w);
    return 1;
}
void getNum(){
    int i,j,k,ps;
    pt[0]=1;
    for(i=1;i<=7;i++)pt[i]=pt[i-1]*10;
    for(k=0;k<seq.size();k++){
        long long res=0;
        int a=seq[k].first,b=seq[k].second;
        if(a<10)a=12;
        for(i=a;i<=b;i++){
            if(DEBUG)printf("%d\n",i);
            if(!used[i]){                           //not recycled
                ps=1;
                used[i]=1;
                int cur=i, d = getD(i),bb;  
                for(j=1;j<d;j++){
                    if(getnext(cur,bb,d,j)){         //not 0                    
                        if(cur!=bb && bb<=b && bb>=a){                  //n<m
                            if(DEBUG && cur>bb)printf("cur>bb %d %d\n",cur,bb);
                            if(DEBUG)printf("next: %d\n",bb);
                            used[bb]=1;
                            if(st.count(bb)==0){st.insert(bb);ps++;}
                        }
                    }
                }
                st.clear();
                res+=ps%2==0?ps/2*(ps-1):ps*(ps-1)/2;
            }
        }
        printf("Case #%d: %I64d\n",k+1,res);
        memset(used,0,sizeof(used));
    }
}
int main(){
    char c;
    int i,a,b;
    scanf("%d\n",&n);
    for(i=0;i<n;i++){
        scanf("%d%d",&a,&b);
        seq.push_back(make_pair(a,b));
    }
    getNum();
    return 0;
}
