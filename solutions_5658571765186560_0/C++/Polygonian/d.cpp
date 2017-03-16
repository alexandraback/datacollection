#include <iostream>
#include <assert.h>
#include <vector>

using namespace std;

int flood(char *A, int x, int y, int W, int H) {
	const int xy = x + y * W;
	assert(A[xy] == 0);
	A[xy] = 1;
	int count = 1;
	if (x > 0 && A[xy - 1] == 0) count += flood(A, x - 1, y, W, H);
	if (x < W - 1 && A[xy + 1] == 0) count += flood(A, x + 1, y, W, H);
	if (y > 0 && A[xy - W] == 0) count += flood(A, x, y - 1, W, H);
	if (y < H - 1 && A[xy + W] == 0) count += flood(A, x, y + 1, W, H);
	return count;
}

bool testShapeXY(const char *a, int w, int h, int ox, int oy,
	char *A, int W, int H, int K) {

	memset(A, 0, sizeof(char) * W * H);
	for (int y = 0, xy = 0; y < h; y++) {
		for (int x = 0; x < w; x++, xy++) {
			if (a[xy] != '.') {
				A[(ox + x) + (oy + y) * W] = 2;
			}
		}
	}
	// cout << "(" << K << ") -------------------------------------" << endl;
	// for (int y = 0, xy = 0; y < H; y++) {
	// 	for (int x = 0; x < H; x++, xy++) {
	// 		cout << A[xy];
	// 	}
	// 	cout << endl;
	// }

	for (int y = 0, xy = 0; y < H; y++) {
		for (int x = 0; x < W; x++, xy++) {
			if (A[xy] == 0) {
				int count = flood(A, x, y, W, H);
				if (count % K != 0) {
					// cout << "FALSE";
					return false;
				}
			}
		}
	}
	// cout << "TRUE" << endl;
	return true;
}

bool testShapeOneMinor(const char *a, int w, int h, char *A, int W, int H, int K) {
	if (((W * H) % K) != 0) return false;  // will not fit;
	if (W >= w + 2 && H >= h + 2) return true;  // will always fit;
	bool successful = false;
	for (int y = 0; y < H; y++) {
		if (y + h > H) continue;
		for (int x = 0; x < W; x++) {
			if (x + w > W) continue;
			bool t = testShapeXY(a, w, h, x, y, A, W, H, K);
			if (t) {
				return true;
			}
		}
	}
	return false;
}

struct Shape {
	const char *a;
	int w, h;
	int K;
	vector<Shape *> minors;
public:
	Shape(const char *argA, int argW, int argH, int argK) :
		a(argA), w(argW), h(argH), K(argK) {
		if (strlen(a) != w * h) {
			cout << "BAD: " << a << " " << w << " " << h << " " << K << endl;
			assert(0);
		}
		int count = 0;
		for (int i = 0; i < strlen(a); i++) {
			assert(a[i] == '.' || a[i] == 'X');
			if (a[i] == 'X') count++;
		}
		assert(count == K);
	}
	void print() {
		cout << "---- " << K << " ----" << endl;
		for (int y = 0, xy = 0; y < h; y++) {
			for (int x = 0; x < w; x++, xy++) {
				cout << a[xy];
			}
			cout << endl;
		}
	}
	bool operator==(const Shape &s) const {
		return s.w == w && s.h == h && strcmp(s.a, a) == 0;
	}
};

vector<Shape *> S1;
vector<Shape *> S2;
vector<Shape *> S3;
vector<Shape *> S4;
vector<Shape *> S5;
vector<Shape *> S6;

bool testShape(Shape *shape, char *A, int W, int H, int K) {
	for (int i = 0; i < int(shape->minors.size()); i++) {
		if (testShapeOneMinor(shape->minors[i]->a,
			shape->minors[i]->w,
			shape->minors[i]->h,
			A, W, H, K)) return true;
	}
	return false;
}

