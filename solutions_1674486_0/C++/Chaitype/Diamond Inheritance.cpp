#include<stdio.h>
#include<vector>
using namespace std;
vector<int> data[1010];
int check[1010],cal[1010];
int T;
int C,M;
void work(int q){
        cal[q]=1;
        vector<int>::iterator V;
            for(V=data[q].begin();V!=data[q].end();++V){
                if(!cal[*V]) work(*V);
                check[*V]++;
            }
        //printf("a");
}
int main()
{   int N;
    int q,w,e,r;
    freopen("A-small-attempt6.in","r",stdin);
    freopen("out.out","w",stdout);
    scanf(" %d",&T);
    for(q=0;q<T;++q){
        scanf(" %d",&M);C=0;
        //printf("%d\n",M);
        for(w=0;w<M;++w){
            scanf(" %d",&N);
            //printf("%d ",N);
            data[w+1].clear();
            for(e=0;e<N;++e){
                scanf(" %d",&r);
                //printf("%d\n",r);
                data[w+1].push_back(r);
            }
        }
        for(w=0;w<M;++w){
            for(e=1;e<=M;++e) {cal[e]=0;check[e]=0;}
            work(w+1);
            for(e=1;e<=M;++e){
                if(check[e]>=2){
                    C=2;break;
                }
            }
            if(C==2) break;
        }
        printf("Case #%d: ",q+1);
        if(C<=1) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
/*
3
3
1 2
1 3
0
5
2 2 3
1 4
1 5
1 5
0
3
2 2 3
1 3
0
5
3 2 3 4
0
0
1 5
0
5
3 2 3 4
1 5
1 4
1 5
0
5
3 2 3 4
1 4
1 4
1 5
0
5
3 2 3 4
1 3
1 4
1 5
0

*/
