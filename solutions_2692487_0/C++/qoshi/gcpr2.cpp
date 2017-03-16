#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <queue>

using namespace std;

struct node {
    long long eat;
    int step;
    int now;
};

const int size = 105;

int t,A,N;

int a[size];

queue<node> Q;


int solve(){
    node s1,s2;
    int i,e;
    int ans;
    ans = -1;
    while ( !Q.empty() ){
        Q.pop();
    }
    s1.now = 0;
    s1.step = 0;
    s1.eat = A;
    Q.push(s1);

    while ( !Q.empty() ){
        s1 = Q.front();
        //printf("bfs %d %d %d\n",s1.now,s1.step,s1.eat);
        //getchar();
        Q.pop();
        if ( s1.now >= N ){
            if ( ( ans == -1 ) || ( ans > s1.step ) ){
                ans = s1.step;
            }
        }else
        {
        if ( a[s1.now] < s1.eat ){
            e = s1.eat;
            for ( i = s1.now; ( a[i] < e ) && ( i < N ) ; i++ ){
                e = e+a[i];
            }
            s2.eat = e;
            s2.step = s1.step;
            s2.now = i;
           // printf("push %d %d %d\n",s2.now,s2.step,s2.eat);
            Q.push(s2);
        }else{
            s2.eat = s1.eat*2-1;
            s2.step = s1.step+1;
            s2.now = s1.now;
            if ( s2.step <= N ){
               // printf("push %d %d %d\n",s2.now,s2.step,s2.eat);
               Q.push(s2);
            }
            s2.eat = s1.eat;
            s2.step = s1.step+1;
            s2.now = s1.now+1;
            //printf("push %d %d %d\n",s2.now,s2.step,s2.eat);
            Q.push(s2);
        }
        }

    }
return ans;
}


int main(){
    int cas,i;
    FILE* fin = fopen("d:\\g4.in","r");
    FILE* fout = fopen("d:\\out.txt","w");
    fscanf(fin,"%d",&t);

    for ( cas = 1; cas <= t; cas++ ){
        fscanf(fin,"%d%d",&A,&N);
        for ( i = 0; i < N; i++ ){
            fscanf(fin,"%d",&a[i]);
        }
        sort(a,a+N);

        fprintf(fout,"Case #%d: %d\n",cas,solve());
    }
    fclose(fin);
    fclose(fout);
}
