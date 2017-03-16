#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

void solve();
void runCase();

int s[500];

void runCase()
{
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) scanf("%d",&s[i]);

    int M = (1<<20);
    map<int,int> cnt;
    for(int i = 1; i < M; i++) {
        int sum = 0;
        for(int j = 0; j < N; j++) {
            if(((1<<j)&i)) {
                sum += s[j];
            }
        }
        //cout << sum << endl;
        map<int,int>::iterator ite = cnt.find(sum);
        if(ite==cnt.end()) {
            cnt[sum] = i;
        } else {
            int c = ite->second;
            if(c&i) continue;
            printf("\n");
            for(int j = 0; j < N; j++) {
                if(((1<<j)&c)) {
                    printf("%d ",s[j]);
                }
            }
            printf("\n");
            for(int j = 0; j < N; j++) {
                if(((1<<j)&i)) {
                    printf("%d ",s[j]);
                }
            }
            printf("\n");
            return;
        }
    }
    printf("Impossible\n");
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
