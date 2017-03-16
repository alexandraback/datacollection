#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


bool Compare(int, int);

int main()
{
	int a, n;
	int i, j;
	int t;
	int min = 0;
	int table[102] = {0, };

	vector<int> mote;
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> t;
	for(i=0; i<t; i++)
	{
		mote.clear();
		in >> a >> n;
		for(j=0; j<n; j++){
			int temp;
			in >> temp;
			mote.push_back(temp);
		}
		stable_sort(mote.begin(), mote.end(), Compare);
		int cnt;
		for(j=0; j<n; j++){
			if(a <= mote[j]){
				if(a==1){
					table[j] = 10000;
				}else{
					cnt = 0;
					while(true){
						a+=a-1;
						cnt++;
						if(a > mote[j])break;
					}
					a+=mote[j];
					if(j==0)table[j] = cnt;
					else table[j] = table[j-1] + cnt;
				}
			}else{
				if(j==0)table[j] = 0;
				else table[j] = table[j-1];
				a+=mote[j];
			}
		}
		min = n;
		for(j=0; j<n; j++)
		{
			if(table[j] + n-j-1 < min){
				min = table[j] + n - j - 1;
			}
		}
		out << "Case #"<<i+1<<": "<<min<<endl;
	}
	return 0;
}

bool Compare(int q, int p)
{
	return q < p;
}