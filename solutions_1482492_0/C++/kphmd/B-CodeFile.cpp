#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <map>

using namespace std;

void solve();
void runCase();

#define REP(i,n) for(int i = 0; i < (n); i++)
#define SZ(x) (int)(x.size())

const int MN = 2000,MA = 250;
double D;
int N,A;
double t[MN],x[MN],v[MN],s2[MN],v2[MN];
double a[MA];

double get(double p1,double p2,double p3) {
    return (sqrt(p2*p2-4*p1*p3)-p2)/(2*p1);
}

double calc(double ac) {
    double res = 0;
    s2[0] = 0;
    v2[0] = 0;
    for(int i = 1; i < N; i++) {
        double s,sp,dt;
        dt = t[i]-t[i-1];
        sp = v2[i-1]+ac*dt;
        s = s2[i-1]+v2[i-1]*dt+0.5*ac*dt*dt;
        if(s>x[i]) {
            s = x[i];
            sp = ac*t[i];
            sp = get(0.5*ac,0,-v[i]*t[i]);
        }
        s2[i] = s;
        v2[i] = sp;
    }
    double ds,dtime = 0;
    int n = N-1;
    ds = D;
    res = t[n];
    if(ds > 0) {
        double p1,p2,p3;
        p1 = 0.5*ac;
        p2 = v2[n];
        p3 = s2[n]-ds;
        dtime = get(p1,p2,p3);
        res += dtime;
    }
    //cout << s2[n] << " " << ds<<" " << dtime << " ";
    return res;
}

void runCase()
{
    scanf("%lf %d %d",&D,&N,&A);
    REP(i,N) {
        scanf("%lf %lf",&t[i],&x[i]);
    }
    for(int i = 1; i < N; i++) {
        v[i] = (x[i]-x[i-1])/(t[i]-t[i-1]);
        if(x[i]>=D) {
            N = i+1;
            break;
        }
    }
    t[N-1] = t[N-1] - (x[N-1]-D)/v[N-1];
    x[N-1] = D;
    REP(i,A) {
        scanf("%lf",&a[i]);
    }
    REP(i,A) {
        printf("%lf\n",calc(a[i]));
    }
}

void runSample()
{
	string input;

	char buf[501] = {0};
	cin.getline(buf,501);

	input = buf;


	printf("%s\n",input.c_str());
}

void solve()
{
	int n;
	scanf("%d",&n);
	getchar();

	for(int i = 0; i < n; i++) {
		printf("Case #%d:\n",i+1);
		runCase();
		//runSample();
	}
}

int main()
{
	solve();
	return 0;
}
