inputFile = open('B-small-attempt0.in', 'r')
outputFile = open('B-small-attempt0.out', 'w')

numTests = int(inputFile.readline())

for i in range(numTests):
    nums = map(lambda x: int(x), inputFile.readline().split())
    a = nums[0]
    b = nums[1]
    k = nums[2]

    count = 0
    for m in range(a):
        for n in range(b):
            if m&n < k:
                count += 1

    outputFile.write('Case #'+str(i+1)+': ' + str(count) + '\n')

inputFile.close()
outputFile.close()
