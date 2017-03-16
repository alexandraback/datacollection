#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int x[1000010][2];
int T,t;
bool isConsonant(char e){
    if(e!='a'&&e!='e'&&e!='i'&&e!='o'&&e!='u'){
        return true;
    }
    return false;
}
int N;
char str[1000010];
int main(){
    int i,j,k;
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        memset(x,0,sizeof x);
        printf("Case #%d: ",t);
        scanf("%s",str);
        scanf("%d",&N);
        int sum=0;
        j=0;int cur=0;int cov=0;
        for(i=0;i<strlen(str);i++){
            if(isConsonant(str[i])){
                cur++;
                if(cur>=N)
                cov=i-N+2;
                //printf(">%d\n",cov);
            }
            else cur=0;
            sum+=cov;
        }
        printf("%d\n",sum);
    }
    return 0;
}


