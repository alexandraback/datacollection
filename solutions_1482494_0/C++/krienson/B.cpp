/*
*  Javier Segovia
*  0.016
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair

int main(){
	int T,N;
	cin>>T;
	for (int kases = 1; kases <= T ; kases++) {
		cin>>N;
		vector<pair<int,int> > vpi;
		vector<int> visited(N,0);
		int a,b;
		for (int i=0; i<N ; i++) {
			cin>>a>>b;
			vpi.PB(MP(a,b));
		}
		sort(vpi.begin(),vpi.end());
		int ac_stars = 0,steps = 0,completed = 0;
		while (completed < N ) {
			bool ok = false;
			for (int i=0; i<N ; i++) { // full direct missions
				if(visited[i] == 0 && ac_stars >= vpi[i].second){ //cout<<"1 "<<ac_stars<<endl;
					//cout<<"I: "<<i<<" -> "<<vpi[i].first<<","<<vpi[i].second<<" -> completed direct"<<endl;
					ac_stars += 2;
					visited[i] = 2;
					steps++;
					completed++;
					ok=true;
				}
			}
			if(ok) continue;
			for (int i=0; i<N ; i++) {// partial initiated missions
				if(visited[i] == 1 && ac_stars>=vpi[i].second){ //cout<<"3 "<<ac_stars<<endl;
					ac_stars++;
					visited[i] = 2;
					steps++;
					completed++;
					ok=true;
					break;
				}
			}
			if(ok) continue;
			/*for (int i=0; i<N ; i++) { // full semidirect missions
				if(visited[i] == 0 && ac_stars >= vpi[i].first && (ac_stars+1) >= vpi[i].second){  cout<<"2 "<<ac_stars<<endl;
					//cout<<"I: "<<i<<" -> "<<vpi[i].first<<","<<vpi[i].second<<" -> completed semidirect"<<endl;

					ac_stars += 1;
					visited[i] = 1;
					steps++;
					//completed++;
					ok=true; break;
				}
			}
			
			if(ok) continue;*/
			for (int i=N-1; i>=0 ; i--) {// non initiated missions
				if(visited[i] == 0 && ac_stars>=vpi[i].first ){ //cout<<"4 "<<ac_stars<<endl;
					ac_stars++;
					visited[i] = 1;
					steps++;
					ok=true;
					break;
				}
			}
			if(!ok) break;
		}
		
		if(completed == N) cout<<"Case #"<<kases<<": "<<steps<<endl;
		else cout<<"Case #"<<kases<<": Too Bad"<<endl;
	}
}