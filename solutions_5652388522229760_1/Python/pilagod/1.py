class Solution(object):
    def fallAsleep(self, n):
        if n == 0:
            return "INSOMNIA"

        step = 0
        # test if 1023, then stop
        bitsTable = 0

        while bitsTable != 1023:
            step += 1

            numBits = 0
            numString = str(n * step)

            for i in numString:
                numBits |= 1 << int(i)

            bitsTable |= numBits

        return n * step

# raw_input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# This is all you need for most Google Code Jam problems.
t = int(input())  # read a line with a single integer
test = Solution()

# for i in range(100000):
#     print("Case #{}: {}".format(i, test.fallAsleep(i)))

for i in range(1, t + 1):
    n = int(input())
    print("Case #{}: {}".format(i, test.fallAsleep(n)))
    # check out .format's specification for more formatting options