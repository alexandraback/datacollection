#include<iostream>
#include<string.h>
//#include<conio.h>

using namespace std;

int Smax;
//int s[1001];
int Answer;
string s;

int main()
{
	int T;
	int Temp=0;
	cin >> T;
	for(int test_case=0; test_case<T; test_case++){
		cin >> Smax;
		/*for(int i=0; i<=Smax; i++){
			cin >> s[i];
		}*/
		cin.get();
		getline(cin, s);
		//cout << "String taken :" << s << ":" << endl;
		Answer = 0;
		int sum = 0;
		int i = 0;
		while(i<=Smax){
			if(s[i] > '0'){
			if((sum+Answer) < i){
				Answer = i - sum;
				//cout << "Answer made " << Answer << "i is " << i << "sum is " << sum << endl;
				continue;
			} else {
				sum = sum + s[i] - '0';
				//cout << "sum is " << sum << "s[i] is " << s[i] << endl;
				i++;
			}
		} else {
			i++;
		}
		}
		cout << "Case #" << test_case+1 <<": ";
		cout << Answer << endl;
	}
	return 0;
}
