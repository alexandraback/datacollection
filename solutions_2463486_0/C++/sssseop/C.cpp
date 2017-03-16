#include <fstream>
#include <math.h>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int a, b;
int visit[1001] = {0,};

bool chk(int a)
{
	if(a/10 == 0){
		return true;
	}
	else if (a/100 == 0){
		if(a / 10 == a % 10)return true;
		else return false;
	}
	else if( a/1000 == 0){
		if(a/ 100 == a%10)return true;
		return false;
	}
	return false;
}
int main()
{
	int t;
	int count = 0;
	in >> t;

	for(int i = 1; i<=1000; i++){
		int sq = sqrt((double)i);
		if(sq * sq != i)continue;
		if(!chk(i) || !chk(sq))continue;
		visit[i] = 1;
	}

	for(int i = 0; i < t; i++)
	{
		count = 0;
		in >> a >> b;
		for(int j = a; j<=b; j++) count +=visit[j];
		out <<"Case #"<<i+1<<": "<< count << endl;
	}
	return 0;
}