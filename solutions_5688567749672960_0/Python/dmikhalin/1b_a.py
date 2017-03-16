input = open('A-small-attempt0.in', 'r')
output = open('A-small.out', 'w')
t = int(input.readline().rstrip())
dp = [999999999] * 1000001
dp[1] = 1
for i in range(2, 1000001):
    if len(str(i)) == len(str(int(str(i)[::-1]))):
        dp[i] = min(dp[i - 1], dp[int(str(i)[::-1])]) + 1
    else:
        dp[i] = dp[i - 1] + 1
for test in range(t):
    data = int(input.readline().rstrip())
    output.write("Case #" + str(test + 1) + ": " + str(dp[data]) + "\n")

input.close()
output.close()
