class Solution(object):
    def flipPancakes(self, pancakeStack):
        pancakeStatus = ""
        flipCount = -1

        for pancake in pancakeStack:
            if pancakeStatus != pancake:
                pancakeStatus = pancake
                flipCount += 1

        if pancake == '-':
            flipCount += 1

        return flipCount

# raw_input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# This is all you need for most Google Code Jam problems.
t = int(input())  # read a line with a single integer
test = Solution()

for i in range(1, t + 1):
    pancakeStack = input()
    print("Case #{}: {}".format(i, test.flipPancakes(pancakeStack)))
    # check out .format's specification for more formatting options