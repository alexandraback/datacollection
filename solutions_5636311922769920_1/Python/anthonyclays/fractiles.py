#!/usr/bin/env python
# -*- coding: utf-8 -*-

def create(K, C, S):
    if C*S < K:
        return None
    def chunks(itr, n):
        return [itr[i:i+n] for i in range(0, len(itr), n)]
    def to_ind(inds):
        return sum(i * K**(i%C) for i in inds)
    return map(to_ind, chunks(range(K), C))

def case(t):
    K, C, S = map(int, input().split())
    inds = create(K, C, S)
    if inds is None:
        print('Case #{}: IMPOSSIBLE'.format(t))
    else:
        print('Case #{}: {}'.format(t, ' '.join(str(1 + ind) for ind in inds)))

if __name__ == "__main__":
    for t in range(1, int(input())+1):
        case(t)
