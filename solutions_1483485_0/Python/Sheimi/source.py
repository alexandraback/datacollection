#!/usr/bin/env python

m = {' ': ' ', 'a': 'y', 'c': 'e', 'b': 'h', 'e': 'o', 'd': 's', 'g': 'v', 'f': 'c', 'i': 'd', 'h': 'x', 'k': 'i', 'j': 'u', 'm': 'l', 'l': 'g', 'o': 'k', 'n': 'b', 'q': 'z', 'p': 'r', 's': 'n', 'r': 't', 'u': 'j', 't': 'w', 'w': 'f', 'v': 'p', 'y': 'a', 'x': 'm', 'z': 'q'}

def compute_map(i):
    i = i + 1
    s = raw_input()
    sr = 'Case #%d: ' % i
    for l in s:
        sr += m[l]
    print sr

if __name__ == '__main__':
    i = int(raw_input())
    for x in range(i):
        compute_map(x)
