#define R1AP3
#ifdef R1AP3



#include <iostream>
#include <stdint.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>

class node {
	node * next = nullptr;

	bool cycleMarked = false;
	void markCycle(int cycleID, int currentSize) {
		if (cycleMarked) {
			cycleSize = currentSize;
		}
		else {
			this->cycleID = cycleID;
			this->distFromCycle = 0;
			cycleMarked = true;
			next->markCycle(cycleID, currentSize + 1);
			this->cycleSize = next->cycleSize;
		}
	}

public:

	int distFromCycle = 100000;
	int cycleEntryPoint = -1;
	int cycleID = -1;
	int cycleSize = -1;
	int id = -1;

	void clear() {
		distFromCycle = 100000;
		cycleID = -1;
		cycleSize = -1;
		id = -1;
		cycleMarked = false;
		computeMarked = COMPUTE_NOVISIT;
	}

	enum {COMPUTE_VISITED_NOW, COMPUTE_VISITED_BEFORE, COMPUTE_NOVISIT} computeMarked = COMPUTE_NOVISIT;
	void compute(int &cycleID) {
		if (computeMarked == COMPUTE_VISITED_BEFORE) return;
		else if (computeMarked == COMPUTE_VISITED_NOW) 
			markCycle(cycleID++, 0);
		else {
			computeMarked = COMPUTE_VISITED_NOW;
			next->compute(cycleID);
			computeMarked = COMPUTE_VISITED_BEFORE;
			if (distFromCycle == 100000) {
				distFromCycle = next->distFromCycle + 1;
				this->cycleID = next->cycleID;

				if (next->distFromCycle == 0) cycleEntryPoint = next->id;
				else cycleEntryPoint = next->cycleEntryPoint;
			}
		}
	}

	void setNext(int thisId, node * n) {
		id = thisId;
		next = n;
	}
};

int solve(node ** n, int * bff, size_t cnt) {
	
	for (int i = 0; i < cnt; i++) {
		n[i]->clear();
		n[i]->setNext(i, n[bff[i]]);
	}
	
	int cycleIndex = 0;
	for (int i = 0; i < cnt; i++) 
		n[i]->compute(cycleIndex);
	
	int * bestLength = new int[cycleIndex];
	int * secondBestLength = new int[cycleIndex];
	int * bestEntry = new int[cycleIndex];
	int * cycleSize = new int[cycleIndex];
	memset(bestLength, 0x00, cycleIndex * sizeof(int));
	memset(secondBestLength, 0x00, cycleIndex * sizeof(int));

	for (int i = 0; i < cnt; i++) {
		int candidate = n[i]->distFromCycle;
		int candidateCycle = n[i]->cycleID;
		int candidateEntry = n[i]->cycleEntryPoint;

		if (candidateCycle == -1) continue;

		cycleSize[candidateCycle] = n[i]->cycleSize;

		if (candidate >= bestLength[candidateCycle]) {

			if (candidateEntry == bestEntry[candidateCycle]) {
				bestLength[candidateCycle] = candidate;
			}
			else {

				secondBestLength[candidateCycle] = bestLength[candidateCycle];
				bestLength[candidateCycle] = candidate;
				bestEntry[candidateCycle] = candidateEntry;
				
			}

		}
		else if (candidate > secondBestLength[candidateCycle]) {
			
			if (candidateEntry == bestEntry[candidateCycle]) continue;
			
			secondBestLength[candidateCycle] = candidate;

		}
	}
	int twosSizes = 0;
	int biggerSizes = 0;
	for (int i = 0; i < cycleIndex; i++) {
		if (cycleSize[i] == 2) twosSizes += cycleSize[i] + bestLength[i] + secondBestLength[i];
		else biggerSizes = std::max(biggerSizes, cycleSize[i]);
	}
	
	delete[] cycleSize;
	delete[] bestLength;
	delete[] secondBestLength;
	delete[] bestEntry;

	return std::max(biggerSizes, twosSizes);
}


int main(void) {
	int testCases;
	std::cin >> testCases;
	const size_t MAX_N = 1024;

	int * bff = new int[MAX_N];
	
	node ** nodes = new node*[MAX_N];
	for (int i = 0; i < MAX_N; i++) 
		nodes[i] = new node;

	for (int c = 1; c <= testCases; c++) {
		std::cout << "Case #" << c << ": ";

		memset(bff, 0x00, MAX_N * sizeof(int));
		
		uint64_t N;
		std::cin >> N;
		for (size_t i = 0; i < N; i++) {
			scanf("%i", &bff[i]);
			bff[i]--;
		}
		
		std::cout << solve(nodes, bff, N) << "\n";
	}

	delete[] bff;
	for (int i = 0; i < MAX_N; i++) delete nodes[i];
	delete[] nodes;
	
	return 0;
}

#endif