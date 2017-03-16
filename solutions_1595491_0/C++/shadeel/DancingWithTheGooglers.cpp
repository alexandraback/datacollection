#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct NODE{
    int s, sur, nsur;
};

/*NODE peo[100];
int p;

bool cmp(NODE a, NODE b){
    if( a.nsur>=p && b.nsur>=p ){
        if( a.sur ) return true;
        else        return false;
    }
    else if( a.nsur>=p && b.nsur<p )return true;
    else if( a.nsur<p && b.nsur>=p )return false;
    else{
        if( a.sur>=p )  return true;
        else            return false;
    }
}*/

int main(void){
    
    freopen("BSin.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    int cas, c=0, n, sur, p;
    
    int sur_max[30]={0}, nsur_max[30], peo[100];
    for(int i=2; i<=28; ++i)
        sur_max[i] = (i+4)/3;
    for(int i=0; i<=30; ++i)
        nsur_max[i] = (i+2)/3;
    
    scanf("%d", &cas);
    while( cas-- ){
        printf("Case #%d: ", ++c);
        scanf("%d %d %d", &n, &sur, &p);
        for(int i=0; i<n; ++i){
            scanf("%d", &peo[i]/*.s*/);
            //peo[i].sur = sur_max[peo[i].s];
            //peo[i].nsur = nsur_max[peo[i].s];
        }
        
        //sort(peo,peo+n,cmp);
        int oo=0, ou=0, uo=0, uu=0;
        for(int i=0; i<n; ++i){
            if( nsur_max[peo[i]]>=p ){
                if( sur_max[peo[i]]>=p )    ++oo;
                else                        ++ou;
            }
            else{
                if( sur_max[peo[i]]>=p )    ++uo;
                else                        ++uu;
            }
        }
        
        if( uo>=sur )               printf("%d\n", oo+ou+sur);
        else if( uo+uu+oo>=sur )    printf("%d\n", oo+ou+uo);
        else                        printf("%d\n", oo+ou+uo-(sur-oo-ou-uo));
                   
        
    }
    
    return 0;
}
