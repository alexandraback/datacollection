#coding=utf-8



T = int(raw_input())

for Case in range(1, T + 1):
    N = raw_input()
    tot = 0
    if N[-1:] == '0':
        tot += 1
        N = str(int(N) - 1)
    while len(N) != 1:
        l = len(N)
        t = int(N) - int('9' * (l - 1))
        tot += min(t, int(N[0:l/2][::-1]) + int(N[l/2:]) + 1)
        N = '9' * (l - 1)
    tot += int(N)
    print "Case #%d:"%Case, tot

