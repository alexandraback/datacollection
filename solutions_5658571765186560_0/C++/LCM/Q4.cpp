#include<cstdio>

int t, x, rr, c;
bool r;

int main() {
//	freopen("D-small-attempt0.in", "r", stdin);
//	freopen("D-small-attempt0.out", "w", stdout);
	scanf("%d", &t);
	for (int zzz = 1 ; zzz <= t ; zzz++) {
		scanf("%d %d %d", &x, &rr, &c);
		switch (x * 100 + rr * 10 + c) {
			case 111 : r = false; break;
			case 112 : r = false; break;
			case 113 : r = false; break;
			case 114 : r = false; break;
			case 121 : r = false; break;
			case 122 : r = false; break;
			case 123 : r = false; break;
			case 124 : r = false; break;
			case 131 : r = false; break;
			case 132 : r = false; break;
			case 133 : r = false; break;
			case 134 : r = false; break;
			case 141 : r = false; break;
			case 142 : r = false; break;
			case 143 : r = false; break;
			case 144 : r = false; break;
			case 211 : r = true; break;
			case 212 : r = false; break;
			case 213 : r = true; break;
			case 214 : r = false; break;
			case 221 : r = false; break;
			case 222 : r = false; break;
			case 223 : r = false; break;
			case 224 : r = false; break;
			case 231 : r = true; break;
			case 232 : r = false; break;
			case 233 : r = true; break;
			case 234 : r = false; break;
			case 241 : r = false; break;
			case 242 : r = false; break;
			case 243 : r = false; break;
			case 244 : r = false; break;
			case 311 : r = true; break;
			case 312 : r = true; break;
			case 313 : r = true; break;
			case 314 : r = true; break;
			case 321 : r = true; break;
			case 322 : r = true; break;
			case 323 : r = false; break;
			case 324 : r = true; break;
			case 331 : r = true; break;
			case 332 : r = false; break;
			case 333 : r = false; break;
			case 334 : r = false; break;
			case 341 : r = true; break;
			case 342 : r = true; break;
			case 343 : r = false; break;
			case 344 : r = true; break;
			case 411 : r = true; break;
			case 412 : r = true; break;
			case 413 : r = true; break;
			case 414 : r = true; break;
			case 421 : r = true; break;
			case 422 : r = true; break;
			case 423 : r = true; break;
			case 424 : r = true; break;
			case 431 : r = true; break;
			case 432 : r = true; break;
			case 433 : r = true; break;
			case 434 : r = false; break;
			case 441 : r = true; break;
			case 442 : r = true; break;
			case 443 : r = false; break;
			case 444 : r = false; break;
		}
		if (r) printf("Case #%d: RICHARD\n", zzz);
		else printf("Case #%d: GABRIEL\n", zzz);
	}
}
