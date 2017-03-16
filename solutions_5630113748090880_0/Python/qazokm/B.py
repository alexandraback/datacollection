inputFile = open("B.in")
outputFile = open("B.out", "w")

T = int(inputFile.readline())

for i in range(T):
    N = int(inputFile.readline())
    lists = [None] * (N * 2 - 1)
    for j in range(N * 2 - 1):
        lists[j] = list(map(int, inputFile.readline().split(" ")))

    heights = [0] * 2501

    for rank in lists:
        for height in rank:
            heights[height] = heights[height] + 1

    missing = []
    for height, count in enumerate(heights):
        if count % 2 == 1:
            missing.append(str(height))

    outputFile.write("Case #" + str(i + 1) + ": " + " ".join(missing) + "\n")
            

        
    
inputFile.close()
outputFile.close()
    


