#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

#define cin fin
#define cout fout
#define double long double
bool have = true;
int *nexthaha;
double ans = 0;
int K, L, S, p[111][111];
double f[110][110];
string kb, out;
void findNext(string temp)
{
	nexthaha[0] = -1;
	int i = 0;
	int j = -1;

	while (i < temp.length())
	{
		if (j == -1 || temp[i] == temp[j])          // (2)
		{
			i++;
			j++;
			nexthaha[i] = j;
		}
		else
			j = nexthaha[j];
	}
}
double solve(){
	string tmp = "";
	memset(p, 0, sizeof(p));
	for (int i = 0; i <= L; ++i){
		for (int j = 0; j < K; ++j){
			string now = tmp + kb[j];
			//	cout<<now<<endl;
			int nxt = 0;
			for (int k = i + 1; k >= 1; --k){
				bool ok = 1;
				int pos = i + 1 - k;
				for (int l = 0; l<k; ++l)
					if (now[pos + l] != out[l])
						ok = 0;
				if (ok){
					nxt = k;
					break;
				}
			}
			p[i][nxt]++;
			//	printf("%d %d %d\n",i,j,nxt);
		}
		tmp += out[i];
	}
	memset(f, 0, sizeof(f));
	f[0][0] = 1;
	for (int i = 0; i<S; ++i)
		for (int j = 0; j <= L; ++j)
			for (int k = 0; k <= L; ++k)
				f[i + 1][k] += f[i][j] * p[j][k] / K;
	double ans = 0;
	for (int i = 0; i <= S; ++i)ans += f[i][L];
	return ans;
}
int main() {
	ifstream fin("haha.in");
	ofstream fout("output.out");
	int T;
	cin >> T;
	for (int i = 0; i<T; i++) {
		cin >> K >> L >> S;
		cin >> kb >> out;
		have = true;
		if (L > S)
		{
			have = false;
		}
		for (int j = 0; j < out.length(); j++)
		{
			bool haha = false;
			for (int k = 0; k < kb.length(); k++)
			{
				if (out[j] == kb[k])
					haha = true;
			}
			if (haha == false)
			{
				have = false;
				break;
			}
		}
		if (have == false)
		{
			ans = 0;
			cout << "Case #" << i + 1 << ": " << ans << endl;
			continue;
		}
		nexthaha = new int[out.length()];
		int houzhuichangdu = 0;
		findNext(out);
		ans = (S - L) / (L - nexthaha[out.length() - 1]-1) + 1;
		cout << "Case #" << i + 1 << ": " << (double)ans-solve() << endl;
	}
	fin.close();
	fout.close();
	system("pause");
	return 0;
}
