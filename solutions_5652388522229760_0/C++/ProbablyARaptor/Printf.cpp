#include <cstdio>

#include "Printf.h"

template<typename V> void PrintStrings(V strings)
{
	for(auto string : strings)
	{
		printf("%s\n", string.c_str());
	}
}

template<typename V> void PrintInts(V ints)
{
	for(auto anInt : ints)
	{
		printf("%d\n", anInt);
	}
}