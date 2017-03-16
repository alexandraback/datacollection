#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

typedef set<double> SD;

typedef vector<double> VD;

vector<double> readv(int n)
{
  vector<double> v(n);
  for(int i=0; i < n; i++)
    cin >> v[i];
  return v;
}

void printv( SD v)
{
  for (auto d : v)
    cout << d << " ";
  cout << endl;
}
int  naomi_score( SD& naomi, SD& ken);

int ken_score( SD& naomi, SD& ken, double item)
{
  SD::iterator selection = ken.lower_bound( item);
  double ken_item;
  if (selection == ken.end())
  {
    ken_item = *ken.begin();
    ken.erase( ken.begin());
    int r = 1 + naomi_score(naomi, ken);
    ken.insert(ken_item);
    return r;
  }
  else
  {
    ken_item = *selection;
    ken.erase( selection);
    int r= naomi_score(naomi, ken);
    ken.insert(ken_item);
    return r;
  }
}

 
int naomi_score(SD& naomi, SD& ken)
{
  if (naomi.empty())
    return 0;

  int best = 0;

  for (SD::iterator i=naomi.begin(); i != naomi.end();  )
  {
    double item = *i;
    naomi.erase(i);
    int score =ken_score( naomi, ken, item);
    i= naomi.insert(item).first;
    i++;
    best = max(score, best);
  }
  return best;
}

int naomi_score_deceit(SD naomi, SD ken)
{
	int score = 0;
	
	while (!naomi.empty())
	{		

		auto n_smallest = naomi.begin();
		auto k_smallest = ken.begin();


		if ( *n_smallest > *k_smallest)
		{
				score++;
				naomi.erase(n_smallest);
				ken.erase(k_smallest);
		}
		else
		{
			naomi.erase(n_smallest);
			ken.erase( --ken.rbegin().base());
		}
	}
	return score;
}

int naomi_score_fast(SD naomi, SD ken)
{
	int score = 0;

	while (!naomi.empty())
	{
		auto n_largest = naomi.rbegin();
		auto selection = ken.lower_bound( *n_largest);

		if (selection == ken.end())
		{
			score++;
			ken.erase( ken.begin());
			naomi.erase( --n_largest.base());	
		}
		else
		{
			ken.erase(selection);
			naomi.erase( --n_largest.base());
		}
	}

	return score;
}

void proc_case()
{
 

  int N;
  cin >> N;
  vector<double> naomi_ = readv(N);
  vector<double> ken_ = readv(N);

  set<double> naomi(naomi_.begin(), naomi_.end());
  set<double> ken(ken_.begin(), ken_.end());

  //printv(ken);
  //printv(naomi);
  cout << naomi_score_deceit( naomi, ken) << " " ;
  //cout << naomi_score( naomi, ken) << " ";
  cout << naomi_score_fast( naomi, ken) << endl;
  
}



int main()
{
  int nCases;
  cin >> nCases;
  for (int caseNo=0; caseNo < nCases; caseNo++)
  {
      cout << "Case #" << caseNo+1 << ": ";
      proc_case();
  }
}