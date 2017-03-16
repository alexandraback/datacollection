#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int T;
int L, X;
string str;

struct quat {
	int sign;
	char val;
	quat(int sign, char val) {
		this->sign = sign;
		this->val = val;
	}

	quat operator*(quat &o) {
		int retSign = this->sign*o.sign;
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

int findFirst(int start, char key)
{
	quat ret(1,str[start]);
	if (ret.sign==1 && ret.val==key)
		return start;

	for (int i=start+1; i<str.size(); i++) {
		ret = ret*quat(1, str[i]);
		if (ret.sign==1 && ret.val==key)
			return i;
	}
	return -1;
}

quat computeValue(int start) {
	quat ret(1, str[start]);
	for (int i=start+1; i<str.size(); i++) {
		ret = ret*quat(1, str[i]);
	}
	return ret;
}

bool checkPossible() 
{
	int i_indx = findFirst(0, 'i');
	if (i_indx == -1)
		return false;

	int j_indx = findFirst(i_indx+1, 'j');
	if (j_indx==-1)
		return false;

	quat rest = computeValue(j_indx+1);
	if (rest.sign==1 && rest.val=='k')
		return true;

	return false;
}


int main() 
{
	ifstream cin;
	cin.open("C-small-attempt0.in");

	ofstream cout;
	cout.open("dijkstra_sevag.out");

	cin >> T;

	for (int t=1; t<=T; t++)
	{
		cin>>L>>X;
		string strTemp;
		cin>>strTemp;

		str.clear();
		for (int i=0; i<X; i++) {
			str.append(strTemp);
		}

		bool valid = checkPossible();

		cout<<"Case #"<<t<<": ";
		if (valid)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}

	return 0;
}