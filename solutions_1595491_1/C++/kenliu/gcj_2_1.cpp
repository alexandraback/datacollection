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

int t,n,s,p,cases;
vector<int>seq;
void getNum(){
    int i,sum=0,cur=0;
    for(i=seq.size()-1;i>=0;i--){
        int a=seq[i];
        if(a%3==0){    
            if(a/3>=p){if(DEBUG)printf("%d\n",a);sum++;} 
            else if(a>=3 && cur<s && (a-3)/3+2>=p){cur++;sum++;}
        }
        else if(a>=1 && (a-1)%3==0){
            if(DEBUG)printf("%d\n",a);
            if((a-1)/3+1>=p)sum++;
        }   
        else if(a>=2&&(a-2)%3==0){               //a-2%3==0
            if((a-2)/3+1>=p){if(DEBUG)printf("%d\n",a);sum++;}
            else if(cur<s&& (a-2)/3+2>=p){cur++;sum++;}
        }
    }
    printf("Case #%d: %d\n", cases, sum);
}
int main(){
    char c;
    int i,j,a;
    scanf("%d\n",&t);
    for(i=0;i<t;i++){
        cases = i+1;
        scanf("%d%d%d",&n,&s,&p);
        for(j=0;j<n;j++){   
            scanf("%d",&a);
            if(DEBUG)printf("scan: %d\n",a);
            seq.push_back(a);
        }
        sort(seq.begin(),seq.end());
        getNum();
        seq.clear();
    }

    return 0;
}
