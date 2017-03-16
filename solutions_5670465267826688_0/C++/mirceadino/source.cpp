#include<cstdio>
#include<algorithm>
#include<queue>

using namespace std;

typedef long long int lld;

int number_of_cases, testcase;

struct quaternion {
	char value;
	int sign;

	quaternion() {value = '1', sign = 1;}

	quaternion(char _value, int _sign) {value = _value, sign = _sign;}

	quaternion operator*(quaternion B) {
		quaternion C;

		if (value == '1' && B.value == '1') C = quaternion('1', 1 * sign * B.sign);
		if (value == '1' && B.value == 'i') C = quaternion('i', 1 * sign * B.sign);
		if (value == '1' && B.value == 'j') C = quaternion('j', 1 * sign * B.sign);
		if (value == '1' && B.value == 'k') C = quaternion('k', 1 * sign * B.sign);
		if (value == 'i' && B.value == '1') C = quaternion('i', 1 * sign * B.sign);
		if (value == 'i' && B.value == 'i') C = quaternion('1', -1 * sign * B.sign);
		if (value == 'i' && B.value == 'j') C = quaternion('k', 1 * sign * B.sign);
		if (value == 'i' && B.value == 'k') C = quaternion('j', -1 * sign * B.sign);
		if (value == 'j' && B.value == '1') C = quaternion('j', 1 * sign * B.sign);
		if (value == 'j' && B.value == 'i') C = quaternion('k', -1 * sign * B.sign);
		if (value == 'j' && B.value == 'j') C = quaternion('1', -1 * sign * B.sign);
		if (value == 'j' && B.value == 'k') C = quaternion('i', 1 * sign * B.sign);
		if (value == 'k' && B.value == '1') C = quaternion('k', 1 * sign * B.sign);
		if (value == 'k' && B.value == 'i') C = quaternion('j', 1 * sign * B.sign);
		if (value == 'k' && B.value == 'j') C = quaternion('i', -1 * sign * B.sign);
		if (value == 'k' && B.value == 'k') C = quaternion('1', -1 * sign * B.sign);

		return C;
	}

	bool operator==(quaternion B) {
		return (value == B.value && sign == B.sign);
	}

	void print(const char dupa[]) {
		if (sign == -1)
			printf("-");
		printf("%c%s", value, dupa);
	}
};

lld X;
int L;
char S[10005];
quaternion M[70005];
vector<int> I, K;

int main() {
	int i, sol = 0;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &number_of_cases);

	for (testcase = 1; testcase <= number_of_cases; testcase++) {
		scanf("%d%lld", &L, &X);
		scanf("%s", S + 1);

		M[0] = quaternion('1', 1);
		I.resize(0);
		K.resize(0);

		for (i = 1; i <= 7 * L; i++)
			M[i] = M[i - 1] * quaternion(S[(i % L) ? (i % L) : L], 1);

		int rest = X % 4;
		quaternion r('1', 1);

		for (i = 1; i <= rest; i++)
			r = r * M[L];

		sol = 0;

		if (r == quaternion('1', -1)) {
			if (rest + 4 <= X)
				rest += 4;
			else
				rest = X;

			for (i = 1; i <= rest * L; i++) {
				if (M[i] == quaternion('i', 1))
					I.push_back(i);
				if (M[i] == quaternion('k', 1))
					K.push_back(i);
			}

			for (auto i : I) {
				auto it = upper_bound(K.begin(), K.end(), i);
				if (it == K.end())
					break;

				sol = 1;
				break;
			}
		}

		printf("Case #%d: %s\n", testcase, sol ? "YES" : "NO");
	}

	return 0;
}