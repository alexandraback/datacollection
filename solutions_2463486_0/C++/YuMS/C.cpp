#include <iostream>
#include <string>

const int scale = 39;
std::string numbers[] = 
{
"1"
, "4"
, "9"
, "121"
, "484"
, "10201"
, "12321"
, "14641"
, "40804"
, "44944"
, "1002001"
, "1234321"
, "4008004"
, "100020001"
, "102030201"
, "104060401"
, "121242121"
, "123454321"
, "125686521"
, "400080004"
, "404090404"
, "10000200001"
, "10221412201"
, "12102420121"
, "12345654321"
, "40000800004"
, "1000002000001"
, "1002003002001"
, "1004006004001"
, "1020304030201"
, "1022325232201"
, "1024348434201"
, "1210024200121"
, "1212225222121"
, "1214428244121"
, "1232346432321"
, "1234567654321"
, "4000008000004"
, "4004009004004"
};
int comp(std::string &A, std::string &B) {
	if (A.length() < B.length()) {
		return -1;
	} else if (A.length() > B.length()) {
		return 1;
	} else return A.compare(B);
}
int main() {
	int T;
	std::cin >> T;
	std::string A, B;
	int ans;
	bool inRange;
	for (int i = 0; i < T; i++) {
		std::cin >> A >> B;
		ans = 0;
		inRange = false;
		for (int j = 0; j < scale; j++) {
			//std::cout << numbers[j] << ' ' << comp(numbers[j], A) << ' ' << comp(numbers[j], B) << "\n";
			if (comp(numbers[j], B) > 0) {
				break;
			}
			if (!inRange) {
				if (comp(numbers[j], A) >= 0) {
					inRange = true;
				}
			}
			if (inRange) {
				ans++;
			}
		}
		std::cout << "Case #" << i + 1 << ": " << ans << "\n";
	}
	return 0;
}
