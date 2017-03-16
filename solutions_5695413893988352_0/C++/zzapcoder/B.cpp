#include"tmp.h"



ull tp(ull i) {
	//0 ~ 18
	ull ret = 1;
	for (int j = 0; j < i; ++j) {
		ret *= 10ull;
	}
	return ret;
}

ull getDiff(ull c, ull j) {
	if (c > j) return c - j;
	else return j - c;
}
ull getDiff(pair<ull, ull> p) {
	return getDiff(p.second, p.first);
}

tuple<ull, ull, ull> ansTie(pair<ull, ull> p) {
	return make_tuple(getDiff(p), p.first, p.second);
}
tuple<ull, ull, ull> ansTie(ull c, ull j) {
	return make_tuple(getDiff(c,j), c,j);
}


pair<string,string> makeans(string c, string j) {
	string cans, jans;
	int n = c.size();
	ull cVal=0, jVal=0;

	for (int i = 0; i < n; ++i) {
		if (c[i] == '?' || j[i] == '?' || c[i] == j[i])
			continue;

		int i_ = n - 1 - i;
		cVal += tp(i_) * (c[i] - '0');
		jVal += tp(i_) * (j[i] - '0');
	}

	//cout << cVal << ' ' << jVal << endl;

	for (int i = 0; i < n; ++i) {
		int i_ = n - 1 - i;

		if (c[i] != '?' && j[i] != '?') {
			continue; // 둘다 숫자가 차 있는 건, 이미 위에서 숫자를 추가했습니다.
		}

		// 일단 둘이 다른거 확정임 cVal == jVal 같은 순간은 절대 찾아오지 않음
		if (i == n-1) {
			if (cVal < jVal) {
				if (c[i] == '?') c[i] = '9';
				if (j[i] == '?') j[i] = '0';
			}
			else {
				if (c[i] == '?') c[i] = '0';
				if (j[i] == '?') j[i] = '9';
			}
			cVal += tp(i_) * (c[i] - '0');
			jVal += tp(i_) * (j[i] - '0');
			continue;
		}

		if (c[i] == '?' && j[i] == '?') {
			// 이미 결정났는지 확인합니다.
			if (getDiff(cVal, jVal) / tp(i_)) {
				if (cVal > jVal) {
					c[i] = '0';
					j[i] = '9';
				}
				else {
					c[i] = '9';
					j[i] = '0';
				}
			}
			else { // 아직 결정나지 않았습니다.
				if (getDiff(cVal, jVal)  <= 5 * tp(i_ - 1)) { // 크기가 많이 차이나지 않는다면 둘다 똑같은 값을 주는 것이 좋습니다.
					c[i] = '0';
					j[i] = '0';
				}
				else if (cVal > jVal) {
					c[i] = '0';
					j[i] = '1';
				}
				else {
					c[i] = '1';
					j[i] = '0';
				}
			}
		}
		else if (c[i] == '?') {


			// 이미 결정났는지 확인합니다.
			if (getDiff(cVal, jVal) / tp(i_)) {
				if (cVal > jVal) {
					c[i] = '0';
				}
				else {
					c[i] = '9';
				}
			}
			else { // 아직 결정나지 않았습니다.
				if (getDiff(cVal, jVal) == 5 * tp(i_ - 1)) {
					c[i] = max((char)(j[i] - 1), '0');
				}
				else if (getDiff(cVal, jVal) < 5 * tp(i_ - 1)) { // 크기가 많이 차이나지 않는다면 둘다 똑같은 값을 주는 것이 좋습니다.
					c[i] = j[i];
				}
				else if (cVal > jVal) { // c에게 j보다 작은 값을
					c[i] = max((char)(j[i]-1), '0');
				}
				else { // j보다 큰 값을
					c[i] = min((char)(j[i]+1), '9');
				}
			}


		}
		else { // j[i] == '?'

			   // 이미 결정났는지 확인합니다.
			if (getDiff(cVal, jVal) / tp(i_)) {
				if (cVal > jVal) {
					j[i] = '9';
				}
				else {
					j[i] = '0';
				}
			}
			else { // 아직 결정나지 않았습니다.
				if (getDiff(cVal, jVal) == 5 * tp(i_ - 1)) {
					j[i] = max((char)(c[i] - 1), '0');
				}
				else if (getDiff(cVal, jVal) < 5 * tp(i_ - 1)) { // 크기가 많이 차이나지 않는다면 둘다 똑같은 값을 주는 것이 좋습니다.
					j[i] = c[i];
				}
				else if (cVal > jVal) { // j에게 c보다 큰 값을
					j[i] = min((char)(c[i] + 1), '9');
				}
				else {
					j[i] = max((char)(c[i] - 1), '0');
				}
			}

		}
		cVal += tp(i_) * (c[i] - '0');
		jVal += tp(i_) * (j[i] - '0');
	}

	return make_pair(c,j);
}



int main() {

	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B-small-attempt1.out", "w", stdout);
	cin.sync_with_stdio(false);
	int TC; cin >> TC;

	for (int tc = 1; tc <= TC; ++tc) {
		string c, j;
		cin >> c >> j;
		int n = c.size();

		bool canBeSame = true;
		bool cIsBiggerInFixedPart = false;
		bool isFirstDiff = true;
		int firstDiff = -1;
		for (int i = 0; i < n; ++i) {
			if (c[i] != '?' && j[i] != '?') {
				if (c[i] != j[i]) {
					canBeSame = false;
					if (isFirstDiff) {
						cIsBiggerInFixedPart = c[i] > j[i];
						isFirstDiff = false;
						firstDiff = i;
					}
				}
			}
		}

		
		
		string cAns = "", jAns = "";
		if (canBeSame) {
			string ans = "";
			for (int i = 0; i < n; ++i) {

				if (c[i] == '?' && j[i] == '?') {
					ans += "0";
				}
				else if (c[i] != '?') {
					ans += c[i];
				}
				else {
					ans += j[i];
				}
			}
			cAns = jAns = ans;
			cout << "Case #" << tc << ": " << cAns << ' ' << jAns << endl;
		}
		else {
			tie(cAns, jAns) = makeans(c, j);

			cout << "Case #" << tc << ": " << cAns << ' ' << jAns << endl;
		}

	}
	return 0;
}