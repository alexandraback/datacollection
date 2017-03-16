#include<iostream>

using namespace std;



int main() {
	int cnt;
	cin >> cnt;
	for (int itr = 0; itr < cnt; itr++)
	{
		cout << "Case #" << itr + 1 << ": ";
		char* input = new char[1000];
		cin >> input;
		int leng = strlen(input);
		char* stackf = new char[1000];
		int idxf = 0;
		char* stacke = new char[1000];
		int idxe = 0;
		for (int i = 0; i < leng; i++)
		{
			if (i == 0) {
				stackf[idxf] = input[i];
				idxf++;
			}
			else {
				if (input[i] >= stackf[idxf - 1]) {
					stackf[idxf] = input[i];
					idxf++;
				}
				else {
					stacke[idxe] = input[i];
					idxe++;
				}
			}
		}
		for (int i = 0; i < idxf; i++)
		{
			cout << stackf[idxf - 1 - i];
		}
		for (int i = 0; i < idxe; i++)
		{
			cout << stacke[i];
		}
		cout << endl;
	}
	return 0;
}