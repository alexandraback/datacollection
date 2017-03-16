#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

long long T;
long long L, X;
string str;

struct quat {
	long long sign;
	char val;
	quat(long long sign, char val) {
		this->sign = sign;
		this->val = val;
	}

	quat operator*(quat &o) {
		long long retSign = this->sign*o.sign;
		if (this->val=='1'){
			return quat(retSign, o.val);
		}
		if (this->val=='i'){
			if (o.val=='1') {
				return quat(retSign, 'i');
			}
			if (o.val=='i') {
				return quat(-retSign, '1');
			}
			if (o.val=='j') {
				return quat(retSign, 'k');
			}
			if (o.val=='k') {
				return quat(-retSign, 'j');
			}
		}
		if (this->val=='j') {
			if (o.val=='1') {
				return quat(retSign, 'j');
			}
			if (o.val=='i') {
				return quat(-retSign, 'k');
			}
			if (o.val=='j'){
				return quat(-retSign, '1');
			}
			if (o.val=='k'){
				return quat(retSign, 'i');
			}
		}
		if (this->val=='k'){
			if (o.val=='1') {
				return quat(retSign, 'k');
			}
			if (o.val=='i'){
				return quat(retSign, 'j');
			}
			if (o.val=='j'){
				return quat(-retSign, 'i');
			}
			if (o.val=='k') {
				return quat(-retSign, '1');
			}
		}

		return quat(-1, 'x');
	}

};

long long findFirst(long long start, char key)
{
	quat ret(1,str[start]);
	if (ret.sign==1 && ret.val==key)
		return start;

	vector<quat> visited;
	for (long long i=start+1; true ; i++) {
		i = (i%str.size());
		if (i==0){
			X--;
		}
		ret = ret*quat(1, str[i]);
		if (ret.sign==1 && ret.val==key)
			return i;
		if (i==0){
			for (long long j=0; j<visited.size(); j++) {
				if (visited[j].sign==ret.sign && visited[j].val==ret.val)
					return -1;
			}
			visited.push_back(ret);
		}
	}
	return -1;
}

quat computeValue(long long start) {
	if (start==0)
		X--;
	quat ret(1, str[start]);
	for (long long i=start+1; i<str.size(); i++) {
		ret = ret*quat(1, str[i]);
	}
	return ret;
}

quat repeatedSquarring(quat a, long long b)
{
	quat x(1,'1');
	quat y(a);
	while (b>0) {
		if (b%2==1)
			x = x*y;
		y = y*y;
		b = b/2;
	}
	return x;
}



bool checkPossible() 
{
	if (str.size()<3 && X<=1)
		return false;
	if (str.size()==3 && X<=1) {
		if (str=="ijk")
			return true;
		else 
			return false;
	}

	long long i_indx = findFirst(0, 'i');
	if (i_indx == -1)
		return false;

	long long j_indx = findFirst((i_indx+1)%str.size(), 'j'); //TODO fix
	if (j_indx==-1)
		return false;

	quat rest = computeValue((j_indx+1)%str.size());
	quat oneL = computeValue(0);
	if (X<0)
		return false;
	quat squarred = repeatedSquarring(oneL, X);
	rest = rest*squarred;

	if (rest.sign==1 && rest.val=='k')
		return true;

	return false;
}

int main() 
{
	ifstream cin;
	cin.open("C-large.in");

	ofstream cout;
	cout.open("dijkstra_sevag_large.out");
	
	cin >> T;

	for (long long t=1; t<=T; t++)
	{
		cin>>L>>X;
		cin>>str;

		bool valid = checkPossible();

		cout<<"Case #"<<t<<": ";
		if (valid)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}

	return 0;
}