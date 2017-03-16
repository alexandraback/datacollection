#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
typedef long long ll;

struct Node {
	Node(int key) : left(NULL), right(NULL), key(key) {}
	Node * left;
	Node * right;
	int key;
};
Node * head;

ifstream fin("b.in");
ofstream fout("b.out");
int E, R, n;
vector<int> v;
ll ans = 0;

void CartesianTree(vector<int> v) {
	head = new Node(0);
	stack<Node *> rightpath;
	rightpath.push(head);

	for (int i = 1; i <= n; ++i) {
		while (v[rightpath.top()->key] < v[i]) {
			rightpath.pop();
		}
		Node * tmp = new Node(i);
		tmp->left = rightpath.top()->right;
		rightpath.top()->right = tmp;
		rightpath.push(tmp);
	}
}

int leftmax(int energy, Node * root) {
	if (root->left != NULL) {
		energy = leftmax(energy, root->left);
	}
	if (root->right != NULL) {
		int energyleft = min( energy, (int)max( 0ll, ll(E) - ll(root->right->key - root->key + 1) * R ) );
		ans += ll(energy - energyleft) * v[root->key];
		return leftmax( energyleft + R, root->right );
	}
	else {
		int energyleft = min( energy, max( 0, E - R ) );
		ans += ll(energy - energyleft) * v[root->key];
		return energyleft + R;
	}
}

ll leftmin(int energy, Node * root) {
	if (root->left != NULL) {
		energy = leftmax(energy, root->left);
	}
	if (root->right != NULL) {
		int energyleft = 0;
		ans += ll(energy - energyleft) * v[root->key];
		return leftmin( energyleft + R, root->right );
	}
	else {
		int energyleft = 0;
		ans += ll(energy - energyleft) * v[root->key];
		return energyleft + R;
	}
}

void solve() {
	fin >> E >> R >> n;
	v.resize(n+1);
	v[0] = 1<<30;
	ans = 0;
	for (int i = 1; i <= n; ++i) {
		fin >> v[i];
	}
	CartesianTree(v);
	leftmin(E, head->right);
	fout << ans << '\n';
	delete(head);
}

int main() {
	int n;
	fin >> n;
	for (int case_num = 1; case_num <= n; ++case_num) {
		fout << "Case #" << case_num << ": ";
		solve();
	}
	return 0;
}
