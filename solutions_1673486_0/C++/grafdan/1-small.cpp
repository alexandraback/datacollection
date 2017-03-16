#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int T,t,A,B;
int a,b,i,j,anz;
vector < double > P;
double p,r,res,Exp;
void testc() {
	scanf("%d %d",&A, &B);
	P.clear();
	for(a=0;a<A;a++) {
		scanf("%lf",&p);
		P.push_back(p);
	}
	res = 2*B;
	r=1.0;
	a=A; b=B;
	for(i=1;i<=a;i++) { //Position des vordersten ersten Fehlers
		p = 1-r; // Wahrscheinlichkeit einen Fehler davor zu haben
		anz = (a-i)+1+(b-i+1)+1; // zurueck bis i und dann bis ans Ende und Enter 
		Exp = (1-p)*anz + (p) * (anz+b+1); //plus Wiederholung
		//printf("i %d, p %lf, anz %d, Exp %lf\n",i,p,anz,Exp);
		res = min(res,Exp);
		r*= P.at(i-1);
	}
	//direkt fertig tippen:
	anz = b-a+1;
	p = r;
	Exp = p*anz + (1-p) * (anz+b+1); //plus Wiederholung
	//printf("Schluss %d, p %lf, anz %d, Exp %lf\n",i,p,anz,Exp);
	res = min(res,Exp);
	// enter und dann ...
	Exp = 1+b+1;
	res = min(res,Exp);
	//printf("Enter %d, p %lf, anz %d, Exp %lf\n",i,p,anz,Exp);
	printf("Case #%d: %.6lf\n",t,res);

}
int main() {
	scanf("%d",&T);
	for(t=1;t<=T;t++) testc();
	return 0;

}