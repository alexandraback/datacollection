#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;
void main(){
	int T,N;
	double s[200];
	double y[200];
	bool flag[200];
	ifstream cin("A-large (1).in");
	ofstream cout("test.txt");
	cin >> T;
	for(int i = 0; i < T; i++){
		cin >> N;
		memset(s,0,sizeof(s));
		memset(y,0,sizeof(y));
		memset(flag,true,sizeof(flag));
		double x = 0.0,dx = 0.0;double max = -1;int key = 0;
		int tds = 0;
		for(int j = 0; j < N; j++){
			cin >> s[j];
			x+=s[j];
			if(s[j] > max){
				max = s[j];
				key = j;
			}
		}
		while(true){
			for(int j = 0; j < N; j++){
				if(flag[j]){
					y[j] = s[key]-s[j];
					dx+=y[j];
				}
			}
			if((x-dx)<0){
				y[key] = 0;
				flag[key] = false;
				tds++;
				max = -1.0;dx = 0.0;
				for(int j = 0; j < N; j++){
					if(flag[j]&&(s[j] > max)){
						max = s[j];
						key = j;
					}
				}
			}
			else break;
		}

		for(int j = 0; j < N; j++){
			if(flag[j])y[j]+=(x-dx)/(N-tds);
		}
		cout << "Case #"<<i+1<<": ";
		for(int j = 0; j < N; j++){
			double temp =0.0;
			temp = (double)(y[j]*100)/(double)x;
			cout << setiosflags(ios::fixed)<<setprecision(6)<<temp;
			if(j != N-1)cout << " ";
		}
		cout << endl;
		
	}
	system("pause");
}