import sys
input = open('input.txt', 'r')
output = open('output.txt', 'w')


#input = sys.stdin
#output = sys.stdout


t = int(input.readline())
for z in range(t):
    r, ans = 0, 0
    s = input.readline().split()[1]
    for i in range(len(s)):
        j = int(s[i])
        if j == 0:
            continue
        if i > r:
            ans += (i - r)
            r = i
        r += j
    print('Case #', z + 1, ':', sep = '', end = ' ', file = output)
    print(ans, file = output)