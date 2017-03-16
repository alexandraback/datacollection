#include<iostream>
#include<string>

using namespace std;

int L;
int X;

int flag;

string s;

int arr[4][4] = {{1,2,3,4},{2,-1,4,-3},{3,-4,-1,2},{4,3,-2,-1}};

int mul(int a, int b){
	int fact=1;
	if(a<0)	{
		fact=fact*-1;
		a = a*-1;	
	}
	if(b<0) fact=fact*-1; //never useful
	return (arr[a-1][b-1]*fact);
}

int main()
{
	int T;
	cin >> T;
	for(int test_case=0; test_case<T; test_case++){
		//input
		cin >> L;
		cin >> X;
		cin.get();
		getline(cin, s);
		
		flag=2;
			
		int val = 1;
		
		while(X--){
			for(int i=0; i<s.length(); i++){
				val = mul(val,s[i]-'i'+2);
				if(val == flag){
					flag = flag+1;
					val = 1;
					if(flag == 4)
						flag = 0;
				}
			}
		}	
	
		if(flag == 0 && val==4)
			flag = 1;
	
		//output
		if(flag == 1)
			cout << "Case #" << test_case+1 << ": YES" << endl;
		else
			cout << "Case #" << test_case+1 << ": NO" << endl;
	}
	return 0;
}
