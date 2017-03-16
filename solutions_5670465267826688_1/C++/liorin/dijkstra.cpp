#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string> 
using std::string;
using std::vector;

/*
this is terrible but it works. many possible small optimizations
*/

enum Q {one, i, j, k};
class quaternion {
	public:
	int sign;
	Q val;
	quaternion(char c) {
		sign = 1;
		switch (c) {
			case 'i': val = i; break;
			case 'j': val = j; break;
			case 'k': val = k; break;
			default: val = one;
		}
	}

	quaternion() {
		sign =1; val = one;
	}

	quaternion& operator*=(const quaternion& rhs) {
		this->sign *= rhs.sign;
		switch (this->val) {
			case one: this->val = rhs.val; break;
			case i: switch (rhs.val) {
					case i: this->val = one; this->sign *= -1; break;
					case j: this->val = k; break;
					case k: this->val = j; this->sign *= -1; break;
				  };
				  break;
			case j: switch (rhs.val) {
					case i: this->val = k; this->sign *= -1; break;
					case j: this->val = one; this->sign *= -1; break;
					case k: this->val = i; break;
				  };
				  break;
			case k: switch (rhs.val) {
					case i: this->val = j; break;
					case j: this->val = i; this->sign *= -1; break;
					case k: this->val = one; this->sign *= -1; break;
				  }
				  break;

		};
		return *this;
	}

	friend quaternion operator*(quaternion lhs, const quaternion& rhs) {
		return lhs *= rhs;
	}
	
	string to_string() {
		string s;
		if (this->sign == -1) {
			s = "-";
		} else {
			s = " ";
		}
		switch (this->val) {
			case one: s+= "1"; break;
			case i: s+= "i"; break;
			case j: s+= "j"; break;
			case k: s+= "k"; break;
		}
		return s;
	}
};


bool operator==(const quaternion& lhs, const quaternion& rhs){ 
	return lhs.sign == rhs.sign && lhs.val == rhs.val;
}

bool operator!=(const quaternion& lhs, const quaternion& rhs){ 
	return !(lhs == rhs);
}


int main() {
	long long int t, i,j,l,x, num_left, idx_i, num_i, idx_k, num_k;
	bool y;
	char c;
	quaternion lval, l2,l3, target, tmp, full;

	scanf("%lld\n", &t);
	for (i = 1; i <=t; i++) {
		y= true;
		scanf("%lld %lld\n", &l, &x);
		
		vector<quaternion> v(l);
		vector<quaternion> left(l);
		vector<quaternion> right(l);
		for (j = 0; j < l; j++) {
			scanf("%c", &c);
			v[j] = quaternion(c); 
		}
		scanf("\n");
		left[0] = v[0];
		right[l-1] = v[l-1];
		for  (j = 1; j < l; j++) {
			left[j] = left[j-1] * v[j];
			right[l-1-j] = v[l-1-j] * right[l-j];
		}
		lval = left[l-1];
		l2 = lval * lval;
		l3 = l2 * lval;

		//calculate value for L^X
		full.sign = 1;
		full.val = one;
		if (x % 4 == 1) full = full*lval;
		if (x % 4 == 2) full = l2;
		if (x % 4 == 3) full = l3;
		tmp.sign = -1; tmp.val = one; //we start with tmp == 1
		if (full != tmp) y = false; // ijk == -1, so full must be -1
		//find first i :
		if  (y) {
			target = quaternion('i');
			
			idx_i = 0; //what is the index in L of position where first occurence of i is
			num_i = 1; //how many L's were used to get i
			while (left[idx_i] != target && num_i <=4) {
				idx_i++;
				if (idx_i >= l) {
					num_i++;
					idx_i = 0;
					target = l3 * target;
				}
			}
			//printf("first i at num %d idx %d\n", num_i, idx_i);
			if (num_i > 4) { //not possible to get i
				y = false;
			}
		}

		if (y) {
			idx_k = l-1; num_k = 1;
			target = quaternion('k'); //now we find  a last k
			while (right[idx_k] != target && num_k <=4) {
				idx_k--;
				if (idx_k < 0 ) {
					num_k++;
					idx_k = l-1;
					target = target * l3;
				}
			}
			//printf("last k at num %d idx %d\n", num_k, idx_k);
			if (num_k > 4) y =false;

		}

		//now we dont need to find j, only to check if there is nonempty part between first i and last j
		//as L^X evaluates to -1, the nonempty part must be equal to j
		if ( x - num_k - num_i < -1) {
			y = false;
		} else {
			if (x - num_k - num_i == -1 && idx_i >= idx_k - 1)
				y = false;
		}
		printf("Case #%lld: %s\n", i, (y ? "YES" : "NO"));
	}

	return 0;
 }
