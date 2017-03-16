#include <fstream>
#include <math.h>
#include <vector>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

__int64 a, b;
vector<__int64> dap;


int intleng(__int64 num)
{
	int count = 0;
	while(num!=0){
		num/=10;
		count++;
	}
	return count;
}

bool chk(__int64 num, int leng)
{
	int i;
	char toString[100];
	for(i=0; i<leng; i++){
		toString[i] = num%10;
		num/=10;
	}
	for(i=0; i<leng/2; i++){
		if(toString[i] != toString[leng-i-1])return false;
	}
	return true;
	
}

int main()
{
	int t;
	int count = 0;
	int leng;
	__int64 temp;
	in >> t;

	for(__int64 i = 1; i<=10000000; i++){
		leng = intleng(i);
		if(!chk(i, leng))continue;
		temp = i * i;
		leng = intleng(temp);
		if(!chk(temp, leng))continue;
		dap.push_back(temp);
	}

	for(int i = 0; i < t; i++)
	{
		count = 0;
		in >> a >> b;
		for(vector<__int64>::iterator it = dap.begin(); it!=dap.end(); ++it){
			if( a<=(*it) && (*it)<=b){
				count++;
			}
		}
		out <<"Case #"<<i+1<<": "<< count << endl;
	}
	return 0;
}