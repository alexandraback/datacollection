//
//  Treasure.cpp
//  Google Code Jam 2013
//
//  Created by Kristopher Giesing on 4/12/13.
//  Copyright (c) 2013 Kristopher Giesing. All rights reserved.
//
#include <iostream>
#include <fstream>

#include <map>
#include <vector>
#include <set>

// 201 because I was too lazy to convert out of one-based indexing
#define MAX_KEY_TYPES 201

typedef int KeyType;
typedef std::vector<KeyType> Keys;

struct Chest
{
	bool mIsOpen;
	int mIndex;
	KeyType mToOpen;
	Keys mKeys;
	
	void describe();
};

void
Chest::describe()
{
	std::cout << "Chest " << mIndex << " opened by " << mToOpen << " with:";
	for (Keys::iterator iter = mKeys.begin(); iter != mKeys.end(); iter++) {
		std::cout << " " << *iter;
	}
	std::cout << "\n";
}

typedef std::vector<Chest *> Solution;

class Solver
{
public:
	Solver();
	
	void addKey(KeyType iType);
	void addChest(Chest *iChest);
	
	void solve();
	
	Solution &getSolution() { return mSolution; }
	
private:
	typedef int KeyCounts[MAX_KEY_TYPES];
	typedef std::vector<Chest *> Chests;
	typedef std::map<KeyType, Chests> ChestMap;
	
	typedef uint32_t Transposition;
	typedef std::set<Transposition> Failures;
	
	void openChest(Chest *iChest);
	void unopenChest(Chest *iChest);
	
	bool impossible();
	
	Transposition position();
	
	KeyCounts mKeys;
	Chests mChests;
	Solution mSolution;
	Failures mFailures;
};

Solver::Solver()
{
	for (int i = 0; i < MAX_KEY_TYPES; i++) {
		mKeys[i] = 0;
	}
}

void
Solver::addKey(KeyType iType)
{
	mKeys[iType]++;
}

void
Solver::addChest(Chest *iChest)
{
	mChests.push_back(iChest);
}

// A transposition represents all the chests we've opened so far,
// in order of their index rather than order of opening
// This works because once they're open, the order we opened them in
// becomes irrelevant
Solver::Transposition
Solver::position()
{
	Transposition pos = 0;
	for (int i = 0; i < mSolution.size(); i++) {
		pos += 1 << (mSolution[i]->mIndex - 1);
	}
	return pos;
}

void
Solver::solve()
{
	Transposition currentPostion = position();
	if (mFailures.find(currentPostion) == mFailures.end()) {
		for (Chests::iterator iter = mChests.begin(); iter != mChests.end(); iter++) {
			Chest *chest = *iter;
			if (!chest->mIsOpen && mKeys[chest->mToOpen] > 0) {
				this->openChest(chest);
				if (mSolution.size() != mChests.size()) {
					this->solve();
				}
				if (mSolution.size() == mChests.size()) {
					return; // Quick exit on solution
				}
				this->unopenChest(chest);
			}
		}
		mFailures.insert(currentPostion);
	}
}

void
Solver::openChest(Chest *iChest)
{
	mSolution.push_back(iChest);
	mKeys[iChest->mToOpen]--;
	for (int i = 0; i < iChest->mKeys.size(); i++) {
		mKeys[iChest->mKeys[i]]++;
	}
	iChest->mIsOpen = true;
}

void
Solver::unopenChest(Chest *iChest)
{
	iChest->mIsOpen = false;
	for (int i = 0; i < iChest->mKeys.size(); i++) {
		mKeys[iChest->mKeys[i]]--;
	}
	mKeys[iChest->mToOpen]++;
	mSolution.pop_back();
}

int main(int argc, const char * argv[])
{
	std::ifstream input(argv[1]);
	int nTests;
	input >> nTests;
	for (int i = 0; i < nTests; i++) {
		int nKeys;
		int nChests;
		input >> nKeys;
		input >> nChests;
		
		Solver solver;
		for (int k = 0; k < nKeys; k++) {
			KeyType type;
			input >> type;
			solver.addKey(type);
		}
		for (int c = 0; c < nChests; c++) {
			Chest *chest = new Chest;
			chest->mIsOpen = false;
			chest->mIndex = c+1;
			input >> chest->mToOpen;
			int nKeysInChest;
			input >> nKeysInChest;
			for (int k = 0; k < nKeysInChest; k++) {
				KeyType containedKey;
				input >> containedKey;
				chest->mKeys.push_back(containedKey);
			}
			solver.addChest(chest);
		}
		
		solver.solve();
		Solution &solution = solver.getSolution();
		std::cout << "Case #" << (i+1) << ":";
		if (solution.size() == nChests) {
			for (Solution::iterator iter = solution.begin(); iter != solution.end(); iter++) {
				std::cout << " " << (*iter)->mIndex;
			}
		} else {
			std::cout << " IMPOSSIBLE";
		}
		std::cout << "\n";
	}
	
    return 0;
}
