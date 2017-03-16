import sys

input = open('///Users/Zetilov/Downloads/B-large.in.txt', 'r')
output = open('output.txt', 'w')


#input = sys.stdin
#output = sys.stdout


t = int(input.readline())
for z in range(t):
    r = 1000
    n = int(input.readline())
    v = [int(j) for j in input.readline().split()]
    for i in range(1, 1000):
        ans = i
        for j in v:
            if j > i:
                ans += j // i - (j % i == 0)
        r = min(r, ans)
    print('Case #', z + 1, ': ', end = '', sep = '', file = output)
    print(r, file = output)