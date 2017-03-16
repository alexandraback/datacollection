#include "stdafx.h"

Int repeats[256];


template<>
void Prepare<ProblemB>()
{
}

Int  K, L, S;
Int overlapedLength;
Str trgt;
Int maxBanana;

void InitRepeats(const Str& kb)
{
	maxBanana = 0;
	memset(repeats, 0, sizeof(repeats));
	for (Int i = 0; i < kb.size(); i++)
	{
		if (trgt.find(kb[i]) == Str::npos)
		{
			repeats['Z'+1]++;
		}
		else
			repeats[kb[i]]++;
	}
}
bool CanMake(const Str& trgt)
{
	for (Int i = 0; i < trgt.size(); i++)
	{
		if (!repeats[trgt[i]]) return false;
	}
	return true;
}
Int CountRepeat(const Str& trgt)
{
	for (Int i = 1; i < trgt.size(); i++)
	{
		Int idx = trgt.find(trgt.substr(i));
		if (idx == 0)
		{
			return trgt.size() - 1;
		}
	}
	return trgt.size();
}

Int Count(const Str & curr)
{
	Int res = 0;
	for (Int i = 0; i <= S - trgt.size(); i++)
	{
		if (curr.find(trgt, i) == i){
			res++;
			if (overlapedLength < trgt.size())
				i += trgt.size() - overlapedLength - 1;
			else
				i += trgt.size() - 1;
		}
	}
	maxBanana = max(maxBanana, res);
	return res;
}
Int Cnt(Str & curr, Int i)
{
	Int res = 0;
	if (i >= S) {
		res += Count(curr);
		
	} 
	else
	{
		for (Int j = 'A'; j <= 'Z'+1; j++)
		{
			if (repeats[j]) {
				curr.append(1, (char)j);
				res += Cnt(curr, i + 1) * repeats[j];
				curr.resize(i);
			}
		}
	}
	return res;
}

template<>
void Solve<ProblemB>(Int T)
{
	K = ReadNum(); //K contains a string of K uppercase English letters representing the monkey's keyboard
	L = ReadNum(); // the target word length
	S = ReadNum(); // S times

	Str kb = ReadStr();
	trgt = ReadStr();
	//if (trgt.size() > S) {
	//	Write(T, "0.0");
	//	return;
	//}
	InitRepeats(kb);
	//if (!CanMake(trgt)){
	//	Write(T, "0.0");
	//	return;
	//}
	 
	overlapedLength = CountRepeat(trgt);

	Str tmp;
	Float options = pow(kb.size(), S);
	Int cnt = Cnt(tmp, 0);
	Float result = maxBanana - cnt / options;
	if (result <= 0.000001)
		Write(T, "0.0");
	else
		Write(T, result);
}