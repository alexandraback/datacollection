#include "iohelper.h"
#include <set>
#include <sstream>
#include <algorithm>
using namespace std;

vector<string> result2;

void readFunc2(ifstream& in)
{
	int N;
	in>>N;
	vector<double> naomis;
	vector<double> kens;
	for(int i = 0;i < N;i++)
	{
		double wei;
		in>>wei;
		naomis.push_back(wei);
	}
	for(int i = 0;i < N;i++)
	{
		double wei;
		in>>wei;
		kens.push_back(wei);
	}
	sort(naomis.begin(),naomis.end());
	sort(kens.begin(),kens.end());
	int t = 0;
	for(t = 0;t < N && naomis[N-1] <= kens[N-1-t];t++);
	int count1 = 0;
	int l = t,r = 0;
	for(r = 0;l < N && r < N-t;r++)
	{
		if(naomis[l] > kens[r]){
			l++;
			count1++;
		}
		else{
			while(l < N && naomis[l] <= kens[r])
			{
				l++;
			}
			if(l < N && naomis[l] > kens[r])
			{
				l++;
				count1++;
			}
		}
	}
	int count2 = 0;
    l = 0;
	r = 0;
	for(l = 0;l < N && r < N;l++)
	{
		if(naomis[l] < kens[r]) r++;
		else{
			while(r < N && kens[r]<naomis[l])
			{
				count2++;
				r++;
			}
			if(r < N && naomis[l] < kens[r]) r++;
		}
	}
	stringstream ss("");
	ss<<count1<<' '<<count2;
	result2.push_back(ss.str());
}

int main()
{
	IOHelper io;
	io.readFile("D-small-attempt0.in",readFunc2);
	io.writeFile("D-small-attempt0.out",result2);
	return 0;
}