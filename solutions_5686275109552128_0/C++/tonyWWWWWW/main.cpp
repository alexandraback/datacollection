#include <iostream>
#include <algorithm>

#define MAX 1000;

using namespace std;

typedef struct node {
	int val;
	node* next;
	node* previous;
};

bool compare(int a, int b)
{
	return a>b;
}

int main() {
	freopen("a.txt", "r", stdin);
	freopen("b.txt", "w", stdout);
	int T = 0;
	cin >> T;
	int t = 0;
	int max = 100;
	while (t < T) {
		if (t != 0) cout << endl;
		int ans = 0;
		int d = 0;
		short p[100] = {0};
		cin >> d;
		for (int i = 0; i < d; i++) {
			cin >> p[i];
		}
		sort(p, p + d, compare);
		node* head;
		node* rear;
		for (int i = 0; i < max; i++) {
			node *new_node = new node{ p[i], NULL , NULL};
			if (i == 0){
				head = new_node;
				rear = new_node;
			}
			else {
				rear->next = new_node;
				new_node->previous = rear;
				rear = new_node;
			}
		}

		while (head->val != 0) {
			int reduce = 0;
			if ((head->val + 1 + rear->val) / 2 < head->next->val) {
				reduce = head->val - head->next->val;
			}
			else {
				reduce = head->val - (head->val + 1 + rear->val) / 2;
			}
			if (reduce <= 1) {
				node *v = head;
				while (v != NULL) {
					if (v->val > 0) {
						v->val -= 1;
						v = v->next;
					}
					else {
						break;
					}
				}
			}
			else {
				int temp = head->val + rear->val;
				head->val = (head->val + 1 + rear->val) / 2;
				rear->val = temp - head->val;
				node *v = head->next;
				while (v->val > head->val && v->next != NULL) {
					v = v->next;
				}
				if (v->previous == head) {
					node* r = rear->previous;
					rear->next = v;
					head->next = rear;
					rear->previous = head;
					v->previous = rear;
					r->next = NULL;
					rear = r;
				}
				else if (v == rear) {
					node* h = head->next;
					rear->previous->next = head;
					head->previous = v->previous;
					head->next = rear;
					rear->previous = head;
					h->previous = NULL;
					head = h;
				}
				else {
					node* h = head->next;
					node* r = rear->previous;
					v->previous->next = head;
					head->previous = v->previous;
					head->next = rear;
					rear->previous = head;
					rear->next = v;
					v->previous = rear;
					h->previous = NULL;
					head = h;
					r->next = NULL;
					rear = r;
				}
			}
			ans++;
		}

		cout << "Case #" << t + 1 << ": " << ans;
		t++;
	}
}