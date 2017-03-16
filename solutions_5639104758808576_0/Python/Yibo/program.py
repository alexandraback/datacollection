#!/usr/bin/python2.7

f = open('input.txt', 'r')
T = int(f.readline())

def solve(S_max, arr):
    num_total = 0
    num_need = 0
    for index in range(len(arr)):
        if num_total + num_need < index:
            num_need += (index - num_total - num_need)
        freq = int(arr[index])
        num_total += freq

    print num_need

for t in range(T):
    line = f.readline().rstrip()
    (S_max, arr) = line.split(' ')
    S_max = int(S_max)
    assert S_max + 1 == len(arr)

    print "Case #" + str(t + 1) + ":",
    solve(S_max, arr)

