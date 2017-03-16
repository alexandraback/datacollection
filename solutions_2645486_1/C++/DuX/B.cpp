#include<stdio.h>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;

#define sz size()
#define pb push_back
#define len length()
#define clr clear()

#define eps 0.0000001
#define PI  3.14159265359

long long e,r,n,res,v[55555],m[55555],o[55555];
bool mark[55555];

void idar(long long t, long long x, long long k) {

    int i;

    if (x==n) {
        if (k>res) res=k;
        return;
    }

    for(i=0; i<=t; i++) {
        idar(min(t-i+r, e), x+1, k+v[x]*i);
    }

    return;
}

int main() {

    FILE *ff=fopen("B-large.in", "r"), *gg=fopen("B-largesad.out", "w");

    int i,j,p,tt,ttt;;
    long long q,res2;

    fscanf(ff,"%d", &ttt);
    for(tt=1;tt<=ttt;tt++) {

        printf("%d\n", tt);

        fscanf(ff,"%lld%lld%lld", &e, &r, &n);
        p=0;
        for(i=0; i<n; i++) {
            fscanf(ff,"%lld", &v[i]);
            m[i] = e;
            o[i] = 0;
            if (v[i] > v[p]) p=i;
            mark[i]=0;
        }

        //res=0;
        //idar(e,0,0);

        res2=0;
        res2 = v[p]*e;
        mark[p] = true;

        printf("ok\n");

        q=r;
        if (q>e) q=e;
        for(i=p+1; i<n; i++) {
            m[i]=q;
            q+=r;
            if (q>e) q=e;
        }

        q=e-r;
        if (q<0) q=0;
        for(i=p-1; i>=0; i--) {
            o[i]=q;
            q-=r;
            //if (q<0) q=0;
            if (q<=0) break;
        }

        printf("ok\n");

        for(i=0; i<n-1; i++) {

            p=-1;
            for(j=0; j<n; j++) if (!mark[j] && (p==-1 || v[j] > v[p])) p=j;

            //if (tt==9) printf("->%d %lld %lld %lld   %lld\n", p, v[p], m[p], o[p], res2);

            if (m[p] < o[p]) {
                mark[p] = true;
                continue;
            }

            res2 += v[p]*(m[p]-o[p]);
            mark[p] = true;

            q=o[p]+r;
            if (q>e) q=e;
            j=p+1;
            while(j<n && !mark[j]) {
                m[j]=min(m[j],q);
                q+=r;
                if (q>e) q=e;
                j++;
            }

            q=m[p]-r;
            if (q<0) q=0;
            j=p-1;
            while(j>=0 && !mark[j]) {
                o[j]=max(o[j],q);
                q-=r;
                if (q<0) q=0;
                j--;
            }
        }

        //if (res2 != res) printf("KURAC %d ~ %lld %lld\n", tt, res, res2);
        printf("%d\n", tt);
        fprintf(gg,"Case #%d: %lld\n", tt, res2);
    }

    fclose(ff); fclose(gg);

    return 0;
}
