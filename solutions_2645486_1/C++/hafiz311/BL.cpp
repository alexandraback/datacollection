#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <math.h>
#include <stack>
#include <list>

#define SZ 10007
#define EPS 1e-10
#define pb push_back
#define pi (acos(-1.0))


using namespace std;

typedef long long Long;


Long v[SZ+7];
Long n,E,R;
Long tk[SZ+7];
Long lft[SZ+7];

struct ss
{
    Long vv,pos;
};


ss s[SZ+7];
bool cmp(const ss &s1,const ss &s2)
{
    if(s1.vv!=s2.vv) return s1.vv>s2.vv;
    return s1.pos<s2.pos;
}

int tree1[1000007];
int tree2[1000007];

void walk(int node,int l,int r)
{
    tree1[node] = -1;  /// lft max
    tree2[node] = n+1;  /// ryt max

    if(l>=r) return ;
    walk(node*2,l,(l+r)/2);
    walk(node*2+1,(l+r)/2 + 1 , r);
}


int L,rx;

void update(int node,int l,int r)
{
    if(l>r) return ;
    if(r<L || l>L ) return ;
    if(l==r) {
        tree1[node] = l; tree2[node] = l;
        //printf("updated %d\n",l);
        return ;
    }
    update(node*2,l,(l+r)/2);
    update(node*2+1,(l+r)/2 + 1 , r);

    tree1[node] = max(tree1[node*2],tree1[node*2+1]);
    tree2[node] = min(tree2[node*2],tree2[node*2+1]);

}




Long query1(int node,int l,int r)
{
    if(L>rx) return -1;
    if(l>r) return -1;
    if(r<L ||rx<l) return -1;

    if(l>=L&&r<=rx) return tree1[node];

    return max(query1(node*2,l,(l+r)/2),query1(node*2+1,(l+r)/2 + 1 , r));

}


Long query2(int node,int l,int r)
{
    if(L>rx) return n+1;
    if(l>r) return n+1;
    if(r<L ||rx<l) return n+1;

    if(l>=L&&r<=rx) return tree2[node];

    return min(query2(node*2,l,(l+r)/2),query2(node*2+1,(l+r)/2 + 1 , r));

}







int main()
{
    int tst,cas;
    freopen("BL.in","rt",stdin);
    freopen("BL.out","wt",stdout);
    scanf("%d",&tst);
    for(cas=1;cas<=tst;cas++) {

        scanf("%lld%lld%lld",&E,&R,&n);




        for(int i=0;i<n;i++) scanf("%lld",&s[i].vv),s[i].pos = i;
        //printf("%d\n",cas);
        //continue;

        sort(s,s+n,cmp);

        for(int i=0;i<=n;i++) tk[i] = -1;
        for(int i=0;i<=n;i++) lft[i]=0;



        Long ans = 0;
        walk(1,1,n);


        for(int i=0;i<n;i++) {

            Long hi=E,lo=0,mid;




            /*for(int j=s[i].pos-1;j>=0;j--) {
                if(tk[j]!=-1) {

                    hi = (s[i].pos-j)*R + lft[j];
                    break;
                }
            }*/

            L = 1;
            rx = s[i].pos;
            Long ind = query1(1,1,n);
            if(ind!=-1) {
                ind--;
                //printf("here\n");
                hi = (s[i].pos-ind)*R + lft[ind];
            }


            hi = min(hi,E);
            Long ast = hi;

           // printf("%lld\n",ast);


            Long mxt=0;
            ind=n-1;

            /*
            for(int j=s[i].pos+1;j<n;j++) {
                if(tk[j]!=-1) {
                    mxt = lft[j] + tk[j];
                    ind = j;
                    break;
                }
            }*/
            L = s[i].pos + 2; rx = n;
            ind = query2(1,1,n);
            if(ind>n) ind = n-1;
            else {
                ind--;
                mxt = lft[ind] + tk[ind];
            }


            tk[s[i].pos] = 0;

            while(lo<=hi) {
                mid = (lo+hi)/2;
                if(ast-mid+R*(ind-s[i].pos)>=mxt) {
                    tk[s[i].pos] = mid;
                    lo = mid + 1;
                }
                else hi = mid - 1;

            }

            lft[s[i].pos] = ast - tk[s[i].pos];

           // printf("%lld %lld %d\n",tk[s[i].pos],lft[s[i].pos],s[i].pos);

            ans+=tk[s[i].pos]*s[i].vv;

            L = s[i].pos+1;



            update(1,1,n);






        }

        printf("Case #%d: %lld\n",cas,ans);




    }

    return 0;
}
