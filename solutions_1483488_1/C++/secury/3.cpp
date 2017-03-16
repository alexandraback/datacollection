#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int get_digits(int n)
{
	int ten = 1, cnt = 0;
	while (ten <= n) ten *= 10, cnt++;
	return cnt;
}

int rotate_number(int n, int digits)
{
	int ten = 1;
	for (int i=0;i<digits-1;i++) ten*=10;

	int tail = n / ten;
	int head = n % ten;

	return head * 10 + tail;
}

int number_of_pairs(int A, int B, int n)
{
	int result = 0;
	int digits = get_digits(n);

	int i;
	int m = n;
	for (i=0;i<digits;i++){
		m = rotate_number(m, digits);
		if (m == n) break;
		if (A <= n && n < m && m <= B){
			result++;
		}
	}
	return result;
}

int main(int argc, char *argv[])
{
	if (argc != 2){
		cout << "Error!" << endl;
		return 1;
	}
	ifstream fin(argv[1]);
	if (fin.fail()){
		cout << "Error2!" << endl;
		return 1;
	}

	int T;
	fin >> T;
	int a;
	for (a=1;a<=T;a++){
		
		int A, B;
		fin >> A >> B;
		int n;
		int cnt = 0;
		for (n=A;n<=B;n++){
			cnt += number_of_pairs(A, B, n);
		}
		cout << "Case #" << a << ": ";
		cout << cnt << endl;
	}
	
	return 0;
}