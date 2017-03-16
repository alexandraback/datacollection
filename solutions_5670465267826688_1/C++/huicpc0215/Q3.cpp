#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
char mp[300][300];
char rmp[300][300];
void init(){
    mp['1']['1']='1';
    mp['1']['i']='i';
    mp['1']['j']='j';
    mp['1']['k']='k';
    mp['i']['1']='i';
    mp['i']['i']=-'1';
    mp['i']['j']='k';
    mp['i']['k']=-'j';
    mp['j']['1']='j';
    mp['j']['i']=-'k';
    mp['j']['j']=-'1';
    mp['j']['k']='i';
    mp['k']['1']='k';
    mp['k']['i']='j';
    mp['k']['j']=-'i';
    mp['k']['k']=-'1';
}

char str[10010];
char allstr[80010];
int main(){
    freopen("./C-large.in","r",stdin);
    freopen("./C-large.out","w",stdout);
    init();
    int T,casenum=1;
    scanf("%d",&T);
    while(T--){
        printf("Case #%d: ",casenum++);
        int x,l;
        scanf("%d%d",&l,&x);
        scanf("%s",str);
        if( x > 8 ){
            x = x%4+4;
        }
        for(int i=0;i<x;i++)
            for(int j=0;j<l;j++)
                allstr[i*l+j]=str[j];
        bool findi=false,findk=false;
        char nowi=str[0],nowk=str[l-1];
        int isPositive=true;
        for(int i=1;i<x*l;i++){
            if( mp[nowi][ allstr[i] ] < 0 ){
                nowi = - mp[ nowi ][ allstr[i] ];
                isPositive = 1 - isPositive;
            }
            else nowi = mp[ nowi ][ allstr[i] ];
        }
        if(!isPositive && nowi =='1' ){
            nowi = str[0];
            if( nowi =='i' || nowi ==(-'i') ) findi = true;
            if( nowk =='k' || nowk ==(-'k') ) findk = true;
            for(int i=1;i<x*l-i-1;i++){
                nowi = mp[ nowi ][ allstr[i] ];
                nowk = mp[ allstr[x*l-1-i] ][ nowk ];
                if( nowi =='i' || nowi ==(-'i') ) findi = true;
                if( nowk =='k' || nowk ==(-'k') ) findk = true;
                nowi = nowi > 0? nowi : -nowi;
                nowk = nowk > 0? nowk : -nowk;
                if( findi && findk ) break;
            }
            if( findi && findk ) printf("YES\n");
            else printf("NO\n");
        }
        else printf("NO\n");
    }
    return 0;
}
