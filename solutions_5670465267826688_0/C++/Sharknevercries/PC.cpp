#include<bits\stdc++.h>
using namespace std;
long long X, L;
int T[4][4] = { { 1, 2, 3, 4 }, { 2, -1, 4, -3 }, { 3, -4, -1, 2 }, { 4, 3, -2, -1 } };
char str[10005];
inline int convert(char c){
	if (c == 'i')	return 2;
	if (c == 'j')	return 3;
	if (c == 'k')	return 4;
}
int mul(int a, int b){
	bool sign = a * b > 0;
	a = abs(a), b = abs(b);
	int res = T[a - 1][b - 1];
	if (!sign)
		res *= -1;
	return res;
}
bool solve(){
	bool repeat = true;
	for (int i = 1; str[i] != '\0'; i++)
		repeat &= str[i] == str[i - 1];
	if (repeat)	return false;
	long long leftCount, rightCount;
	int leftRes = convert(str[0]);
	int rightRes = convert(str[L - 1]);
	for (leftCount = 1; leftCount < X * L && leftRes != 2; leftCount++)
		leftRes = mul(leftRes, convert(str[leftCount % L]));
	leftCount--;
	if (leftRes != 2)	return false;
	for (rightCount = X * L - 2; rightCount >= 0 && rightRes != 4; rightCount--)
		rightRes = mul(convert(str[rightCount % L]), rightRes);
	rightCount++;
	if (rightRes != 4)	return false;
	if (leftCount >= rightCount)	return false;
	int midRes = convert(str[0]);
	for (int i = 1; i < L; i++)	midRes = mul(midRes, convert(str[i]));
	int remainX = rightCount / L - leftCount / L - 1;
	if (remainX >= 0){
		if (abs(midRes) != 1){
			if (remainX % 4 == 0)	midRes = 1;
			if (remainX % 4 == 1)	midRes = midRes;
			if (remainX % 4 == 2)	midRes = -1;
			if (remainX % 4 == 3)	midRes = -midRes;
		}
		else if (midRes == -1){
			if (remainX % 2 == 0)	midRes = 1;
			if (remainX % 2 == 1)	midRes = -1;
		}
		for (int i = L - 1; i > leftCount % L; i--)
			midRes = mul(convert(str[i]), midRes);
		for (int i = 0; i < rightCount % L; i++)
			midRes = mul(midRes, convert(str[i]));
	}
	else{
		midRes = 1;
		for (int i = leftCount + 1; i < rightCount; i++)
			midRes = mul(midRes, convert(str[i]));
	}
	return midRes == 3;
}
int main(){
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t, c = 1;
	scanf("%d", &t);
	while (t--){
		scanf("%lld%lld", &L, &X);
		scanf("%s", str);
		printf("Case #%d: %s\n", c++, solve() ? "YES" : "NO");
	}
	return 0;
}