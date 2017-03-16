#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <list>

#define FORST(X,S,T) for(int X=S; X<=T; X++)  
#define RFORST(X,S,T) for(int X=S; X>=T; X--)  
#define FOR(X,XB) for(int X=0; X<XB; X++)
#define RFOR(X,XB) for(int X=(XB)-1; X>=0; X--)
#define FORSTL(X,C) for(X=C.begin();X!=C.end();X++)
#define SQR(X) ((X)*(X))
#define MID(X,Y) (((X)+(Y))/2)
#define FILL(X,V) memset(X,V,sizeof(X))
#define FILE_R(X) freopen(X, "r", stdin)  
#define FILE_W(X) freopen(X, "w", stdout)  
#define ERREQ(X,Y) (fabs((X)-(Y))<EPS)
#define DBGL cout << "here" << endl;
#define SZ(X) sizeof(X)
const double PI = acos(-1.0);
const double EPS = 1E-9;
const int INF = (int)1E9;
typedef long long INT;
using namespace std;

#define BIGINT_SIZE 100	// support STEP*SIZE integer
#define BIGINT_STEP 9	// elementary step 10^k
#define BIGINT_CHARSIZE (BIGINT_SIZE*BIGINT_STEP+1)

class bigint{
public:
	bool negative;
	int lenChars;
	int lenNumbers;
	long long divider;
	long long numbers[BIGINT_SIZE];
	char chars[BIGINT_CHARSIZE];
	static const int step = BIGINT_STEP;
	
	// initializer
	void inline init(){
		negative = 0;
		lenChars = lenNumbers = 0;
		chars[0] = 0;
		divider = (long long)pow(10.0, (double)step);
	}

	// constructors
	bigint(){ init(); }
	bigint(const bigint &num){ init(); copyFromBigint(num); }
	bigint(int num){ init(); convertLonglongToNumbers((long long)num); }
	bigint(long long num){ init(); convertLonglongToNumbers(num); }
	bigint(char *str, bool rev){	// rev determines if the input is in reversed character order
		init();
		int len = strlen(str);
		int offset = 0;
		if(str[0]=='-'){ 
			negative = 1;
			len--;
		}
		if(rev) FOR(i, len) chars[i] = str[len-1-i+negative];
		else FOR(i, len) chars[i] = str[i+negative];
		chars[len] = 0;
		lenChars = len;
		convertCharsToNumbers();
	}
	
	// conversion functions
	void convertCharsToNumbers(){
		for(int i=0; i<lenChars; i+=step){
			long long base = 1;
			long long sum = 0;
			for(int j=0; i+j<lenChars && j<step; j++){
				long long x = (long long)(chars[i+j]-'0');
				sum += x*base;
				base *= 10;
			}
			numbers[i/step] = sum;
			lenNumbers = i/step + 1;
		}
	}
	void convertNumbersToChars(){
		int len = 0;
		FOR(i, lenNumbers){
			int x = (int)numbers[i];
			int j=0;
			while(x){
				chars[len++] = '0'+x%10;
				x/=10;
				j++;				
			}
			while(j<step){
				chars[len++] = '0';
				j++;
			}
		}
		lenChars = len;
		removeLeadingCharZeros();
	}
	void convertLonglongToNumbers(long long num){
		int len=0;
		long long lnum = (long long)num;
		if(lnum<0){
			negative = 1;
			lnum = -lnum;
		}
		while(lnum){
			numbers[len++] = lnum%divider;
			lnum /= divider;
		}
		if(!len) numbers[len++] = 0;
		lenNumbers = len;
	}
	void removeLeadingNumberZeros(){
		int len = lenNumbers;
		RFORST(i, lenNumbers-1, 1){
			if(numbers[i]==0) len = i;
			else break;
		}
		lenNumbers = len;
	}
	void removeLeadingCharZeros(){
		int len = lenChars;
		RFORST(i, lenChars-1, 1){
			if(chars[i]=='0'){
				chars[i] = 0;
				len = i;
			}
			else break;
		}
		lenChars = len;
	}

