input = open('A-small-attempt1.in', 'r')
output = open('A-small-attempt1.out', 'w')
t = int(input.readline().rstrip())
for test in range(t):
    r, c, m = map(int, input.readline().rstrip().split())
    ans = c // m
    if c % m == 0:
        ans += m - 1
    else:
        ans += m
    output.write("Case #" + str(test + 1) + ": " + str(ans) + "\n")

input.close()
output.close()