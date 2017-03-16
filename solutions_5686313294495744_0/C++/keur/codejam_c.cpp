#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

__attribute__ ((const, hot)) bool cmp(string my_string, int index, int n){
	if (-1 == index) {return 0 == n;}
	char last_ = my_string[index];
	if ('?' != last_ ){
		return (last_-'0' == n%10)
		&&
		cmp(my_string, index-1, n/10);}
	return cmp(my_string, index-1, n/10);
	}

void print_digits(int number, int digits){
	if (digits > 2){
		cout << (number/100)%10;
		}
	if (digits > 1){
		cout << (number/10)%10;
	}
	if (digits > 0){
		cout << (number/1)%10;
	}
}

typedef struct {string a; string b;} my_struct;


void foo(vector<my_struct> my_vector){
	map<string, int> first_words;
	map<string, int> second_words;
	set<string> first_words_seen;
	set<string> second_words_seen;
	vector<bool> my_vector_original (my_vector.size(), false);
	vector<bool> my_vector_fake (my_vector.size(), false);

	for(auto v : my_vector){
		first_words[v.a]++;
		second_words[v.b]++;
	}
	int counter = 0;
	for(uint j = 0; j < my_vector.size(); j += 1){
		auto v = my_vector[j];
		if (1 == first_words[v.a] or 1 == second_words[v.b]){
			first_words_seen.insert(v.a);
			second_words_seen.insert(v.b);
			my_vector_original[j] = true;
			counter++;
		}
	}
	//for (auto v : my_vector_original) cout << v << " ";
	//cout << endl;
	for(uint j = 0; j < my_vector.size(); j += 1){
		auto v = my_vector[j];
		if (not my_vector_original[j] and first_words_seen.end() != first_words_seen.find(v.a) and second_words_seen.find(v.b) != second_words_seen.end()){
			my_vector_fake[j] = true;
			//counter++;
		}
	}
	//for (auto v : my_vector_original) cout << v << " ";
	//cout << endl;
	//follows aproximmation
	for(uint j = 0; j < my_vector.size(); j += 1){
		auto v = my_vector[j];
		if (not my_vector_original[j] and first_words_seen.end() == first_words_seen.find(v.a) and second_words_seen.find(v.b) == second_words_seen.end()){
			first_words_seen.insert(v.a);
			second_words_seen.insert(v.b);
			my_vector_original[j] = true;
			counter++;
		}
	}
	//for (auto v : my_vector_original) cout << v << " ";
	//cout << endl;
	for(uint j = 0; j < my_vector.size(); j += 1){
		auto v = my_vector[j];
		if (not my_vector_original[j] and not my_vector_fake[j] and first_words_seen.end() != first_words_seen.find(v.a) and second_words_seen.find(v.b) != second_words_seen.end()){
			my_vector_fake[j] = true;
		}
	}
	//for (auto v : my_vector_original) cout << v << " ";
	//cout << endl;
	for(uint j = 0; j < my_vector.size(); j += 1){
		auto v = my_vector[j];
		if (not my_vector_original[j] and not my_vector_fake[j] and ( first_words_seen.end() != first_words_seen.find(v.a) or second_words_seen.find(v.b) != second_words_seen.end() ) ){
			if ( first_words_seen.end() != first_words_seen.find(v.a) and second_words_seen.find(v.b) != second_words_seen.end() )
			{
				my_vector_fake[j] = true;
				continue;
			}
			first_words_seen.insert(v.a);
			second_words_seen.insert(v.b);
			my_vector_original[j] = true;
			counter++;
		}
	}
	//for (auto v : my_vector_original) cout << v << " ";
	//cout << endl;
	cout << my_vector.size()-counter;
}


int main(void){
	int t;
	cin >> t;
	for (int i = 1; i <= t; i += 1){
		int N; cin >> N;
		vector<my_struct> my_vector (N);
		for (int j = 0; j < N ; j +=1) {
			cin >> my_vector[j].a >> my_vector[j].b;
		}
		cout << "Case #" << i << ": ";
		foo(my_vector);
		cout << "\n";
	}
	return 0;
}