	// arithmetic
	bigint operator + (const bigint &another) const{
		// negative handling
		if(negative && !another.negative){
			bigint a = abs();
			if(a<=another) return another - a;
			else return (a - another).negate();
		}else if(!negative && another.negative){
			bigint b = another.abs();
			if(*this>=b) return *this - b;
			else return (b-*this).negate();
		}
		bigint ans(0);
		ans.negative = negative;
		int l1 = lenNumbers, l2 = another.lenNumbers;
		int len = l1>l2?l1:l2;
		long long carry = 0;
		FOR(i, len){
			ans.numbers[i] = carry;
			if(i<l1) ans.numbers[i] += numbers[i];
			if(i<l2) ans.numbers[i] += another.numbers[i];
			carry = 0;
			if(ans.numbers[i]>=divider){
				ans.numbers[i] %= divider;
				carry = 1;
			}
		}
		if(carry) ans.numbers[len++] = carry;
		ans.lenNumbers = len;

		FOR(i, len){
			if(ans.numbers[i]<0){
				cerr << "Cannot-be in Plus";
			}
		}

		return ans;
	}
	bigint operator - (const bigint &another) const{
		// handling negative
		if(negative && !another.negative) return (abs() + another).negate();
		else if(!negative && another.negative) return *this + another.abs();
		else if(negative && another.negative) return *this + another.negate();//XXX
		
		long long dir = *this >= another ? 1:-1;
		bigint ans(0);
		int l1 = lenNumbers, l2 = another.lenNumbers;
		int len = l1>l2?l1:l2;
		long long carry = 0;
		FOR(i, len){
			ans.numbers[i] = -carry;
			if(i<l1) ans.numbers[i] += numbers[i]*dir;
			if(i<l2) ans.numbers[i] += -another.numbers[i]*dir;
			carry = 0;
			if(ans.numbers[i]<0){
				ans.numbers[i] += divider;
				carry = 1;
			}
		}
		if(carry){
			cerr << "Cannot-be in minus" << endl;
		}
		ans.lenNumbers = len;
		ans.removeLeadingNumberZeros();
		ans.negative = dir>0?0:1;
		return ans;
	}
	bigint operator * (const bigint &another) const{
		bigint ans(0);
		if(negative && !another.negative || !negative && another.negative) ans.negative = 1;
		if(*this==0 || another==0) return bigint(0);
		int l1 = lenNumbers, l2 = another.lenNumbers;
		long long carry;
		FOR(i, l1+l2) ans.numbers[i] = 0;
		FOR(i, l1){
			carry = 0;
			FOR(j, l2){
				ans.numbers[i+j] += numbers[i] * another.numbers[j] + carry;
				carry = ans.numbers[i+j] / divider;
				ans.numbers[i+j] %= divider;
			}
			if(carry) ans.numbers[i+l2] += carry;	// cannot carry over
		}
		ans.lenNumbers = l1 + l2;
		ans.removeLeadingNumberZeros();
		return ans;
	}
	bigint operator / (const bigint &another) const{
		bigint ans(0);
		if(negative && !another.negative || !negative && another.negative) ans.negative = 1;
		if(*this==0) return bigint(0);
		if(abs()<another.abs()) return bigint(0);
		int l1 = lenNumbers, l2 = another.lenNumbers, l3;
		int len = l1 - l2 + 1;
		long long dividend[BIGINT_SIZE];
		FOR(i, l1) dividend[i] = numbers[i];
		long long tmp[BIGINT_SIZE];

		long long carry;
		RFOR(i, len){
			long long l = 0, r = divider-1;
			while(l<=r){
				long long m = (l+r)/2;
				
				carry = 0;
				FOR(j, l2){
					tmp[j] = carry + another.numbers[j]*m;
					carry = 0;
					if(tmp[j]>=divider){
						carry = tmp[j] / divider;
						tmp[j] %= divider;
					}
				}
				l3 = l2;
				if(carry) tmp[l3++] = carry;
				bool tooLarge = 0;
				if(i+l3>l1) tooLarge = 1;
				else if(i+l3<l1 && dividend[i+l3]){
					// dividend has larger length
				}else{
					RFOR(j, l3){
						if(tmp[j]>dividend[i+j]){
							tooLarge = 1;
							break;
						}else if(tmp[j]<dividend[i+j]) break;
					}
				}
				// if no break, then equal is acceptable as not too large

				if(tooLarge) r = m-1;
				else l = m+1;
			}

			carry = 0;
			FOR(j, l2){
				tmp[j] = carry + another.numbers[j]*r;
				carry = 0;
				if(tmp[j]>=divider){
					carry = tmp[j] / divider;
					tmp[j] %= divider;
				}
			}
			l3 = l2;
			if(carry) tmp[l3++] = carry;
			
			carry = 0;
			FOR(j, l3){
				dividend[i+j] -= carry + tmp[j];
				carry = 0;
				if(dividend[i+j]<0){
					dividend[i+j] += divider;
					carry = 1;
				}
			}
			if(carry) dividend[i+l3] = 0;

			ans.numbers[i] = r;
		}
		ans.lenNumbers = len;
		ans.removeLeadingNumberZeros();
		return ans;
	}
	bigint operator % (const bigint &another) const{
		bigint quotient = *this / another * another;
		return *this - quotient;
	}
	bigint & operator = (const bigint &another){
		copyFromBigint(another);
		return *this;
	}
	bigint & operator += (const bigint &another){
		return *this = *this + another;
	}
	bigint & operator -= (const bigint &another){
		return *this = *this - another;
	}
	bigint & operator *= (const bigint &another){
		return *this = *this * another;
	}
	bigint & operator /= (const bigint &another){
		return *this = *this / another;
	}
	bigint & operator %= (const bigint &another){
		return *this = *this % another;
	}
	
