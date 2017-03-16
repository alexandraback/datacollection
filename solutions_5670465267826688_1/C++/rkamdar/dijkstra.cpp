#include<iostream>
#include<string>
#include<conio.h>

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

void print(int val){
	if(val < 0)	{
		cout <<"-";
		val = val*-1;
	}
	switch(val){
		case 1:
			cout << "1 ";
			break;
		case 2:
			cout << "i ";
			break;
		case 3: cout << "j ";
				break;
		case 4: cout << "k ";
				break;
	}
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
		
		int val = 1;
		
		for(int i=0; i<s.length(); i++){
			val = mul(val,s[i]-'i'+2);
		}
		
		if((val == 1) || (val == -1 && X%2==0) || (X%4 != 2 && val != -1)){
			flag = 0;
		} else {
		
		flag=2;
		
		val = 1;
		
		int count=0;
		
		while(X--){
			if(flag == -1)
				break;
			for(int i=0; i<s.length(); i++){
				if(count > 4*L){
					flag = -1;
					break;
				}
				count++;
				val = mul(val,s[i]-'i'+2);
				if(val == flag){
					flag = flag+1;
					val = 1;
					count = 0;
					if(flag == 5){
						flag = 0;
						X = X%4;
					}
				}
			}
		}
		if(flag == 0 && val == 1){
			flag = 1;
		}
		/*
		while(X--){
			for(int i=0; i<s.length(); i++){
				val = mul(val,s[i]-'i'+2);
				print(val);
				getch();
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
		*/
		}
		//output
		if(flag == 1)
			cout << "Case #" << test_case+1 << ": YES" << endl;
		else
			cout << "Case #" << test_case+1 << ": NO" << endl;
	}
	return 0;
}
