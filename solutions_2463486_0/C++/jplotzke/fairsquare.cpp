#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

const long long UPPER = 1000;
const int N = 1000;

bool is_pal(const long long & num){
	stringstream ss; ss << num;
	string str; ss >> str;
	for (int x = 0; x < str.length()/2; ++x)
		if (str[x] != str[str.length()-1-x])
			return false;
	return true;
}

int get_count(const long long sqpal[], const int & count, const long long & upper){
	int low = 0, high = count;
	while (low < high){
		int mid = (low + high) / 2;
		if (sqpal[mid] < upper) low = mid + 1;
		else if (sqpal[mid] > upper) high = mid;
		else return mid + 1;
	}
	return low;
}

int main(){
	freopen("fairsquare.in", "r", stdin);
	freopen("fairsquare.out", "w", stdout);
	int run, count, ans; long long sqpal[N], num, sq, lower, upper;
	for (count = 0, num = 1; true; ++num){
		if ((sq = num * num) > UPPER) break;
		if (is_pal(num) && is_pal(sq))
			sqpal[count++] = sq;
	}
	cin >> run;
	for (int a = 1; a <= run; ++a){
		cin >> lower >> upper;
		ans = get_count(sqpal, count, upper) - get_count(sqpal, count, lower-1);
		cout << "Case #" << a << ": " << ans << endl;
	}
	return 0;
}
