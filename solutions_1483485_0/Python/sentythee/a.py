#!/usr/bin/python

from sys import stdin

mapping = {'\n': '\n', ' ': ' ', 'a': 'y', 'c': 'e', 'b': 'h', 'e': 'o', 'd': 's', 'g': 'v', 'f': 'c', 'i': 'd', 'h': 'x', 'k': 'i', 'j': 'u', 'm': 'l', 'l': 'g', 'o': 'k', 'n': 'b', 'p': 'r', 's': 'n', 'r': 't', 'u': 'j', 't': 'w', 'w': 'f', 'v': 'p', 'y': 'a', 'x': 'm', 'q':'z', 'z':'q'}	

input = stdin.readlines()
n = int(input[0].strip())

for i in range(0, n):
	cipher = input[i+1]
	print 'Case #%d: %s' % (i+1, ''.join([mapping[x] for x in cipher])),

