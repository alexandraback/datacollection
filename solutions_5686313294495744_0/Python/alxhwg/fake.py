import sys
import string
import numpy as np

def main():
    inF = open(sys.argv[1], 'r')
    name = string.split(sys.argv[1], '.', 1)[0]
    ouF = open("{0}.out".format(name), 'w')
    T = int(inF.readline())
    for i in range(T):
        n = int(inF.readline())
        first, second = [], []
        for j in range(n):
            topic = inF.readline().split()
            first.append(topic[0])
            second.append(topic[1])
        k = solve(first, second)

        ouF.write("Case #{0}: {1}\n".format(i+1, k))
    inF.close()
    ouF.close()

def solve(f, s):
    firsts = {}
    seconds = {}
    for i in range(len(f)):
        if f[i] not in firsts:
            firsts[f[i]] = [i]
        else:
            firsts[f[i]] += [i]
        if s[i] not in seconds:
            seconds[s[i]] = [i]
        else:
            seconds[s[i]] += [i]
    repeat1 = []
    repeat2 = []
    for key in firsts:
        if len(firsts[key]) > 1:
            print(firsts[key])
            repeat1 += firsts[key]
    for key in seconds:
        if len(seconds[key]) > 1:
            repeat2 += seconds[key]
    pure = list(set(repeat1).intersection(repeat2))
    num = 0
    while len(pure) > 0:
        overlaps = []
        for i in pure:
            overlap = len(firsts[f[i]]) + len(seconds[s[i]])
            overlaps.append(overlap)
        maxR = np.argmax(overlaps)
        # print(pure)
        # print(overlaps)
        # print(maxR)
        maxR = pure[maxR]
        firsts[f[maxR]].remove(maxR)
        seconds[s[maxR]].remove(maxR)
        num += 1
        for key in firsts:
            repeat1 = []
            if len(firsts[key]) > 1:
                repeat1 += firsts[key]
        for key in seconds:
            repeat2 = []
            if len(seconds[key]) > 1:
                repeat2 += seconds[key]
        pure = list(set(repeat1).intersection(repeat2))
    return num

main()
