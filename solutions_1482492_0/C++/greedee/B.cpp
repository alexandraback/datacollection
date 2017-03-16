#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cctype> 
#include <string> 
#include <cstring> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 

using namespace std; 


#define PI acos(-1)
#define CLEAR(A) memset(A,0,sizeof(A))
#define SETMAX(A) memset(A,0x7f,sizeof(A))
#define SETM1(A) memset(A,-1,sizeof(A))
#define SQ(A) (A)*(A)

double vel[2002];
double tim[2002];
double dis[2002];
double acc[252];
int T;
int A;
int N;
double D;

double f(double accl) {
	for(int i=1;i<=N;i++) {
		if(tim[i]-tim[i-1] > 1e-8)	vel[i] = (dis[i]-dis[i-1])/(tim[i]-tim[i-1]);
		else vel[i] = 0;
	}
	double currVel = 0;
	double newDist = 0;
	double currDist = 0;
	double newVel = 0;
	double ret = 0;
	for(int i=1;i<=N;i++) {
		currVel = newVel;
		currDist = newDist;
		if(dis[i] > D-1e-7) {
			double timeForOtherCar = (D-dis[i-1])/vel[i];
			double distTravelledByOurCar = currVel*timeForOtherCar+0.5*accl*SQ(timeForOtherCar);
			if(currDist + distTravelledByOurCar > D) ret += timeForOtherCar;
			else {
				double tempDist = D-currDist;
				ret += (-currVel+sqrt(SQ(currVel)+2*accl*tempDist))/accl;
			}
			break;
		} else {
			newDist = currDist + currVel*(tim[i]-tim[i-1])+ 0.5*accl*SQ(tim[i]-tim[i-1]);
			if(newDist < dis[i]) {
				newVel = currVel + accl*(tim[i]-tim[i-1]);
			} else {
				newDist = dis[i];
				double tempDist = dis[i]-currDist;
				double tempTime =  (-currVel+sqrt(SQ(currVel)+2*accl*tempDist))/accl;
				newVel = currVel+accl*tempTime;
			}
			ret += tim[i]-tim[i-1];
		}
	}
	return ret;
}


int main()
{
	cout << setprecision(9) ;
	cin >> T;
	for(int i=1;i<=T;i++) {
		cin >> D >> N >> A;
		for(int j=1;j<=N;j++) {
			cin >> tim[j] >> dis[j];
		}
		cout << "Case #" << i << ": " << endl;
		for(int j=1;j<=A;j++) {
			cin >> acc[j];
			cout << f(acc[j]) << endl;
		}		
	}
	return 0;
}


