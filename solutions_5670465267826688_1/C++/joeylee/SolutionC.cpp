#include <iostream>
#include <fstream>
#include <assert.h>
using namespace std;

int sign(int a) {
	if (a > 0) {
		return 1;
	}
	else {
		return -1;
	}
}

bool verify_i(char str[10000], int index_h, int table[5][5], int L) {
	int product = 1;
	for (int j = 0; j <= index_h; j++) {
		if (str[j % L] == 'i') {
			product = sign(product) * table[abs(product)][2];
		}
		else {
			if (str[j % L] == 'j') {
				product = sign(product) * table[abs(product)][3];
			}
			else {
				product = sign(product) * table[abs(product)][4];
			}
		}
	}
	if (product == 2) {
		return true;
	}
	else {
		return false;
	}
}

bool verify_j(char str[10000], int index_h_1, int index_t_1, int table[5][5], int L) {
	int product = 1;
	for (int j = index_h_1; j <= index_t_1; j++) {
		if (str[j % L] == 'i') {
			product = sign(product) * table[abs(product)][2];
		}
		else {
			if (str[j % L] == 'j') {
				product = sign(product) * table[abs(product)][3];
			}
			else {
				product = sign(product) * table[abs(product)][4];
			}
		}
	}
	if (product == 3) {
		return true;
	}
	else {
		return false;
	}
}

bool verify_k(char str[10000], int end, int index_t, int table[5][5], int L) {
	int product = 1;
	for (int j = index_t; j < end; j++) {
		if (str[j % L] == 'i') {
			product = sign(product) * table[abs(product)][2];
		}
		else {
			if (str[j % L] == 'j') {
				product = sign(product) * table[abs(product)][3];
			}
			else {
				product = sign(product) * table[abs(product)][4];
			}
		}
	}
	if (product == 4) {
		return true;
	}
	else {
		return false;
	}
}

bool verify_p(char str[10000], int end, int table[5][5], int L) {
	int product = 1;
	for (int j = 0; j < end; j++) {
		if (str[j % L] == 'i') {
			product = sign(product) * table[abs(product)][2];
		}
		else {
			if (str[j % L] == 'j') {
				product = sign(product) * table[abs(product)][3];
			}
			else {
				product = sign(product) * table[abs(product)][4];
			}
		}
	}
	if (product == -1) {
		return true;
	}
	else {
		return false;
	}
}


