#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
int nStar, searchVal;

struct KR {
	int idx;
	int starVal;
	int starReq;
	int starReq2;
};
bool sort_req(KR a, KR b)
{
	return (a.starReq2 > b.starReq2);
}

bool sort_star(KR a, KR b)
{
	return (a.starVal > b. starVal);
}

bool lessThanCurrStar( KR a)
{
	return(a.starReq <= nStar);
}

bool isSame(KR a)
{
	return (a.idx == searchVal);
}

int main(int argc, char * argv[])
{
	ifstream fin("input.txt"); 
	if(!fin.good())
	{
		cout << "opps" << endl;
	}
	string str;
	getline(fin, str);
	istringstream iss(str);
	int nCaseCount;
	iss>>nCaseCount;	

	ofstream fout("output.txt");
	for( int aaa = 0; aaa < nCaseCount ; aaa++)
	{
		getline(fin, str);
		int N;
		istringstream iss3(str);
		iss3 >> N;

	vector<KR> miss_req;
	miss_req.reserve(N);
		for(int bbb = 0; bbb < N ; bbb++)
		{
			getline(fin,str);
			istringstream iss2(str);
			int tempa, tempb;
			iss2 >> tempa; iss2 >>tempb;
			KR tempKR;
			tempKR.idx = bbb; tempKR.starVal = 1; tempKR.starReq = tempa; tempKR.starReq2 = tempb;
			miss_req.push_back(tempKR);
			tempKR.idx = bbb; tempKR.starVal = 2; tempKR.starReq = tempb; tempKR.starReq2 = tempb;
			miss_req.push_back(tempKR);	
		}
		bool flag = true; int turns = 0; bool succ=true;
		nStar = 0;

		stable_sort(miss_req.begin(), miss_req.end(), sort_req);
		stable_sort(miss_req.begin(), miss_req.end(), sort_star);

		while(flag)
		{
			stable_sort(miss_req.begin(), miss_req.end(), sort_star);
			for(vector<KR>::iterator it = miss_req.begin(); it<miss_req.end(); it++)
{		
		cout << it->idx << " ";	
}
			vector<KR>::iterator idx = find_if(miss_req.begin(), miss_req.end(), lessThanCurrStar);
			if(idx == miss_req.end())
			{
				succ = false;
				break;
			}
			int starvalue = idx->starVal;
			searchVal = idx->idx;
			turns++;
			miss_req.erase(idx);
			if(starvalue ==2)
			{
				vector<KR>::iterator idx2 = find_if(miss_req.begin(), miss_req.end(), isSame);
	
				if(idx2 == miss_req.end())
				{
				cout << "UP once" ;
					nStar++;
				}
				else{
					nStar+=2;
				miss_req.erase(idx2);
				}
			}
			else
				nStar++;

			cout << nStar<<endl;	
			if(!miss_req.size())
				flag = false;
	
		}
		cout << endl << endl;
		if(succ)	
			fout << "Case #" << aaa+1 << ": " << turns << endl;	
		else
			fout << "Case #" << aaa+1 << ": Too Bad" << endl;	

	}
	fin.close(); fout.close();
	return 0;
}
