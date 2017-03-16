/*
 * =====================================================================================
 *
 *       Filename:  consonants.cpp
 *
 *    Description:  Consonants
 *
 *        Version:  1.0
 *        Created:  05/12/2013 12:01:00 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jan Sebechlebsky (), sebecjan@fit.cvut.cz
 *   Organization:  FIT CTU
 *
 * =====================================================================================
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>

using namespace std;

char word[2000000];

bool isvowel(char c){
	return (c=='a')||(c=='e')||(c=='i')||(c=='o')||(c=='u');
}

struct Interval{
	Interval( int x = 0, int y = 0){
		a = x;
		b = y;
	}
	int a,b;
	bool operator < ( const struct Interval & i )const {
		return (a==i.a)? b < i.b : a < i.a;
	}
};

long solve()
{
	set<Interval> s;
	int l;
	scanf("%s %d",word,&l);
	long current = 0;
	int len = strlen(word);
	long res = 0;
	if(l>len){
		return 0;
	}
	//init
	for( int i = 0; i < l; i++ ){
		if(!isvowel(word[i]))current++;	
	}
	if(current==l){
		res+=(len-l+1);
		Interval in;
		in.a= 0;
		for( int i = l; i <= len; i++ ){
			in.b = i;
			s.insert(in);	
		}
	}
	//printf("After init: %ld, current %ld\n",res,current);
	for( int i = 1; i <= (len-l); i++ ){
		if(!isvowel(word[i-1]))current--;
		if(!isvowel(word[i+l-1]))current++;
		//printf("Pos %d: %ld\n",i,current);
		if(current==l){
			//printf("adding %d\n",(i+1)*(len-i-l+1));
			res+=(i+1)*(len-i-l+1);
			for( int j = 0; j <= i; j++ )
				for( int k = i+l; k <= len; k++ ){
				//	printf("Interval %d - %d\n",j,k);
					s.insert(Interval(j,k));
				}
		}
	}
	return s.size();
}

int main( int argc, char ** argv ){
	int n;
	scanf("%d",&n);
	for( int c = 1; c <=n; c++ ){
		printf("Case #%d: %ld\n",c,solve());
	}
	return 0;
}