int main() {
  ifstream fin("E:\\C-large.in");
  // ifstream fin("E:\\temp.txt");
  ofstream fout("E:\\C-large.out");
  int T;
  fin >> T;
  int table[5][5] = {
	  {0, 0, 0, 0 ,0},
	  {0, 1, 2, 3, 4},
	  {0, 2,-1, 4,-3},
	  {0, 3,-4,-1, 2},
	  {0, 4, 3,-2,-1}};
  
  char str[10000];

  for (int i = 1; i <= T; i++) {
	  int L;
	  __int64 X;
	  fin >> L;
	  fin >> X;
	  int product = 1;
	  for (int j = 0; j < L; j++) {
		  while ((str[j] = fin.get()) && str[j] != 'i' && str[j] != 'j' && str[j] != 'k');
		  if (str[j] == 'i') {
			  product = sign(product) * table[abs(product)][2];
		  }
		  else {
			  if (str[j] == 'j') {
				  product = sign(product) * table[abs(product)][3];
			  }
			  else {
				  product = sign(product) * table[abs(product)][4];
			  }
		  }
	  }
	  if (product != -1 && product != 1) {
		  if (X % 4 != 2) {
			  fout << "Case #" << i << ": " << "NO" << endl;
		  }
		  else {
			  int circle_limit;
			  if (X > 4) {
				  circle_limit = 4;
			  }
			  else {
				  circle_limit = (int)X;
			  }
			  int index_h = 0;
			  int index_t = circle_limit * L - 1;
			  int head_i = 1;
			  int tail_k = 1;

			  while(index_h < circle_limit * L) {
				  if (str[index_h % L] == 'i') {
					  head_i = sign(head_i) * table[abs(head_i)][2];
				  }
				  else {
					  if (str[index_h % L] == 'j') {
						  head_i = sign(head_i) * table[abs(head_i)][3];
					  }
					  else {
						  head_i = sign(head_i) * table[abs(head_i)][4];
					  }
				  }
				  if (head_i == 2) {
					  break;
				  }
				  index_h++;
			  }

			  while(index_t >= 0) {
				  if (str[index_t % L] == 'i') {
					  tail_k = sign(tail_k) * table[2][abs(tail_k)];
				  }
				  else {
					  if (str[index_t % L] == 'j') {
						  tail_k = sign(tail_k) * table[3][abs(tail_k)];
					  }
					  else {
						  tail_k = sign(tail_k) * table[4][abs(tail_k)];
					  }
				  }
				  if (tail_k == 4) {
					  break;
				  }
				  index_t--;
			  }
			  if (index_h < circle_limit * L && index_t >= 0 && index_h < X * L - (circle_limit * L - index_t) - 1) {
				  /*assert(verify_p(str, X * L, table, L));
				  assert(verify_i(str, index_h, table, L));
				  assert(verify_j(str, index_h + 1, X * L - (circle_limit * L - index_t) - 1, table, L));
				  assert(verify_k(str, X * L, X * L - (circle_limit * L - index_t), table, L));*/
				  fout << "Case #" << i << ": " << "YES" << endl;
			  }
			  else {
				  fout << "Case #" << i << ": " << "NO" << endl;
			  }
		  }
	  }
	  else {
		  if (product == 1) {
			  fout << "Case #" << i << ": " << "NO" << endl;
		  }
		  else {
			  if (X % 2 != 1) {
				  fout << "Case #" << i << ": " << "NO" << endl;
			  }
			  else {
				  int circle_limit;
				  if (X > 2) {
					  circle_limit = 2;
				  }
				  else {
					  circle_limit = (int)X;
				  }
				  int index_h = 0;
				  int index_t = circle_limit * L - 1;
				  int head_i = 1;
				  int tail_k = 1;

				  while(index_h < circle_limit * L) {
					  if (str[index_h % L] == 'i') {
						  head_i = sign(head_i) * table[abs(head_i)][2];
					  }
					  else {
						  if (str[index_h % L] == 'j') {
							  head_i = sign(head_i) * table[abs(head_i)][3];
						  }
						  else {
							  head_i = sign(head_i) * table[abs(head_i)][4];
						  }
					  }
					  if (head_i == 2) {
						  break;
					  }
					  index_h++;
				  }

				  while(index_t >= 0) {
					  if (str[index_t % L] == 'i') {
						  tail_k = sign(tail_k) * table[2][abs(tail_k)];
					  }
					  else {
						  if (str[index_t % L] == 'j') {
							  tail_k = sign(tail_k) * table[3][abs(tail_k)];
						  }
						  else {
							  tail_k = sign(tail_k) * table[4][abs(tail_k)];
						  }
					  }
					  if (tail_k == 4) {
						  break;
					  }
					  index_t--;
				  }
				  if (index_h < circle_limit * L && index_t >= 0 && index_h < X * L - (circle_limit * L - index_t) - 1) {
					  /*assert(verify_p(str, X * L, table, L));
					  assert(verify_i(str, index_h, table, L));
					  assert(verify_j(str, index_h + 1, X * L - (circle_limit * L - index_t) - 1, table, L));
				      assert(verify_k(str, X * L, X * L - (circle_limit * L - index_t), table, L));*/
					  fout << "Case #" << i << ": " << "YES" << endl;
				  }
				  else {
					  fout << "Case #" << i << ": " << "NO" << endl;
				  }
			  }
		  }
	  }
  }
  return 0;
}