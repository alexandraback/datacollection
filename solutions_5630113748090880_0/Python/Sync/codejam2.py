def readFile (filename):
    result = []
    with open(filename, "r") as f:
        for line in f:
            line = line.split()
            result.append(line)
    return result

def missing(lists):
    # Every element should appear twice
    nums = [0]*2500
    for i in lists:
        for j in i:
            nums[int(j)] += 1
    result = []
    for i in range(1, len(nums)):
        if nums[i]%2==1:
            result.append(i)
    return result

def main():
    file = "file.txt"
    data = readFile(file)
    counter = 1
    num = 1
    while counter < len(data):
        size = int(data[counter][0])
        answer = missing(data[counter+1:(counter + size*2)])
        answer.sort()
        result = ""
        for i in answer:
            result += str(i) + " "
        print("Case #{0}: {1}".format(num, result[:-1]))
        counter += size*2
        num += 1
        
    #answer = missing(data[2:])
    #answer.sort()
    #print(answer)
    
    #for i in range(1, len(data)):
    #    print("Case #{0d}: {1}".format(i, lastWord(data[i][0])))
