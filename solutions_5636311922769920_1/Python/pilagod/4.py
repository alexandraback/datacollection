class Solution(object):
    def getFractiles(self, k, c, s):
        if k == 1:
            return 1

        if c == 1:
            if s < k:
                return "IMPOSSIBLE"
            return " ".join([str(i) for i in range(1, k + 1)])
        else:
            if s < k - 1:
                return "IMPOSSIBLE"
            return " ".join([str(i) for i in range(2, k + 1)])

# raw_input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# This is all you need for most Google Code Jam problems.
t = int(input())  # read a line with a single integer
test = Solution()

for i in range(1, t + 1):
    testCase = input().split(' ')
    k = int(testCase[0])
    c = int(testCase[1])
    s = int(testCase[2])
    print("Case #{}: {}".format(i, test.getFractiles(k, c, s)))
    # check out .format's specification for more formatting options
