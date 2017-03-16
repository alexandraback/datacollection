#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<stack>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;

class event{
public:
	double time,pos;
	event(double time,double pos):time(time),pos(pos){}
};

double calc(double a,double b,double c){
	return (-b+sqrt(b*b-4*a*c))/(2*a);
}


int main()
{
	int T;cin>>T;
	for(int t=1;t<=T;t++){
		double D;
		int N,A;
		cin>>D>>N>>A;
		vector<event> E;
		for(int i=0;i<N;i++){
			double time,pos; cin>>time>>pos;
			E.push_back(event(time,pos));
		}
		vector<double> ace;
		for(int i=0;i<A;i++){
			double a;
			cin>>a;
			ace.push_back(a);
		}
		cout<<"Case #"<<t<<":"<<endl;;

		double other;
		if(N==2){
			double s=(E[1].pos-E[0].pos)/(E[1].time-E[0].time);
			other=E[0].time+(D-E[0].pos)/s;
		}

		for(int i=0;i<A;i++){
			double a=ace[i],ans;
			ans=sqrt(2.0*D/a);
			if(N==2) ans=max(other,ans);
			printf("%.7lf\n",ans);
		}

	}
	return 0;
}