bool solve(int W, int H, int K) {
	if ((W * H) % K != 0) {
		return true;  // first one always win;
	}
	if (K >= 7) {
		return true;  // first one always win;
	}
	bool firstOneWins = false;
	char *A = new char[W * H];

	vector<Shape *> *S = 0;
	if (K == 1) S = &S1;
	if (K == 2) S = &S2;
	if (K == 3) S = &S3;
	if (K == 4) S = &S4;
	if (K == 5) S = &S5;
	if (K == 6) S = &S6;

	for (int i = 0; i < int(S->size()); i++) {
		// cout << "testing: " << endl;
		Shape *shape = (*S)[i];
		if (testShape(shape, A, W, H, K)) continue;  // will be able to do it;
		// cout << "AHA-the following shape will allow RICHARD to win:" << endl;
		// shape->print();
		// cout << "---" << endl;
		firstOneWins = true;
		break;
	}
	delete[] A;
	return firstOneWins;
}

void makeShape(Shape *shape, vector<Shape *> &shapes, int K) {
	int shapeStart = int(shapes.size());
	for (int i = 0; i < 8; i++) {
		const int sw = shape->w;
		const int sh = shape->h;
		const int h = i < 4 ? sh : sw;
		const int w = i < 4 ? sw : sh;
		// cout << i << ": " << "w = " << w << ", h = " << h << endl;
		// cout << i << ": " << "sw = " << sw << ", sh = " << sh << endl;
		char *a = new char[w * h + 1];
		memset(a, 0, sizeof(char) * (w * h + 1));
		for (int y = 0, xy = 0; y < h; y++) {
			for (int x = 0; x < w; x++, xy++) {
				int sx, sy;
				switch (i) {
					case 0: sx = x; sy = y; break;
					case 1: sx = x; sy = sh - 1 - y; break;
					case 2: sx = sw - 1 - x; sy = y; break;
					case 3: sx = sw - 1 - x; sy = sh - 1 - y; break;
					case 4: sx = y; sy = x; break;
					case 5: sx = sw - 1 - y; sy = x; break;
					case 6: sx = y; sy = sh - 1 - x; break;
					case 7: sx = sw - 1 - y; sy = sh - 1 - x; break;
				}
				// cout << i << ": " << "a[xy] = " << a[xy] << " --> " << x << " " << y << " " << sx << " " << sy << endl;
				assert(sx >= 0 && sy >= 0 && sx < shape->w && sy < shape->h);
				assert(sx + sy * sw < shape->w * shape->h);
				a[xy] = shape->a[sx + sy * sw];
			}
		}
		Shape *newShape = new Shape(a, w, h, K);
		bool identical = false;
		for (int i = shapeStart; i < int(shapes.size()); i++) {
			if (*newShape == *shapes[i]) identical = true;
		}
		if (!identical) {
			shapes.push_back(newShape);
		}
	}
}

void makeShapes(vector<Shape *> shapes, int K) {
	for (int i = 0; i < int(shapes.size()); i++) {
		makeShape(shapes[i], shapes[i]->minors, K);
	}
	// cout << "WHAT? " << shapeAlls.size() << endl;
	// for (int i = 0; i < int(shapeAlls.size()); i++) {
	// 	shapeAlls[i]->print();
	// }
}

