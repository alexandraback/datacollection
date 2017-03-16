#include "stdafx.h"

template<>
void Prepare<ProblemA>()
{
}

template<> 
void Solve<ProblemA>(Int T)
{
	Int R, C, W;
	// .....
	// .xx..
	// .......
	// .xxxxx.
	// 
	R = ReadNum();
	C = ReadNum();
	W = ReadNum();
	Int result = (C / W) * (R-1);
	result += C / W;
	if (C % W == 0) {
		result--;
		result += W;
	}
	else {
		result += W;
	}
	Write(T, result);
}