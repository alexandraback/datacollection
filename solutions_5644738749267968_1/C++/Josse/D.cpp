// I can hear you thinking: what's with the comments? Well, I had to convince myself. :P
// First of all, I present Ken's general strategy:
// *) If he has a block heavier than the block Naomi chose, then he uses a block as light as possible to win this round.
// *) If he cannot win this round, then he uses his very lightest block.

#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

void solve() {
	int N;
	cin >> N;
	deque<double> NaomiA(N), NaomiB, KenA(N), KenB;
	for (int i = 0; i < N; i++)
		cin >> NaomiA[i];
	sort(NaomiA.begin(), NaomiA.end());
	NaomiB = NaomiA;
	for (int i = 0; i < N; i++)
		cin >> KenA[i];
	sort(KenA.begin(), KenA.end());
	KenB = KenA;
	// Deceitful War. Naomi's strategy: play blocks from low to high.
	// After reading the steps in the strategy below, it should be clear why this is optimal.
	// (Use blocks that are a lost cause to get rid of Ken's heavy blocks.)
	int scoreA = 0;
	for (int i = 0; i < N; i++) {
		if (NaomiA.front() < KenA.front()) {
			// Lost cause. This block is lighter than ANY block Ken has.
			// Lie about weight so that Ken wastes his heaviest block.
			KenA.pop_back();
		}
		else {
			// Tell Ken that this one weighs more than anything he has left.
			// Ken will then use his lightest block, so that Naomi wins this round.
			KenA.pop_front();
			scoreA++;
		}
		NaomiA.pop_front();
	}
	// Regular War. Naomi's strategy: play blocks from high to low.
	// It's not so easy to see why this is optimal, but here we go:
	// Firstly, we call one of Ken's blocks inevitible if it is heavier than every block Naomi has.
	// If Ken has an inevitble block, then Naomi has to get rid of it before she can win another round.
	// We call two of Naomi's blocks N_1 and N_2 equivalent if they win and lose from exactly the same of Ken's blocks.
	// (This is precisely when Ken doesn't have a block weighing somewhere between N_1 and N_2.)
	// Let N_max and K_max denote both player's heaviest block at the present time.
	// Any block N' that might lose to K_max at some point in the future, will at that stage be equivalent to N_max. (Because of how Ken plays.)
	// Thus, there can be no benefit from saving N_max for later.
	//
	// Secondly, if N_max is a guaranteed winner, then Naomi might put it aside until the end of the game.
	// However, now she still loses from the same inevitible blocks as described above, so this doesn't affect the final score.
	int scoreB = 0;
	for (int i = 0; i < N; i++) {
		if (NaomiB.back() < KenB.back()) {
			// Ken has a heavier block, and he will use it. He might not necessarily use his
			// heaviest block (since he might have a lighter block capable of winning this round),
			// but it doesn't matter for the remainder of the game. The blocks are equivalent.
			KenB.pop_back();
		}
		else {
			// Ken cannot win this round, so he will use his lightest block.
			KenB.pop_front();
			scoreB++;
		}
		NaomiB.pop_back();
	}
	cout << scoreA << " " << scoreB << endl;
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cout << "Case #" << (i + 1) << ": ";
		solve();
	}
	return 0;
}
