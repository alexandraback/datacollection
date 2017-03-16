#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

void solve();
void runCase();

void runCase()
{
    int N,X=0;
    cin >> N;
    vector<int> s(N),js(N);
    for(int i = 0; i < N; i++) {
        cin >> s[i];
        X += s[i];
    }
    js = s;
    sort(s.begin(),s.end());

    double ok = (X*2.0)/N;
    for(int i = 0; i < N-1; i++) {
        double sum = 0;
        for(int j = 0;j <=i; j++) {
            sum += s[j];
        }
        sum += X;
        sum /= (i+1);
        if(sum <= 1.0*s[i+1]) {
            ok = sum;
            break;
        }
    }

    s = js;
    for(int i = 0; i < N; i++) {
        double res = 0;
        res = 100.0*(ok-s[i])/X;
        if(res<0) res = 0;
        if(i==N-1) printf("%lf\n",res);
        else printf("%lf ",res);
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
		printf("Case #%d: ",i+1);
		runCase();
		//runSample();
	}
}

int main()
{
	solve();
	return 0;
}
