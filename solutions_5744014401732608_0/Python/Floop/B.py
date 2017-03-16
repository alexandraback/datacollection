#!/usr/bin/env python3
import random
import numpy as np

def test(G, i, j, M):
    if paths(G) == M:
        return True

    j_ = (j+1) % G.shape[1]
    i_ = i
    if j + 1 >= G.shape[1]:
        i_ += 1
    j_ = max(i_ + 1, j_)

    if i_ >= G.shape[0]:
        return False

    if test(G, i_, j_, M):
        return True
    G[i,j] = 1
    if test(G, i_, j_, M):
        return True
    G[i,j] = 0

def paths(G):
    C = np.zeros((G.shape[0]), dtype='uint8')
    C[0] = 1
    for i in range(G.shape[0]):
        for j in range(G.shape[1]):
            if G[i][j] == 1:
                C[j] += C[i]
    return C[C.shape[0] - 1]

if __name__ == '__main__':
    T = int(input())
    for t in range(1, T+1):
        B, M  = map(int, str.split(input()))
        G = np.zeros((B, B), dtype='uint8')
        for i in range(G.shape[0]):
            for j in range(i+1, G.shape[1]):
                G[i, j] = 1
        upper = paths(G)
        G = np.zeros((B, B), dtype='uint8')
        if M <= upper and test(G, 0, 1, M):
            print('Case #{}: POSSIBLE'.format(t))
            for i in range(B):
                for j in range(B):
                    print(G[i,j], end='')
                print()
        else:
            print('Case #{}: IMPOSSIBLE'.format(t))

        #for B in range(1, 10):
        #    for M in range(1, 20):
        #        G = np.zeros((B, B), dtype='uint8')
        #        if test(G, 0, 1, M):
        #            print('Case #{}, {}: POSSIBLE'.format(B, M))
        #            for i in range(B):
        #                for j in range(B):
        #                    print(G[i,j], end='')
        #                print()
        #        else:
        #            print('Case #{}, {}: IMPOSSIBLE'.format(B, M))
