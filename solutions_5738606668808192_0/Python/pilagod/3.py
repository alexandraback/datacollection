class Solution(object):
    def getJamcoins(self, n, j):
        maxJamcoins = (1 << n) - 1
        curJamcoins = (1 << (n - 1)) + 1
        result = ""
        count = 0

        while count < j and curJamcoins < (maxJamcoins - 1):
            curJamcoins += 2
            binaryJamcoins = "{0:b}".format(curJamcoins)
            isPrimeFlag = False

            for base in range(2, 11):
                if int(binaryJamcoins, base) % (base + 1) != 0:
                    isPrimeFlag = True

            if not isPrimeFlag:
                result += "{0} {1}\n".format(binaryJamcoins, ' '.join([str(i) for i in range(3, 12)]))
                count += 1

        return result

# raw_input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# This is all you need for most Google Code Jam problems.
t = int(input())  # read a line with a single integer
test = Solution()

for i in range(1, t + 1):
    testCase = input().split(' ')
    n = int(testCase[0])
    j = int(testCase[1])
    print("Case #{}:\n{}".format(i, test.getJamcoins(n, j)), end="")
    # check out .format's specification for more formatting options
