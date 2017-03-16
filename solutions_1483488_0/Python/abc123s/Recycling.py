# solution
def solve(A, B):
    answer = 0
    for num in range(A, B):
        #check to see if any of it's recycled pairs are in the range.
        snum = str(num)
        wlen = len(snum)
        counter = 1
        pairs = set()
        while (counter < wlen):
            if snum[counter] >= snum[0]:
                num2 = int(snum[counter:] + snum[:counter])
                if num2 > num and num2 <= B:
                    pairs.add(num2)
            counter += 1
        answer += len(pairs)
    return answer

# grab number of cases
cases = int(raw_input())

# array to store input values
inputs = []

#parse input, store in inputs array
for ncase in range(cases):
    A, B = map(int, raw_input().split(' '))
    inputs.append((ncase, A, B))

# calculate answer
for case in inputs:
    ncase, A, B = case
    print "Case #" + str(ncase + 1) + ": " + str(solve(A, B))
