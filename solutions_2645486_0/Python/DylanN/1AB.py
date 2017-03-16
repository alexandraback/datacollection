#benoni.boy
#Google Code Jam
#13 April 2013
import sys

sys.stdin = open('C:\GCJ\in.txt')
sys.stdout = open('C:\GCJ\out.txt', 'w')

def maxGain(maxE, E, R, N, v):
    if N == 1: return E*v[0]
    m = 0
    for e in range(0, E + 1):
        gain = e * v[0] + maxGain(maxE, min(E - e + R, maxE), R, N - 1, v[1:])
        if gain > m: m = gain
    return m

def do(i):
    #Small test case bf will do
    E, R, N = list(map(int, input().split()))
    v = list(map(int, input().split()))
    print('Case #' + str(i + 1) + ':', maxGain(E, E, R, N, v))

for i in range(eval(input())): do(i)

sys.stdin.close()
sys.stdout.close()
