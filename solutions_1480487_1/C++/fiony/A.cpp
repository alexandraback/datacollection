#include <bitset>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

const char* input_file = "A-large.in";
const char* output_file = "A-small.out";


int main()
{
	ifstream ifs(input_file,ios_base::in);
	ofstream ofs(output_file,ios_base::out);

	int num,n;
	ifs >> num;
	for(int i=0;i<num;i++)
	{
		ifs >> n;
		vector<int> arr(n);
		int total = 0;
		for(int j=0;j<n;j++)
		{
			ifs >> arr[j];
			total += arr[j];
		}
		double mean = total * 2.0 / n;
		double mean2 = 0;
		double total2 = total *  2.0;
		ofs << "Case #" << i+1 << ": ";
		int large = 0;
		for(int j=0;j<n;j++)
		{
			if(arr[j]>mean)
			{
				total2 -= arr[j];
				large++;
			}
		}
		if(large > 0)
			mean2 = total2 / (n - large);
		else
			mean2 = mean;

		for(int j=0;j<n;j++)
		{
			double per = 0;
			if(arr[j] >= mean)
				per = 0;
			else
				per = 100*(mean2-arr[j])*1.0/total;
			ofs.precision(8);			
			ofs.fixed;
			ofs << per <<" ";
		}
		ofs << endl;
	}

}