#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <sstream>

using namespace std;

string incr(string inp)
{
	bool carry = true;
	for(int i=inp.size() -1; i>=0; i--) {
		if(!carry) break; // else

		carry=false;
		switch(inp[i])
		{
			case '0':
				inp[i] = '1';
				break;
			case '1':
				inp[i] = '2';
				break;
			case '2':
				inp[i] = '3';
				break;
			case '3':
				inp[i] = '4';
				break;
			case '4':
				inp[i] = '5';
				break;
			case '5':
				inp[i] = '6';
				break;
			case '6':
				inp[i] = '7';
				break;
			case '7':
				inp[i] = '8';
				break;
			case '8':
				inp[i] = '9';
				break;
			case '9':
				inp[i] = '0';
				carry=true;
				break;
		}
	}
	return inp;
}

bool strlt(string A, string B)
{
	long int Ai, Bi;
	sscanf(A.c_str(), "%ld", &Ai);
	sscanf(B.c_str(), "%ld", &Bi);
	return Ai < Bi;
}

bool strle(string A, string B)
{
	long int Ai, Bi;
	sscanf(A.c_str(), "%ld", &Ai);
	sscanf(B.c_str(), "%ld", &Bi);
	return Ai <= Bi;
}

string rot(string A)
{
	char temp = A[A.size() - 1];
	A.erase(A.size() - 1, 1);
	A.insert(0, 1, temp);
	return A;
}

int main()
{
	int N;
	
	cin>>N;
	// Case-independent stuff?
	
	// Cases:
	for(int t=1; t<=N; t++)
	{
		// Each Case:
		int output=0;
		
		// random variables
		
		// input variables
		string A, B; cin>>A>>B;
		int num_rotates = A.size() -1;
		
		// compute
		while ( A != B ) // not done yet
		{
			string temp = A;
			map<string, bool> hackfix;
			hackfix[A] = true;
			for(int i=0; i<num_rotates; i++)
			{
				temp = rot(temp);
				if(hackfix[temp] == true) continue;
				if(strlt(A, temp) && strle(temp, B)) { // A < temp && temp <= B?
					output++;
					hackfix[temp] = true;
					//if( t == 4 )
					//	cout<<A<<"\t\t"<<temp<<endl;
				}
			}
			A = incr(A);
		}
		
		printf("Case #%d: %d\n", t, output);
	}
	return 0;
}
