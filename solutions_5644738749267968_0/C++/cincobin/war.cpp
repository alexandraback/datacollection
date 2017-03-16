#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("warsmall.in", std::ifstream::in);
    fout.open("warsmall.out", std::ifstream::out);
    int count;
    fin>>count;
    for(int i = 0; i < count; i++)
    {
        int n;
        fin>>n;
        vector<double> ken(n);
        vector<double> naoshi(n);
        for(int j = 0; j < n; j++)
            fin>>naoshi[j];
        for(int j = 0; j < n; j++)
            fin>>ken[j];

        sort(ken.begin(), ken.end());
        sort(naoshi.begin(), naoshi.end());
		int result1 = 0;
        int bottom = 0;
        int top = n-1;
        int result2 = 0;
		int tmp = n-1;
        for(int k = n-1; k >= 0; k--)
        {
			while(tmp >= 0 && naoshi[tmp] > ken[k])
				tmp--;
			if(tmp >= 0)
			{
				result2 ++;
				tmp --;
			}
        }
		bottom = 0;
		for(int j = 0; j < n; j++)
		{
			for(int k = bottom; k < n; k++)
			{
				if(naoshi[j] > ken[k])
				{
					result1++;
					bottom=k+1;
					break;
				}
			}
		}
        fout<<"Case #"<<i+1<<": "<<result1<<" "<<n-result2<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}
