#include <iostream>
#include <vector>

using namespace std;

 
class Solution
{
public:
	vector<vector<int> > getComb(vector<int> vals, int n, int S)
	{
		vector<vector<int> > result;
		vector<int> singleComb;
		if(n == 0 || S == 0) return result;
 
		resultArr = new vector<vector<int> >[S+1];
 
		//Initialize DP Array
		resultArr[0].push_back(singleComb);
 
		//Run DP Array
		for(int i = 0; i < n; ++i) {
			for(int s = 0; s <= S; ++s) {
				if(s >= vals[i])
					combineResult(resultArr[s], resultArr[s-vals[i]], vals[i]);
			}
		}
 
		result = resultArr[S];
		delete [] resultArr;
		return result;
	}
 
private:
	vector<vector<int> > *resultArr;

	void combineResult(vector<vector<int> > &dest, const vector<vector<int> > &src, int number)
	{
		int size = src.size();
		vector<int> singleRes;
		for(int i = 0; i < size; ++i) {
			singleRes = src[i];
			singleRes.push_back(number);
			dest.push_back(singleRes);
		}
	}
};
 
bool solve(vector<int> coinvalue, int limit){

	Solution so;
	vector<int> vals;
	for(int i=0; i <limit;i++){
		vals.push_back(i+1);
	}
	vector<vector<int> > result = so.getComb(vals, vals.size(), limit);
	for(int i = 0; i < result.size(); ++i){
		vector<int> result_var;
		result_var.resize(limit);
		for(int j = 0; j < result[i].size(); ++j){
			result_var[result[i][j]-1]++ ;
		}
		bool answer = true;
		for(int k = 0; k < limit; ++k){
			if(coinvalue[k]<result_var[k]){
				answer = false;
				break;
			}
		}
		if(answer == true){
			return true;
		}
	}
	return false;
	

}

int main(){
	int cases;
	cin>>cases;
	for(int t =0;t<cases;t++){
		int numbercopy,coin,limit,answer=0;
		cin>>numbercopy>>coin>>limit;
		vector<int> coinvalue;
		coinvalue.resize(limit);
		for(int i=0;i<limit;i++){
			coinvalue[i]=0;
		}
		for(int i=0;i<coin;i++){
			int temp;
			cin>>temp;
			coinvalue[temp-1] = numbercopy;
		}
		for(int i=0;i<coinvalue.size();i++){
			bool able = true;
			if(coinvalue[i] == 0){
				able = solve(coinvalue,i+1);
			}
			if(able == false){
				answer++;
				coinvalue[i]=numbercopy;
			}
		}
		cout<<"Case #"<<t+1<<": "<<answer<<endl;
	}
	return 0;
}

