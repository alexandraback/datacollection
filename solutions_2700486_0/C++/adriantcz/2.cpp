#include<iostream>
#include<vector>
#include<cmath>
#define VECINT std::vector<int>


int P=0;
int praw(int n, int k, int w, int a = 0, int b = 0){
	if(a>w||b>w)
		return 0;
	

	if(n==0){
		++P;
		if(a>=k)
			return 1;
		else
			return 0;
	}
	else
		return praw(n-1,k,w,a+1,b)+praw(n-1,k,w,a,b+1);
		
}

int main(){
	int T;
	std::cin >> T;
	
	VECINT DW(3);
	VECINT W(3);
	DW[0]=1;
	DW[1]=6;
	DW[2]=15;
	
	W[0]=0;
	W[1]=2;
	W[2]=4;
	W[3]=8;
	
	for(int i=0; i <T;++i){
		P=0;
		double R=-1;
		int n;
		std::cin >> n;
		int x,y;
		std::cin >> x >> y;
		x=fabs(x);
		int w;
		
		if((x+y)==0)
			R=1;
		else if((x+y)==2)
			w = 1;
		else if((x+y)==4)
			w = 2;
		else if((x+y)==8)
			w = 3;
		else
			R = 0;
			
		if(R==(-1)){
			n-=DW[w-1];
				
			if(n>=W[w]+y+1)
				R=1;
			else if(n<y+1)
				R=0;
			else{
				if(x==0)
					R=0;
				else{
					R=(double)praw(n,y+1,W[w])/P;
				}
			}
			
		}
		
		if(R==(int)R)
			std::cout << "Case #" << (i+1) << ": " << R << ".0" <<std::endl;
		else
			std::cout << "Case #" << (i+1) << ": " << R  <<std::endl;
		
	}
	
	return 0;
}
