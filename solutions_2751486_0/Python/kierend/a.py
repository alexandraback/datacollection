#!/usr/bin/python3

def vowel(c):
    return c in "aeiou"

T = int(input())

for t in range(T):
    name, n = input().split()
    n = int(n)
    clusters = []
    i = 0
    j = 0
    while j <= len(name):
        if vowel(name[j-1]):
            i = j
            j += 1
        elif j - i == n:
            clusters.append(i)
            i += 1
            j += 1
        elif j - i > n:
            i += 1
        else: # j - i < n:
            j += 1
    value = 0
    if len(clusters) > 0:
        value += (clusters[0] + 1) * (len(name) - clusters[0] - n + 1)
    for i in range(1, len(clusters)):
        value += (clusters[i] - clusters[i-1]) * (len(name) - clusters[i] - n + 1)
    print("Case #{}: {}".format(t + 1, value))

