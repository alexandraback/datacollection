#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>

#define EPS 0.000001

double dist_to_wall(int r, int c, int dr, int dc, char* board, int H, int W) {
	double dist = 0;
	if (dr > 0 && !dc) {
		while (board[r * W + c] != '#') {
			++r;
			dist += 1.0;
		}
		dist -= .5;
	}
	else if (dr < 0 && !dc) {
		while (board[r * W + c] != '#') {
			--r;
			dist += 1.0;
		}
		dist -= .5;
	}
	else if (dc > 0 && !dr) {
		while (board[r * W + c] != '#') {
			++c;
			dist += 1.0;
		}
		dist -= .5;
	}
	else if (dc < 0 && !dr) {
		while (board[r * W + c] != '#') {
			--c;
			dist += 1.0;
		}
		dist -= .5;
	}
	else {
		errno = EINVAL;
		perror("d");
		exit(1);
	}
	return dist;
}

int num_even_reflects_dir(int r, int c, int x_dir, int y_dir, char* board, int H, int W, int D) {
	int bounces = 0;
	double x_close = dist_to_wall(r, c, 0, x_dir, board, H, W);
	double y_close = dist_to_wall(r, c, y_dir, 0, board, H, W);
	double x_far = dist_to_wall(r, c, 0, -x_dir, board, H, W);
	double y_far = dist_to_wall(r, c, -y_dir, 0, board, H, W);
	double dist;
	//Direct Path
	dist = sqrt(x_close*x_close + y_close*y_close);
	if (dist > D)
		return 0;//Can't even make it directly to the corner
	int count = 1; //direct is ok;

	double f,p;
	//Part 1
	bounces = 1;
	while(1) {
		if (bounces % 2 == 1)
			p = x_far / W;
		else
			p = x_close / W;
		f = y_close / (p + bounces);

		//get len of short piece
		if (bounces % 2 == 1)
			dist = sqrt(x_far * x_far + f*p*f*p);
		else
			dist = sqrt(x_close * x_close + f*p*f*p);
		dist += bounces * sqrt(f*f + W*W);
		dist *= 2; //there and back again
		if (dist < D + EPS) {
			++count;
			++bounces;
		}
		else {
			break;
		}
	}

	//Part 1
	bounces = 1;
	while(1) {
		if (bounces % 2 == 1)
			p = y_far / H;
		else
			p = y_close / H;
		f = x_close / (p + bounces);

		//get len of short piece
		if (bounces % 2 == 1)
			dist = sqrt(y_far * y_far + f*p*f*p);
		else
			dist = sqrt(y_close * y_close + f*p*f*p);
		dist += bounces * sqrt(f*f + H*H);
		dist *= 2; //there and back again
		if (dist < D + EPS) {
			++count;
			++bounces;
		}
		else {
			break;
		}
	}
	return count;
}

int num_even_reflects(int r, int c, char* board, int H, int W, int D) {
	return num_even_reflects_dir(r, c, -1, -1, board, H, W, D) +
	       num_even_reflects_dir(r, c, -1, 1, board, H, W, D) +
	       num_even_reflects_dir(r, c, 1, -1, board, H, W, D) +
	       num_even_reflects_dir(r, c, 1, 1, board, H, W, D);
}

