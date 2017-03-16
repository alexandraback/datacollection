#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct level {
	int one_star;
	int two_star;
	bool one_star_earned;
	bool two_star_earned;
	int one_index;
	int two_index;
	int length;
};

bool two_star_sort(struct level *a, struct level *b) {
	return a->two_star < b->two_star;
}

bool one_star_sort(struct level *a, struct level *b) {
	if(a->two_index == -1 || b->two_index == -1)
		return a < b;
	else
		return a->one_star - 1.0f*a->two_index/a->length < b->one_star - 1.0f*b->two_index/b->length;
}

int min_plays(vector<struct level*> &v) {
	vector<struct level*> ts = v;

	// Sort by number needed for two stars
	vector<struct level*>::iterator it;
	sort(ts.begin(), ts.end(), two_star_sort);
	for(int i = 0; i < ts.size(); ++i) {
		ts[i]->two_index = i;
		ts[i]->length = ts.size();
	}

	vector<struct level*> os = v;
	sort(os.begin(),os.end(), one_star_sort);
	for(int i = 0; i < os.size(); ++i) {
		os[i]->one_index = i;
	}

	int stars = 0; int levels = 0;
	do {
		// Try to find a level that can be beat in ts
		if(ts.size() > 0 && ts[0]->two_star <= stars) {
			stars += 2;
			ts[0]->two_index = -1;
			os.erase(os.begin()+ts[0]->one_index);
			ts.erase(ts.begin());
			levels++;
			for(int i = 0; i < os.size(); ++i)
				os[i]->one_index = i;
			for(int i = 0; i < ts.size(); ++i)
				ts[i]->two_index = i;
		}
		else if(os.size() > 0 && os[0]->one_star <= stars) {
			stars++; levels++;
			if(os[0]->two_index == -1) {
				os.erase(os.begin());
				for(int i = 0; i < os.size(); ++i)
					os[i]->one_index = i;
			}
			else {
				ts.erase(ts.begin()+os[0]->two_index);
				os[0]->two_index = -1;
				os[0]->one_star = os[0]->two_star;
				sort(os.begin(),os.end(),one_star_sort);
				for(int i = 0; i < os.size(); ++i)
					os[i]->one_index = i;
				for(int i = 0; i < ts.size(); ++i)
					ts[i]->two_index = i;
			}
		}
		else
			return -1;
	} while(os.size() > 0);

	return levels;
}

int main(int argc, char **argv) {
	ifstream in(argv[1]);
	ofstream out(argv[2]);	
	
	int N;
	in >> N;
	for(int i = 0; i < N; ++i) {
		int num_levels;
		in >> num_levels;

		vector<struct level*> v;
		for(int j = 0; j < num_levels; ++j) {
			level *l = new struct level;
			in >> l->one_star >> l->two_star;
			l->one_star_earned = false;
			l->two_star_earned = false;
			v.push_back(l);
		}
		int m = min_plays(v);
		if(m!=-1)
			out << "Case #" << i + 1 << ": " << m << endl;
		else
			out << "Case #" << i + 1 << ": Too Bad" << endl;

		for(int j = 0; j < num_levels; ++j)
			delete v[j];
	}

	in.close();
	out.close();
}
