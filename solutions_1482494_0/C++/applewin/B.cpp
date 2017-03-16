#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;
int N;
vector<pair<pair<int,int>,int> > P1;
//vector<pair<int ,int> > P1;
vector<pair<int,int> > P2;
int check[1010];

int main(){
    int T;
    scanf("%d", &T);
    int a,b;
    for(int c = 1;c<=T;++c){
        scanf("%d", &N);
        P1.clear();
        P2.clear();
        memset(check, 0, sizeof(check));
        for(int i=0;i<N;++i){
            scanf("%d%d", &a,&b );
            P1.push_back(make_pair(make_pair(a,-b),i));
            //P1.push_back(make_pair(a,i));
            P2.push_back(make_pair(b,i));
        }
        sort(P1.begin(), P1.end()); 
        sort(P2.begin(), P2.end()); 
        int step = 0;
        int ini = 0;
        int a1= 0, a2 = 0;
        while(a2 < N){
            while(a2 < N && P2[a2].first <= ini){
                if(check[P2[a2].second] == 0){
                    ini += 2; 
                    step ++;
                    
                    check[P2[a2].second] = 2;
                }
                else if (check[P2[a2].second] == 1){
                    step ++;
                    ini += 1;
                    
                    check[P2[a2].second] = 2;
                }
                a2++;
            }
            if (a2 < N && a1 < N && P1[a1].first.first <= ini){
            //if (a2 < N && a1 < N && P1[a1].first <= ini){
                if(check[P1[a1].second] == 0){
                    ini += 1;
                    step ++ ;
                    check[P1[a1].second] = 1;
                }
                a1++;
            }
            else
                break;
        }
        if(ini != 2*N)
            printf("Case #%d: Too Bad\n", c);
        else
            printf("Case #%d: %d\n", c,step );
        //printf("%d\n", ini);
    }
    return 0;
}
