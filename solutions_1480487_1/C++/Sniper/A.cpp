#include <vector>
#include <iostream>
using namespace std;

const double eps = 1e-8;

double judge(int id, int X, const vector<int>& points){
	double l = 0, r = 1;
	while(r-l>eps){
		double m = (l+r)/2;
		double score = points[id] + m*X;
		double sum = m;
		for(int i =0;i<points.size();++i){
			if(i == id)	continue;
			if(points[i] < score){
				double ratio = (score - points[i])/X;
				sum += ratio;
				if(sum > 1)	break;
			}	
		}
		if(sum > 1){
			r = m;
		} else {
			l = m;
		}
	}
	return l;
}

int main(){
	int T;
	cin >> T;
	for(int t=1;t<=T;++t){
		int N;
		cin >> N;
		vector<int> points;
		points.clear();
		int X = 0;
		for(int i=0;i<N;++i){
			int p;
			cin >> p;
			X += p;
			points.push_back(p);
		}
		cout<<"Case #"<<t<<":";
		for(int i=0;i<N;++i){
			double ratio = judge(i,X,points);
			cout<<" "<<ratio*100;
		}
		cout<<endl;
	}
}
