#include <iostream>
#include <iomanip>

using namespace std;

int *s;

int main(){
	int T;
	cin >> T;
	for(int i = 1; i <= T; i++){
		int N;	//contestants
		cin >> N;
		s = new int [N];	//judges
		int x = 0;
		for(int j = 0; j < N; j++){
			cin >> s[j];
			x += s[j];
		}
		std::cout << std::setprecision(6) << std::fixed;
		cout << "Case #" << i << ":";
		double *m = new double [N];
		double neg = 0.0;
		int cnt = 0;
		for(int j = 0; j < N; j++){
			m[j] = 100.0*(double)(2*x - N*s[j])/(double)(N*x);
			if (m[j] < 0.0)	{
				neg += m[j];
				m[j] = 0.000000;
			}else cnt++;
		}
		//cout << "cnt " << cnt << " neg: " << neg << endl;
		if (cnt > 0)	neg = neg/(double)cnt;
		else neg = 0.0;
		for(int j = 0; j < N; j++){
			if(m[j] > 0.0)	cout << " " << m[j] + neg;
			else cout << " " << m[j];
		}
		cout << endl;
		delete [] m;
		delete [] s;
	}
	return 0;
}
