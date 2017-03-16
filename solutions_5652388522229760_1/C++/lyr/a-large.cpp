#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int base = 10000;    // (base^2) fit into int 
const int width = 4;       // width = log base 
const int N  = 1000;       // n * width: 可表示的大位数 
struct BigInt {  
	int ln, v[N];  
	BigInt (int r = 0) {  //直接整数构造  
		for (ln = 0; r > 0; r /= base) v[ln++] = r % base;  
	}  
	BigInt& operator = (const BigInt& r) {
		memcpy(this, &r, (r.ln + 1) * sizeof(int));// !   
		return *this;  
	} 
}; 

bool operator < (const BigInt& a, const BigInt& b) {
	int i;  
	if (a.ln != b.ln) return a.ln < b.ln;  
	for (i = a.ln - 1; i >= 0 && a.v[i] == b.v[i]; i--);  
	return i < 0 ? 0 : a.v[i] < b.v[i]; 
} 


bool operator <= (const BigInt& a, const BigInt& b) {
	return !(b < a); 
} 

BigInt operator + (const BigInt& a, const BigInt& b) {  
	BigInt res; 
	int i, cy = 0;  
	for (i = 0; i < a.ln || i < b.ln || cy > 0; i++) {
		if (i < a.ln) cy += a.v[i];   
		if (i < b.ln) cy += b.v[i];   
		res.v[i] = cy % base; cy /= base;  
	}  
	res.ln = i;  
	return res; 
} 

BigInt operator - (const BigInt& a, const BigInt& b) {
	BigInt res; int i, cy = 0;  
	for (res.ln = a.ln, i = 0; i < res.ln; i++) {
		res.v[i] = a.v[i] - cy;
		if (i < b.ln) res.v[i] -= b.v[i];
		if (res.v[i] < 0) cy = 1, res.v[i] += base;
		else cy = 0;  
	}  
	while (res.ln > 0 && res.v[res.ln - 1] == 0) res.ln--;  
	return res; 
} 

BigInt operator * (const BigInt& a, const BigInt& b) {
	BigInt res; res.ln = 0;  
	if (0 == b.ln) { res.v[0] = 0; return res; }  
	int i, j, cy;  
	for (i = 0; i < a.ln; i++) {   
		for (j=cy=0; j < b.ln || cy > 0; j++, cy/= base) {    
			if (j < b.ln) cy += a.v[i] * b.v[j];    
			if (i + j < res.ln) cy += res.v[i + j];    
			if (i + j >= res.ln) res.v[res.ln++] = cy % base;    
			else res.v[i + j] = cy % base;   
		}  
	} 
	return res; 
} 

BigInt operator / (const BigInt& a, const BigInt& b) {   // ! b != 0  
	BigInt tmp, mod, res;  
	int i, lf, rg, mid;  
	mod.v[0] = mod.ln = 0;  
	for (i = a.ln - 1; i >= 0; i--) {   
		mod = mod * base + a.v[i];   
		for (lf = 0, rg = base -1; lf < rg; ) {    
			mid = (lf + rg + 1) / 2;    
			if (b * mid <= mod) lf = mid;    
			else rg = mid - 1;   
		}   
		res.v[i] = lf;   
		mod = mod - b * lf;  
	}  
	res.ln = a.ln;  
	while (res.ln > 0 && res.v[res.ln - 1] == 0) res.ln--;  
	return res;          // return mod 就是%运算 
} 

BigInt operator % (const BigInt& a, const BigInt& b) {   // ! b != 0  
	BigInt tmp, mod, res;  
	int i, lf, rg, mid;  
	mod.v[0] = mod.ln = 0;  
	for (i = a.ln - 1; i >= 0; i--) {   
		mod = mod * base + a.v[i];   
		for (lf = 0, rg = base -1; lf < rg; ) {    
			mid = (lf + rg + 1) / 2;    
			if (b * mid <= mod) lf = mid;    
			else rg = mid - 1;   
		}   
		res.v[i] = lf;   
		mod = mod - b * lf;  
	}  
	res.ln = a.ln;  
	while (res.ln > 0 && res.v[res.ln - 1] == 0) res.ln--;  
	return mod;   
} 

int digits(BigInt& a) {   // 返回位数 
	if (a.ln == 0) return 0;  
	int l = ( a.ln - 1 ) * 4;  
	for (int t = a.v[a.ln - 1]; t; ++l, t/=10) ;  
	return l; 
}

bool read(BigInt& b, char buf[]) {  // 读取失败返回0   
	if (1 != scanf("%s", buf)) return 0;  
	int w, u, ln = strlen(buf);  
	memset(&b, 0, sizeof(BigInt));  
	if ('0' == buf[0] && 0 == buf[1]) return 1;  
	for (w = 1, u = 0; ln; ) {   
		u += (buf[--ln] - '0') * w;   
		if (w * 10 == base) {    
			b.v[b.ln++] = u; u = 0; w = 1;   
		}   
		else w *= 10;  
	}  
	if (w != 1) b.v[b.ln++] = u;  
	return 1; 
} 

void write(const BigInt& v) {
	int i;  
	printf("%d", v.ln == 0 ? 0 : v.v[v.ln - 1]);  
	for (i = v.ln - 2; i >= 0; i--)   
		printf("%04d", v.v[i]);  // ! 4 == width  
	printf("\n"); 
} 




bool vis[15];
BigInt ten(10);
BigInt zero(0);

void deal(BigInt x) {
	while (zero < x) {
		vis[(x % ten).v[0] % 10] = true;
		x = x / ten;
	}
}

bool check() {
	for (int i = 0; i < 10; i++) {
		if (!vis[i]) return false;
	}
	return true;
}

int main() {
	int kase = 0;
	int T;
	char buf[10];
	scanf("%d", &T);
	while (T--) {
		printf("Case #%d: ", ++kase);
		BigInt n;
		read(n, buf);
		if (n <= zero) {
			printf("INSOMNIA\n");
			continue;
		}
		memset(vis, 0, sizeof(vis));
		BigInt tmp;
		for (int i = 1; ; i++) {
			tmp = BigInt(i);
			deal(n * tmp);
			if (check()) {
				write(n * tmp);
				break;
			}
		}
	}
	return 0;
}
