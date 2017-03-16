#include <iostream>
#include <algorithm>
#include <list>

using namespace std;


int war(list<double> naomi, list<double> ken){
	int points = 0;

	while(naomi.size()){
		if(naomi.back() > ken.back())
		{
			naomi.pop_back();
			ken.pop_front();
			points++;
		}
		else
		{
			naomi.pop_back();
			ken.pop_back();
		}
	}

	return points;
}

int dwar(list<double> naomi, list<double> ken){
	int points = 0;



	while(naomi.size()){
/*		for( auto const & it : naomi)
			cout << it << " ";
		cout << endl;

		for( auto const & it : ken)
			cout << it << " ";
		cout << endl;

		cout << naomi.front() << " " << ken.front()  << " " << naomi.size()<< endl;
*/
		if(naomi.front() < ken.front()){
			naomi.pop_front();
			ken.pop_back();
		}
		else {
			naomi.pop_front();
			ken.pop_front();
			points++;
		}
	}
	return points;
}

void solveCase(int caseNum){
	int count;
	cin >> count;

	list<double> naomi, ken;


	for(int i=0;i<count;i++){
		double n;
		cin >> n;
		naomi.push_back(n);
	}

	for(int i=0;i<count;i++){
		double k;
		cin >> k;
		ken.push_back(k);
	}
/*
	list::sort(naomi.begin(),naomi.end());
	list::sort(ken.begin(),ken.end());
*/
	naomi.sort();
	ken.sort();

	cout << "Case #" << caseNum << ": " << dwar(naomi,ken) << " " << war(naomi,ken) << endl;
}



int main(){
	int T;
	cin >> T;
	for(int i=0;i<T;i++){
		solveCase(i+1);
	}	
	return 0;
}