import math

input = open('B-small-attempt0.in', 'r')
output = open('B-small-attempt0.out', 'w')
t = int(input.readline().rstrip())
for test in range(t):
    b, m = map(int, input.readline().rstrip().split())
    if m > 2 ** (b - 2):
        output.write("Case #" + str(test + 1) + ": IMPOSSIBLE\n")
        continue
    output.write("Case #" + str(test + 1) + ": POSSIBLE\n")
    t = [[0] * b for i in range(b)]
    k = int(math.log(m, 2))
    for i in range(k):
        for j in range(i + 1):
            t[b - i - 2][b - j - 1] = 1
        t[0][b - i - 1] = 1
    t[0][b - k - 1] = 1
    m -= 2 ** k
    j = b - 2
    if m > 0:
        t[0][b - k - 2] = 1
    while j > b - k - 2:
        t[b - k - 2][j] = m % 2
        m >>= 1
        j -= 1
    for i in range(b): 
        output.write("".join(map(str, t[i])) + "\n")

input.close()
output.close()