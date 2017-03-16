#include <stdio.h>
#include <iostream>
#define TEST

using namespace std;

int main()
{
	#ifndef TEST
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0);

}
