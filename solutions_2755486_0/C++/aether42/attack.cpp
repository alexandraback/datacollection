#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

typedef struct {
	int attackDay;
	int numAttacks;
	int westPoint;
	int eastPoint;
	int strength;
	int numDaysBtwAttacks;
	int travelDelta;
	int strengthChng;
} Tribe;

typedef struct {
	int wallLoc;
	int newHeight;
} WallUpdate;

int main(int argc, const char *argv[])
{
	int numCases = 0;
	int numTribes = 0;
	string temp;

	vector<Tribe> tribes;
	tribes.reserve(500);

	cin >> numCases;
	getline(cin, temp);

	for (int i = 0; i < numCases; ++i) {
		cin >> numTribes;
		getline(cin, temp);
		int eastMostPoint = 0;
		int westMostPoint = 0;
		int numSuccessfulAttacks = 0;
		Tribe tr;

		// read in the first tribe to get initial values for east/west most point
		cin >> tr.attackDay >> tr.numAttacks >> tr.westPoint >> tr.eastPoint >> tr.strength
				>> tr.numDaysBtwAttacks >> tr.travelDelta >> tr.strengthChng;
		getline(cin, temp);

		if (tr.travelDelta > 0 ) {
			eastMostPoint = tr.eastPoint + tr.travelDelta * (tr.numAttacks - 1);
			westMostPoint = tr.westPoint;
		}
		else {
			westMostPoint = tr.westPoint - tr.travelDelta * (tr.numAttacks - 1);
			eastMostPoint = tr.eastPoint;
		}

		tribes.push_back(tr);

		// get the rest of them
		for (int tribeNum = 1; tribeNum < numTribes; ++tribeNum) {
			cin >> tr.attackDay >> tr.numAttacks >> tr.westPoint >> tr.eastPoint >> tr.strength
					>> tr.numDaysBtwAttacks >> tr.travelDelta >> tr.strengthChng;
			getline(cin, temp);

			tribes.push_back(tr);

			int tribeEastMostPoint, tribeWestMostPoint;

			if (tr.travelDelta > 0 ) {
				tribeEastMostPoint = tr.eastPoint + tr.travelDelta * (tr.numAttacks - 1);
				tribeWestMostPoint = tr.westPoint;
			}
			else {
				tribeWestMostPoint = tr.westPoint - tr.travelDelta * (tr.numAttacks - 1);
				tribeEastMostPoint = tr.eastPoint;
			}

			if (tribeEastMostPoint > eastMostPoint) { eastMostPoint = tribeEastMostPoint; }
			if (tribeWestMostPoint > westMostPoint) { westMostPoint = tribeWestMostPoint; }
		}

		// change all the west points to negative
		for (Tribe &tribe : tribes) {
			tribe.westPoint = -tribe.westPoint;
		}

		// create a vector representing the wall
		vector<unsigned> wall(westMostPoint + eastMostPoint + 1);
		vector<WallUpdate> updates;
		updates.reserve(westMostPoint + eastMostPoint + 1);

		int currentDay = 0;
		while (1) {
			// find the tribe with the least day
			int nextDay = INT_MAX;
			Tribe *currentTribe = NULL;

			for (int tNum = 0; tNum < tribes.size(); ++tNum) {
				Tribe &tribe = tribes[tNum];

				if (tribe.numAttacks) {
					if (tribe.attackDay <= nextDay) {
						currentTribe = &tribes[tNum];
						nextDay = tribe.attackDay;
					}
				}
			}

			// check if no more tribes
			if (!currentTribe) {
				break;
			}

			// check if this is a new day
			if (currentDay != nextDay) {
				currentDay = nextDay;

				// update the wall
				for (WallUpdate wu : updates) {
					if (wall[wu.wallLoc] < wu.newHeight) { wall[wu.wallLoc] = wu.newHeight; }
				}

				updates.clear();
			}

			// check if the attack was successful at all
			bool attackSuccessful = false;
			for (int loc = currentTribe->westPoint + westMostPoint; loc <= currentTribe->eastPoint + westMostPoint; ++loc) {
				if (wall[loc] < currentTribe->strength) { 
					attackSuccessful = true; 
					updates.push_back({loc, currentTribe->strength});
				}
			}

			if (attackSuccessful) { ++numSuccessfulAttacks; }

			// update the tribe
			--currentTribe->numAttacks;
			currentTribe->attackDay += currentTribe->numDaysBtwAttacks;
			currentTribe->strength += currentTribe->strengthChng;
			currentTribe->eastPoint += currentTribe->travelDelta;
			currentTribe->westPoint += currentTribe->travelDelta;
		}

		cout << "Case #" << (i + 1) << ": " << numSuccessfulAttacks << endl;
	}

	return 0;
}
