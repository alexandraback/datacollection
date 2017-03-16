import sys

FROMFILE = True

def get_input():
    if FROMFILE:
        return fin.readline()
    else:
        return raw_input()

def write_output(string):
    if FROMFILE:
        fout.write(string)
    else:
        sys.stdout.write(string)

if FROMFILE:
    fin = open('B-large.in', 'r')
    fout = open('B.out', 'w')

t = int(get_input().strip())

for test in range(t):
    inp = map(int, get_input().strip().split())
    (n, s, p) = inp[:3]
    ind = 0
    dp = [[-1000000 for i in range(s + 1)] for j in range(n + 1)]
    dp[0][0] = 0
    for i in inp[3:]:
        ind += 1
        tmp = [False for j in range(4)]
        for a in range(11):
            for b in range(a - 2, a + 3):
                for c in range(i - a - b, i - a - b + 1):
                    if 10 >= b >= 0 and 10 >= c >= 0 and max([a, b, c]) <= min([a, b, c]) + 2:
                        if max([a, b, c]) == min([a, b, c]) + 2 and max([a, b, c]) >= p:
                            tmp[0] = True
                        elif max([a, b, c]) >= p:
                            tmp[1] = True
                        elif max([a, b, c]) == min([a, b, c]) + 2:
                            tmp[2] = True
                        else:
                            tmp[3] = True
        for j in range(s + 1):
            if tmp[0]:
                if j > 0:
                    dp[ind][j] = max(dp[ind][j], dp[ind - 1][j - 1] + 1)
            if tmp[1]:
                dp[ind][j] = max(dp[ind][j], dp[ind - 1][j] + 1)
            if tmp[2]:
                if j > 0:
                    dp[ind][j] = max(dp[ind][j], dp[ind - 1][j - 1])
            if tmp[3]:
                dp[ind][j] = max(dp[ind][j], dp[ind - 1][j])
        
    write_output('Case #' + str(test + 1) + ': ' + str(dp[n][s]) + '\n')

if FROMFILE:
    fin.close()
    fout.close()
