#include<iostream>
#include<fstream>
#include<vector>
#include<set>
#include<math.h>

std::ifstream file;
std::ofstream ofile;
#define MAXD 52
char maze[33][33];
int h,w;
int d;

int ex;
int ey;

int top,botton,left,right;

class CPos{
public:
	CPos(int a,int b) : x(a),y(b) {};
	void print(){
		std::cout << x << ":" << y << std::endl;
	}
	bool operator >(const CPos& p){
		return (p.x > x);
	}
	bool operator <(const CPos& p){
		return (p.x < x);
	}
	int x,y;
};

class CMaze{
public:
	CMaze(bool xf,bool yf,int xi,int yi,int line,bool sm)
		: x(xi) , y(yi) , xFlop(xf) , yFlop(yf) , flopLine(line) , smaller(sm) {}
	int x,y;
	bool xFlop;
	bool yFlop;
	bool smaller;
	int flopLine;
	CPos getEyePostion(){
			if( xFlop ){  // x-flopLine
				return CPos( x - (ex - flopLine) , y + ey );
			}
			if( yFlop ){ // y-flopLine

			}
	}
};

int gcd(int m,int n){
	if( n==0 ) return m;
	else return gcd( n, m % n );
}

std::pair<int,int> reduce(std::pair<int,int>& p){
	//return p;
	int x = (p.first - ex) ;
	int y = (p.second - ey) ;
	int g = abs( gcd(x,y) );
	int l = ( x*x + y*y ) ;
	if( l <= d*d )
		/*if( x!=0 && y != 0 )
			return std::make_pair<int,int>( (x/abs(x)) * x / g , (y/abs(y)) *  y / g );
		else if( x != 0 )
			return std::make_pair<int,int>( (x/abs(x)) * x / g ,  y / g );
		else
			return std::make_pair<int,int>( x / g ,  (y/abs(y)) * y / g );
			*/
		return std::make_pair<int,int>( x / g ,  y / g );
	else
		return std::make_pair<int,int>( 0, 0 );
		
}

int problem(){
	std::set<std::pair<int,int> > mEyePos;
	file >> h >> w >> d;
	for( int i=0;i<h;i++ ){
		for( int j=0;j<w;j++ ){
			file >> maze[ i ][ j ];
			if( maze[i][j] == 'X' ){
				ex = j; ey=i;
			}
		}
	}
	top = ex*2 -1;
	botton = (w - ex - 1)*2 -1;
	left = ey*2 -1;
	right = (h - ey - 1)*2 -1;
	
	int tx = ex;
	int ty = ey;
	std::set<std::pair<int,int> > tmp;
	tx = ex; ty = ey;
	for( int i=0;i<MAXD;i++ ){ // top
		if( i % 2 == 0 ){
			tx = tx - top;  ty = ty;
		}else{
			tx = tx - botton; ty = ty;
		}
		tmp.insert( std::make_pair( tx , ty ) );
	}
	tx = ex; ty = ey;
	for( int i=0;i<MAXD;i++ ){ // down
		if( i % 2 == 0 ){
			tx = tx + botton;  ty = ty;
		}else{
			tx = tx + top; ty = ty;
		}
		tmp.insert( std::make_pair( tx , ty ) );
	}

	// = mEyePos;
	std::set<std::pair<int,int> >::iterator iter = tmp.begin();
	for( iter ; iter!=tmp.end() ; iter++ ){
		tx = (*iter).first ; ty = (*iter).second;
		for( int i=0;i<MAXD;i++ ){ // left
			if( i % 2 == 0 ){
				tx = tx ;  ty = ty - left;
			}else{
				tx = tx ; ty = ty - right;
			}
			mEyePos.insert( reduce( std::make_pair( tx , ty ) ));
		}
		tx = (*iter).first ; ty = (*iter).second;
		for( int i=0;i<MAXD;i++ ){ // right
			if( i % 2 == 0 ){
				tx = tx ;  ty = ty + right;
			}else{
				tx = tx ; ty = ty + left;
			}
			mEyePos.insert( reduce( std::make_pair( tx , ty )) );
		}		
		mEyePos.insert( reduce( std::make_pair( (*iter).first , (*iter).second ) ) );
	}

	tx = ex; ty = ey;
	for( int i=0;i<MAXD;i++ ){ // left
		if( i % 2 == 0 ){
			tx = tx ;  ty = ty - left;
		}else{
			tx = tx ; ty = ty - right;
		}
		mEyePos.insert( reduce( std::make_pair( tx , ty ) ));
	}
	tx = ex; ty = ey;
	for( int i=0;i<MAXD;i++ ){ // right
		if( i % 2 == 0 ){
			tx = tx ;  ty = ty + right;
		}else{
			tx = tx ; ty = ty + left;
		}
		mEyePos.insert( reduce( std::make_pair( tx , ty )) );
	}

	if( mEyePos.find( std::make_pair<int,int>(0,0) ) != mEyePos.end() )
		return mEyePos.size() - 1;

	return mEyePos.size();
}


int main(int argc,char **argv){
	if( argc == 1 ){
		file.open("testQ2.txt");
		ofile.open("DQQ.out.txt");
	}else{
		file.open(argv[1]);
		ofile.open("D.out.txt");
	}
	if( file.fail() || ofile.fail() )
		return -1;

	int n;
	file >> n;

	for( int i=0;i<n;i++ ){
		ofile << "Case #" << i+1 << ": " << problem() << std::endl;
	}

	return 0;
}