	// comparison
	bool smallerOrEqualThan(const bigint &another, bool canEqual) const{
		if(negative && !another.negative) return true;
		if(!negative && another.negative) return false;
		if(negative && another.negative) return abs()>=another.abs();
		if(lenNumbers>another.lenNumbers) return false;
		if(lenNumbers<another.lenNumbers) return true;
		RFOR(i, lenNumbers){
			if(numbers[i] > another.numbers[i]) return false;
			else if(numbers[i] < another.numbers[i]) return true;
		}
		return canEqual;
	}
	bool largerOrEqualThan(const bigint &another, bool canEqual) const{
		if(negative && !another.negative) return false;
		if(!negative && another.negative) return true;
		if(negative && another.negative) return abs()<=another.abs();
		if(lenNumbers>another.lenNumbers) return true;
		if(lenNumbers<another.lenNumbers) return false;
		RFOR(i, lenNumbers){
			if(numbers[i] > another.numbers[i]) return true;
			else if(numbers[i] < another.numbers[i]) return false;
		}
		return canEqual;
	}
	bool operator < (const bigint &another) const{
		return smallerOrEqualThan(another, false);
	}
	bool operator <= (const bigint &another) const{
		return smallerOrEqualThan(another, true);
	}
	bool operator > (const bigint &another) const{
		return largerOrEqualThan(another, false);
	}
	bool operator >= (const bigint &another) const{
		return largerOrEqualThan(another, true);
	}
	bool operator == (const bigint &another) const{
		if(lenNumbers!=another.lenNumbers || negative!=another.negative) return false;
		FOR(i, lenNumbers) if(numbers[i] != another.numbers[i]) return false;
		return true;
	}
	bool operator != (const bigint &another) const{
		return !(*this == another);
	}
	bool operator && (const bigint &another) const{
		return (*this!=0) && (another!=0);
	}
	bool operator || (const bigint &another) const{
		return (*this!=0) || (another!=0);
	}
	

	// copy of long long operators
	bigint operator + (const long long &num) const{
		return *this + bigint(num);
	}
	bigint operator - (const long long &num) const{
		return *this - bigint(num);
	}
	bigint operator * (const long long &num) const{
		return *this * bigint(num);
	}
	bigint operator / (const long long &num) const{
		return *this / bigint(num);
	}
	bigint operator % (const long long &num) const{
		return *this % bigint(num);
	}
	bool operator < (const long long &num) const{
		return *this < bigint(num);
	}
	bool operator <= (const long long &num) const{
		return *this <= bigint(num);
	}
	bool operator > (const long long &num) const{
		return *this > bigint(num);
	}
	bool operator >= (const long long &num) const{
		return *this >= bigint(num);
	}
	bool operator != (const long long &num) const{
		return !(*this == num);
	}
	bool operator && (const long long &num) const{
		return (*this!=0) && (num!=0);
	}
	bool operator == (const long long &num) const{
		return *this == bigint(num);
	}
	bool operator || (const long long &num) const{
		return (*this!=0) || (num!=0);
	}
	// function
	void copyFromBigint(const bigint &another){
		negative = another.negative;
		lenNumbers = another.lenNumbers;
		FOR(i, lenNumbers) numbers[i] = another.numbers[i];
	}
	bigint abs() const{
		bigint ans(*this);
		ans.negative = 0;
		return ans;
	}
	bigint negate() const{
		bigint ans(*this);
		ans.negative = !ans.negative;
		return ans;
	}
	friend bigint operator +(const bigint &num){
		return bigint(num);
	}
	friend bigint operator -(const bigint &num){
		return num.negate();
	}
    friend bool operator !(const bigint &num){
		return num==0 ? true:false;
	}
	
	// input and output
	void print(){
		convertNumbersToChars();
		if(negative) printf("-");
		RFOR(i, lenChars) printf("%c", chars[i]);
	}
	void print(ostream & os){
		convertNumbersToChars();
		if(negative) os << "-";
		RFOR(i, lenChars) os << chars[i];
	}
	friend inline ostream & operator << (ostream & os, const bigint &num){
		bigint out(num);
		out.print(os);
		return os;
	}
	friend inline istream & operator >> (istream & is, bigint &num){
		string str;
		is >> str;
		num = bigint((char *)str.c_str(), 1);
		return is;
	}
};


int main(){
	int cs;

	FILE_W("output");

	cin>>cs;

	for(int csn=1;csn<=cs;csn++){
		printf("Case #%d: ", csn);

		bigint r, t;
		cin >> r >> t;

		bigint ll = 1, rr = 1000000000;
		rr *= rr;
		rr *= rr;

		while(ll<=rr){
			bigint m = (ll+rr)/2;

			bigint k = m*m*2+(r*2-1)*m;
			if(k<=t){
				ll = m+1;
			}else{
				rr = m-1;
			}
		}
		cout << rr << endl;
	}
	return 0;
}