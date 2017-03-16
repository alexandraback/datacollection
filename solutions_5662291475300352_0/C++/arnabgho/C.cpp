#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main() {
	int T;
	cin>>T;
	for (int cas = 1; cas <=T ; ++cas)
	{
		int N;
		cin>>N;
		std::vector<int> Theta,Time;
		for (int i = 0; i <N ; ++i)
		{
			int h,d,m;
			cin>>d>>h>>m;
			// cout<<"h "<<h<<endl;
			if(h==2){
				Theta.push_back(d);
				Theta.push_back(d);
				Time.push_back(m);
				Time.push_back(m+1);
			}
			else if(h==1){
				Theta.push_back(d);
				Time.push_back(m);
			}
		}
		int res=0;
		// cout<<"Time.size() "<<Time.size()<<endl;
		// cout<<"Theta size "<<Theta.size()<<endl;
		double Tfast,Tslow,Thetafast,Thetaslow;
		double Thetameet;
		if(N==1 || Time[0]==Time[1]){
			res=0;
		}
		else if(N==2 && Time[0]!=Time[1]){
			if(Time[0]<Time[1]){
				Tfast=Time[0];
				Thetafast=Theta[0];
				Tslow=Time[1];
				Thetaslow=Theta[1];
			}
			else{
				Tfast=Time[1];
				Thetafast=Theta[1];
				Tslow=Time[0];
				Thetaslow=Theta[0];
			}
			// cout<<"HI\n";
			if(Thetafast==Thetaslow){
				Thetameet=360*Tfast-Thetafast*Tfast+Thetaslow*Tslow;
				Thetameet/=(Tslow-Tfast);
				if(Thetameet>360) res=0;
				else res=1;
			}
			else{
				if(Thetaslow>Thetameet){
					Thetameet=360*Tfast-Thetafast*Tfast+Thetaslow*Tslow;
					Thetameet/=(Tslow-Tfast);
					if(Thetameet>360) res=0;
					else res=1;
				}
				else{
					Thetameet=-Thetafast*Tfast+Thetaslow*Tslow;
					Thetameet/=(Tslow-Tfast);
					if(Thetameet>360) res=0;
					else res=1;
				}
			}
		}
		cout<<"Case #"<<cas<<": "<<res<<endl;
	}
	return 0;
}