int num_odd_reflects(int r, int c, char* board, int H, int W, int D) {
	int loops;
	int count = 0;
	double d, x, y, dist, length, d1, d2;

	//right
	loops = 1;
	d = dist_to_wall(r, c, 0, 1, board, H, W);
	while (1) {
		x = r - .5;
		y = H - 2 - x;
		dist = d / loops;
		d1 = dist / (y / x + 1);
		d2 = dist / (x / y + 1);
		length = loops * ( 
				sqrt(x*x + d1*d1) + //Hypotenuse 1
				sqrt(y*y + d2*d2)   //Hypotenuse 2
				) * 2.0;
		if (length < D + EPS) {
			printf("Found loop of length %lf\n", length);
			++count; //found one
			++loops; //keep going
		}
		else {
			printf("Didn't find loop of length %lf\n", length);
			break;
		}
	}

	//left
	loops = 1;
	d = dist_to_wall(r, c, 0, -1, board, H, W);
	while (1) {
		x = r - .5;
		y = H - 2 - x;
		dist = d / loops;
		d1 = dist / (y / x + 1);
		d2 = dist / (x / y + 1);
		length = loops * ( 
				sqrt(x*x + d1*d1) + //Hypotenuse 1
				sqrt(y*y + d2*d2)   //Hypotenuse 2
				) * 2.0;
		if (length < D + EPS) {
			printf("Found loop of length %lf\n", length);
			++count; //found one
			++loops; //keep going
		}
		else break;
	}

	//down
	loops = 1;
	d = dist_to_wall(r, c, 1, 0, board, H, W);
	while (1) {
		x = c - .5;
		y = W - 2 - x;
		dist = d / loops;
		d1 = dist / (y / x + 1);
		d2 = dist / (x / y + 1);
		length = loops * ( 
				sqrt(x*x + d1*d1) + //Hypotenuse 1
				sqrt(y*y + d2*d2)   //Hypotenuse 2
				) * 2.0;
		if (length < D + EPS) {
			printf("Found loop of length %lf\n", length);
			++count; //found one
			++loops; //keep going
		}
		else break;
	}

	//up
	loops = 1;
	d = dist_to_wall(r, c, -1, 0, board, H, W);
	while (1) {
		x = c - .5;
		y = W - 2 - x;
		dist = d / loops;
		d1 = dist / (y / x + 1);
		d2 = dist / (x / y + 1);
		length = loops * ( 
				sqrt(x*x + d1*d1) + //Hypotenuse 1
				sqrt(y*y + d2*d2)   //Hypotenuse 2
				) * 2.0;
		if (length < D + EPS) {
			printf("Found loop of length %lf\n", length);
			++count; //found one
			++loops; //keep going
		}
		else break;
	}
	return count;
}

int num_1_reflects(int r, int c, char* board, int H, int W, int D) {
	int count = 0;
	if (dist_to_wall(r, c, 1, 0, board, H, W) * 2.0 < D + EPS) {
		++count;
	}
	if (dist_to_wall(r, c, 0, 1, board, H, W) * 2.0 < D + EPS) {
		++count;
	}
	if (dist_to_wall(r, c, -1, 0, board, H, W) * 2.0 < D + EPS) {
		++count;
	}
	if (dist_to_wall(r, c, 0, -1, board, H, W) * 2.0 < D + EPS) {
		++count;
	}
	return count;
}

int num_reflects(int r, int c, char* board, int H, int W, int D) {
	return num_1_reflects(r, c, board, H, W, D) +
	       num_odd_reflects(r, c, board, H, W, D) +
	       num_even_reflects(r, c, board, H, W, D);
}

//Plenty long, only needs to be 30
#define BUF_LEN 256
int main() {
	int T, H, W, D;
	scanf("%d", &T);
	int i, r, c;
	char buffer[BUF_LEN];
	char *board;
	int Xr, Xc;
	for (i = 0; i < T; ++i) {
		scanf("%d %d %d\n", &H, &W, &D);
		board = (char*) malloc(H * W * sizeof(char));
		for (r = 0; r < H; ++r) {
			fgets(buffer, BUF_LEN, stdin);
			buffer[BUF_LEN] = '\0'; //Just in case
			for (c = 0; c < W; ++c) {
				board[r*W + c] = buffer[c];
				if (buffer[c] == 'X') {
					Xr = r;
					Xc = c;
				}
			}
		}
		int num = num_reflects(Xr, Xc, board, H, W, D);
		printf("Case #%d: %d\n", i + 1, num);
		free(board);
	}
}
