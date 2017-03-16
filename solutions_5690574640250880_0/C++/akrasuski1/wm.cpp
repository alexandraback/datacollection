/*
 * wm.cpp
 *
 *  Created on: 12 kwi 2014
 *      Author: admin
 */
#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;

struct rect{
	int a;
	int h;
};

#define DEBUG_INFO 0

vector<rect> solve(vector<rect>solution,int n,int r,int c){
	//this function assumes we already have some empty (no mines) columns to the right, saved in solution vector.
	//if it is empty, then there is edge of the board to the right.

	if(DEBUG_INFO){printf("Called with n=%d, r=%d, c=%d\n",n,r,c);}

	vector<rect> emp; //returning empty vector means no solution found

	//base cases:
	if(n==0){
		return solution;//this solution is complete, as there are no free places left to place
	}
	if(n>r*c){
		return emp; //impossible to add so many places
	}
	if(n==r*c){
		rect p={c,r};
		solution.push_back(p);
		return solution;
	}
	if(c==1){
		//as this function assumes that the real C is at least 3, it means there is some columns to the right:
		assert(solution.size()>0);
		if(n>1&&n<=r){
			rect p={1,n};
			solution.push_back(p);//we can't have 1 free cell in last column, but other number <=r will fit
			return solution;
		}
		else{
			return emp;
		}
	}
	if(r==2){
		if(solution.empty()){
			if(n<4){
				return emp;
			}
		}
		if(n%2==0){
			if(n<=r*c){
				rect p={n/2,2}; //rectangle 2 squares high and n/2 squares wide
				solution.push_back(p);
				return solution;
			}
		}
		return emp;
	}

	//end of base cases, start of recursion
	for(int a=0;a<c;a++){
		if(a!=1||!solution.empty()){//if this is the first rectangle, its width cannot be 1
			if(n-r*a>=0&&c-a>=1){// parameters for next recurrence must be all right
				vector<rect>sol2=solution;
				if(a!=0){
					rect p={a,r}; //adding rectangle of width a and height r
					sol2.push_back(p);
				}
				vector<rect>sol3=solve(sol2,n-r*a,r-1,c-a);
				if(!sol3.empty()){
					return sol3; //if solution found, return it
				}
			}
		}
	}
	return emp; //unfortunately, nothing found
}

int main(){
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		int r,c,m,n;
		scanf("%d %d %d",&r,&c,&m);
		n=r*c-m;
		printf("Case #%d:\n",i+1);
		if(n==1){
			printf("c");
			for(int j=0;j<c-1;j++){
				printf("*");
			}
			printf("\n");
			for(int j=1;j<r;j++){
				for(int k=0;k<c;k++){
					printf("*");
				}
				printf("\n");
			}
		}
		else if(r==1){
			printf("c");
			for(int j=1;j<n;j++){
				printf(".");
			}
			for(int j=0;j<m;j++){
				printf("*");
			}
			printf("\n");
		}
		else if(c==1){
			printf("c\n");
			for(int j=1;j<n;j++){
				printf(".\n");
			}
			for(int j=0;j<m;j++){
				printf("*\n");
			}
		}
		else if(r==2){
			if(m%2==1){
				printf("Impossible\n");
			}
			else{
				if(n<=2){
					printf("Impossible\n");
				}
				else{
					for(int j=0;j<m/2;j++){
						printf("*");
					}
					for(int j=0;j<n/2;j++){
						printf(".");
					}
					printf("\n");
					for(int j=0;j<m/2;j++){
						printf("*");
					}
					for(int j=0;j<n/2-1;j++){
						printf(".");
					}
					printf("c\n");
				}
			}
		}//all of above cases work, to my knowledge
		else{//the interesting case...
			vector<rect>emp;
			vector<rect> solution=solve(emp,n,r,c);
			if(solution.size()>0){
				if(DEBUG_INFO){
					printf("YAY\n");
					for(int j=0;j<solution.size();j++){
						printf("width: %d, height: %d;\n",solution[j].a,solution[j].h);
					}
					printf("\nWas to write n=%d, r=%d, c=%d\n",n,r,c);
				}
				int free_number[r];
				for(int j=0;j<r;j++){
					int cnt=0;
					//count what is the total width of rectangles higher than j in solution
					for(int k=0;k<solution.size();k++){
						if(solution[k].h>j){
							cnt+=solution[k].a;
						}
					}
					free_number[j]=cnt;
				}

				for(int j=0;j<r;j++){
					if(j==0){
						printf("c");
					}
					for(int k=0;k<free_number[j];k++){
						if(j==0&&k==0){// skip, if 'c' should be written there
							continue;
						}
						printf(".");
					}
					for(int k=0;k<c-free_number[j];k++){
						printf("*");
					}
					printf("\n");
				}
			}
			else{
				printf("Impossible\n");
			}
		}
	}



}

