#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

typedef long long ll;
#define MAXVAL 100000000000000000ll

map<char, map<char, char> > next;
map<char, map<char, bool> > next_negative;

void init(){
	next['1']['1'] = '1';
	next['1']['i'] = 'i';
	next['1']['j'] = 'j';
	next['1']['k'] = 'k';

	next['i']['1'] = 'i';
	next['i']['i'] = '1';
	next['i']['j'] = 'k';
	next['i']['k'] = 'j';

	next['j']['1'] = 'j';
	next['j']['i'] = 'k';
	next['j']['j'] = '1';
	next['j']['k'] = 'i';
	
	next['k']['1'] = 'k';
	next['k']['i'] = 'j';
	next['k']['j'] = 'i';
	next['k']['k'] = '1';

	next_negative['i']['i'] = true;
	next_negative['i']['k'] = true;
	next_negative['j']['i'] = true;
	next_negative['j']['j'] = true;
	next_negative['k']['j'] = true;
	next_negative['k']['k'] = true;
}

bool ex_or(bool a, bool b){
	return a != b;
}

struct quaternion{
	char v;
	bool negative;
	quaternion(char v, bool negative){
		this->v = v;
		this->negative = negative;
	}
	quaternion operator*(const quaternion &q) const{
		return quaternion(next[this->v][q.v], ex_or(ex_or(q.negative, this->negative), next_negative[this->v][q.v]));
	}
	quaternion operator/(const quaternion &q) const{
		for(map<char, map<char, char> >::iterator it = next.begin(); it != next.end(); ++it){
			if(it->second[q.v] == this->v){
				bool res = ex_or(next_negative[it->first][q.v], this->negative);
				return quaternion(it->first, res != q.negative);
			}
		}
	}
	bool operator<(const quaternion &q) const{
		if(q.v != this->v)
			return this->v < q.v;
		if(q.negative != this->negative)
			return this->negative;
		return false;
	}
	bool operator==(const quaternion &q) const{
		return this->v == q.v && this->negative == q.negative;
	}
};

quaternion power(quaternion a, ll N){
	if(N==0)
		return quaternion('1', false);
	quaternion tmp = power(a, N/2);
	tmp = tmp*tmp;
	if(N%2 == 1){
		tmp = tmp*a;
	}
	return tmp;
}

ll get_power(quaternion base, quaternion x){
	set<quaternion> reached;
	quaternion curr('1', false);
	ll pow = 0;
	while(reached.count(curr) == 0){
		if(curr == x){
			return pow;
		}
		reached.insert(curr);
		curr = curr*base;
		pow++;
	}
	return -1;
}

ll get_best_pos(vector<quaternion> qs, quaternion result){
	vector<quaternion> cumulative_product;
	quaternion product('1', false);
	for(vector<quaternion>::iterator it = qs.begin(); it != qs.end(); ++it){
		product = product * (*it);
		cumulative_product.push_back(product);
	}
	ll best_pos = MAXVAL;
	quaternion current_product = cumulative_product.back();
	for(int i = 0; i < qs.size(); ++i){
		current_product  = quaternion('1', false)/qs[i]*current_product * qs[i];
		quaternion needed = quaternion('1', false) / cumulative_product[i] * result;
		ll pos = get_power(current_product, needed);
		if(pos == -1){
			continue;
		}
		pos = pos * qs.size() + i;
		best_pos = min(pos, best_pos);
	}
	return best_pos;
}	

vector<quaternion> get_quaternions(string s, int start_index){
	vector<quaternion> qs;
	for(int i = 0; i < s.size(); ++i){
		qs.push_back(quaternion(s[(i+start_index)%s.size()], false));
	}
	return qs;
}
quaternion get_product(vector<quaternion> qs){
	quaternion curr('1', false);
	for(vector<quaternion>::iterator it = qs.begin(); it != qs.end(); ++it){
		curr = curr * (*it);
	}
	return curr;
}

bool solve(string s, ll X){
	ll i_pos = get_best_pos(get_quaternions(s, 0), quaternion('i', false));
	if(i_pos > X*s.size())
		return false;
	ll j_pos = get_best_pos(get_quaternions(s, (i_pos + 1)%s.size()), quaternion('j', false));
	if(j_pos > X*s.size())
		return false;
	if(i_pos + j_pos + 2> X*s.size())
		return false;
	quaternion product = get_product(get_quaternions(s, 0));
	quaternion p = power(product, X);
	if(!(p == quaternion('i', false) * quaternion('j', false) * quaternion('k', false))){
		return false;
	}
	return true;
}

int main(){
	init();
	std::ios::sync_with_stdio(false);
	int nb_testcases; cin >> nb_testcases;
	for(int current_case = 1; current_case <= nb_testcases; ++current_case){
		ll L, X;
		cin >> L >> X;
		string s;
		cin >> s;
		cout << "Case #" << current_case << ": " << (solve(s, X)?"YES":"NO") << endl;
	}

    return 0;
}
