#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
#include<limits>
#include<utility>
#define PB push_back
#define MP make_pair
#define _F first
#define _S second
#define PP system("PAUSE");

using namespace std;
typedef pair<double, double> pii;

double dis;
int N, A;
pii car[5000]; //_F = time, _S = pos;
double G;

void solve(void){
    double speed = 0.0;
    double ans = 0.0;
    double lastt = 0.0;
    double carx = car[0]._S;
    double myx = 0.0;
    double tempspeed, tempx, carspeed;
    double cardis;

    if(N == 1){
        ans = 2.0*dis/G;
        ans = sqrt(ans);
        printf("%.9lf\n", ans);
        return;
        }

    for(int i = 1; i < N; i++){
        double cT = car[i]._F-car[i-1]._F;
        tempspeed = speed+G*cT;//printf("ts:%lf\n", tempspeed);
        tempx = speed*cT+0.5*G*cT*cT;
        carspeed = car[i]._S-car[i-1]._S;
        carspeed /= car[i]._F-car[i-1]._F;
        cardis = car[i-1]._S-myx;
        if(tempx-(car[i]._S-car[i-1]._S) > cardis){//printf("QQ");
            myx = car[i]._S;
            if(speed < carspeed)
                speed = min(carspeed+(carspeed-speed), tempspeed);
            else speed = carspeed;
            cardis = 0.0;
            ans += cT;
            continue;
            }
        else if(myx+tempx > dis){//printf("ZZ");
            double tm = dis-myx;
            double tempans = -speed;
            tempans += sqrt(speed*speed+2*G*tm);
            tempans /= G;
            ans += tempans;
            myx = dis;
            break;
            }
        else if(myx+tempx == dis){//printf("WW");
            double tm = dis-myx;
            double tempans = -speed;
            tempans += sqrt(speed*speed+2*G*tm);
            tempans /= G;
            ans += tempans;
            myx = dis;
            break;
            }
        else{//printf("RR");
            myx += tempx;
            speed = tempspeed;
            ans += cT;
            continue;
            }
        }//printf("speed:%lf pos:%lf, time:%lf\n", speed, myx, ans);
    if(myx < dis){//printf("YY");
        double tm = dis-myx;
        double tempans = -speed;
        tempans += sqrt(speed*speed+2*G*tm);
        tempans /= G;
        ans += tempans;
        myx = dis;
        }
    printf("%.9lf\n", ans);
    return;
    }

int main(void){
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("B-small-attempt1.out", "w", stdout);
    int T;
    scanf("%d", &T);

    for(int i = 1; i <= T; i++){
        printf("Case #%d:\n", i);
        scanf("%lf%d%d", &dis, &N, &A);
        for(int j = 0; j < N; j++){
            double t, x;
            scanf("%lf%lf", &t, &x);
            car[j]._F = t, car[j]._S = x;
            }
        for(int j = 0; j < N; j++){
            if(car[j]._S >= dis){
                if(j == 0) break;
                double tempcs = car[j]._S-car[j-1]._S;
                tempcs /= (car[j]._F-car[j-1]._F);
                car[j]._F = car[j-1]._F+(dis-car[j-1]._S)/tempcs;
                car[j]._S = dis;
                N = j+1;
                break;
                }
            }
        //printf("------%lf %lf\n", car[N-1]._F, car[N-1]._S);
        for(int j = 0; j < A; j++){
            scanf("%lf", &G);
            solve();
            }
        }
    return 0;
    }
