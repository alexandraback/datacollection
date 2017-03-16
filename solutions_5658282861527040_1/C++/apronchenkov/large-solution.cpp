#include <iostream>
#include <tuple>
#include <unordered_map>


class LessAutomaton {
public:
    explicit LessAutomaton(int bound)
      : bound_(bound)
    { }

    int numberOfStates() const
    {
        return 34;
    }

    int initialState() const
    {
        return 0;
    }

    int nextState(int state, bool bit) const
    {
        if (state <= 30) {
            const int mask = 1 << (30 - state);
            if (bit) {
                if (bound_ & mask) {
                    return state + 1;
                } else {
                    return 33;
                }
            } else {
                if (bound_ & mask) {
                    return 32;
                } else {
                    return state + 1;
                }
            }
        }
        return state;
    }

    bool isAcceptable(int state) const
    {
        return state == 32;
    }

private:
    int bound_;
};


struct State {
    int a, b, k;

    bool operator == (const State& other) const
    {
        return a == other.a &&
            b == other.b &&
            k == other.k;
    }
};


struct StateHash {
    size_t operator() (const State& state) const
    {
        return state.a * 100 + state.b * 10000 + state.k;
    }
};


unsigned long long countWinCombinations(int firstMax, int secondMax, int boundary)
{
    const LessAutomaton A(firstMax), B(secondMax), K(boundary);
    std::unordered_map<State, unsigned long long, StateHash> frontier;

    frontier.insert({State{A.initialState(), B.initialState(), K.initialState()}, 1});
    for (int i = 0; i <= 30; ++i) {
        std::unordered_map<State, unsigned long long, StateHash> nextFrontier;
        for (const auto& pair : frontier) {
            const auto& state = pair.first;
            for (int a = 0; a < 2; ++a) {
                for (int b = 0; b < 2; ++b) {
                    State nextState = {
                        A.nextState(state.a, a),
                        B.nextState(state.b, b),
                        K.nextState(state.k, a & b)
                    };
                    nextFrontier[nextState] += pair.second;
                }
            }
        }
        
        frontier = nextFrontier;
    }

    unsigned long long result = 0;
    for (const auto& pair : frontier) {
        const auto& state = pair.first;
        if (A.isAcceptable(state.a) &&
            B.isAcceptable(state.b) &&
            K.isAcceptable(state.k))
        {
            result += pair.second;
        }
    }
    return result;
}





int main()
{
    int numberOfCases;
    std::cin >> numberOfCases;
    for (int caseNo = 1; caseNo <= numberOfCases; ++caseNo) {
        int A, B, K;
        std::cin >> A >> B >> K;
        std::cout << "Case #" << caseNo << ": " << countWinCombinations(A, B, K) << '\n';
    }
    return 0;
}
