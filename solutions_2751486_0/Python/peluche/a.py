#!/usr/bin/env python2.7
#
# naive version
# generate all permutation with a stack

import Queue

tried = {}
q = []
vowel = ['a', 'e', 'i', 'o', 'u']

def is_n_complex(name, n):
    max = 0
    for c in name:
        if c in vowel:
            max = 0
        else:
            max += 1
        if max == n:
            return True
    return False

def solve(n):
    while q:
        name = q.pop()
        ind, word = name.split('-')
        ind = int(ind)
        if is_n_complex(word, n):
            tried[name] = 1
            a = '{}-{}'.format(ind+1, word[1:])
            if a not in tried:
                tried[a] = 0
                q.append(a)
            a = '{}-{}'.format(ind, word[:-1])
            if a not in tried:
                tried[a] = 0
                q.append(a)
    return sum(tried.values())

def main():
    T = int(raw_input())
    for i in range(0, T):
        # reset the globals
        global tried
        tried = {}
        global q
        q = []

        name, n = raw_input().split(' ')
        n = int(n)
        #print name
        #print n
        q.append('{}-{}'.format(0, name))
        res = solve(n)
        print 'Case #{}: {}'.format(i+1, res)

if __name__ == '__main__':
    main()
    #print is_n_complex('quartz', 3)
    #print is_n_complex('quarte', 3)
    #print is_n_complex('quartz', 3)
    #print is_n_complex('rtz', 3)
    #print is_n_complex('rtze', 3)
