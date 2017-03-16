#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define F first
#define S second
#define pb push_back
#define rep(I,N) for(int (I) = 0; (I) < (N); (I)++)

typedef pair<int,int> pii;
typedef long long ll;
int n,m,d;
int k;
double p1, p2, v1, v2;
double where(double dist, double whereSecond){
    double time = dist / (v1-v2);
    return whereSecond + time * v2;
}
int main(){
    int t;
    scanf("%d",&t);
    rep(testId,t){
        printf("Case #%d: ", testId+1);
        scanf("%d",&n);
        if (n == 1){
            scanf("%d%d%d",&d, &k, &m);
            p1 = double(d)/360.0;
            p2 = p1 - 1e-8;
            v1 = 1.0/double(m);
            v2 = 1.0/double(m+1);
        } else {
            scanf("%d%d%d",&d,&k, &m);
            p1 = double(d)/360.0;
            v1 = 1.0/double(m);
            scanf("%d%d%d",&d,&k, &m);
            p2 = double(d)/360.0;
            v2 = 1.0/double(m);
            if (v2 > v1){
                swap(v1, v2);
                swap(p1, p2);
            }
            if (abs(p1 - p2) < 1e-8){
                p2 -= 1e-8;
            }
        }
        double dist = (p2 - p1);
        while (dist < 0.0)
            dist = 1.0+dist;
        double time = dist / (v1-v2);
        //printf("velos: %lf %lf, pos %lf %lf, time %lf\n", v1, v2, p1, p2, time);

        bool faster = false;
        if (p1 > p2)
            faster = false;
        else
            faster = true;
      //  printf("faster %d\n", faster);


        if (faster){
            double meetingTime = dist / (v1-v2);
            double meeting = where(dist, p2);
         //   printf("meeting %lf\n", meeting);
            if (meeting > 1.0){
                printf("0\n");
                continue;
            }
            double second = where(1.0, meeting);
            if (second > 1.0){
                printf("0\n");
                continue;
            }
            printf("1\n");
            continue;
        }
        double meeting = where(dist, p2);
        if (meeting > 1.0){
            printf("0\n");
        } else printf("1\n");
    }
}
