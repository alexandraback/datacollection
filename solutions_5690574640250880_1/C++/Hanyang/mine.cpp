#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
	if(argc < 2) {
		printf("No input file\n");
		return -1;
	}
	ifstream input;
	input.open(argv[1]);
	ofstream output;
	output.open("output");
	
	// number of cases
	int caseNum = 0;
	input>>caseNum;
	int counter = 0;
	while(counter < caseNum) {
		int r,c,m;
		input>>r>>c>>m;
		int space = r*c;
		output<<"Case #"<<counter+1<<":"<<endl;
		if(m == space) {
			output<<"Impossible"<<endl;
		}
		else if(m == space - 1) {
			for(int i = 0; i < r; i ++) {
				for(int j = 0; j < c; j ++) {
					if(i == 0 && j == 0) output<<'c';
					else output<<'*';
				}
				output<<endl;
			}
		}
		else if(m == 0) {
			for(int i = 0; i < r; i ++) {
				for(int j = 0; j < c; j ++) {
					if(i == 0 && j == 0) output<<'c';
					else output<<'.';
				}
				output<<endl;
			}
		}
		else if(r == 1 || c == 1) {
			bool rFlag = true;
			int large = c;
			if(c == 1) {
				rFlag = false;
				large = r;
			}
			for(int i = 0; i < large; i ++) {
				if(i < m) output<<'*';
				else {
					if(i == large - 1) output<<'c';
					else output<<'.';
				}
				if(!rFlag) output<<endl;
			}
			if(rFlag) output<<endl;
		}
		else if(r == 2 || c == 2){
			if(m%2 == 1) {
				output<<"Impossible"<<endl;
			}
			else {
				if(m == space - 2){
					output<<"Impossible"<<endl;
				}
				else {
					if(c == 2) {
						int mr = m/2;
						for(int i = 0; i < r; i ++) {
							if(i < mr) output<<"**"<<endl;
							else{
								if(i == r-1) output<<".c"<<endl;
								else output<<".."<<endl;
							}
						}
					}
					else {
						int cr = m/2;
						for(int i = 0; i < c; i ++) {
							if(i < cr) output<<'*';
							else output<<'.';
						}
						output<<endl;
						for(int i = 0; i < c; i ++) {
							if(i < cr) output<<'*';
							else {
								if(i == c-1) output<<'c'<<endl;
								else output<<'.';
							}
						}
					}
				}
			}
		}
		else {
			int empty = space - m;
			bool odd = true;
			if(empty%2 == 0) odd = false;
			if((odd && empty < 9) || (!odd && empty == 2)) {
				output<<"Impossible"<<endl;
			}
			else {
				int er = empty/c;
				int lf = empty%c;
				if(er >= 2) {
					if(lf == 1) {
						if(er == 2) {
							for(int i = 0; i < r; i ++) {
								for(int j = 0; j < c; j ++) {
									if(i == 0 && j == 0) output<<'c';
									else {
										if(i < 2) {
											if(j == c-1) output<<'*';
											else output<<'.';
										}
										else if(i == 2 && j < 3) output<<'.';
										else output<<'*';
									}
								}
								output<<endl;
							}
						}
						else {
							for(int i = 0; i < r; i ++) {
								for(int j = 0; j < c; j ++){
									if(i == 0 && j == 0) output<<'c';
									else{
										if(i < er-1) output<<'.';
										else if(i == er-1) {
											if(j == c-1) output<<'*';
											else output<<'.';
										}
										else if(i == er) {
											if(j < 2) output<<'.';
											else output<<'*';
										}
										else output<<'*';
									}
								}
								output<<endl;
							}
						}
					}
					else{
						for(int i = 0; i < r; i ++) {
							for(int j = 0; j < c; j ++) {
								if(i == 0 && j == 0) output<<'c';
								else {
									if(i < er) output<<'.';
									else if(i == er && j < lf) output<<'.';
									else output<<'*';
								}
							}
							output<<endl;
						}
					}
				}
				else{
					if(odd) {
						int mc3 = empty/3;
						int ml3 = empty%3;
						for(int i = 0; i < r; i ++) {
							for(int j = 0; j < c; j ++) {
								if(i == 0 && j == 0) output<<'c';
								else{
									if(i < 3) {
										if(ml3 == 0) {
											if(j < mc3) output<<'.';
											else output<<'*';
										}
										else if(ml3 == 1) {
											if(i < 2 && j <= mc3) output<<'.';
											else if(i == 2 && j < mc3-1) output<<'.';
											else output<<'*';
										}
										else if(ml3 == 2) {
											if(j < mc3) output<<'.';
											else if(j == mc3 && i < 2) output <<'.';
											else output<<'*';
										}
									}
									else output<<'*';
								}
							}
							output<<endl;
						}
					}
					else{
						int mc = empty/2;
						for(int i = 0; i < r; i ++){
							for(int j = 0; j < c; j ++){
								if(i == 0 && j == 0) output<<'c';
								else{
									if(i < 2 && j < mc) output<<'.';
									else output<<'*';
								}
							}
							output<<endl;
						}
					}
				}
			}
		}
		counter ++;
	}
	input.close();
	output.close();
	return 0;
}