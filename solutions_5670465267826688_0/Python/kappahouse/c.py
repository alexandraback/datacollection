# C. Dijkstra

M = ['01234567',
     '14365072',
     '27416305',
     '32547610',
     '45670123',
     '50721436',
     '63052741',
     '76103254']

def find_i(s):
    c = 0
    for i in range(len(s)):
        c = int(M[c][s[i]])
        if c == 1:
            return i + 1
    return len(s) + 1

def find_k(s):
    c = 0
    for i in range(len(s), 0, -1):
        c = int(M[s[i - 1]][c])
        if c == 3:
            return i - 1
    return -1

def is_j(s, start, end):
    if start >= end:
        return False
    c = 0
    for i in range(start, end):
        c = int(M[c][s[i]])
    return (c == 2)

t = input()
for c in range(t):
    (l, x) = [int(s) for s in raw_input().rstrip().split(' ')]
    if x >= 16:
        x = 12 + (x % 4)
    s = [ord(cc) - ord('h') for cc in raw_input().rstrip()] * x
    print "Case #" + str(c + 1) + ":",
    print 'YES' if is_j(s, find_i(s), find_k(s)) else 'NO'
