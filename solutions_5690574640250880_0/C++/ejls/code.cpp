#include <iostream>
#include <vector>

int H, L, M;
int min, max, total;
int safe_fill;

bool impossible;
std::vector<std::vector<bool> > map;
void process();

void degenerate_map1(){
	for(int i=0; i<M; ++i)
		map[H==1?0:i][H==1?i:0]=true;
}

void degenerate_map2(){
	if(M%2 && M!=max*2-1 || M==max*2-2)
		impossible=true;
	else
		for(int i=0; i<(M+1)/2; ++i)
			map[H==2?0:i][H==2?i:0]=map[H==2?1:i][H==2?i:1]=true;
}

void degenerate_map3(int dy=0, int dx=0){
	if(M==1)
		map[dy+0][dx+0]=true;
	else if(M==3)
		map[dy+0][dx+0]=map[dy+0][dx+1]=map[dy+0][dx+2]=true;
	else if(M==5)
		map[dy+0][dx+0]=map[dy+0][dx+1]=map[dy+0][dx+2]=map[dy+1][dx+0]=map[dy+2][dx+0]=true;
	else if(M==8)
		map[dy+0][dx+0]=map[dy+0][dx+1]=map[dy+0][dx+2]=map[dy+1][dx+0]=map[dy+1][dx+1]=map[dy+1][dx+2]=map[dy+2][dx+0]=map[dy+2][dx+1]=map[dy+2][dx+2]=true;
	else if(M!=0)
		impossible=true;
}

void easy_fill(){
	for(int y=0; y<H; ++y)
		for(int x=0; x<L; ++x)
			if(y<H-2 && x<L-2 && M>0){
				map[y][x]=true;
				--M;
			}
}

void it_s_complicated(){
	easy_fill();

	if(M%2){
		map[H-3][L-3]=false;
		++M;
	}

	for(int y=0; y<H-3; ++y)
		if(M>1){
			map[y][L-1]=map[y][L-2]=true;
			M-=2;
		}

	for(int x=0; x<L-3; ++x)
		if(M>1){
			map[H-1][x]=map[H-2][x]=true;
			M-=2;
		}

	if(M>0 && map[H-3][L-3]){
		map[H-3][L-3]=false;
		++M;
	}

	degenerate_map3(H-3, L-3);
}

void process(){
	min=std::min(H, L);
	max=std::max(H, L);
	total=H*L;
	safe_fill=(min-2)*(max-2);
	impossible=false;
	map.clear();
	map.resize(H, std::vector<bool>(L, false));

	if(min==1)
		degenerate_map1();
	else if(min==2)
		degenerate_map2();
	else if(max==3)
		degenerate_map3();
	else if(M<=safe_fill)
		easy_fill();
	else
		it_s_complicated();
}

void print_sol(){
	if(impossible)
		std::cout << "Impossible\n";
	else{
		for(std::vector<std::vector<bool> >::const_iterator ite=map.begin(); ite!=map.end(); ++ite){
			for(std::vector<bool>::const_iterator iti=ite->begin(); iti!=ite->end(); ++iti)
				if(ite==map.end()-1 && iti==ite->end()-1)
					std::cout << 'c';
				else
					std::cout << (*iti?'*':'.');
			std::cout << '\n';
		}
	}
}

int main(){
	int T;
	std::cin >> T;
	for(int t=1; t<=T; ++t){
		std::cout << "Case #" << t << ":\n";
		std::cin >> H >> L >> M;
		process();
		print_sol();
	}
}

void harder_fill(){
	if(H==max){
		int x=0;
		while(M>H){
			for(int i=0; i<H; ++i)
				map[i][x]=true;
			++x;
			M-=H;
		}
		int y=0;
		while(M>0){
			map[y][L-1]=map[y][L-2]=true;
			M-=2;
		}
	} else {
		int y=0;
		while(M>L){
			for(int i=0; i<L; ++i)
				map[y][i]=true;
			++y;
			M-=L;
		}
		int x=0;
		while(M>0){
			map[H-1][x]=map[H-2][x]=true;
			M-=2;
		}
	}
}