void init() {
	S1.push_back(new Shape("X", 1, 1, 1));

	S2.push_back(new Shape("XX", 2, 1, 2));

	S3.push_back(new Shape("XXX", 3, 1, 3));
	S3.push_back(new Shape("XXX.", 2, 2, 3));

	S4.push_back(new Shape("XXXX", 4, 1, 4));
	S4.push_back(new Shape("XXXX", 2, 2, 4));
	S4.push_back(new Shape("XXXX..", 3, 2, 4));
	S4.push_back(new Shape("XXX.X.", 3, 2, 4));
	S4.push_back(new Shape(".XXXX.", 3, 2, 4));

	S5.push_back(new Shape(".XXXX..X.", 3, 3, 5));
	S5.push_back(new Shape("XXXXX", 5, 1, 5));
	S5.push_back(new Shape("XXXXX...", 4, 2, 5));
	S5.push_back(new Shape("XX...XXX", 4, 2, 5));
	S5.push_back(new Shape("XXX.XX", 3, 2, 5));
	S5.push_back(new Shape("XXX.X..X.", 3, 3, 5));
	S5.push_back(new Shape("X.XXXX", 3, 2, 5));
	S5.push_back(new Shape("XXXX..X..", 3, 3, 5));
	S5.push_back(new Shape(".XXXX.X..", 3, 3, 5));
	S5.push_back(new Shape(".X.XXX.X.", 3, 3, 5));
	S5.push_back(new Shape("..X.XXXX", 4, 2, 5));
	S5.push_back(new Shape("XX..X..XX", 3, 3, 5));

	S6.push_back(new Shape("XXXXXX", 6, 1, 6));
	S6.push_back(new Shape("XXXXXX....", 5, 2, 6));
	S6.push_back(new Shape("XXXXX.X...", 5, 2, 6));
	S6.push_back(new Shape("XXXXX..X..", 5, 2, 6));
	S6.push_back(new Shape("XXXX....XX", 5, 2, 6));
	S6.push_back(new Shape("XXXXXX..", 4, 2, 6));
	S6.push_back(new Shape("XXXXX.X.", 4, 2, 6));
	S6.push_back(new Shape("XXXXX..X", 4, 2, 6));
	S6.push_back(new Shape("XXXX.XX.", 4, 2, 6));
	S6.push_back(new Shape("XXXXX...X...", 4, 3, 6));
	S6.push_back(new Shape("XXXX.X...X..", 4, 3, 6));
	S6.push_back(new Shape("XXX.X..X..X.", 3, 4, 6));
	S6.push_back(new Shape(".XXXX..X..X.", 3, 4, 6));
	S6.push_back(new Shape(".XX.X.XX..X.", 3, 4, 6));
	S6.push_back(new Shape(".XX.X..X.XX.", 3, 4, 6));
	S6.push_back(new Shape(".X..XXXX..X.", 3, 4, 6));
	S6.push_back(new Shape(".X.XXX.X..X.", 3, 4, 6));
	S6.push_back(new Shape(".X.XXXX..X..", 3, 4, 6));
	S6.push_back(new Shape(".XXXX.XX", 2, 4, 6));
	S6.push_back(new Shape(".X.XXXX.X.", 2, 5, 6));
	S6.push_back(new Shape(".XXXXXX.", 2, 4, 6));
	S6.push_back(new Shape("XXXXXX", 2, 3, 6));
	S6.push_back(new Shape("..XXXX.X..X.", 3, 4, 6));
	S6.push_back(new Shape("XXX.XX.X.", 3, 3, 6));
	S6.push_back(new Shape("..X.XXXX..X.", 3, 4, 6));
	S6.push_back(new Shape("..XXXXX..X..", 3, 4, 6));
	S6.push_back(new Shape(".XXXX.X..X..", 3, 4, 6));
	S6.push_back(new Shape("XXXX.XX..", 3, 3, 6));
	S6.push_back(new Shape("X.XXXXX..", 3, 3, 6));
	S6.push_back(new Shape("X.XXXX.X.", 3, 3, 6));
	S6.push_back(new Shape(".XX.X.XX.X..", 3, 4, 6));
	S6.push_back(new Shape("X..XX.XXX", 3, 3, 6));
	S6.push_back(new Shape(".X.XXXXX.", 3, 3, 6));
	S6.push_back(new Shape("..XXXXXX.", 3, 3, 6));
	S6.push_back(new Shape("..X.XXXX.X..", 3, 4, 6));

	makeShapes(S1, 1);
	makeShapes(S2, 2);
	makeShapes(S3, 3);
	makeShapes(S4, 4);
	makeShapes(S5, 5);
	makeShapes(S6, 6);
}

int main(void) {
	init();
	int T;
	scanf("%d", &T);
	int X, R, C;
	for (int i = 0; i < T; i++) {
		scanf("%d%d%d", &X, &R, &C);
		bool answer = solve(R, C, X);
		if (answer) {
			printf("Case #%d: %s\n", i + 1, "RICHARD");
		} else {
			printf("Case #%d: %s\n", i + 1, "GABRIEL");
		}
	}
	return 0;
}
