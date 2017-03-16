#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int nums[12] = { 0, 2, 8, 3, 6, 7, 4, 5, 9, 1 };

//int arr[MX] ;
string strNums[13] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };

//zero// two //// eight // three // six//   seven // four // five // nine // one
char letters[15] = "ZWGHXSUVIO";

int remains;

int cA[300];

void mainF(int x){
	for (int j = 0; j< strNums[x].size(); j++)
	{
		cA[strNums[x][j]]--;
		if (cA[strNums[x][j]] == 0)
		{
			remains--;
		}
	}
}
int main(){

	//freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
	ifstream in("A-large.in"); 
	ofstream out("output.txt");
	int caseNum = 0, testIndex = 1;
	in >> caseNum;
	while (caseNum--)
	{
		out << "Case #";
		out<<to_string(testIndex++);
		out << ": ";
		string caseString;
		in >> caseString;
		memset(cA, 0, sizeof(cA));
		for (int j = 0; j < caseString.size(); j++)
		{
			cA[caseString[j]]++;
		}
		remains = 0;
		for (int j = 0; j < 300; j++)
		{
			if (cA[j])
			{
				remains++;
			}
		}

		vector <int> vec;
		for (int j = 0; j<10; j++)
		{
			while (cA[letters[j]])
			{
				vec.push_back(nums[j]);
				mainF(nums[j]);
			}
		}

		sort(vec.begin(), vec.end());
		for (int j = 0; j < vec.size(); j++)
		{
			out<<vec[j];
		}

		out << endl;
	}

}