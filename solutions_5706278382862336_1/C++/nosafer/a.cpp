#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <queue>


using namespace std;

uint64_t hcf(uint64_t a, uint64_t b)
{
	uint64_t r=0;
	while(b!=0)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return(a);
} 

pair<uint64_t , uint64_t> make_a_pair(pair<uint64_t , uint64_t>& a, pair<uint64_t , uint64_t>& b)
{
	uint64_t cf = hcf(a.second, b.second);
	uint64_t nor = b.second/cf*a.first + a.second / cf * b.first;
	uint64_t dor = a.second / cf * b.second;
	dor *= 2;
	cf = hcf(dor, nor);
	dor /= cf;
	nor /= cf;
	pair<uint64_t, uint64_t> ap = make_pair(nor, dor);
	return ap;
}

int cal_gen(pair<pair<uint64_t , uint64_t>, int>& a, pair<pair<uint64_t , uint64_t>, int>& b)
{
	if (a.first.first == 0){
		return b.second;
	}
	if (b.first.first == 0){
		return a.second;
	}
	return min(a.second, b.second);
}
int search(uint64_t P, uint64_t Q)
{
	vector<pair<pair<uint64_t, uint64_t>, int> > vecP;
	vecP.push_back(make_pair(make_pair(1L, 1L), 0));
	vecP.push_back(make_pair(make_pair(0L, 1L), 0));
	map<pair<uint64_t, uint64_t>, bool > m;
	if (P == 1 && Q == 1){
		return 0;
	}
	if (P == 0){
		return -1;
	}
	pair<uint64_t, uint64_t> ap = make_a_pair(vecP[0].first, vecP[1].first);
	int gen = cal_gen(vecP[0], vecP[1]);
	gen ++;

	if (ap.first == P && ap.second == Q){
		return gen;
	}
	int max_gen = 0;
	uint64_t q = Q;
	while ((q & 1) == 0){
		max_gen ++;
		q >>= 1;
	}

	
	queue<pair<pair<uint64_t, uint64_t>, int> > candi;
	candi.push(make_pair(ap, gen));
	vector<int> result;
	while (!candi.empty())
	{
		pair<pair<uint64_t, uint64_t>, int> ap = candi.front();
		candi.pop();
		for (size_t j = 0; j < vecP.size(); j++){
			pair<uint64_t, uint64_t> t = make_a_pair(vecP[j].first, ap.first);
			int tgen = cal_gen(ap, vecP[j]);
			tgen ++;
			if (tgen > max_gen){
				continue;
			}
			if (t.first == P && t.second == Q){
				result.push_back(tgen);
				continue;
			}
			if (m.find(t) == m.end() && t.second < Q){
				m[t] = true;
				candi.push(make_pair(t, tgen));
				/*
				cout<<vecP[j].first.first<<":"<<vecP[j].first.second<<":"<<vecP[j].second<<endl;
				cout<<ap.first.first<<":"<<ap.first.second<<":"<<ap.second<<endl;
				cout<<t.first<<":"<<t.second<<":"<<tgen<<endl;
				cout<<"----"<<endl;
				*/
			}
		}
		vecP.push_back(ap);
	}
	int min = -1;
	if (result.size() > 0){
		min = result[0];
	}
	for (size_t i = 1; i < result.size(); i++){
		if (result[i] < min){
			min = result[i];
		}
	}
	return min;
}
int main(int argc, char **argv)
{
	ifstream in(argv[1]);
	int nCase;
	in >> nCase;
	for (int i = 0; i < nCase; i++){
		string data ;
		in >> data;
		int pos = data.find("/", 0);
		uint64_t  P = atol(data.substr(0, pos).c_str());
		uint64_t  Q = atol(data.substr(pos+1, data.length() - 1 - pos).c_str());

		uint64_t  cf = hcf(P, Q);
		P /=  cf;
		Q /=  cf;

		int s = search(P, Q);

		if (s == -1){
			cout<<"Case #"<<i+1<<": impossible"<<endl;
		}
		else {
			cout<<"Case #"<<i+1<<": "<<s<<endl;
		}
	}
	return 0;
}
