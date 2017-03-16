#!/usr/local/bin/python

import sys

def solve(t):
    word = sys.stdin.readline().rstrip()

    top = max(word)
    toploc = word.rfind(top)

    best_word = []
    indices = set()
    while toploc >= 0:
        top = max(word[:toploc+1])
        toploc = word.rfind(top, 0, toploc+1) 

        best_word.append(top)
        indices.add(toploc)

        toploc -= 1

    for i in range(len(word)):
        if i not in indices:
            best_word.append(word[i])

    print 'Case #{}: {}'.format(t, ''.join(best_word))

if __name__=="__main__":
    T = int(sys.stdin.readline())
    for i in range(1, T+1):
        solve(i)
