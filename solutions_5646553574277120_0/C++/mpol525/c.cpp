#include "cjheader.h"


using namespace std;
int currCase = 0;
int t;

/*
 * Global variables that are needed should be declared here
 */

int sumVect(vector<int>::iterator start, vector<int>::iterator end){
	int sum = 0;
	for(auto it = start; it != end; ++it){
		sum += (*it);
	}
	return sum;
}

bool vecHas(vector<int>& v, int k){
	for(int i = 0; i < v.size(); ++i){
		if(v[i] == k)
			return true;
	}
	return false;
}

int fact(int n){
	if(n == 1)
		return 1;
	else
		return n*(fact(n - 1));
}


// Returns true if there is a subset of set[] with sun equal to given sum
bool isSubsetSum(vector<int>& set, int n, int sum)
{
    // The value of subset[i][j] will be true if there is a subset of set[0..j-1]
    //  with sum equal to i
    bool subset[sum+1][n+1];

    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
      subset[0][i] = true;

    // If sum is not 0 and set is empty, then answer is false
    for (int i = 1; i <= sum; i++)
      subset[i][0] = false;

     // Fill the subset table in botton up manner
     for (int i = 1; i <= sum; i++)
     {
       for (int j = 1; j <= n; j++)
       {
         subset[i][j] = subset[i][j-1];
         if (i >= set[j-1])
           subset[i][j] = subset[i][j] || subset[i - set[j-1]][j-1];
       }
     }

    /* // uncomment this code to print table
     for (int i = 0; i <= sum; i++)
     {
       for (int j = 0; j <= n; j++)
          printf ("%4d", subset[i][j]);
       printf("\n");
     } */

     return subset[sum][n];
}


/**********************************************************/

void runTestCase(){
	printf("Case #%d: ", ++currCase);
	int c, d, v;
	cin >> c;
	cin >> d;
	cin >> v;

	vector<int> denom;

	for(int i = 0; i < d; ++i){
		int temp;
		cin >> temp;
		denom.push_back(temp);
	}

	sort(denom.begin(), denom.end());
	int numInsert = 0;
	for(int i = 1; i <= v; ++i){
		if(!vecHas(denom, i)){

			int j;
			for(j = 0; j < denom.size(); ++j){
				if(denom[j] > i)
					break;
			}
			if(j == 0){
				numInsert++;
				denom.push_back(i);
				sort(denom.begin(), denom.end());
				continue;
			}else{
				j--;
				/*vector<int> denomSubset;
				vector<int>::iterator endit = denom.begin();
				for(; endit != denom.end(); ++endit){
					denomSubset.push_back(*endit);
					if((*endit) == denom[j])
						break;
				}
				assert(endit != denom.end());*/
				if(isSubsetSum(denom, denom.size(), i)){
					//cout << "yep: i = " << i << endl;
					continue;
				}else{
					numInsert++;
					//cout << "pushing back " << i << endl;
					denom.push_back(i);
				}
			}
		}
	}

	printf("%d\n", numInsert);

	return;
}

void setUp(){

	return;
}

int main(){
	setUp();

	int t;


	assert(scanf("%d", &t) == 1);

	while(t > 0){

		runTestCase();
		t--;
	}

	return 0;
}
