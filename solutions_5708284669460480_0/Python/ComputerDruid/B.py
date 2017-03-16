#!/usr/bin/env python3
from collections import defaultdict

class B:
    def __init__(self, keys, word, S):
        self.keys = keys
        self.word = word
        self.S = S
        self.keysCount = defaultdict(int)
        for key in keys:
            self.keysCount[key] += 1

    def p_instance(self, word):
        result = 1
        for letter in word:
            result *= (self.keysCount[letter] / len(self.keys))
        return result

    def p_overall(self, word):
        result = 0
        if len(word) > self.S:
            return 0
        p_word = self.p_instance(word)
        for i in range(self.S - len(word) + 1):
            result += p_word * (1 - result)
        return result

    def find_overlap(self, word):
        for i in range(1, len(word)):
            if word[i:] == word[:-i]:
                return word[i:]
        return ""

    def build_repetitions(self, word):
        repetitions = []
        rep = word
        count = 0
        body = self.find_overlap(word)
        tail = word[len(body):]
        if body == "":
            body = word
            tail = word
        while len(rep) <= self.S:
            repetitions.append(rep)
            count += 1
            rep = rep + tail
        return repetitions

    def solve(self):
        for letter in self.word:
            if self.keysCount[letter] == 0:
                return 0.0 #bring 0, pay 0
        reps = self.build_repetitions(self.word)
        bananas = len(reps)

        keep_expectation = 0
        prob_any_payout = 0
        probs = [ self.p_overall(rep) for rep in reps ]
        cum_sum = 0
        probs.reverse()
        for i in range(len(probs)):
            probs[i] -= cum_sum
            cum_sum += probs[i]
        probs.reverse()

        for i in range(len(reps)):
            rep = reps[i]
            banana_payout = i + 1
            prob = probs[i]
            keep_expectation += prob * (bananas - banana_payout)
            prob_any_payout += prob
        keep_expectation += (1 - prob_any_payout) * bananas # I keep them all otherwise
        return keep_expectation

def solve(keys, word, S):
    solver = B(keys, word, S)
    return solver.solve()

if __name__ == '__main__':
    T = int(input())
    for t in range(T):
        K, L, S = [int(x) for x in input().split(" ")]
        keys = input()
        word = input()
        print("Case #" + str(t+1) +":", solve(keys, word, S))
